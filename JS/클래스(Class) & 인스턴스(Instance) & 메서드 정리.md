클래스(Class) & 인스턴스(Instance) & 메서드 정리
===

## **🔹 1. 클래스(Class)란?**

👉 **"객체를 만들기 위한 설계도"**

- 직접 데이터를 저장하지 않음 → 단순히 객체를 만드는 틀 역할을 한다.
- `new` 키워드를 사용해야 실제 객체(인스턴스)가 생성된다.

✔ **비유:** 🏗 **"집 설계도"**

✔ **예제:**

```jsx
class Person {
  constructor(name) {
    this.name = name;
  }
}
```

---

## **🔹 2. 인스턴스(Instance)란?**

👉 **"클래스를 기반으로 만들어진 실제 객체"**

- `new` 키워드를 사용하여 클래스를 인스턴스로 변환한다.
- **각 인스턴스는 고유한 데이터를 가질 수 있음**

✔ **비유:** 🏠 **"실제로 지어진 집"**

✔ **예제:**

```jsx
const p1 = new Person("봄"); // 인스턴스 생성
console.log(p1.name); // "봄"
```

---

## **🔹 3. 인스턴스 메서드(Instance Method)란?**

👉 **"인스턴스에서만 실행할 수 있는 메서드"**

- 개별 인스턴스에서 동작해야 하는 기능을 정의
- **클래스에서 직접 호출할 수 없음 (`Person.sayHello()` ❌ 오류 발생)**

✔ **비유:** 🏠 **"집 안에서만 할 수 있는 행동"** (문을 열기, 불 켜기 등)

✔ **예제:**

```jsx
class Person {
  constructor(name) {
    this.name = name;
  }

  sayHello() {
    return `안녕! 나는 ${this.name}이야!`;
  }
}

const p1 = new Person("봄");
console.log(p1.sayHello()); // ✅ "안녕! 나는 봄이야!"

console.log(Person.sayHello()); // ❌ 오류 발생! (클래스에서 직접 호출 불가)
```

🚨 **설계도만 보고 문을 열 수 있을까?**

```jsx

console.log(House.openDoor()); // ❌ 오류 발생! (TypeError: House.openDoor is not a function)

```

🚀 **집을 지어야 문을 열 수 있음!**

```jsx
const myHouse = new House();  // 실제 집(인스턴스) 생성
console.log(myHouse.openDoor()); // ✅ "문을 열었어!"

```

✔️ **즉, `openDoor()`는 "집" 안에서만 할 수 있는 행동!**

✔️ **설계도(House)에서 문을 열 수는 없음! (그래서 `House.openDoor()`는 오류 발생)**

💡 **이게 바로 인스턴스 메서드!**

➡️ **객체(인스턴스)가 있어야 실행할 수 있는 메서드!**

---

## **🔹 4. 정적 메서드(Static Method)란?**

👉 **"클래스에서 직접 실행할 수 있는 메서드"**

- `static` 키워드를 사용하여 정의
- **인스턴스에서 호출할 수 없음 (`p1.greet()` ❌ 오류 발생)**

✔ **비유:** 🏢 **"건축회사가 제공하는 정보"** (설계도만 보고 제공할 수 있는 정보)

✔ **예제:**

```jsx
class Person {
  constructor(name) {
    this.name = name;
  }

  static greet() {
    return "안녕하세요! 저는 정적 메서드입니다!";
  }
}

console.log(Person.greet()); // ✅ "안녕하세요! 저는 정적 메서드입니다!"

const p1 = new Person("봄");
console.log(p1.greet()); // ❌ 오류 발생! (인스턴스에서 호출 불가)
```

🚀 **건축회사(클래스)에서 정보 제공 가능!**

```jsx
console.log(House.companyInfo()); // ✅ "이 집은 ABC 건축회사에서 만들었습니다!"
```

🚨 **하지만, 개별 집(인스턴스)에서는 실행할 수 없음!**

```jsx
const myHouse = new House();
console.log(myHouse.companyInfo()); // ❌ 오류 발생! (TypeError: myHouse.companyInfo is not a function)
```

✔️ **즉, `companyInfo()`는 건축회사(클래스)에서만 실행할 수 있는 기능!**

✔️ **개별 집(인스턴스)에서 호출할 수 없음! (그래서 `myHouse.companyInfo()`는 오류 발생)**

💡 **이게 바로 정적 메서드!**

➡️ **클래스 자체에서 실행할 수 있는 메서드! (인스턴스 없이 호출 가능!)**

---

## **📌 정리된 비교표**

| **구분** | **클래스(Class)** | **인스턴스(Instance)** | **인스턴스 메서드** | **정적 메서드** |
| --- | --- | --- | --- | --- |
| 역할 | 객체를 만들기 위한 설계도 | 설계도로 만든 실제 객체 | 객체에서만 실행 가능한 기능 | 클래스에서 직접 실행 가능한 기능 |
| 생성 방식 | `class` 키워드 사용 | `new 클래스명()` 사용 | `prototype`에 저장됨 | `static` 키워드 사용 |
| 호출 방법 | 직접 실행 불가 | `new` 키워드로 객체 생성 | `인스턴스명.메서드명()` | `클래스명.메서드명()` |
| 비유 | 🏗 "집 설계도" | 🏠 "실제 집" | 🚪 "집 안에서 문을 여는 것" | 🏢 "건축회사에서 제공하는 정보" |
| 예제 | `class Person {}` | `const p1 = new Person()` | `p1.sayHello()` | `Person.greet()` |

---

### **🔥 한 줄 요약**

✔️ **클래스(Class)** = `"설계도"` → 직접 데이터 저장 X

✔️ **인스턴스(Instance)** = `"실제 만들어진 객체"` → `new`를 사용해야 생성

✔️ **인스턴스 메서드** = `"객체 안에서만 사용할 수 있는 기능"` → `p1.sayHello()`

✔️ **정적 메서드** = `"클래스에서 직접 호출하는 기능"` → `Person.greet()`