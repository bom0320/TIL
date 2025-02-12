constructor() 정리
===

## `constructor()`  란?
- 클래스에서 **객체(인스턴스)가 생성될 때 자동으로 실행되는 함수**
- 보통 **속성을 초기화하거나 특정 동작을 실행할 때 사용**

## `constructor()`는 필수인가?
- ❌ 필수 아님!
- `constructor()`을 생략하면 **자바스크립트가 자동으로 기본 생성자(default constructor)를 추가함**
- 즉, 특별히 초기화할 값이 없다면 없어도 잘 동작함

## 언제 `constructor()`가 필요할까?
- 객체를 생성할 때 **초깃값을 설정해야 할 때**
- 객체가 생성될 때 **특정 동작을 실행해야 할 때**

## 언제 `constructor()`를 생략해도 될까?
- **초기화 할 값이 없고,** 단순히 메서드만 있는 경우

---

### 📌 예제 코드
**✔️ `constructor()`가 필요한 경우 (속성 초기화)**

```js
class Person {
  constructor(name) {
    this.name = name;
  }
}

const p = new Person("봄");
console.log(p.name); // "봄"

```

**✔️ `constructor()`를 생략해도 되는 경우**

```js
class Shape {
  area() {
    return 0;
  }
}

const s = new Shape();
console.log(s.area()); // 0
```
- **`constructor()` 없이도 잘 동작하는 이유:** 자바스크립트가 기본 생성자를 자동으로 추가해줌!

---

## 🔥 한 줄 요약
- constructor()는 객체 생성 시 자동 실행되는 함수!
-  없어도 기본 생성자가 자동 추가되므로 꼭 필요한 경우에만 사용하면 된다! 😆✨
