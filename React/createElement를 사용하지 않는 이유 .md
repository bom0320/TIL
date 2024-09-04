createElement 를 사용하지 않는 이유
==

Title
---
### JavaScript
```js
const h3 = React.createElement (
    "h3",
    {
        id: "title",
        onMouseEnter : () => console.log("mouse enter"),
    },
    "Hello I'm a title"
);
```

### JSX
```jsx
const Title = (
    <h3 id="title" onMouseEnter={() => console.log("mouse enter")}>
    Hello I'm a title
    </h3>
)
```

이거 두개 완전히 똑같은 코드임! => JSX 는 일반적ㅇ니 HTML이랑 거의 똑같이 생김 

button
---

```js
const btn = React.createElement(
    "button",
    {
        onClick: () => console.log("Im Clicked"),
        style : {
            backgroundColor: "tomato",
        },
    },
    "Click me"
);
```

```jsx
const Button = (
<button style={{
    backgroundColor : "tomato",
}} onClick={() => console.log("Im Clicked")}
>
    Click me
    </button>
);
```
이 button 코드를 봤을때도 보다시피 개발자들이 봤을 때, 어떤 내용의 코드인지 한눈에 들어온다. => HTML 코드랑 굉장히 비슷하기 때문

**이래서 사람들이 createElement 를 사용하지 않는 것!!!!**
->    