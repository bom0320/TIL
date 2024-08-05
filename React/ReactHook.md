React Hook 이란?
===

> **목차**
> 
- React Hook 의 등장배경
- React Hook 이란?
- 대표적인 React Hook

## 1. React Hook 의 등장 배경

### React Component 종류

리액트 컴포넌트는 함수형 컴포넌트(Functional Component) 와 클래스형 컴포넌트(Class Component) 로 나뉜다.

> 리액트 초기에는 일반적으로 함수형 컴포넌트(Function Component) 를 사용하였으나, **값의 상태를 관리(state) 혹은 Lice Cycle Method(생명 주기=컴포넌트가 생성되고 사라지는 과정이 존재할 때)를 사용해여야 할 때만 클래스형 컴포넌트(Class Component) 를 사용**하였다.
> 

함수형 컴포넌트(Function Component) 가 사용된 이유는 아래와 같은 **클래스형 컴포넌트(Class Component) 의 대표적인 단점**때문이였다.

1. 코드의 구성이 어렵고 Component 의 재사용성이 떨어진다.
2. 컴파일 단계에서 코드 최적화를 어렵게 한다.
3. 최신 기술의 적용이 효과적이지 않다.

이러한 클래스형 컴포넌트(Class Component) 의 **단점을 보완**하여, 함수형 컴포넌트(Functional Component) 를 사용 할 수 있또록 등장한 것이 바로 **React Hook(리액트 훅)**이다. 

## 2. React Hook 이란?

### React Hook(리액트 훅)의 정의

- React Hook 이란, 리액트 v16.8 에 새로 도입된 기능으로, **함수형 컴포넌트(Functional Component)** 에서 **사용되는 몇가지 기술들**을 일컫는다.
- 리액트 훅은 **함수형 컴포넌트(Functional Component) 가 클래스형 컴포넌트(Class Component)의 기능을 사용할 수 있도록** 해주며 대표적인 예로는 **useState, useEffect** 등이 존재한다.

### React Hooke(리액트 훅) 의 규칙

1. 리액트 Hook 은 반복문, 조건문 혹은 중첩된 함수 내에서 호출하면 안되며 **반드시 최상위(at the Top Level)에서만 Hook 을 호출**해야한다.  또한 Hook 은 랜더링 시 항상 동일한 순서로 호출 되어야 한다. 
2. Hook 은 React 함수 내에서만 호출 해야 한다. 죽, 리액트 Hook 은 함수형 컴포넌트(Functional Component) 에서 호출해야하며, 추가적으로 custom hooks 에서 또한 호출이 가능하다.

## 3. 대표적인 React Hook

### 1. useState

- 개념: 함수형 컴포넌트에서 상태를 관리하기 위한 Hook

사용 예씨)

```jsx
const [count, setCount] = useState(0);
```

### 2. useEffect

- 개념:  컴포넌트가 랜더링(화면에 표시)될 때마다 특정 작업을 실행할 수 있게 한다. →  컴포넌트가 화면에 나타날 때, 업데이터될 때, 사라질 때 실행할 코드를 지정할 수 있음

구문)

```jsx
useEffect(() => {
  // 여기에 실행할 코드를 작성 

  return () => {
    // (선택사항) 컴포넌트가 사라질 때 실행할 코드
  };
}, [의존성 배열]); // 배열에 있는 값이 변경될때마다 useEffext 가 실행 
									// -> 빈 배열[] 을 넣으면 컴포넌트가 처음 랜더링 될때만 실행
```