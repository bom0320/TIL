useRef 를 사용하는 이유
===

#### CreateWordPage
```jsx
import axios from "axios";
import React, { useRef, useState } from "react";
import { useNavigate } from "react-router-dom";
import { DayInput, EngInput, KorInput } from "../components";
import WordSubmitButton from "../components/CreateWordForm/WordSubmitButton";

const CreateWordPage = () => {
  const [isLoading, setIsLoading] = useState(false);
  const navigate = useNavigate();

  const engRef = useRef();
  const korRef = useRef();
  const dayRef = useRef();

  const createWord = async (e) => {
    e.preventDefault();
    try {
      setIsLoading(true);
      const newWord = {
        day: dayRef.current.value,
        eng: engRef.current.value,
        kor: korRef.current.value,
        isDone: false,
      };

      await axios.post("http://localhost:3001/words", {
        ...newWord,
      });
      navigate(`/day/${dayRef.current.value}`);
    } catch (e) {
      alert(e);
    } finally {
      setIsLoading(false);
    }
  };

  return (
    <form onSubmit={createWord}>
      <EngInput engRef={engRef} />
      <KorInput korRef={korRef} />
      <DayInput dayRef={dayRef} />
      <WordSubmitButton isLoading={isLoading} />
    </form>
  );
};

export default CreateWordPage;

```

결론부터 말하자면 이 코드는 **사용자가 입력한 값을 가져와서** 각각의 `day`, `eng`, `kor` 에 넣어주기 위해 `useRef` 를 사용하는 것이다.

## 왜 `useRef` 를 사용하는지 설명하자면:

### 1. 입력 필드에서 값을 가져오는 방법:
- React 에서 입력 값을 가져올 때는 보통 두 가지 방법을 사용한다.
    - `useState`로 상태를 관리해서 실시간으로 값을 업데이트 하는 방법
    - `useRef` 로 DOM 요소에 직접 접근해서 값을 가져오는 방법

### 2. 이 코드에서 `useRef` 의 역할:
- `engRef.current.value` , `korFef.current.value`, `dayRef.current.value` 는 각각의 입력창에 사용자가 입력한 값을 가리킨다.
- 이렇게 `useRef` 를 사용하면 **React 상태 관리 없이** DOM 요소의 값을 바로 가져올 수 있다.
- 여기서 `useRef` 는 단순히 **각 입력창에 연결된 값**을 읽어오는 역할을 한다.

## 예시로 더 쉽게 설명하자면:
만약 사용자가 각각의 입력 필드에 다음과 같이 입력했다고 가정해보자.
- `영어 단어 입력 필드` : **apple**
- `한국어 뜻 입력 필드` : **사과**
- `day 입력 필드` : **1**

이 때, **사용자가 입력한 값을** 가져오기 위해 `useRef` 를 사용한 부분이 코드에서 이렇게 동작한다.

```js
const newWord = {
  day: dayRef.current.value,  // day 입력창의 값 (예: 1)
  eng: engRef.current.value,  // 영어 단어 입력창의 값 (예: apple)
  kor: korRef.current.value,  // 한국어 뜻 입력창의 값 (예: 사과)
  isDone: false,
};
```
- `dayRef.current.value`: 사용자가 입력한 day 값 (예를 들어 1)을 가져옵니다.
- `engRef.current.value`: 사용자가 입력한 영어 단어 값 (apple)을 가져옵니다.
- `korRef.current.value`: 사용자가 입력한 한국어 뜻 값 (사과)을 가져옵니다.

이 값을 모두 **새로운 단어 객체**(`newWord`)에 넣어주는 것이다.

## 그럼 왜 `useRef` 를 사용할까?

#### 1. 간단한 코드 작성
입력 필드에서 값을 가져오는 간단한 방법이 필요할 때, `useState` 없이 `useRef` 를 사용해서 쉽게 값을 가져올 수 있다.

#### 2. 값을 직접 참조
`useRef` 는 **입력값을 바로 참조**할 수 있기 때문에, 상태 관리를 위한 추가적인 코드 없이도 값을 처리할 수 있다.

#### 3. 상태 업데이트 불필요
사용자가 입력하는 동안 실시간으로 상태가 업데이트될 필요가 없는 경우, `useState` 대신 `useRef` 를 사용해도 된다.

## `useState` 와 `useRef` 의 차이:
- `useState` : 사용자가 입력할 때마다 상태가 실시간으로 업데이트 되며, 상태가 변하면 컴포넌트가 다시 렌더링된다.
- `useRef` : 사용자가 입력한 값은 **화면에 다시 렌더링하지 않고도** 나중에 버튼이 클릭 시 또는 폼 제출 시 값을 참조할 수 있다.

### 결론:
이 코드에서 `useRef`**는 사용자가 입력한 값을 직접 가져와서** 나중에 `axios` **를 통해 서버로 보낼 때** 사용하기 위해 사용된 것이다. 

입력 필드에서 사용자의 입력 값을 쉽게 가져오기 위한 도구라고 생각하면 된다.