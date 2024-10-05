React 는 선언적인 UI 라이브러리이다.
===
React 가 선언적인(declarative) UI 라이브러리라는 말은, **개발자가 "어떻게(How)" UI 를 구현하는지보다 "무엇(What)을 보여줄지"** 에 더 집중하게 만든다는 뜻이다. 이말이 좀 추상적일 수 있으니 구체적인 예로 알아보도록 하자

## 1. 선언적(Declarative) vs 명령적(Imperative)
- **명령적(Imperative) :** 프로그래머가 UI 를 만들때 "어떻게" 동작해야 하는지, 즉 **구체적인 단계나 절차를 일일이 지정**하는 방식이다.
- **선언적(Declarative) :** "결과(무엇)"를 정의하고, 그 결과에 따라 시스템이 내부적으로 그에 맞게 처리하는 방식이다.

## 2. 예시로 비교하기

### 명령적 방식: (Vanilla JavaScript)
```js
const element = document.createElement('div');
element.textContent = 'Hello, World!';
document.body.appendChild(element);
```
위 코드는 "무엇"을 보여주고 싶은지보다, **어떻게 DOM을 조작해서** UI를 반들어야 하는지를 일일이 명시하고 있다. 개발자가 직접 `document.createElement`, `textContent`,`appendChild` 등을 사용해 UI 요소를 만들고, DOM 에 추가한다.

### 선언적 방식: (React)
```jsx
function App() {
    return <div>Hello, Word!</div>;
}
```
이 코드에서는 "Hello, Word!" 라는 결과를 정의한다. UI 가 어떻게 DOM 에 추가되는지에 대해서는 React 가 알아서 처리해준다. 개발자는 **무엇을 그릴지**에만 집중하고, **어떻게 그려지는지** 는 신경 쓰지 않아도 된다.

## 3. React 의 선언적 업데이트 방식
React 는 선언적인 방식으로 **상태(state)** 가 변할 때 UI 를 자동으로 업데이트한다. 상태가 변경되면, React 는 해당 상태에 따라 UI 가 어떻게 보여야 할지 다시 계산하고, DOM 을 자동으로 갱신한다.

### ex:
```jsx
function App() {
  const [count, setCount] = React.useState(0);

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={() => setCount(count + 1)}>Increment</button>
    </div>
  );
}
```
위 코드에서 `count` 상태가 변할 때마다 `<p>` 태그에 표시된 값이 React 에 의해 자동으로 갱신된다. 개발자는 상태값만 변경하면, UI 는 그에 맞게 자동으로 업데이트되므로, DOM 을 직접적으로 다루는 코드를 작성할 필요가 없다.

## 5. 명령적 방식과 선언적 방식의 차이
- 명령적 방식은 **단계별로 정확하게 지시**해야 하므로 코드가 더 복잡해지고, 유지보수가 어려워질 수 있3ㅏ.
- 선언적 방식은 **결과만 정의**하면 React 가 상태 변화에 따라 UI 를 알아서 갱신하므로 코드가 간단하고 직관적이다.

**결론적으로, React 는 "어떻게(How)" 보다 "무엇(What)"에 집중하게 해주므로 선언적인 UI 라이브러리라고 불린다.**