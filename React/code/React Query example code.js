import logo from "./logo.svg";
import "./App.css";
import { useEffect, useState } from "react";
import axios from "axios";

function App() {
  const [isOpen, setIsOpen] = useState(false)
  const { data: users, isPending, error, isError } = useQuery({
    queryKey: ["users"],
    queryFn: () => axios.get("https://jsonplaceholder.typicode.com/users"),
  });

  const { mutate: submit, error, isError, isLoading } = useMutation({
    mutationKey: ['users', 'create'],
    mutationFn: () => axios.post('https://jsonplaceholder.typicode.com/posts', {
      userId :11,
      id:101,
      body:'test body',
      title:'test title'
    }),
    onSuccess: () => {
    },
    onError: () => {}
  })

  const { mutate: deleteUser } = useMutation({
    mutationKey: ['users', 'delete'],
    mutationFn: () => axios.delete('https://jsonplaceholder.typicode.com/posts')
  })
  

  return (
    <div className="App">
      {users.map((v) => v.name)}
      <button onClick={onClick}>제출</button>
      <button onClick={onDelete}>삭제</button>
    </div>
  );
}

export default App;
