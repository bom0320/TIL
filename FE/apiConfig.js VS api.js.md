apiConfig.js 와 api.js 의 차이
===
`apiConfig.js` 와 `api.js` 는 둘 다 API 와 관련된 코드를 관리하지만, **역할이 다르다.**  각각 어떤 **책임**과 **용도**를 가지는지 명확히 정리해보자

## apiConfig.js : API 설정 및 엔드포인트 관리
`apiConfig.js` 는 **API 관련 설정**과 **경로(엔드포인트)**를 **정리**하는 파일이다.

### 주요 역할

#### 🔥 Base URL 설정
- API 서버 주소를 관리한다.

#### 🔥 엔드포인트(경로) 정리
- API 요청에 필요한 URL의 경로를 한눈에 보기 좋게 모아둔다. 
- URL 이 변경되면 이 파일만 수정하면 된다.

### 예시 코드: `apiConfig.js`

```js
// src/api/apiConfig.js

// 서버 주소 설정 (배포 URL)
export const BASE_URL = 'https://your-backend.com';

// 엔드포인트 목록
export const ENDPOINTS = {
  LOGIN: '/auth/google',
  SESSION: '/auth/session',
  LOGOUT: '/auth/logout',
  MISSIONS: '/missions',
  PROFILE: '/profile',
};
```

### 핵심 포인트
- 이 파일은 **API 주소 (Base URL + 엔드포인트)**를 **하드코딩하지 않고 정리**하는 데 목적이 있다.
- **중앙 집중화된 설정**으로 유지보수가 쉬워진다.

## api.js : API 호출 로직 관리
`api.js` 는 실제로 **API를 호출하는 함수들**을 작성하는 파일이다. 즉, **fetch** 나 **Axios** 를 사용해서 API 요청을 보내는 로직을 포함한다.

### 주요 역할

#### 1. API 호출 함수화
- API 요청 로직을 함수로 만들어 재사용한다.
- 중복되는 로직(`fetch`, 에러 처리 등)을 없애고 깔끔하게 관리한다.

#### 2. 엔드포인트 사용
- `apiConfig.js` 에서 정의한 **Base URL** 과 **엔드포인트**를 가져와서 사용한다.

#### 3. 추가 로직 관리
- 에러 처리, 요청 옵션 설정, 데이터 변환 등을 이 파일에서 담당한다.

### 예시 코드: `api.js`

```js
// src/api/api.js
import { BASE_URL, ENDPOINTS } from './apiConfig';

// 세션 상태 확인 함수
export const checkSession = async () => {
  try {
    const response = await fetch(`${BASE_URL}${ENDPOINTS.SESSION}`, {
      method: 'GET',
      credentials: 'include', // 세션 쿠키 포함
    });
    return response.ok; // 성공 여부 반환
  } catch (error) {
    console.error('세션 확인 오류:', error);
    return false;
  }
};

// 로그아웃 함수
export const logout = async () => {
  try {
    const response = await fetch(`${BASE_URL}${ENDPOINTS.LOGOUT}`, {
      method: 'POST',
      credentials: 'include',
    });
    return response.ok;
  } catch (error) {
    console.error('로그아웃 오류:', error);
    return false;
  }
};

```

## **결론: 차이점 요약**

| **구분** | **apiConfig.js** | **api.js** |
| --- | --- | --- |
| **목적** | API 서버 주소와 엔드포인트를 관리 | API 호출 로직을 함수로 만들어 관리 |
| **역할** | Base URL과 경로 설정 (환경 변수처럼 사용) | API 요청(fetch/Axios), 에러 처리, 옵션 설정 |
| **책임** | **경로 정의**와 **설정 관리** | **실제 API 호출** 및 **로직 관리** |
| **예시** | `BASE_URL`과 `ENDPOINTS`만 작성 | `checkSession()`, `logout()` 함수 구현 |
---

## 왜 둘로 나눠야 할까?

### 1. 분리된 책임
- `apiConfig.js` : API의 경로와 설정을 정리 (데이터)
- `api.js` : API 호출 로직을 관리 (로직)

### 2. 유지보수 쉬움
- 엔드포인트가 변경되면 `apiConfig.js` 만 수정하면 된다.
- 로직이나 에러 처리를 변경하면 `api.js` 만 수정하면 된다.

### 3. 코드 가독성 향상
- 컴포넌트 코드에서 `checkSession()` 처럼 깔끔하게 함수를 호출하면 돼서 이해하기 쉽다.