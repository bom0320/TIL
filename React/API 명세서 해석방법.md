API 명세서 해석하는 방법
===
나이스 급식 API 명세서를 예시로 이 명세서를 일고 해석하는 방법을 단계별로 이해해보자

## 1. API 엔드포인트
- **엔드포인트**는 API 요청을 보낼 기본 주소(URL) 이다.
- 나이스 급식 API의 엔드포인트는 다음과 같다:
```arduino
https://open.neis.go.kr/hub/mealServiceDietInfo
```
이 주소가 API 서버와 통신하는 기본 URL 이다. 이 엔드포인트에 필요한 정보를 추가해서 데이터를 요청하게 된다.

## 2. 필수/선택 인자
API 명세서에서는 **필수 인자** 와 **선택 인자**가 정의되어 있다.

인자는 **API 요청을 할 때 서버에 전달하는 값**이다.

API 가 어떤 데이터를 반환할지 또는 어떤 작업을 할지 결정하는 데 중요한 역할을 한다.

### 기본 인자 (필수) :
#### KEY :
-  필수적으로 제공해야 하는 **인증키**이다. 
- 이 키는 공공데이터 포텔에서 발급받은 값을 넣으면 된다.

#### Type :
- 응답 데이터를 **xml** 형식 또는 **json** 형식으로 받을지를 설정한다. 
- `json` 을 선택하는 것이 데이터를 다루기 더 쉽다.

#### pIndex :
- 페이지 번호를 의미한다.
- 데이터를 여러 페이지로 나누어 가져올 수 있으며, 페이지 번호를 설정할 수 있다. 기본값은 1이다.

#### pSize :
- 한 페이지에 표시할 데이터의 수를 의미한다. 

### 신청 인자 (필수 및 선택) : 

#### ATPT_OFCDC_SC_CODE (필수) :
- 시도 교육청 코드이다.
- 교육청마다 고유한 카드를 가지고 있다 
- 예를 들어, 서울 특별시 교육청 코드는 `B10` 이다.

#### SD_SCHUL_CODE (필수) :
- 학교 코드이다.
- 특정 학교에 대한 급식 정보를 조회하기 위해 학교 고유의 코드를 입력해야 한다.

#### MMEAL_SC_CODE (선택) :
- 식사 코드를 의미한다.
- 예를 들어, 조식은 `1`, 중식은 `2`, 석식은 `3` 이다. 
- 특정 시간대의 급식을 조회할 때 사용한다.

#### MLSV_YMD (선택) :
- 특정 날짜의 급식 정보를 조회할 때 사용한다.
- `YYYYMMDD` 형식으로 입력한다.
- 예를 들어, `20240101` 은 2024년 1월 1일의 급식을 조회하는 요청이다.

#### MLSV_FROM_YMD, MLSV_TO_YMD (선택):
- 특정 기간 동안의 급식을 조회할 때 사용한다.
- `YYYYMMDD` 형식으로 시작일과 종료일을 입력한다.

## 3. 출력값 (응답값)
API 요청을 보내면 서버는 요청한 데이터를 응답으로 반환한다. 응답값은 JSON 이나 XML 형식으로 제공되며, 각각의 출력값은 API 명세서에 설명되어 있다. 여기서 중요한 항목들은 다음과 같다:

- **ATPT_OFCDC_SC_CODE**: 시도 교육청 코드
- **SD_SCHUL_CODE**: 학교 코드
- **SCHUL_NM**: 학교 이름
- **MLSV_YMD**: 급식 일자
- **DDISH_NM**: 급식 메뉴 (메뉴명이 포함된 항목)
- **CAL_INFO**: 칼로리 정보
- **NTR_INFO**: 영양 정보

이 데이터들은 JSON 형식으로 응답받았을 때 객체 또는 배열의 형태로 나타난다. 예를 들어, 급식 메뉴를 나타내는 DDISH_NM 항목은 '불고기, 밥, 국' 과 같은 문자열일 것이다.

## 4. API 호출 예시
이제 실제로 API 명세서를 바탕으로 어떻게 데이터를 요청할지 예시를 봐보자

**예시 URL :**
```
https://open.neis.go.kr/hub/mealServiceDietInfo?KEY=인증키&Type=json&pIndex=1&pSize=100&ATPT_OFCDC_SC_CODE=B10&SD_SCHUL_CODE=7010569&MLSV_YMD=20240101
```
이 URL 을 사용하면 2024년 1월 1일에 대한 서울특별시 교육청 소속 특정 학교(학교 코드: 7010569)의 급식 데이터를 JSON 형식으로 받을 수 있다.

## 5. API 명세서를 바탕으로 코드 작성하기
이제 이 명세서를 해석해 실제 코드에서 어떻게 사용할지 봐보자. JS 의 `fetch` 를 사용하여 API 요청을 보내고, 받은 데이터를 출력하는 예제이다.

```js
// API 호출을 위한 함수
const API_KEY = 'e2e38e8c19fa49f8b9050101d8d386a7'; // 발급받은 인증키
const ATPT_OFCDC_SC_CODE = 'B10';  // 서울특별시 교육청 코드
const SD_SCHUL_CODE = '7010569';   // 특정 학교 코드
const MLSV_YMD = '20240101';       // 급식 조회 날짜 (2024년 1월 1일)

const url = `https://open.neis.go.kr/hub/mealServiceDietInfo?KEY=${API_KEY}&Type=json&pIndex=1&pSize=100&ATPT_OFCDC_SC_CODE=${ATPT_OFCDC_SC_CODE}&SD_SCHUL_CODE=${SD_SCHUL_CODE}&MLSV_YMD=${MLSV_YMD}`;

fetch(url)
  .then(response => response.json())  // JSON 응답 받기
  .then(data => {
    // 급식 데이터를 처리하는 로직
    if (data.mealServiceDietInfo) {
      const meals = data.mealServiceDietInfo[1].row;
      meals.forEach(meal => {
        console.log(`급식 날짜: ${meal.MLSV_YMD}`);
        console.log(`메뉴: ${meal.DDISH_NM}`);
        console.log(`칼로리 정보: ${meal.CAL_INFO}`);
        console.log(`영양 정보: ${meal.NTR_INFO}`);
        console.log('---------------------------');
      });
    } else {
      console.log('급식 정보가 없습니다.');
    }
  })
  .catch(error => console.error('Error:', error));

```

## 6. API 호출 흐름 정리
1. **API 엔드포인트** 에 필요한 파라미터를 추가하여 URL 을 구성한다.
2. `fetch()` 또는 다른 HTTP 클라이언트를 사용하여 API 를 호출한다.
3. 응답 데이터를 JSON 또는 XML 로 받아와 처리한다.
4. 필요한 정보를 추출하여 화면에 표시하거나 로직을 처리한다.

## 요약:
1. **API 엔드포인트**는 고정된 URL 에 필수 및 선택 인자를 덧붙여서 구성한다.
2. **필수 인자**는 반드시 입력해야하는 값들이며, 선택 인자는 필요에 따라 추가로 설정할 수 있는 값들이다.
3. **응답값**은 API 요청에 성공하면 서버에서 보내주는 데이터이며, 급식 메뉴나 날짜 같은 정보를 포함한다.