자바스크립트 프로토타입 개념 총정리 | constructor, prototype, __proto__
===

### **1️⃣ `constructor`, `prototype`, `__proto__`의 차이**

| 속성 | 존재하는 대상 | 역할 |
| --- | --- | --- |
| `constructor` | ✅ 함수만 가짐 | 생성자 함수가 자신을 가리키는 속성 (📌 생성자로 비유 가능: 객체를 생성하는 출생지) |
| `prototype` | ✅ 함수만 가짐 | 생성된 객체들이 공유하는 부모 역할을 하는 원형 객체 (📌 부모로 비유 가능: 객체들이 공통으로 물려받는 원형) |
| `__proto__` | ✅ 객체와 함수 모두 가짐 | 객체가 자신의 부모(프로토타입)를 가리키는 내부 링크 (📌 가계도로 비유 가능: 내가 누구의 자식인지 가리키는 정보) |

💡 **즉, `prototype`은 부모 그 자체이고, `__proto__`는 부모를 가리키는 속성이다!**

✔️ **`constructor`는 객체를 생성하는 출생지(생성자) 역할을 한다.**
✔️ **`prototype`은 부모 역할을 하며, 여러 객체들이 공통으로 물려받는 원형이다.**
✔️ **`__proto__`는 부모를 가리키는 속성으로, 객체 간의 연결 고리를 형성한다.**

---

### **2️⃣ 자바스크립트 객체의 `Prototype` 프로퍼티**

✔️ 자바스크립트 객체는 `Prototype`이라는 내부 프로퍼티를 가진다.

✔️ 거의 모든 객체가 생성될 때, 이 프로퍼티에 `null`이 아닌 값이 할당된다.

### **클래스 함수와 프로토타입 오브젝트**

```jsx
function Foo() {}

```

1. **함수를 정의하면 함수만 생성되는 것이 아니라 `Prototype Object`도 같이 생성된다.**
2. **`Prototype Object`는 기본 속성으로 `constructor`와 `__proto__`를 가지고 있다.**

---

### **3️⃣ `prototype`과 `__proto__`의 관계**

```jsx
function Foo() {}

const obj = new Foo();

```

**관계:**

```
(Foo.prototype)  (부모 역할)
  ├── constructor: Foo
  ├── __proto__: Object.prototype  ✅ Foo.prototype도 결국 하나의 객체이므로 부모가 Object.prototype!

(obj)  (new Foo()로 생성된 객체)
  ├── __proto__ → Foo.prototype  ✅ obj는 Foo.prototype을 부모로 가짐

```

✔️ **`prototype`은 부모 역할을 하는 객체**

✔️ **`__proto__`는 객체가 부모를 가리키는 속성**

---

### **4️⃣ `prototype`과 `__proto__`의 출력 결과**

```jsx
function Foo() {}

const obj = new Foo();

console.log(obj.prototype);   // undefined ❌ (객체는 prototype을 가지지 않음)
console.log(obj.__proto__);   // Foo.prototype ✅ (부모를 가리키는 속성)
console.log(Foo.prototype);   // { constructor: Foo, __proto__: Object.prototype } ✅
console.log(Foo.__proto__);   // Function.prototype ✅ (모든 함수는 Function.prototype을 부모로 가짐)

```

💡 **즉, `prototype`은 부모 역할을 하는 객체고, `__proto__`는 부모를 가리키는 링크다.**

---

### **5️⃣ `__proto__`는 자식이 아니라, 부모를 가리키는 속성**

✔️ **`__proto__`는 자식 자체가 아니라, "내 부모가 누구인지"를 가리키는 속성이다.**

✔️ **즉, "나는 누구의 자식인가?"를 기록하는 속성이다.**

```jsx
console.log(Foo.prototype.__proto__ === Object.prototype);  // true ✅
console.log(obj.__proto__ === Foo.prototype);  // true ✅
console.log(Object.prototype.__proto__ === null);  // true ✅ (Object.prototype은 최상위 조상이므로 부모가 없음)

```

---

### **6️⃣ JavaScript의 프로토타입 체인**

✔️ **`__proto__`를 따라가면 최상위 조상 `Object.prototype`까지 연결된다.**

```
(Function.prototype)
        ↑
(Foo)  ──────→ Foo.prototype (Prototype Object)
        ↑             ↑
        |             ├── constructor: Foo
        |             ├── __proto__: Object.prototype  ✅ (← 여기!)
        |
       new
        ↓
      (obj)
        ↑
        ├── __proto__ → Foo.prototype

```

---

