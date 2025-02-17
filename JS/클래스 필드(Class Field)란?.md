About. Class Field
===

## 1. 클래스 필드(Class Field)란?

클래스 필드는 **ES6 이후(ES2015)에 도입된 최신 JavaScript 문법**이다.

클래스 내부에서 `this` 없이 변수처럼 선언하면 자동으로 `this` 에 저장되는 속성이 된다.!

```jsx
class MyClass {
  value = 10; // ✅ 클래스 필드 (자동으로 this.value가 됨)
}

const obj = new MyClass();
console.log(obj.value); // ✅ 10

```

💡 **클래스 필드의 특징**

- `constructor` 없이도 속성을 정의할 수 있음.
- `this.value = 10;`과 동일한 역할을 함.
- `this`를 생략하고 바로 선언 가능.

---

## 2. 기존 방식 (클래스 필드 없이 속성 정의)

클래스 필드가 나오기 전에는 **속성을 `constructor` 내부에서 `this` 로 정의**해야 했다.

```jsx
class MyClass {
  constructor() {
    this.value = 10; // ✅ 기존 방식 (클래스 필드 없이 정의)
  }
}

const obj = new MyClass();
console.log(obj.value); // ✅ 10
```

🔹 **이전 방식의 문제점**

- 반드시 `constructor`를 사용해야 속성을 정의할 수 있었음.
- `constructor`가 길어지면 가독성이 떨어짐.

---

## 3. 클래스 필드의 장점

✅ **(1) 코드가 더 간결해짐**

```jsx
// 클래스 필드를 사용한 방식
class MyClass {
  value = 10; // 클래스 필드
}
```

**VS.**

```jsx
// 기존 방식 (constructor 사용)
class MyClass {
  constructor() {
    this.value = 10;
  }
}

```

👉 **클래스 필드를 사용하면 `constructor` 없이도 속성을 정의할 수 있어서 코드가 깔끔하다.**

✅ **(2) 모든 인스턴스가 같은 값을 가질 때 더 직관적**

```jsx
class Car {
  wheels = 4; // 모든 자동차 객체는 기본적으로 바퀴가 4개
}

const car1 = new Car();
const car2 = new Car();

console.log(car1.wheels); // 4
console.log(car2.wheels); // 4
```

👉 **클래스 필드를 사용하면 기본 속성을 쉽게 설정 가능!**

(예전 방식에서는 `constructor`에서 `this.wheels = 4;`를 해줘야 했음.)

## 4. 정적 클래스 필드 (Static Class Field)

💡 **클래스 필드에 `static` 키워드를 붙이면, 인스턴스가 아니라 클래스 자체에 속성이 저장됨!**

```jsx
class MathUtils {
  static PI = 3.141592; // ✅ 정적 클래스 필드
}

console.log(MathUtils.PI); // ✅ 3.141592
```

🚀 **정적 필드는 인스턴스가 아닌 클래스 자체에서 바로 사용 가능!**

---

## **5. 클래스 필드 사용 시 주의할 점**

- **클래스 필드는 항상 `this`에 바인딩됨.**
- **생성자에서 초기화하는 방식과 혼용할 수도 있음.**

```jsx
class Example {
  x = 10; // 클래스 필드

  constructor(y) {
    this.y = y; // 생성자에서 정의하는 속성
  }
}

const obj = new Example(20);
console.log(obj.x); // 10 (클래스 필드)
console.log(obj.y); // 20 (생성자에서 초기화)

```

👉 **클래스 필드와 생성자를 함께 사용해도 문제 없음!**

---

## **6. 결론**

✅ `value = 10;` 같은 문법은 **클래스 필드(Class Field)** 문법이며,

✅ **`this.value = 10;`을 자동으로 설정하는 최신 문법**이다.

✅ **기존 `constructor` 방식보다 코드가 깔끔하고 직관적!**

🔥 **최신 JavaScript에서는 `constructor` 없이 클래스 필드를 적극적으로 활용하는 게 좋음!**