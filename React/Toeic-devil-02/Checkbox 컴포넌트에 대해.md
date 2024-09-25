WordCheckbox 컴포넌트에 관해
===
나는 토익 웹페이질 만들어보면서 이런 의문점이 생겼다.
> 왜 이 작은 체크박스를 위해 이렇게 WordCheckbox.jsx 라는 컴포넌트를 따로 분리해서 긴 코드를 작성하는 걸까?
>
> 그냥 `<input type="checkbox" ... >` 이런식으로 적어도 되지 않나? 왜 굳이 컴포넌트까지 나눠서 관리를 하는거지?

**WordCheckbox code**
```jsx
import axios from "axios";
import React from "react";

const WordCheckbox = ({ isDone, setIsDone, word }) => {
  
  const handleWordIsDone = async () => {
    try {
      setIsDone((prev) => !prev);
      await axios.patch(`http://localhost:3001/words/${word.id}`, {
        isDone: !isDone,
      });
    } catch (e) {
      setIsDone((prev) => !prev);
      alert(e);
    }
  };

  return <input type="checkbox" checked={isDone} onChange={handleWordIsDone} />;
};

export default WordCheckbox;
 
```
그냥 솔직히 말해서 왜 이렇게 길게 코드를 쓰는건지 이해가 안됐다.

챗 gpt 가 말해준거에 따르면 이 체크박스 컴포넌트는 단순한 UI 요소 그 이상으로 **데이터 관리와 서버 통신**을 포함하고 있어서 길어졌다고 한다. 

다음과 같은 이유로 세부적인 코드가 필요하다.

### 1. 상태 관리
`isDone` 이라는 상태 값을 사용해 체크박스가 체크되었는지 여부를 관리한다. 

이 값은 부모 컴포넌트에서 전달된다.

### 2. 서버와의 동기화
체크 박스를 클릭하면 `axios.patch` 를 통해 서버에 변경 사항을 보내어 데이터베이스에서  여부 (isDone) 가 업데이트 된다.

### 3. 에러 처리
서버 요청이 실패했을 경우 원래 상태로 되돌려 사용자가 혼란스럽지 않도록 처리한다.

## 4. UI 와 상태 동기화
클릭 시 UI 와 서버의 상태가 일치하게 보이도록 비동기 로직을 처리해준다. 

이 모든 과정이 합쳐져 코드가 길어졌지만, 이는 단순히 `<input type="checkbox" />` 로(적어도 당장은 문제가 없겠지만..) 단순히 데이터를 처리하는 것 보다 이 코드는 **UI 와 데이터의 일관성**을 유지하고 **서버와 클라이언트 간의 상태를 동기화**하기 위한 필수적인 작업이다.