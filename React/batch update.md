Batch Update
===

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

이 상황에서 **‘ setState(state + 1) ‘** 가 세 번 호출되었음에도 불구하고 **‘ state ‘** 가 **+3** 이 아닌 **+1** 로 업데이트되는 이유는 React의 상태 **업데이트 메커니즘**과 **배치 업데이트(batch update)** 때문이다. 이를 좀 더 자세히 살펴봐보자

## 1. 상태 업데이트는 비동기로 처리

React 에서 **setState 함수는 비동기로 처리**된다. 즉, setState 를 호출할 때 바로 **상태가 업데이트 되지 않는다는 것!!!**

 React 는 성능을 최적화하기 위해 상태 업데이트 요청을 모아서 한 번에 처리하려고 한다.

## 2. 상태 업데이트의 배치 처리

배치 처리란 **여러 개의 setState 호출을 모아서 한 번에 처리하는 것을 의미**한다. 이때 React 는 각 setState 호출에서 전달된 **상태 값을 기준**으로 **업데이트를 수행한다.**

### 3. `state + 1` 의 의미

**setState(state +  1)**는 현재의 **state 값에 1을 더하겠다는 의미**이다. 

중요한 점은, 이 state 는 함수가 **처음 호출될 때의 상태를 기반!!!!**으로 한다. 코드에서는 state 가 0일 때, setState(state + 1) 가 세 번 호출된다. 

이때 state 는 0으로 고정된 상태로 사용된다.

### 4. 왜 +1만 되는가?

React는 이 세 번의 **setState** 호출을 모아서 배치 처리한다 이때 React 는 각 setState 호출을 독립적으로 처리하지 않고, 동일한 업데이트 요청으로 인식한다. 따라서 React가 배치 처리를 할 때, **setState( state + 1 )** 가 세 번 실행되지만, 모두 첫 번째 state 값(0) 을 기반으로 1을 더하게 된다.

결국 세 번의 호출 결과가 모두동일하게 ‘1’ 이 되고, 마지막 setState 의 결과가 적용되어 state 는 1로 업데이트된다.

## 5. 해결 방법

만약 이 코드를 통해 state 가 실제고 3 증가하기를 원한다면, setState 를 다음과 같이 함수형 업데이트 방식으로 작성할 수 있다.

```jsx
 const onClick = () => {
    setState(prevState => prevState + 1);
    setState(prevState => prevState + 1);
    setState(prevState => prevState + 1);
    console.log(state);
};
```

이렇게 하면 각 setState 호출에서 이전 상태(’ prevState ’) 가 업데이트된 상태를 반영하기 때문에, 최종적으로 state 가 3 증가하게 된다.

### 정리

React는 성능 최적화를 위해 상태를 배치 처리하고, 각 **setState** 호출에서 동일한 초기 상태 값을 참조하게 된다. 따라서 같은 상태 값을 참조하는 여러 setState 호출이 있더라도 최종 결과는 마지막 호출의 결과로 결정하게 된다.

근데 prevState 는 가독성 떨어지니 상황에 따라 Updater 함수 사용하는 등의 더 나은 방법을 선택해야 할 듯