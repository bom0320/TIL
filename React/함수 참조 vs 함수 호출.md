함수 참조(Function Reference) vs 함수 호출(Function Call)
===
React 에서 **이벤트 헨들러**로 함수가 어떻게 동작하는지를 제대로 이해하려면, 함수 참조와 함수 호출 간의 차이를 분명히 해야한다. 

## 1. 함수 참조 (Function Reference)
ex)
```js
const sayHello = () => {
  console.log("Hello!");
};

<button onClick={sayHello}>Click me</button>
```
- 여기서 `onClick = {sayHello}` 는 함수 참조이다.
- `sayHello` 함수는 **즉시 실행되지 않고,** 버튼이 **클릭될 때** React 가 이 함수를 호출한다.
- 즉, **함수를 넘겼다**고 생각하면 된다. 클릭할 때 실행되도록 넘기는 것이다.

## 2. 함수 호출 (Function Call)
함수 호출은 **함수를 즉시 실행**하는 것이다. 즉, 괄호 `()` 를 사용하여 그 자리에서 함수를 실행시킨다.

ex)
```js
const sayHello = () => {
  console.log("Hello!");
};

<button onClick={sayHello()}>Click me</button>
```
- 여기서 `onClick = {sayHello()}` 는 함수 호출이다.
- 이 코드는 **버튼이 클릭되기 전**에 이미 `sayHello` 함수가 실행되어 버린다. 즉, 페이지가 렌더링될 때 `sayHello()` 가 바로 실행되어 "Hello!" 가 콘솔에 찍히고, 버튼 클릭과는 상관없게 된다.
- 결과적으로, React 가 이벤트 핸들러로 **함수의 결과 값**을 받게 되므로, 클릭 시에는 아무 일이 일어나지 않는다.

## 차이 정리:

**함수 참조(Function Reference) :**
- 함수 이름만 넘기고, 클릭 시에 React 가 그 함수를 실행시킨다.
- 예시: `onClick = {sayHello}`

**함수 호출(Function Call) :**
- 함수에 괄호를 붙여서 넘기면, **즉시 실행**된다.
- 예시: `onClick = {sayHello()}` 는 렌더링 시에 바로 실행되고, 클릭 이벤트와 상관없이 이미 실행된다.

## 익명 함수와의 관계 :
익명 함수를 사용하는 이유는, **인수를 전달하거나 특정 실행 시점을 제어**하기 위함이다.

예를 들어
```js
<button onClick={() => sayHello()}>Click me</button>
```
- 여기서 `() => sayHello()` 는 **익명 함수**이다.
- 클릭할 때마다 **익명 함수가 실행**되고, 그 익명 함수 안에서 `sayHello()` 가 호출된다.
- 이렇게 하면, `sayHello()` 가 **즉시 실행되지 않고,** 클릭 시점에만 실행된다.

### 결론:
- **함수 참조 (`onClick = {sayHello}`) :** 클릭할 때만 실행되도록 넘기는 방식
- **함수 호출 (`onClick = {sayHello()}`) :** 렌더링 시점에서 실행되는 방식
- **익명 함수 (`onClick={() => sayHello()}`) :** 클릭 시 실행되도록 제어하는 방식