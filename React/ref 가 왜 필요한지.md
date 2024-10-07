ref가 왜 필요한지
===
`ref` 는 **가상 DOM 을 거치지 않고, 직접 실제 DOM 에 접근**하는 기능을 제공한다. 그래서 `ref` 를 사용하면 가상 DOM 의 변경 과정을 기다리지 않고 **바로 실제 DOM 에 접근하고 변경 사항을 반영**할 수 있다. 이를 통해 특정 DOM 요소에 대한 직접적인 조작이 가능해지고, 즉각적으로 페이지에 반영될 수 있다.

```jsx
import React, { useRef } from 'react';

function TextInputWithFocusButton() {
  const inputEl = useRef(null);  // ref를 생성

  const onButtonClick = () => {
    inputEl.current.focus();  // 가상 DOM을 거치지 않고, 실제 DOM의 input 요소에 직접 접근
  };

  return (
    <>
      <input ref={inputEl} type="text" />
      <button onClick={onButtonClick}>Focus the input</button>
    </>
  );
}
```
이 예시에서 `inputE1.current.focus()` 는 **가상 DOM**을 거치지 않고 **실제 DOM** 의 `input` 요소에 바로 접근해 포커스를 준다. 그래서 사용자가 즉시 그 변화를 느낄 수 있다.

## 결론
- `ref` 는 **최신 DOM** 요소를 가리키고, 그 요소에 직접 접근하여 **즉시** 변경을 반영한다.
- 이로 인해 **가상 DOM 의 업데이트를 기다리지 않고,** 사용자는 **바로 웹페이지에서 그 변화를 확인**할 수 있다.