### **7️⃣ `Function.prototype`과 `Object.prototype`의 관계**

✔️ **모든 함수는 `Function.prototype`을 부모로 가짐.**

✔️ **모든 객체는 `Object.prototype`을 부모로 가짐.**

```jsx
console.log(Function.prototype.__proto__ === Object.prototype);  // true ✅
console.log(Object.prototype.__proto__ === null);  // true ✅ (최상위 객체는 부모가 없음)

```

---

### **8️⃣ 프로토타입을 활용한 메서드 공유**

✔️ **`prototype`을 사용하면 여러 객체가 메서드를 공유할 수 있다.**

✔️ **모든 객체가 같은 메서드를 참조하므로 메모리 효율이 좋아짐.**

```jsx
function Bar() {}

Bar.prototype.sayHello = function() {
  return "Hello!";
};

const bar1 = new Bar();
const bar2 = new Bar();

console.log(bar1.sayHello === bar2.sayHello);  // ✅ true (같은 부모인 Bar.prototype을 공유함)

```

---

### **🚀 최종 정리**

| 개념 | 역할 | 설명 |
| --- | --- | --- |
| `constructor` | 생성자 함수(출생 병원) | 생성자 함수가 자신을 가리킴 |
| `prototype` | 부모 (유전자 제공) | 생성된 객체들이 공유하는 부모 객체 |
| `__proto__` | 부모를 가리키는 속성 | 객체가 부모(프로토타입)를 가리키는 내부 링크 |

---

## **프로토타입 개념 테스트 문제!** 🎯

완전히 이해했는지 다음 문제를 풀어보며, 개념을 체크해 보자

### 📌 1️⃣ `prototype`과 `__proto__`의 차이

```jsx
function Foo() {}

const obj = new Foo();

console.log(obj.prototype);   // undefined

console.log(obj.__proto__);   // ❌ {}
															// ✅ Foo.prototype
															
console.log(Foo.prototype);   // constructor: Foo() , __proto__: object;

console.log(Foo.__proto__);   // ❌ object
															// ✅ Function.prototype

```

✔️ **이유:**

- `obj.__proto__`는 `Foo.prototype`을 가리킴!
- 즉, `console.log(obj.__proto__)` 하면 **`Foo.prototype` 객체가 출력됨!**

---

✔️ **이유:**

- 모든 함수는 `Function.prototype`을 부모로 가진다.
- 따라서 `Foo.__proto__ === Function.prototype`이 성립함.
- `console.log(Foo.__proto__)` 하면 `Function.prototype`이 출력됨!

### 📌 2️⃣ `Foo.prototype.__proto__`의 값

```jsx
function Foo() {}

console.log(Foo.prototype.__proto__);  // object
```

### 📌 3️⃣ `obj.__proto__ === Foo.prototype`가 성립하는 이유

```jsx
function Foo() {}

const obj = new Foo();

console.log(obj.__proto__ === Foo.prototype); // obj 의 __proto__ 는 Foo 즉, Poo.prototype 을 가리키므로, true

```

### 📌 4️⃣ `Object.prototype.__proto__`의 값

```jsx
console.log(Object.prototype.__proto__);  
// 모든 객체의 최상위 부모가 Object.prototype이다.
// 하지만 Object.prototype 자체는 더 이상의 부모가 없으므로 null이 나온다.
```

### 📌 5️⃣ `Function.prototype.__proto__`의 값

```jsx
console.log(Function.prototype.__proto__);  // ❌ null
																						// ✅ Object.prototype

```

✔️ **이유:**

- `Function.prototype`도 결국 하나의 객체이다.
- 모든 객체는 `Object.prototype`을 부모로 가진다.
- 따라서 **`Function.prototype.__proto__ === Object.prototype`이 성립!**

---

### **🚀 추가 도전 문제 (심화 문제)**

```jsx
function Bar() {}

Bar.prototype.sayHello = function() {
  return "Hello!";
};

const bar1 = new Bar();
const bar2 = new Bar();

console.log(bar1.sayHello === bar2.sayHello);  // true
```

✔️ `bar1`과 `bar2`는 같은 `Bar.prototype`을 공유하므로, `sayHello` 메서드도 공유된다!

✔️ 즉, `bar1.sayHello === bar2.sayHello`가 **true**가 된다!

💡 **네가 적은 이유도 맞지만, 조금 더 명확하게 정리하면:**

✔️ `bar1`과 `bar2`는 각각 `Bar.prototype`을 부모로 가짐.

✔️ 따라서 `sayHello` 메서드는 같은 `Bar.prototype`을 가리키므로 `true`가 나온다.