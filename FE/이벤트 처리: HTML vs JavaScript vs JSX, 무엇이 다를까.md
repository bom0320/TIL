이벤트 처리: HTML vs JavaScript vs JSX, 무엇이 다를까?
===


지금까지 이벤트 처리기는 HTML이 주도하여 JavaScript 함수를 호출하는 방식으로 사용되었다.

하지만, DOM을 활용하면 JavaScript가 주도하여 HTML 요소를 가져와 이벤트 처리기를 연결할 수 있다.

즉, **HTML과 JavaScript 중 어느 쪽을 중심으로 이벤트를 설정하는지에 따라 방식이 달라진다.**

또한, JSX의 `onClick` 문법은 HTML의 `onclick` 속성과 형태가 비슷하지만, 실제로는 JavaScript를 기반으로 동작하기 때문에 차이가 있다.

이번에는 `onclick`을 예로 들어 **HTML, JavaScript, JSX에서의 차이점과 관계**를 살펴보도록 하자.

---

# **1. HTML에서 onclick 사용** (HTML이 주인)

> **기본형**
`onclick = “  ”`
> 

```html
<button onclick="alert('클릭됨!')">클릭하세요</button>
```

✅ HTML 요소 자체에 `onclick` 속성을 추가하여 **이벤트 핸들러를 직접 정의**

✅ HTML 문서가 JavaScript를 호출하는 방식

⚠️ **단점:**

- HTML과 JavaScript가 섞여 있어 **유지보수가 어려움**
- JavaScript 코드를 추가하거나 수정할 때 **HTML을 직접 변경해야 함**
- 하나의 요소에 **여러 개의 이벤트를 추가하기 어려움**

---

# **2. JavaScript에서 onclick 사용** (JavaScript가 주인)

> **기본형**
`웹 요소.onclick = 함수`
> 

```html
<button id="btn">클릭하세요</button>

<script>
  document.getElementById("btn").onclick = function() {
    alert('클릭됨!');
  };
</script>

```

✅ HTML 요소를 JavaScript에서 선택한 후 `onclick`을 설정

✅ JavaScript가 HTML을 **제어하는 방식**

✅ HTML 코드가 깔끔해지고 유지보수 용이

⚠️ **단점:**

- `onclick = 함수` 방식은 **이전 이벤트가 덮어쓰기됨**
- **여러 개의 이벤트 핸들러를 추가할 수 없음**
- 이 문제를 해결하기 위해 `addEventListener` 사용이 등장

## 2-1. J**avaScript에서 `addEventListener()` 사용** (최신 방식)

```html
<button id="btn">클릭하세요</button>

<script>
  const btn = document.getElementById("btn");

  btn.addEventListener("click", function() {
    alert("첫 번째 이벤트!");
  });

  btn.addEventListener("click", function() {
    alert("두 번째 이벤트!");
  });
</script>

```

✅ `addEventListener()`를 사용하면 **여러 개의 이벤트를 추가할 수 있음**

✅ JavaScript가 HTML을 **완전히 제어하면서도 유지보수가 쉬움**

✅ **최신 웹 개발에서 가장 많이 사용되는 방식**

📌 **이 방식의 장점:**

- 여러 개의 이벤트 핸들러를 추가할 수 있음
- JavaScript 코드가 분리되어 유지보수성이 높음

---

# 3. JSX (React)에서 onclick 사용

> **기본형
`onClick = {}`**
> 

```jsx
function App() {
  function handleClick() {
    alert('클릭됨!');
  }

  return (
    <button onClick={handleClick}>클릭하세요</button>
  );
}

```

✅ JSX에서는 `onClick="..."` 대신 **`onClick={함수}`** 사용

✅ React는 **가상 DOM을 사용하므로, `addEventListener()` 없이도 자동으로 이벤트를 바인딩**

✅ `handleClick` 함수만 변경하면 여러 곳에서 **재사용 가능**

📌 **JSX의 특징:**

- JSX는 **JavaScript 문법을 그대로 사용**하므로, 이벤트 핸들러도 **JavaScript 함수로 정의됨**
- 이벤트 속성은 **문자열이 아니라 `{}` 안에 함수로 넣어야 함**
- **`addEventListener()` 없이도 이벤트가 자동으로 관리됨**

---

## **📌 최종 정리: HTML, JavaScript, JSX의 `onClick` 차이점**

| 방식 | 코드 예제 | 특징 | 단점 |
| --- | --- | --- | --- |
| **HTML (`onclick=""`)** | `<button onclick="alert('클릭됨!')">클릭</button>` | HTML에서 직접 이벤트 지정 | 유지보수 어려움, JS가 HTML에 섞임 |
| **JavaScript (`element.onclick`)** | `btn.onclick = function() {}` | HTML과 JavaScript 분리 가능 | 이벤트 덮어쓰기 문제 발생 (한 번만 설정 가능) |
| **JavaScript (`addEventListener`)** | `btn.addEventListener("click", func)` | 여러 개의 이벤트 리스너 추가 가능 | 코드가 길어질 수 있음 |
| **JSX (`onClick={}`)** | `<button onClick={handleClick}>클릭</button>` | React에서 이벤트 관리 | `onClick="..."` 사용 불가능 (JSX 문법 때문) |

---

## 📌 결론

✅ HTML에서 `onclick=""` 방식은 **유지보수가 어려워 현재는 거의 사용되지 않게 됐다.** 

✅ 또한 JavaScript에서 `onclick = 함수` 방식은 HTML과 JS를 분리할 수 있지만 중복 이벤트 등록이 안 되어 이를 사용할려면, addEventListener 을 사용해야한다. 

✅ React의 `onClick={}` 방식은 `addEventListener()`와 유사하지만, React가 자동으로 이벤트를 관리해준다.  즉, React에서의 `onClick={}` 방식은 **JavaScript의 `addEventListener()`를 더 편리하게 만든 발전된 형태**라고 생각하면 된다.