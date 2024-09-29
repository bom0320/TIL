React Hook 과 React Router
===
이들은 각각 다른 역할을 하는 React 기능이다. 차이를 간단히 설명 하자면:

## 1. React Hook:
- **목적 :** React 에서 상태(state) 나 생명주기 (lifecycle) 기능을 사용하기 위한 함수들이다. 주로 함수형 컴포넌트에서 상태 관리와 부수 효과 (side effects) 를 처리하는 데 사용된다.

- **주요 기능 :**
- `useState` : 컴포넌트의 상태를 관리한다.
- `useEffect` : 컴포넌트가 렌더링될 때나 상태가 변경될 때 부수 효과를 처리한다.
- `useContext` : 전역 상태 관리를 도와준다.

- **예시 :**
```js
=import React, { useState, useEffect } from 'react';

function Example() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    document.title = `You clicked ${count} times`;
  }, [count]);

  return (
    <div>
      <p>You clicked {count} times</p>
      <button onClick={() => setCount(count + 1)}>Click me</button>
    </div>
  );
}

```

## 2. React Router:
- **목적 :** SPA(Single Page Application)에서 URL 경로에 따라 컴포넌트를 렌더링할 수 있게 도와주는 라우팅 라이브러리이다. 여러 페이지로 구성된 웹 애플리케이션에서 페이지 간의 이동을 관리한다.
- **주요 기능 :**
- `BrowserRouter` : URL 변화를 감지하고 이에 맞는 컴포넌트를 렌더링한다.
- `Route` : 특정 경로에 맞는 컴포넌트를 매칭해 준다.
- `Link` : 페이지 이동을 위한 링크를 제공한다.
- `useNavigate` ,`useParams` : 라우팅 관련 정보를 가져오거나 제어하는 데 사용된다.

- **예시 :**
```js
import { BrowserRouter as Router, Route, Routes, Link } from 'react-router-dom';

function Home() {
  return <h2>Home</h2>;
}

function About() {
  return <h2>About</h2>;
}

function App() {
  return (
    <Router>
      <div>
        <nav>
          <Link to="/">Home</Link>
          <Link to="/about">About</Link>
        </nav>

        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
        </Routes>
      </div>
    </Router>
  );
}
```

## 주요 차이점:
- **React Hook :** 상태 관리와 컴포넌트 내부의 로직을 처리하는 함수들이다. 컴포넌트의 동작과 상태에 중점을 둔다.
- **React Router :** 페이지 이동과 URL 기반의 라우팅을 담당하는 라이브러리이다.애플리케이션의 네비게이션에 중점을 둔다.

둘은 서로 독립적이며, React 애플리케이션에서 함께 사용되어 다양한 기능을 제공한다.