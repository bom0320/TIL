react 에서 navigate 사용하기 (useNavigate / Navigate)
===
🤙 **Link 는 특정 주소로 이동해주는 태그였다면, Navigate 는 특정 행동을 했을 때 해당 주소로 이동해줄 수 있게 만들어준다.**

---

## 1. useNavigate 쓰기
**useNavigate** 는 양식이 제출되거나 특정 event 가 발생할 때, url 을 조작할 수 있는 interface 를 제공한다.

```jsx
import { useNavigate } from 'react-router-dom';

function Func() {
    const navigate = useNavigate();
    
  const onClickImg = () => {
    navigate(`/comment/id/등등 내가 원하는 주소`);
  };

  return (
    <img src={...} alt={...} onClick={onClickImg} />
  );
}

export default Func;
```
이렇게 작성한다고 함. 이 코드에서는 url 이 **www.naver.com** 이었다면 이는 **www.naver.com/commend/id...** 으로 바뀌었을 것이다.

useNavigate 에는 두 가지 특징이 있다.

---

## (1) useNavigate 의 인자들

```
navigate("../success", {replace:true});
```
첫 번째 인자로는 주소를 받으며 두 번째 인자로 **{ replace, state }** 인수를 사용한다.

- **replace (true or false)**
**true**를 사용한다면, navigate 에 적힌 주소로 넘어간 후 뒤로가기를 하더라도 방금 페이지로 돌아오지 않는다. 이 때는 자신의 메인 페이지 ("/")로 돌아오게 된다. **false** 는 뒤로가기가 가능하며 이 것이 기본 값인 듯하다.

- **state (any)**
state 가 필요하다면 사용할 수 있다고 하지만.. 어떻게 쓰는지 잘 모르겠다.

---

## (2) useHistory 의 기능도 포함
useNavigate 는 react v6 에서 useHistory 가 변화한 것이다. 이 때 useHistory 에서 사용하던, window 의 history 를 이용한 navigate 기능도 할 수 있게 되었다.

```jsx
<>
  <button onClick={() => navigate(-2)}>
    Go 2 pages back
  </button>
  <button onClick={() => navigate(-1)}>
    Go back
  </button>
  <button onClick={() => navigate(1)}>
    Go forward
  </button>
  <button onClick={() => navigate(2)}>
    Go 2 pages forward
  </button>
</>
```
History 란 세션 기록(페이지 방문 기록)에 대한 접근 방법과 메서드를 제공하는 것이다. 또한 세션(session) 이란 웹 사이트의 여러 페이지에 걸쳐 사용되는 사용자 정보를 저장하는 방법을 의미한다.

간단하게 이걸로 뒤로가기 앞으로가기가 된다고 알고 있으면 된다.

## 2. Navigate 쓰기

`<Navigate>` 요소는 렌더링될 때 현재 위치를 변경한다. useNavigate 를 둘러싼 component wrapper 이며 props 와 동일한 모든 인수를 허용한다. 이 태그 역시, **to, replace, state** 를 모두 사용할 수 있다.

```jsx
import { Navigate } from 'react-router-dom';

function Func() {

    const onClickImg = () => {
    return <Navigate to="/login" />;
  }

  return (
  	<img src={...} alt={...} onClick={onClickImg} />
  );
}

export default Func
```
> Note: This API is mostly useful in React.Component subclasses that are not able to use hooks. In functional components, we recommend you use the `useNavigate` hook instead.
-참고 : 이 API는 대부분 후크를 사용할 수 없는 React.Component 하위 클래스에서 유용합니다. 기능적 구성 요소에서는 대신 `useNavigate` 후크를 사용하는 것이 좋습니다.-

라고 공식 홈페이지에서는 얘기한다. 하위 클래스를 위해서 유용하게 쓰이는 것이기 때문에 엥간해서는 useNavigate 를 쓰라고 하는 것 같다.