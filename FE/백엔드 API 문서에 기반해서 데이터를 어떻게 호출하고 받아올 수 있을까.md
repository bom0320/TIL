백엔드 API 문서에 기반해서 데이터를 어떻게 호출하고 받아올 수 있을까?
===

협업을 하다보면 아래와 비슷한 형식으로 backend 개발자에게서 API 명세서를 제공받을 수 있다.


![](https://private-user-images.githubusercontent.com/167315197/396775161-4cdd3441-ab56-4cf2-a321-a03a7f0fd300.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzQ1MDEwMTUsIm5iZiI6MTczNDUwMDcxNSwicGF0aCI6Ii8xNjczMTUxOTcvMzk2Nzc1MTYxLTRjZGQzNDQxLWFiNTYtNGNmMi1hMzIxLWEwM2E3ZjBmZDMwMC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMjE4JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTIxOFQwNTQ1MTVaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hZWVmNDlkMzA5OGIyMjBmZGNjODEzOTJiOWQ2ZTM1MmZlODYwMDY5ZjM3NTQxYThjODg3NGUzMDZmNjM0NDBiJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.7WgWt8vEyropuaXn1Gs51-gbLuo4PcEznxiMnWl1CF4)

여기서 예를들어, Backend 개발자가 제공한 Base URL 이 아래와 같다고 가정해보자

```arduino
https://port-0-server-lz1cq56f81af005d.sel4.cloudtype.app/
```

## 왜 이렇게 하는가?
프론트엔드는 백엔드에서 데이터를 받아와 사용자에게 표시하는 역하을 한다.
- **`GET` 메서드 :** 서버에서 데이터를 **읽어올 때** 사용된다. 이 경우 사용자의 프로필 정보와 레벨 정보를 읽어온다.
- 백엔드와 통신할 때, **Base URL + Endpoint** 를 결합해서 요청을 보내면, 서버는 필요한 데이터를 JSON 형태로 반환한다.
- 이를 프론트엔드에서 **axios** 나 **fetch API** 를 통해 받아 화면에 표시하거나 활용한다.

## API 호출 예제
## **API 호출 예제**

### **a. axios를 사용한 방법**

`axios`는 API 호출을 쉽게 해주는 자바스크립트 라이브러리 이다.

1. **axios 설치** (이미 설치했다면 건너뛰기)

```bash
npm install axios
```

1. **API 호출 코드**

```jsx

import axios from 'axios';

const baseURL = 'https://port-0-server-lz1cq56f81af005d.sel4.cloudtype.app/profile';

// 1. 사용자 My페이지 정보 가져오기
const fetchUserProfile = async (user_id) => {
  try {
    const response = await axios.get(`${baseURL}/${user_id}`);
    console.log('My페이지 데이터:', response.data);
    // 화면에 데이터 렌더링하는 코드 추가 가능
  } catch (error) {
    console.error('My페이지 호출 에러:', error);
  }
};

// 2. 사용자 레벨 정보 가져오기
const fetchUserLevel = async (user_id) => {
  try {
    const response = await axios.get(`${baseURL}/${user_id}/level`);
    console.log('레벨 데이터:', response.data);
    // 화면에 데이터 렌더링하는 코드 추가 가능
  } catch (error) {
    console.error('레벨 호출 에러:', error);
  }
};

// 사용 예시
const user_id = '12345';
fetchUserProfile(user_id);  // 사용자 프로필 데이터 호출
fetchUserLevel(user_id);    // 사용자 레벨 데이터 호출

```

---

### **b. Fetch API 사용**

**Fetch API**는 별도의 설치 없이 사용 가능한 네이티브 기능이다.

```jsx

const baseURL = 'https://port-0-server-lz1cq56f81af005d.sel4.cloudtype.app/profile';

// My페이지 정보 가져오기
const fetchUserProfile = async (user_id) => {
  try {
    const response = await fetch(`${baseURL}/${user_id}`);
    const data = await response.json();
    console.log('My페이지 데이터:', data);
  } catch (error) {
    console.error('My페이지 호출 에러:', error);
  }
};

// 레벨 정보 가져오기
const fetchUserLevel = async (user_id) => {
  try {
    const response = await fetch(`${baseURL}/${user_id}/level`);
    const data = await response.json();
    console.log('레벨 데이터:', data);
  } catch (error) {
    console.error('레벨 호출 에러:', error);
  }
};

// 사용 예시
const user_id = '12345';
fetchUserProfile(user_id);
fetchUserLevel(user_id);

```

---

## **5. 호출 결과 예시**

서버는 주로 JSON 형태의 데이터를 반환한다.

예시 응답:

**`/profile/{user_id}`** 호출 결과:

```json
{
  "user_id": "12345",
  "name": "홍길동",
  "age": 25,
  "email": "hong@example.com"
}

```

**`/profile/{user_id}/level`** 호출 결과:

```json

{
  "user_id": "12345",
  "level": 5,
  "progress": "75%"
}

```

## 정리
1. **API 사용 목적 :** 백엔드 데이터를 가져와 화면에 표시하기 위해
2. **사용 방법 :** `axios` 나 `fetch` 를 사용하여 Base URL 과 엔드포인트를 통해 요청을 보낸다.
3. **왜 GET 메서드를 사용하나?**
    - 서버에서 **데이터를 읽어오기** 위해 사용되기 때문
4. **응답 처리 :** 서버에서 반환된 JSON 데이터를 활용해 사용자 화면에 표시하거나 다른 로직에 사용용