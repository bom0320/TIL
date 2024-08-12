import React, { useState } from "react";

const App = () => {
  const [value, setValue] = useState(""); // value 는 현재 입력된 할일 텍스트를 저장
  const [todoList, setTodoList] = useState([]); // todoList 는 모든 할일 항목을 저장하는 배열

  const onClick = () => {
    setTodoList((prev) => [
      // setTodoList 는 현재 상태 값(prev)을 기반으로 새로운 상태 값을 계산하여 업데이트
      // 여기서 계산한다는 것은 현재 상태값을 기반으로 새로운 상태값을 생성하는 로직을 수행하는것을 말함
      // 로직 1. : 현재 상태값을 복사(...prev)
      // 로직 2. : 새로운 요소를 추가( {id: Data.now(), text:value} )
      // 새로운 상태값 반환: 이러한 계산 결과로 생성된 새로운 배열을 반환하여 상테를 업데이트 한다.
      ...prev,
      // 스프레드 연산자 : 배열의 모든 요소를 새로운 배열에 복사
      {
        id: Date.now(),
        text: value,
      },
      // 새로운 할 일 항목은 현재 시간을 고유 식별자로 사용하고, 입력된 값을 텍스트로 설정
    ]);
    setValue("");
    // 입력 필드를 비움
  };

  const onDelete = (id) =>
    setTodoList((prev) => prev.filter((todo) => todo.id !== id));
/*
  1. const onDelte 는 id 를 매개변수로 받는함수 (이 id 는 삭제하려는 할일 항목의 고유 식별자)
  2. setTodoList 는 useState 훅에서 제공된 업데이트 함수(이 함수는 새로운 상태값을 설정)
  3. setTodoList 는 함수를 매개변수로 받음 -> 이 함수는 이전값을 인자로 받음

  (prev) => prev.filter((todo) => todo.id !== id)
  4. 이 부분은 이전값 상태인 prev(할 일 목록 배열)를 매개변수로 받아 필터링하는 함수임
  5. prev.filter(...) 는 prev 배열의 각 요소를 검사하여 조건에 맞는 요소만 포함된 새로운 배열을 반환

  (todo) => todo.id !== id
  6. filter 함수의 내부 함수로 todo 라는 매개변수를 받음
  7. todo는 prev 배열의 각 요소를 나타내며, 각 요소는 할일 항목 객체이다.
  8. todo.id !== id 는 각 todo 객체의 id가 외부에서 전달된 id 와 다른지 검사한다.
  9. 다르면 true 를 반환해서 필터링 후 배열에 포함시키고, 같으면 false 를 반환하여 배열에서 제외한다.
*/  
  return (
    <div>
      <input
        type="text"
        // type="text" : 텍스트의 입력 필드를 의미
        value={value}
        // value={value} : 입력 필드의 현재값을 상태 변수 value 로 설정
        onChange={(e) => setValue(e.target.value)}
        // onchange 는 이벤트 헨들러 함수 -> 이벤트 객체 e 를 매개변수로 받음 
        // e 는 이벤트에 대한 정보를 담고 있는 객체로, 입력 필드의 현재 값 등에 접근할 수 있다. 

        // e.target 은 이벤트가 발생한 요소(여기서는 <input> 요소)를 가리킴
        // e.target.value 는 입력 필드의 현재값 나타냄

        // setValue(e.target.value)
        // setValue 는 useState 훅으로부터 제공받은 상태 업데이트 함수이다.
        // setValue 는 새로운 상태값을 인자로 받아 value 상태를 업데이트한다.

        /*
          onChange={(e) => setValue(e.target.value)}는 입력 필드의 값이 변경될 때마다 상태를 업데이트하여 입력 값을 React 상태로 관리합니다.
          이벤트 객체 e를 통해 입력 필드의 현재 값을 얻고, 이를 상태 업데이트 함수 setValue에 전달하여 상태를 변경합니다.
          상태가 변경되면 컴포넌트가 다시 렌더링되어 UI에 변경된 상태 값이 반영됩니다.
        */
      />
      <button onClick={onClick}>제출</button>
      {todoList.map((todo) => (
        <div key={todo.id}>
          <span>{todo.text}</span>
          <div onClick={() => onDelete(todo.id)}>삭제</div>
        </div>
      ))}
    </div>
  );
};

// key={todo.id} : todo.id 를 사용하여 각 할일 항목을 고유하게 식별
export default App;
