createRoot
===
- `createRoot` 는 React 18 부터 도입된 새로운 메서드로, React 애플리케이션을 브라우저의 특정 HTML 요소에 연결하는 역할을 한다.
- 즉, 우리가 만든 React 컴포넌트들을 실제 DOM 에 그릴 준비를 하는 과정이라고 생각하면 된다.

예를 들어, index.js 파일에서 아래와 같은 코드가 있을 때,
```js
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<App />);
```
이 코드를 보면:
1. `createRoot` 는 `document.getElementByte('root')` 로 찾은 HTML 요소(보통 `index.html` 에 있는 `<dic id="root">`) 를 React 가 사용할 수 있도록 '준비' 하는 역할을 한다.
2. 준비가 끝나면, `render` 메서드를 사용해서 우리가 만든 React 컴포넌트(여기서는 `<App/>`)를 실제로 그 `root` 라는 곳에 그려준다.


간단히 말해서, `createRoot`  는 React 앱을 시작할 때, 우리가 만든 컴포넌트들을 어디에 그릴지 브라우저에 알려주는 기능이다. `root` 는 HTML 요소를 가리키고, 그 안에 React 컴포넌트를 그리는것!!