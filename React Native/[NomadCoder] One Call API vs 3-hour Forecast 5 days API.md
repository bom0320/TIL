강의에서 사용한 API: One Call API  VS 내가 사용한 API: 3-hour Forecast 5 days API
===
노마드 코더 강의를 보면서 React Native 를 공부하던 도중, 강의에서 나오는 API 는 유료라는 걸 알게되었다. 그리고, OpenWeather 사이트에서 무료 버전을 쓰고 싶은 경우 날씨와 관련해서 사용할 수 있는 API 는 2개라고 한다. 
1. **Current Weather**
2. **3-hour Forecast 5 days**

(* 구독별 사용 가능 API 확인 : https://openweathermap.
org/price )

두 API의 차이는 유료와 무료 외에도 **데이터 제공 방식**과 **사용 목적**에서 차이가 크다. 각각의 API 가 어떤 용도에 적합한지 알아보자.


## 1. 사용된 API 비교

### 강의에서 사용한 API : `One Call API`

#### 특징
- 이 API 는 다양한 시간 시간 단위의 데이터를 제공한다. - 일일(`daily`), 시간별(`hourly`), 현재(`current`) 날씨 정보를 한 번의 API 호출로 가져올 수 있어 편리하다.

#### 용도
- 하루 단위(`daily`) 데이터가 필요할 때 적합하다.
- 예를 들어, 일주일 간의 날씨 예보를 보여줄 때 `daily` 데이터를 그대로 사용하면 된다.

### 내가 사용한 API : `3-hour Forecast 5 days API`

#### 특징
이 API 는 **5일 동안 3시간 간격**의 예보 데이터를 제공한다. 
- 즉, 하루에 총 8개의 데이터가 있는 셈

#### 용도
- 특정 시간대에 맞춘 날씨 데이터가 필요할 때 적합하다. 
- 5일 간의 날씨 예보를 3시간 단위로 보여주는 데 유용하지만, 하루 단위 데이터를 직접 사용할 수 없다.
- 하루 단위 데이터가 필요한 경우, 특정 시간대(예: 자정) 의 데이터만 필터링 해서 사용하는 방식이 필요하다.

## 2. **차이점 요약**

| API | 데이터 제공 방식 | 용도 | 유료/무료 |
| --- | --- | --- | --- |
| **One Call API** | 현재, 시간별, 하루 단위 데이터 | 종합적인 날씨 정보 제공 (하루 단위 등) | 유료 |
| **3-hour Forecast API** | 5일 동안 3시간 간격 데이터 | 짧은 간격의 예보 제공 (3시간 단위) | 무료 |


## 3. 차이점 설명

### 데이터 제공 방식
- **One Call API** 는 여러 시간 단위의 데이터를 한 번에 제공해서, `daily` 데이터로 하루 단위의 온도, 날씨 설명 등을 쉽게 접근할 수 있다.
- **3-hour Forecast API** 는 3시간 간격의 데이터를 제공하므로, 하루 단위 데이터로 만들려면 특정 시간대의 데이터만 선택하는 추가 작업이 필요하다.

### 사용 목적
- **One Call API** 는 하루 단위 예보를 간편하게 보여주고 싶을 때 유용하다.
    - 예를 들어, 일주일치 날씨를 한 눈에 보여주고 싶을 때 `daily` 데이터를 바로 사용할 수 있다.

- **3-hour Forecast API** 는 시간대별로 세밀한 날씨 변화를  볼 때 적합하다.
    - 예를 들어, 하루 동안 시간별 온도 변화를 보여주거나 특정 시간대의 예보를 보고 싶을 때 유용하다.


만약 하루 단위의 데이터가 필요하다면, `One Call API` 가 더 간편하겠지만, 무료로 사용하고 싶다면, `3-hour Forecast API` 로 필요한 시간대의 데이터를 필터링하는 방식으로 충분히 대처할 수 있다.