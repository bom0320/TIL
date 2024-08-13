React-router-dom 이란?
===
react-router-dom 은 React 애플리케이션에서 라우팅을 구현하기 위해 사용하는 라이브러리이다.  

**라우팅이란?** 사용자가 브라우저의 URL 을 통해 애플리케이션의 서로 다른 페이지나 뷰로 이동할 수 있도록 하는 기능이다. 

## 주요 기능과 구성 요소

### 1. BrowserRouter

- 애플리케이션을 감싸는 최상위 라우터 컴포넌트
- HTML5 의 History API 를 사용하여 URL 관리
- 브라우저의 주소 표시줄에 직접 URL 을 입력하거나 뒤로/ 앞으로 가기 버튼을 사용할 때도 적절한 컴포넌트를 랜더링하도록 한다.

### 2. Routes 및 Route

- Routes 는 여러 개의 Route 를 포함하여 URL 경로에 따라 다른 컴포넌트를 랜더링 할 수 있도록 하는 컴포넌트
- 각 Route 는 특정 경로 (path 속성) 와 해당 경로에서 랜더링될 컴포넌트(element 속성)를 지정한다.

### 3. URL 매개 변수와 경로

- 경로에 동적 매개변수를 포함할 수 있도록 한다
- 예를 들어, ‘/day/:day 와 같은 경로는 /day/1 , /day/2 등의 URL 에 대해 day 라는 매개변수를 컴포넌트해서 사용할 수 있게 한다.


### 사용 예

- react-router-dom 을 사용하면 SPA(Single Page Application) 에서 다수의 페이지처럼 보이는 경험을 제공할 수 있다.
- 사용자가 다른 URL 을 방문할 때마다 전체 페이지를 다시 로드하지 않고,클라이언트 측에서 해당 URL 에 맞는 컴포넌트만 새로 랜더링한다.

### 설치 방법

- react-router-dom 을 사용하려면 먼저 프로젝트에 설치해야한다. 터미널에서 다음같은 명령어를 사용한다.

```bash
npm install react-router-dom
```

또는 Yarn 을 사용하는 경우

```bash
yarn add react-router-dom
```

이렇게 설치한 후, 애플리케이션에서 라우팅을 설정하여 다양한 URL 에 대응하는 컴포넌트를 정의할 수 있다. React-router-dom 은 React 애플리케이션에서 중요한 역할을 하며, 사용자 경험을 향상시키는 데 도움을 준다.