DOM 요소에 접근한다는 것이란?
===
 
> **DOM 이란?**
>
> DOM은 웹 페이지 구조를 표현하는 객체 모델이다. 웹페이지는 HTML 로 작성되지만, 브라우저는 HTML 을 읽고 트리 구조의 객체로 변환하여 DOM 을 만든다. 이 DOM 을 통해 자바스크립트 코드가 HTML 요소(태그들) 에 접근하고, 그 요소들을 조작할 수 있디.

## DOM 요소에 접근한다는 것
- **DOM 요소에 접근한다는 것** 은 자바스크립트를 사용해 HTML 요소들을 제어하거나 정보를 가져올 수 있다는 뜻이다. 예를 들어, 웹 페이지에 있는 `<button>` , `<input>` , `<div>` 같은 요소들을 자바스크립트를 통해 직접 **참조**하거나 **조작**할 수 있게 되는 것이다.

## DOM 요소 접근의 예시

#### 1. 자바스크립트의 `document.getElementById()` 를 사용하여 특정 요소를 가져오는 방법:

```html
<input id="myInput" type="text" />
<button onclick="focusInput()">Focus Input</button>

<script>
  function focusInput() {
    const inputElement = document.getElementById('myInput');
    inputElement.focus(); // 입력칸에 포커스를 줌
  }
</script>
```
여기서 `document.getElementById('myInput')` 로 `id="myInput"` 을 가진 **input 요소를 가져와서** 그 요소에 **포커스를 주는 것**이 DOM 에 접근하는 한 가지 예이다.

## React 에서의 DOM 접근:
React 에서는 직접적으로 `document.getElementById()` 같은 메소드를 사용하지 않고, `useRef` 를 통해 **DOM 요소에 접근**할 수 있다. 이렇게 하면 React 에서 렌더링된 요소에 접근하거나 조작할 수 있다.

예를 들어, React 에서 특정 입력 필드에 포커스를 주려면 다음과 같이 `useRef` 를 사용할 수 있다.

## React 에서 `useRef` 를 사용하여 DOM 에 접근하는 예시:
```jsx
import React, { useRef } from 'react';

function FocusInput() {
  const inputRef = useRef(null);  // input 요소를 참조할 ref 생성

  const handleClick = () => {
    inputRef.current.focus();  // input 요소에 포커스 주기
  };

  return (
    <div>
      <input ref={inputRef} type="text" />  {/* input 요소를 ref로 연결 */}
      <button onClick={handleClick}>Click to Focus Input</button>
    </div>
  );
}
```

### 동작 설명:
1. `useRef(null):` useRef는 DOM 요소를 참조할 수 있는 변수를 만든다. 이 변수는 inputRef로, 아직 아무 값도 들어있지 않음(null)
2. `<input ref={inputRef} />`: 이 줄은 HTML의 `<input>` 요소를 inputRef와 연결해 준다. 이제 inputRef가 그 입력 필드를 가리키게 된다.
3. `inputRef.current.focus()`: 버튼을 클릭하면 inputRef.current는 `<input>` 요소를 가리키고 있으므로, 이 코드로 그 요소에 포커스를 준다. 즉, 사용자가 입력칸을 클릭하지 않아도 자동으로 입력칸에 커서가 깜빡이게 되는 것

### 정리하자면:
- DOM 요소에 접근한다는 것은 자바스크립트나 React 에서 특정 HTML 요소를 제어하거나 정보를 얻기 위해 직접 참조하는 것이다.
- `useRef` 는 React 에서 이런 DOM 요소에 접근할 수 있도록 도와주는 도구이다.
- 이를 통해 HTML 요소에 대한 조작(포커스 주기, 값 가져오기, 스크롤 위치 제어 등)을 할 수 있다.

쉽게 말해, 브라우저가 화면에 렌더링한 HTML 요소를 자바스크립트 코드로 직접 **참조해서** 무언가 **작업을 할 수 있는 것** 이 바로 DOM 요소에 접근하는 것이다.