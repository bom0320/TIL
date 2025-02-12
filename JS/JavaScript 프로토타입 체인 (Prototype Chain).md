JavaScript 프로토타입 체인 (Prototype Chain)
===

### **✅ 프로토타입 체인이란?**

객체가 특정 속성이나 메서드를 찾을 때,

**자기 자신 → 부모(프로토타입) → 그 위 부모** 순으로 탐색하는 과정을 **프로토타입 체인(Prototype Chain)** 이라고 한다.

```jsx
function User(name) {
  this.name = name;
}

// 프로토타입에 메서드 추가
User.prototype.greet = function() {
  console.log(`안녕, 나는 ${this.name}이야.`);
};

const user1 = new User("봄");
const user2 = new User("가을");

user1.greet(); // 안녕, 나는 봄이야.
user2.greet(); // 안녕, 나는 가을이야.
```

### **📌 `user1.greet()` 실행 시 프로토타입 체인 탐색 과정**

1️⃣ `user1` 객체에서 `greet` 메서드를 찾음 → ❌ 없음

2️⃣ `User.prototype`에서 `greet`을 찾음 → ✅ 있음 → **실행!**

3️⃣ 만약 `User.prototype`에도 없었다면? → `Object.prototype`에서 찾음

4️⃣ `Object.prototype`에도 없었다면? → `null`을 만나고 **`TypeError` 발생**

---

## **✅ `Object.prototype`이란?**

**JavaScript에서 모든 객체의 최상위 부모(prototype chain의 끝) 역할을 하는 객체다.**

즉, **모든 객체는 `Object.prototype`을 조상으로 가진다.**

```jsx
console.log(Object.prototype);
```

위 코드를 실행하면 다음과 같은 기본 메서드들이 포함된 객체를 확인할 수 있다.

```jsx
{
  constructor: f,
  toString: f,
  valueOf: f,
  hasOwnProperty: f,
  ...
}
```

✔️ **`Object.prototype`에는 JavaScript가 기본적으로 제공하는 메서드들이 존재한다.**

✔️ `toString()`, `valueOf()`, `hasOwnProperty()` 등의 메서드는 모든 객체가 사용할 수 있다.

✔️ **즉, `Object.prototype`은 모든 객체가 상속받는 공통 조상 객체다!**

---

## **✅ 프로토타입 체인 탐색 과정**

어떤 객체에서 속성 또는 메서드를 실행하면, JavaScript는 **다음 순서로 속성을 찾는다.**

1️⃣ **객체 내부에서 먼저 찾음**

```jsx
user1.greet(); // `user1` 내부에서 `greet` 속성을 찾음
```

2️⃣ **없으면 부모(프로토타입)에서 찾음**

```jsx
user1.__proto__ === User.prototype; // `User.prototype`에서 `greet` 찾음
```

3️⃣ **부모에도 없으면 `Object.prototype`에서 찾음**

```jsx
User.prototype.__proto__ === Object.prototype; // `Object.prototype`에서 `greet` 찾음
```

4️⃣ **`Object.prototype`에도 없으면 `null`을 만나고 `TypeError` 발생**

```jsx
Object.prototype.__proto__ === null; // 더 이상 찾을 곳이 없음 → 오류 발생
```

✅ **즉, `Object.prototype`은 JavaScript의 "마지막 부모" 역할을 한다.**

---

## **✅ `Object.prototype`에 존재하는 기본 메서드**

`Object.prototype`에 정의된 기본 메서드들은 모든 객체에서 사용할 수 있다.

```jsx
const user1 = { name: "봄" };

console.log(user1.toString());
// 실행됨! (`Object.prototype.toString()`을 상속받았기 때문)

console.log(user1.hasOwnProperty("name"));
// 실행됨! (`Object.prototype.hasOwnProperty()`를 상속받았기 때문)
```

✔️ 하지만 `Object.prototype`에도 없는 속성이나 메서드를 실행하면 `null`에 도달하여 **에러가 발생한다.**

```jsx
console.log(user1.someRandomMethod());
// ❌ TypeError: user1.someRandomMethod is not a function
```

---

## **✅ `window.toString()`과 유사한 원리**

✔️ **JavaScript는 기본적으로 `prototype`을 활용하여 객체들을 연결(상속)하는 구조를 가진다.**

✔️ **이와 유사하게, `window.toString()`을 명시하지 않아도 `toString()`을 실행하면 `window.toString()`을 찾는 원리와 비슷하다.**

```jsx
console.log(toString());
// window.toString() 실행됨 (브라우저 환경에서는 `window`가 전역 객체이기 때문)
```

💡 **즉, JavaScript는 자동으로 `prototype`을 사용해 부모-자식 관계를 만들고 활용한다는 점에서 유사한 개념이다.**

---

## **🚀 최종 요약**

✔️ **`Object.prototype`은 JavaScript에서 기본 제공되는 "최상위 조상 객체"다.**

✔️ **모든 객체는 `Object.prototype`을 자동으로 조상으로 가진다.**

✔️ **객체에서 속성을 찾을 때 `prototype` 체인을 따라가면서 `Object.prototype`까지 탐색한다.**

✔️ **`Object.prototype`에는 `toString()`, `hasOwnProperty()` 같은 기본 메서드들이 존재한다.**

✔️ **기본 제공 메서드는 `Object.prototype`에 있기 때문에 에러 없이 실행된다.**

✔️ **하지만 `Object.prototype`에도 없는 속성을 찾으려고 하면 `null`에 도달해 `TypeError`가 발생한다.**

✔️ **이 원리는 `window.toString()`처럼 JavaScript가 자동으로 `prototype`을 활용하는 방식과 유사하다.**