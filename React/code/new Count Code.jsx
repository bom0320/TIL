// 부모 컴포넌트
const Parent = () => {
    const [count, setCount] = useState(0);  // 상태는 부모 컴포넌트에서 관리
  
    // 상태를 변경하는 함수(콜백)를 자식 컴포넌트에 전달
    return <Child count={count} increment={() => setCount(count + 1)} />;
  };
  
  // 자식 컴포넌트
  const Child = ({ count, increment }) => {
    return (
      <div>
        <p>현재 카운트: {count}</p>
        <button onClick={increment}>카운트 증가</button>
      </div>
    );
  };
