React는 {}, JavaScript는 innerText와 innerHTML
===

✅ 1. React에서 값 넣는 방식
React에서는 {}(중괄호)를 사용해서 JS 변수를 HTML처럼 직접 넣을 수 있다.

```js
const text = "Hello, React!";
return <div id="current">{text}</div>;
```

- `{text}` → JSX 문법에서는 변수를 직접 HTML에 넣을 수 있음.
- **컴포넌트가 자동으로 렌더링되면서 값이 화면에 표시됨.**

---

### ✅ **2. JavaScript에서 값 넣는 방식**

순수 JS에서는 `{}` 문법이 없기 때문에, **JavaScript 코드로 직접 DOM을 조작해야 한다.**

```js
document.getElementById("current").innerText = "Hello, JavaScript!";

```

- **초기 HTML에는 값이 없고, JavaScript 실행 후 값이 들어감.**
- `innerText`가 `<div>` 내부의 내용을 변경한다.

---

### 🔥 **결론: `innerText`와 `innerHTML`이 React의 `{}` 역할을 한다!**

React에서는 `{}`를 사용하면 자동으로 값이 들어가지만,

JavaScript에서는 **`innerText`나 `innerHTML`로 값을 넣어줘야 한다.**

| 기술 | 값 넣는 방식 | 자동 업데이트? |
| --- | --- | --- |
| **React** | `<div>{text}</div>` | ✅ (상태 변경 시 자동 렌더링) |
| **JavaScript** | `document.getElementById("current").innerText = text;` | ❌ (직접 업데이트해야 함) |
---

### 📌 **이 코드에서 `<div id="current"></div>`가 비어있는 이유**

- **`innerText`와 `innerHTML`이 `<div>` 내부에 값을 넣어주는 역할을 하기 때문!**
- HTML에서 `<div id="current"></div>`처럼 비워둬도,JavaScript가 실행되면서 내용이 자동으로 들어간다.

💡 **React처럼 `{변수}`를 직접 쓸 수 없으니까, JavaScript에서는 `innerText`와 `innerHTML`을 사용해서 값이 들어가도록 한다!** 🚀