React의 State 와 setState 비동기 처리 원리
===

### State 라는 것

간단하게 말해 state 는 변수다. 그렇다면 const, let, var 가 있는데 왜 **state** 라는 변수를 사용할까?

State 는 일반 변수와 다르게 **값이 변하면 렌더링**이 일어난다.

State 는 props 와 같이 컴포넌트 렌더링에 영향을 주는 객체, 컴포넌트 안에서 관리된다.

## setState?

setState 는 state를 변경할 때 사용하는 함수다. setState 가 쓰일 때 컴포넌트의 state 객체에 대한 업데이트를 실행한다. state 가 변경되면, 컴포넌트가 리랜더링 된다.

## setState 의 동작

setState 는 **비동기**적으로 동작한다.

**ex) setState 실행**

```jsx
const Index = () => {
	const [state,setState] = useState(0);
	
	const onClick = () => {
		setState(state + 1);
		console.log(state);
	};
	
	return (
		<div>
			<p>현재 값 {state}</p>
			<button onClick={onClick}>+1</button>
		</div>
	);
};
```

여기서 console 의 값을 살펴보고 왜 그런지 생각해보기

### setState를 동기적으로 사용하기

우리는 함수 컴포넌트를 사용하기 때문에 useEffect 를 사용하면 된다.

```jsx
const Index = () => {
	const [state, setState] = useState(0);
	
	const onClick = () => {
		setState(state + 1);
	};
	
	useEffect(() => {
		console.log(state);
	},[state])
	
	return (
		<div>
			<p>현재 값 {state}</p>
			<button onClick={onClick}>+1</button>
		</div>
	);
};

export default Index;
```

## 왜 비동기로 작동하는가

state는 값이 변경되면 리렌더링이 발생한다. 그런데 변경되는 state 가 많을 경우 리렌더링이 계속 일어날테고 속도가 저하될 것이다.

따라서 Reat 는 성능을 위하여 변경된 값들을 모아 한번에 업데이트를 진행하여 렌더링을 줄이고자 배치(Batch) 기능을 사용해 비동기로 작동한다고 볼 수 있다. 배치 업데이트는 16ms 주기

**ex) 연속적으로  setState 호출했을 때**

```jsx
const Index = () => {
	const [state,setState] = useState(0);
	
	const onClick = () => {
		setState(state + 1);
		setState(state + 1);
		setState(state + 1);
		console.log(state);
	};
	return (
		<IndexContainer>
			<p>현재 값 {state}</p>
			<button onClick={onClick}>+1</button>
	)
}
```

위 예시 코드에서 버튼을 클릭할 때마다 +3씩 증가해 출력되기를 원하고 만들었지만 +1씩 증가하는 것을 볼 수 있다. 그 이유가 바로 **React 에서 배치 업데이트를 하기 때문**이다.

## Updater 함수

**setState** 함수는 새로운 **state** 객체를 인자로 받을 수 있지만, 이전 **state** 값을 기준으로 계산해야한다면, 객체 대신 **updater** 함수를 전달하면 된다.

> **updater 함수란?**
state 와 props 를 인자로 받는 state 를 변화시키는 함수.
`(state, props) ⇒ 변경할 상태 값` 에서 state 와 props 는 최신상태로 보장한다.
> 

```jsx
const Index = () => {
	const [state,setState] = useState(0);
	
	const onClick = () => {
		setState((state) => state + 1);
		setState((state) => state + 1);
		setState((state) => state + 1);
		console.log(state);
	};
	return (
		<IndexContainer>
			<p>현재 값 {state}</p>
			<button onClick={onClick}>+1</button>
	)
}
```

updater 함수를 전달하면 updater 함수 안에서 이전 state 값에 접근하게 된다.

setState 호출은 일괄적으로 처리되어서 여러 업데이트 사항이 충돌 없이 차례대로 반영하게 한다.

## 요약

> **왜 state를 직접 변경하지 않고, useState를 사용해야 하나요?**
> 
> 
> state는 컴포넌트 렌더링에 영향을 주는 데이터를 갖고 있는 객체인데, 이것을 업데이트 하기위해서는 setState, useState가 필요하다. 직접 state를 수정하면 리액트는 render 함수를 호출하지 않아서 렌더링이 일어나지 않고 setState를 호출하여 state를 변경하면 리액트 엔진이 render 함수를 이용해서 렌더링을 실행하기 때문이다.
> 

> **왜 React는 상태 값을 비동기적으로 처리하게 만들었을까?**
> 
> 
> React의 setState 등이 비동기적으로 작동하는 이유는 일정 시간 동안 변화하는 상태를 모아 한 번에 랜더링 하기 위해서이다.
> 
> 결국, 웹 페이지 불필요한 렌더링 횟수를 줄여 좀 더 빠른 속도로 동작하게 만들기 위해서이다.
> 

> **왜 React는 리렌더링 대신 즉시 state를 업데이트하지 않는지?**
> 
> 
> props와 state 사이의 일괄성을 해칠 수 있으며 이것은 디버깅하기 힘든 이슈가 생길 수 있기 때문이다.
>