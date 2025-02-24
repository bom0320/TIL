React의 이벤트 객체(event)와 SyntheticEvent 
===


## **1️⃣ 이벤트 객체(`event`)란?**

👉 **"이벤트가 발생했을 때, 그 정보를 담고 있는 객체"**

✔ 클릭, 입력, 마우스 이동 등 **이벤트 발생 시 자동 생성**

✔ **이벤트가 발생한 요소, 입력값, 이벤트 종류 등의 정보**를 포함

📌 **예제: `event` 객체 확인하기**

```jsx

const handleClick = (event) => {
    console.log(event);  // 이벤트 객체 확인
};

<button onClick={handleClick}>클릭</button>

```

✔ 버튼을 클릭하면 콘솔에 `event` 객체가 출력됨!

✔ 이벤트 객체는 **어떤 요소에서 이벤트가 발생했는지(`target`) 등의 정보를 포함함.**

---

## **2️⃣ `event.target`을 사용하면?**

✔ **이벤트가 발생한 요소(HTML 태그)를 가리킴!**

📌 **예제: 클릭된 요소 확인**

```jsx

const handleClick = (event) => {
    console.log(event.target);  // 클릭된 요소 출력
};

<button onClick={handleClick}>클릭</button>

```

✅ 버튼을 클릭하면 **콘솔에 `<button>` 태그가 출력됨**

✅ 즉, **어떤 요소에서 이벤트가 발생했는지 알 수 있음!**

---

## **3️⃣ `event.target.value`를 사용하면?**

✔ **입력 필드(`input`)에서 입력된 값을 가져옴**

📌 **예제: 입력값 가져오기**

```jsx

const handleChange = (event) => {
    console.log(event.target.value);  // 입력된 값 확인
};

<input type="text" onChange={handleChange} />

```

✅ 사용자가 `"Hello"`를 입력하면 콘솔에 `"Hello"`가 출력됨!

✅ 즉, **`input` 태그의 입력값을 가져올 때 사용됨.**

---

## **4️⃣ `preventDefault()`란?**

✔ **기본 동작(예: 폼 제출 시 새로고침)을 막고 싶을 때 사용!**

📌 **예제: 폼 제출 시 새로고침 막기**

```jsx

const handleSubmit = (event) => {
    event.preventDefault();  // 기본 동작(새로고침) 막기
    console.log("폼이 제출됨!");
};

<form onSubmit={handleSubmit}>
    <button type="submit">제출</button>
</form>

```

✅ 원래는 폼을 제출하면 새로고침되지만, `preventDefault()`를 사용하면 막을 수 있음!

---

## **5️⃣ `stopPropagation()`이란?**

✔ **이벤트 버블링(부모 요소까지 이벤트가 전달되는 것)을 막을 때 사용!**

📌 **예제: 부모 요소로 이벤트 전달 막기**

```jsx

const handleOuterClick = () => {
    console.log("부모 div 클릭됨!");
};

const handleInnerClick = (event) => {
    event.stopPropagation();  // 부모로 이벤트 전달 막기
    console.log("자식 div 클릭됨!");
};

<div onClick={handleOuterClick}>
    <div onClick={handleInnerClick}>클릭하세요!</div>
</div>

```

✅ `stopPropagation()`이 없으면 `"부모 div 클릭됨!"`도 같이 실행됨 ❌

✅ `stopPropagation()`이 있으면 `"자식 div 클릭됨!"`만 실행됨 ✅

---

## **6️⃣ `event` 객체와 `SyntheticEvent`의 관계**

📌 **React에서는 브라우저의 `event` 객체를 그대로 쓰지 않고, `SyntheticEvent`로 감싸서 제공함!**

| **브라우저 기본 `event` 객체** | **React의 `SyntheticEvent` 객체** |
| --- | --- |
| 브라우저가 제공 | React가 제공 |
| 브라우저마다 동작이 다를 수 있음 | 모든 브라우저에서 동일하게 동작 |
| `event.target` 사용 가능 | `event.target` 사용 가능 |
| `event.preventDefault()` 가능 | `event.preventDefault()` 가능 |
| `event.stopPropagation()` 가능 | `event.stopPropagation()` 가능 |
| 메모리 관리 X | **이벤트 풀링(Pooling)으로 메모리 최적화** |

✅ React에서는 **모든 브라우저에서 일관된 동작을 보장하기 위해 `SyntheticEvent`를 사용!**

✅ `SyntheticEvent`는 브라우저 기본 이벤트 객체를 감싸면서도, 같은 속성(`target`, `type` 등)을 유지함.

---

## **7️⃣ `SyntheticEvent` 내부 구조 확인하기**

📌 **React의 `SyntheticEvent`는 브라우저의 기본 이벤트 객체(`nativeEvent`)를 포함하고 있음!**

📌 **React가 자동으로 최적화해서 메모리를 관리해줌.**

```jsx

const handleClick = (event) => {
    console.log(event);  // React의 `SyntheticEvent` 객체 출력
    console.log(event.nativeEvent); // 원래 브라우저 이벤트 객체 출력
};

<button onClick={handleClick}>클릭</button>

```

✅ `event.nativeEvent`를 출력하면 **브라우저의 기본 `event` 객체**를 볼 수 있음!

✅ 즉, **React의 `SyntheticEvent`는 브라우저의 `event` 객체를 감싼 래퍼(wrapper)!**

---

## **8️⃣ `SyntheticEvent`에서 `event.target.value`를 사용할 수 있는 이유**

```jsx

const handleChange = (event) => {
    console.log(event.target.value);  // 입력된 값 확인
};

<input type="text" onChange={handleChange} />

```

✅ `SyntheticEvent`가 내부적으로 **`event.target`을 브라우저의 원래 이벤트 객체와 동일하게 유지**하기 때문!

✅ 그래서 `event.target.value`를 사용하면 **브라우저 이벤트와 동일하게 동작함.**

---

## **9️⃣ `SyntheticEvent`를 이해하면 좋은 점**

✔ 모든 브라우저에서 **일관된 이벤트 처리를 할 수 있다.**

✔ 브라우저 기본 `event` 객체와 **동일한 속성(`target`, `type` 등)을 유지하면서 React가 최적화해준다.**

✔ React에서 이벤트가 어떻게 동작하는지 더 깊이 이해할 수 있다.

---

## **🏁 최종 정리**

### **✅ `event` 객체란?**

- 이벤트가 발생했을 때 자동 생성되는 객체
- `event.target` → 이벤트가 발생한 요소
- `event.target.value` → 입력값 가져오기 (`input`에서 유용)
- `event.preventDefault()` → 기본 동작 막기 (예: 폼 제출 막기)
- `event.stopPropagation()` → 이벤트 전파 막기 (예: 부모 요소 클릭 방지)

### **✅ `SyntheticEvent`란?**

- React가 제공하는 "합성이벤트 객체"
- 브라우저 기본 `event` 객체를 감싸서 **모든 브라우저에서 일관되게 동작하도록 함**
- `event.target`, `event.preventDefault()` 같은 속성은 그대로 유지됨
- 내부적으로 `event.nativeEvent`를 통해 브라우저 원본 `event` 객체를 포함하고 있음

✔ **즉, React의 `SyntheticEvent`는 브라우저 이벤트 객체를 감싼 래퍼(wrapper) 역할을 하면서, React가 자체적으로 최적화한 이벤트 시스템!** 🚀