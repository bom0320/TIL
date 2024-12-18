axios 를 사용해 엔드포인트 호출 VS app.js 를 사용하는 것
===
각 페이지에서 바로 `axios` 를 사용해서 엔드포인트를 호출하는 것과, **`app.js`를 사용하는 것**의 차이점은 **코드의 재사용성**과 **관리 효율성**에 있다.

## 1. 페이지마다 엔드포인트를 직접 가져오는 경우
각 페이지에서 `axios` 를 사용해 직접 API 를 호출하는 방식이다.

### 예시: 페이지에서 직접 요청
```js
import axios from 'axios';

const MyPage = () => {
  const fetchMissions = async () => {
    try {
      const response = await axios.get('https://your-backend.com/missions');
      console.log('미션 데이터:', response.data);
    } catch (error) {
      console.error('데이터 가져오기 실패:', error);
    }
  };

  useEffect(() => {
    fetchMissions();
  }, []);
};
```

### ⚠️ 문제점

#### 1. 반복 코드
- 각 페이지에서 `axios` 요청 로직이 반복된다.
- 예: **에러 처리,** `widthCredentials` **옵션 설정**이 모두 중복됨

#### 2. 유지보수 어려움
- **Base URL** 이 바뀌서나 **공통 설정** (ex. `Authorization` 헤더 추가)이 필요하면 모든 페이지의 코드를 수정해야한다.
- 에러 처리 방식을 변경하고 싶어도 모든 페이지를 찾아서 수정해야한다.

#### 3. 가독성 저하
- 페이지마다 `axios` 요청 코드가 섞여 있어서 핵심 로직이 눈에 작 안 띈다.

## 2. app.js 를 사용하는 경우
`app.js` 는 **API 요청 로직** 을 **공통 함수로 만들어 관리**하는 파일이다. 이렇게 하면 각 페이지에서 함수만 호출하면 되니까 코드가 간결하고 중복을 줄일 수 있다.

### 개선된 구조

#### app.js (공통 API 함수)

```js
import axios from 'axios';
import { BASE_URL, ENDPOINTS } from './apiConfig';

// Axios 기본 설정
const apiClient = axios.create({
  baseURL: BASE_URL,
  withCredentials: true, // 세션 쿠키 자동 포함
});

// 공통 API 함수
export const fetchMissions = async () => {
  try {
    const response = await apiClient.get(ENDPOINTS.MISSIONS);
    return response.data;
  } catch (error) {
    console.error('미션 가져오기 실패:', error);
    throw error; // 에러를 페이지로 전달
  }
};

export const logout = async () => {
  try {
    const response = await apiClient.post(ENDPOINTS.LOGOUT);
    return response.status === 200;
  } catch (error) {
    console.error('로그아웃 실패:', error);
    return false;
  }
};
```

### 페이지에서 사용
이제 페이지에서 `app.js`  에 정의된 함수를 호출하기만 하면 된다.

```js
import React, { useEffect } from 'react';
import { fetchMissions } from '../api/api';

const MyPage = () => {
  const getMissions = async () => {
    try {
      const data = await fetchMissions();
      console.log('미션 데이터:', data);
    } catch (error) {
      console.error('API 요청 실패:', error);
    }
  };

  useEffect(() => {
    getMissions();
  }, []);

  return <div>미션 데이터를 불러오는 중...</div>;
};

export default MyPage;
```

## app.js 사용 시 장점

### 1. 코드 재사용성
- API 호출 로직을 한 곳(`app.js`) 에 작성해두면 모든 페이지에서 재사용할 수 있다.
- 똑같은 `axios` 코드와 에러 처리 코드를 반복해서 작성하지 않아도 된다.

### 2. 유지보수 용이
- **Base URL 변경**이나 **공통 옵션 추가** (예: 인증 헤더 추가)가 필요할 때 `app.js`만 수정하면 모든 페이지가 적용된다.

### 3. 가독성 향상
- 각 페이지는 `fetchMission()` 같은 함수만 호출하면 되기 때문에, 핵심 로직에 집중할 수 있다.
- API 호출 로직이 컴포넌트 코드와 분리되기 때문에 더 깔끔해진다.

### 4. 에러 처리 일관성
- `app.js`에서 에러 처리 방식을 통일할 수 있다.

## **정리: 차이점 요약**

| **구분** | **페이지에서 직접 호출** | **api.js 사용** |
| --- | --- | --- |
| **코드 재사용성** | 코드 중복이 많음 | 한 번만 작성하면 여러 페이지에서 재사용 가능 |
| **유지보수** | 수정 시 모든 페이지를 찾아야 함 | `api.js`만 수정하면 모든 페이지에 반영됨 |
| **가독성** | 요청 코드가 페이지 로직과 섞여서 복잡해짐 | 페이지에서는 함수만 호출하므로 코드가 깔끔 |
| **에러 처리** | 각 페이지마다 별도로 에러 처리를 작성해야 함 | 에러 처리를 통합해서 관리 가능 |

### 결론
`app.js` 를 사용하면 **반복되는 코드**를 없애고, **API 요청 로직을 일관되게 관리**할 수 있다.

페이지에서는 필요한 함수만 호출하면 되기 때문에 **코드가 간결하고 유지보수하기 쉬운 구조**가 된다.
