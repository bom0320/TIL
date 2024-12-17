API 호출 깔끔하게 관리하기
===
아래 내용은 **API 호출 관리를 체계적으로 할 수 있는 개념**을 익히기위한 메모이다. 그리고 나중에 프로젝트가 커지더라도 바로 적용할 수 있다고 하니, 실무에 가까운 코드 관리 방법으로 공부하도록 하자


## 1. 왜 API 호출 관리를 따로 해야 할까?

### 🔥 코드 재사용
- 여러 컴포넌트에서 같은 API 요청을 반복적으로 작성

### 🔥 유지보수 용이
- **Base URL** 이나 **엔드포인트 경로**가 바뀌어도 한 곳만 수정하면 된다. 
- 에러 처리와 옵션 설정을 한 군데서 관리할 수 있다.

### 🔥가독성 향상
- 코드가 깔끔해지고 어디서든 쉽게 가져다 쓸 수 있다.

## 2. `📌 apiConfig.js` : Base URL 과 엔드포인트 관리
- `apiConfig.js` 는 **서버 주소(Base URL)** 와 API **경로(엔드포인트)**를 정리해 두는 파일이다. 

```js
// src/api/apiConfig.js

// 백엔드 서버 URL
export const BASE_URL = 'https://your-backend.com';

// 엔드포인트 목록
export const ENDPOINTS = {
  LOGIN: '/auth/google',
  SESSION: '/auth/session',
  LOGOUT: '/auth/logout',
  MISSIONS: '/missions',
};
```

## 3. `📌 api.js` : API 호출 함수 만들기
- `api.js` 는 API 호출 로직을 함수로 만들어 관리한다.

```js
// src/api/api.js
import { BASE_URL, ENDPOINTS } from './apiConfig';

// 세션 상태 확인 함수
export const checkSession = async () => {
  try {
    const response = await fetch(`${BASE_URL}${ENDPOINTS.SESSION}`, {
      method: 'GET',
      credentials: 'include',
    });

    return response.ok;
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

## 4. 컴포넌트에서 API 함수 사용하기
- 컴포넌트에서 `api.js` 파일에 있는 함수를 호출해서 사용한다.

```js
import React from 'react';
import { Alert } from 'react-native';
import { checkSession } from '../api/api';
import { BASE_URL, ENDPOINTS } from '../api/apiConfig';
import * as WebBrowser from 'expo-web-browser';

export default function GoogleLoginButton({ navigation }) {
  const handleGoogleLogin = async () => {
    try {
      const authUrl = `${BASE_URL}${ENDPOINTS.LOGIN}`;
      const result = await WebBrowser.openBrowserAsync(authUrl);

      if (result.type !== 'cancel') {
        console.log('Google 로그인 성공!');
        const isSessionValid = await checkSession();

        if (isSessionValid) {
          navigation.replace('Main');
        } else {
          Alert.alert('세션 확인 실패', '세션이 만료되었습니다.');
        }
      } else {
        Alert.alert('로그인 실패', '로그인이 취소되었습니다.');
      }
    } catch (error) {
      console.error('로그인 오류:', error);
      Alert.alert('로그인 실패', '다시 시도해주세요.');
    }
  };

  return <CommonGoogleButton onPress={handleGoogleLogin} text="Google로 로그인" />;
}

```

## 5. 정리
- **`📌 apiConfig.js` :** Base URL과 API 경로를 한 곳에 정리
- **`📌 api.js` :** API 호출 로직을 함수로 만들어 재사용

### 장점
- 코드가 깔끔하고 재사용 가능
- 수정이 필요할 때 한 파일만 바꾸면 돼서 유지보수가 쉽다.
