파라미터(Parameter)란?
===

파라미터(Paramter) 는 프로그래밍에서 함수, 메서드, 또는 URL 등 다양한 컨텍스트에서 사용되는 용어로 주로 다음과 같은 의미를 가진다.

## 함수나 메서드에서의 파라미터

**함수나 메서드를 호출할 때 전달되는 값이나 인수를 의미**한다. 

파라미터는 함수가 수행하는 작업에 필요한 데이터를 제공하는 역할을 한다.

**EX) Javascript 함수 파라미터**

```jsx
function greet(name) = {
	console.log("Helo, " + name + "!");
}

greet("Alice") // "Hello, Alice!" 출력
```

여기서  name 이 파라미터이다. 

greet 함수를 호출할 때 Alice  라는 값을 전달한다.

## URL 에서의 파라미터

웹 개발에서 URL 파라미터는 URL 에 포함된 데이터로, 

서버가 추가 정보를 전달하기 위해 사용된다. URL 파라미터는 주로 **쿼리 파라미터**와 **경로 파라미터**로 나눌 수 있다. 

### 1. 쿼리 파라미터

쿼리 문자열로 URL 의 끝에 **‘?’** 로 시작하여 **key=value**  형태로 추가된다. 여러 개의 쿼리 파라미터는 & 로 구분된다.

쿼리 파라미터는 웹 애플리케이션 및 API 에서 URL 을 통해 특정 데이터를 전달하거나, 필터링할 때 사용된다. 

**EX) 쿼리 파라미터**

```
https://example.com/search?query=javascript&sort=desc
```

여기서 `query=javascript` 와 `sort=desc` 가 쿼리 파라미터

### 2. 경로 파라미터

URL 경로의 일부로 포함되어 특정 리소스나 데이터를 식별하는데 사용된다.

**EX) 경로 파라미터**

```
https://example.com/users/123
```

여기서 ‘123’ 은 ‘users’ 이라는 리소스의 경로 파라미터이다. 

React Router 에서는 이를 쉽게 추출하기 위해 useParams 훅을 사용한다.

## React Router 에서의 파라미터

React Router 에서는 URL 의 경로 파라미터를 사용하여 동적 경로를 정의하고, 특정 컴포넌트로 전달할 수 있다.

**EX) React Router 경로 파라미터**

```jsx
import React from "react";
import { BrowserRouter as Router, Route, Switch, useParams } from "react-router-dom";

const UserDetail = () => {
  // useParams 훅을 사용하여 URL 파라미터를 가져옵니다.
  const { userId } = useParams();

  return <div>User ID: {userId}</div>;
};

const App = () => {
  return (
    <Router>
      <Switch>
        <Route path="/users/:userId" component={UserDetail} />
      </Switch>
    </Router>
  );
};

export default App;

```

이 예제에서 `/users/:userID` 경로는 `:userId` 라는 경로 파라미터를 사용한다.

`UserDetail` 컴포넌트에서 useParams 훅을 사용하여 userID 파라미터를 추출할 수 있다.

### 요약

- **파라미터(Parameter) :** 함수나 메서드에 전달되는 값, 또는 URL 에 포함된 데이터를 의미한다.
- **함수 파라미터:** 함수가 필요로 하는 입력값
- **URL 파라미터:** 서버에 추가 정보를 전달하기 위해 URL 에 포함된 값, 쿼리 파라미터와 경로 파라미터로 나눌 수 있다.
- **React Router 파라미터**: 동적 경로를 정의하고, 컴포넌트에서 useParams 훅을 사용하여 URL 경로의 파라미터를 추출할 수 있다.