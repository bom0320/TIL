import React, { useState } from 'react'
import * as S from './style'

const Header = () => {
    const [value,setValue] = useState<string>("");
    const [todoList,setTodoList] = useState<{ id: number, text: string }[]>([]);

    const onClick = () => {
        setTodoList((prev)=>[
            ...prev,
            {
                id:Date.now(),
                text:value,
            },
        ])
        setValue("");
    }

    const onDelete = (id: number) => {
        setTodoList((prev)=>prev.filter((todo) => todo.id !== id))
    }

  return (
   <div>
    <input
    type='text'
    value={value}
    onChange={(e) => setValue(e.target.value)} 
    />
    <button onClick={onClick}>제출</button>
    {todoList.map((todo)=>(
        <div key={todo.id}>
            <span>{todo.text}</span>
            <div onClick={()=>onDelete(todo.id)}>삭제</div>
        </div>
    ))}
   </div>
  )
}

export default Header
