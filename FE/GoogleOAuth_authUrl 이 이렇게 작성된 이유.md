GoogleOAuth_authUrl 이 이렇게 작성된 이유
===

```jsx
const authUrl = `https://accounts.google.com/o/oauth2/v2/auth` +
  `?client_id=YOUR_GOOGLE_CLIENT_ID` +
  `&redirect_uri=${encodeURIComponent(REDIRECT_URI)}` +
  `&response_type=token` +
  `&scope=profile%20email`;
```
GoogleOAuth 기능을 구현하던 중, 코드 authURL 이 왜 이렇게 작성되었는지 알아보았다. 

## 1. 문자열 템플릿 문법이란?
- **문자열 템플릿**은 JS 에서 문자열을 더 쉽게 만들기 위해 사용하는 문법이다.
- 백틱 ( ` )  기호를 사용하고, **변수를 ${}** 안에 넣어 사용할 수 있다.

#### 예시:
```js
const name = "봄";
const greeting = `안녕하세요, ${name}님!`;
console.log(greeting); // 출력: 안녕하세요, 봄님!
```

### 문자열 템플릿 문법 적용
`authUrl` 에서 이 문법을 사용한 이유는 **긴 URL 을 변수와 결합해서 가독성 있게 작성**하기 위해서이다.

## 2. Google OAuth URL 은 왜 이렇게 작성되는가?
📌 Google OAuth 2.0 을 통해 로그인을 구현하려면 **Google 이 제공하는 엔드포인트**로 요청을 보내야한다.

### 기본 URL 과 파라미터

**`https://accounts.google.com/o/oauth2/v2/auth`**
이 URL 은 **Google 로그인**을 시작하는 오픈 엔드포인트이다. 

뒤에 **쿼리 파라미터**를 추가해서 Google 에게 "내가 요청하는 조건"을 전달한다.

## 3. 쿼리 파라미터 설명

### ① client_id (고유 아이디)
- `client_id` 는 **Google API Console**에서 발급받은 앱의 고유한 ID 이다.
- Google 에 "나는 이 앱이다"라고 인증하기 위해 사용된다.

#### 어디서 받을까?
- [Google Cloud Console](https://cloud.google.com/cloud-console/?utm_source=google&utm_medium=cpc&utm_campaign=japac-KR-all-ko-dr-BKWS-all-mv-trial-PHR-dr-1605216&utm_content=text-ad-none-none-DEV_c-CRE_631263160246-ADGP_Hybrid+%7C+BKWS+-+BRO+%7C+Txt+-Management+Tools-Cloud+Console-google+cloud+console-main-KWID_43700081105743302-kwd-296393718382&userloc_1009856-network_g&utm_term=KW_google%20cloud%20console&gad_source=1&gclid=CjwKCAiA34S7BhAtEiwACZzv4VSdm2zcc6AL0vBPb6yzVu47BGm_16PCe1JIrrTvZMYzefYoya_wsRoCRHcQAvD_BwE&gclsrc=aw.ds) 에서 프로젝트를 생성하고 OAuth 클라이언트를 설정하면 `client_id` 를 발급받는다.

### ② redirect_uri (리다이렉트 URI)
- `redirect_uri` 는 **로그인이 끝난 후 Google 이 사용자를 되돌려 보낼 주소**이다.

- **⚠️ 직접 지정해야 한다.**
    - Google API 설정에서 **리다이렉트 URL** 을 허용된 주소로 등록해야한다.

- **리다이렉트 URL 의 역할**
    - Google 이 로그인 성공 후 **토큰이나 인증 코드**를 이 주소로 전달한다.

- **예시**
    - `https://auth.expo.io/@username/your-app`
    - Expo 환경에서는 `AuthSession.makeRedirectUri`가 자동으로 프룩시 서버용 리다이렉트 URL 를 생성한다.


### ③ response_type=token
- `response_type` 은 **Google 이 어떤 응답을 반환할지**를 지정한다.
- **token :** 엑세스 토큰을 즉시 반환 (Implicit Flow)
- **Code :** 인증 코드를 반환해 백엔드에서 토큰을 교환하도록 사용 (Authorization Code Flow)
    - 일반적으로 `code` 를 사용하는 게 더 보안이 좋다.

### ④ scope=profile%20email
- `scope` 는 앱이 어떤 정보를 요청할지 명시하는 부분이다. 
- Google 에 요청할 권한을 나열한다. 
    - profile: 사용자 이름, 프로필 사진 등
    - email: 사용자 이메일 주소
- 여러 권한을 나열할 때는 **공백 대신 `%20`** 으로 연결한다.

## 4. 최종적으로 authUrl 동작 흐름
1. 앱이 `authUrl` 로 Google 로그인 페이지를 열어준다.
2. 사용자가 로그인하면 Google 은 **redirect_uri** 로 결과를 전달한다.
3. 이때 `response_type = token` 이라면 **액세스 토큰**이 리다이렉트 URL 에 포함된다.
4. 앱은 리다이렉트 URL 를 확인해 **액세스 토큰**을 받아오고, 이를 서버나 백엔드에 전달한다.

## 5. 백엔드와 협업이 필요한 이유
- **백엔드**는 클라이언트 앱에서 받은 **토큰을 검증**하고,
- 사용자의 정보를 **데이터베이스에 저장**하거나,
- **세션**을 생성해 로그인 상태를 유지하는 역할을 한다.

### 협업해야 할 내용

1. 백엔드에서 Google OAuth 를 처리하는 **엔드포인트**를 만들어야 함
    - 예시 : `POST/ auth/google`
2. 클라이언트가 받아온 토큰을 백엔드에 전달하면,
    - 백엔드가 Google 에 요청해서 토큰이 유효한지 확인한다.
3. 세션이나 JWT 를 생성해 사용자의 로그인 상태를 유지한다.

## **정리**

1. **문자열 템플릿**: 백틱 `` 를 사용해 변수와 문자열을 결합하는 문법.
2. **Google 로그인 URL**: Google이 제공하는 엔드포인트에 쿼리 파라미터로 조건을 전달함.
3. **client_id**: Google API에서 발급받은 앱의 고유 ID (직접 설정).
4. **redirect_uri**: 로그인이 끝난 후 돌아올 주소 (직접 지정).
5. **백엔드 협업**: 토큰 검증과 세션 유지 기능을 백엔드에서 구현해야 함.