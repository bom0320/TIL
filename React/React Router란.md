React Router란?
===

## 1. 왜 React Router 인가?
현재 리액트 공부를 하고 있는데 그중에서도 a태그를 쓰지 않고 많은 개발자ㅣ들이 React Router 을 왜 쓸까 라는 의문도 있었다.

## 2. React Router 란?
React Router 를 알기 위해서는 Routing 의 개념을 알 필요가 있는데

 **Routing이란 간단하게 말하면 사용자가 요청한 URL 에 따라 해당 URL 에 맞는 페이지를 보여주는 것** 이라고 생각할 수 있다.

 이렇게 Routing 관련 라이브러리가 많이 있고 그중에서도 사람들이 가장 많이 쓰는 라이브러리가 React Router 이다. 


그럼 이런 질문이 생길 수가 있다.

> "ㅇㅋ 알겠어 사람들 많이 쓰는거 근데 그래서 왜 REACT ROUTER를 써야되지?"

이 질문에는 이렇게 답해주면 된다.

> "a태그만 써도 페이지 이동이 가능하고 다른 라이브러리도 있지만, a 태그는 화면을 새로고침 한 다음에 페이지를 이동한다는 단점이 있어.
>
> 하지만 React Router에서는 새로운 페이지를 로드하지 않고 하나의 페이지 안에서 필요한 데이터만 가져오는 형태를 가지기 때문에 불필요한 렌더링을 막을 수 있다~"

## 3. 그래서 React Router 어떻게 쓰는데

**1) 설치 npm install react-router-dom**
**2) add yarn add react-router-dom**

우선 `react-router-dom` 을 npm 을 통해 설치해주고, 사용하고자하는 곳에 add react-router-dom 을 해주면 됨.

**3) 실사용**
```js
<BrowserRouter>
          <Routes>
            <Route
              path="/"
              element={<Login authService={authService}></Login>}
            ></Route>
            <Route
              path="/maker"
              element={<Maker authService={authService}></Maker>}
            ></Route>
          </Routes>
        </BrowserRouter>
```
우선 Router 를 위한 파일을 새로 만들어서 BrowserRouter 안에 Routes 안에 Route로 도메인을 설정 가능한데 도메인은 위에 코드처럼 `path="도메인"` 처럼 작성해주고 element 에 본인이 윈하는 페이지를 넣어주면 된다.

React Router 에서 페이지를 이동을 할때는 두가지 방법이 있고, 그중 `LINK` 를 통해서 하는 방법과 `useNavigate` 를 사용하는 방법이있다.

### 3-1 . Link 를 통한 페이지 이동
```js
<Link to="/mainChoice">
   <MenuRecommendBtn type="button">메뉴 추천받기</MenuRecommendBtn>
</Link>
```
이전 테오의 스프린트때 사용했던 방법을 긁어온 것인데 위와 같은 방법으로 Link 하면 아마 자동으로 `react-router-dom` 에서 import 될 것인데 안되면 직접 import 해준 뒤 `to="본인이 이동하고자하는 도메인"` 으로 해주면 된다. 

처음에 이렇게만 해주면 그래서 이동은 어떻게 하지? onclick 과 같은 이벤트가 있어야하는 것 아닌가? 라는 생각을 했었는데 Link 를 쓰면 자동으로 클릭시 이동하는 개념이고 이는 **A태그와 유사**하다고 보면 된다.

그럼 클릭 시 페이지 이동 말고 어떤 로직에서 페이지 이동은 어떻게 해야하냐? 라는 질문은 아래에서 해결 가능하다.

### 3-2. useNavigate 를 통한 페이지이동
우선 이번 드림코딩 강의에서 Firebase를 이용한 로그인 이후 페이지가 넘어가는 상황에서 useNavigate 를 사용했다.

`const navigator = useNavigate();` 로 useNavigate로 선언해주고 본인이 원하는 로직에서 이제 `navigator("이동하고자 하는 도메인 = 위에서 path 로 설정했던 도메인")` 로 작성하면 그 로직이 잘 실행되면 navigator() 안에 받은 인자의 페이지로 이동한다. 

## 4. React Router 쓰고난 후기
솔직히 처음으로 Routing 을 위해 사용한 라이브러리가 React Router 라서 다른 Routing 라이브러리와 비교는 힘들지만, 앞에서 설명했던 

> **새로운 페이지를 로드하지 않고 하나의 페이지 안에서 데이터를 가져오는 형태를 가지기 때문에 불필요한 렌더링을 막을 수 있다.**

라는 개념에서 React스러운 라이브러리라는 생각이 들었다.