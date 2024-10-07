Functional Component vs Class Component
===

함수형 컴포넌트 (Functional Component)
- **React 에서 UI 를 그리는 함수**이다.
- props 라는 입력을 받아 JSX 로 화면을 그려준다.
- `useState`,`useEffect` 같은 **Hooks** 를 사용하여 상태나 사이드 이펙트를 처리할 수 있다.
- 코드가 간결하고, 더 최근의 React 방식에서 선호된다.

```jsx
function MyComponent(props) {
  return <h1>Hello, {props.name}</h1>;
}
```

## 클래스형 컴포넌트 (Class Component)
- **React 에서 상태와 생명주기를 관리하는 클래스로 작성된 컴포넌트**이다.
- 클래스에서 `render()` 메서드를 사용하여 JSX 를 반환한다.
- 상태는 `this.state` 로 관리하고, `this.setState()` 로 상태를 업데이트한다.
- Hooks 이전에 사용되던 방식으로, 지금은 덜 사용된다.

```jsx
class MyComponent extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}
```

## 간단한 차이

#### 함수형 컴포넌트
더 간단하고 요즘 더 많이 사용됨. 상태와 생명주기는 Hooks 로 처리

#### 클래스형 컴포넌트
과거에 많이 사용되던 방식. 상태와 생명주기는 클래스의 메서드로 처리


## 왜 클래스형 컴포넌트 사용도가 낮아졌는가?
1. React Hooks 는 함수형 컴포넌트에서 상태 관리와 생명주기 관리 같은 작업을 가능하게 해준다 -> 즉, **Hooks 가 클래스형 컴포넌트의 기능을 대체한것!**
2. Hooks 덕분에 함수형 컴포넌트가 클래스형 컴포넌트가 하던 일을 대신할 수 있게 되었고, 그 결과로 클래스형 컴포넌트의 사용 빈도가 크게 줄어듬!
3. 함수형 컴포넌트는 코드가 간결하고 직관적이기 때문에 최신 React 개발에서는 더 많이 사용된다.