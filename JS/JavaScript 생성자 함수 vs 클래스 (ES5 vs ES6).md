JavaScript 생성자 함수 vs 클래스 (ES5 vs ES6)
===

### **✅ ES5 방식 (생성자 함수 + `prototype`)**

```jsx

function Shape(x, y) {
  this.name = "Shape"; // 🔹 개별 인스턴스에 저장됨
  this.move(x, y); // 🔹 `move()`를 호출
}

// 🔹 정적 메서드 (클래스에서 직접 호출 가능)
Shape.create = function (x, y) {
  return new Shape(x, y);
};

// 🔹 prototype에 저장됨 (모든 인스턴스가 공유)
Shape.prototype.move = function (x, y) {
  this.x = x;
  this.y = y;
};

// 🔹 prototype에 저장됨 (모든 인스턴스가 공유)
Shape.prototype.area = function () {
  return 0;
};

var s = new Shape(0, 0);
console.log(s.area()); // ✅ 0

```

✔ **`this.name = "Shape";`** → **각 인스턴스에 독립적으로 저장됨!**

✔ **`Shape.create()`** → **정적(static) 메서드, 인스턴스에서는 사용 불가!**

✔ **`Shape.prototype.move`** → **모든 인스턴스가 공유하는 메서드! (`prototype`에 저장됨)**

---

### **✅ ES6 방식 (class 사용)**

```jsx

class Shape {
  static create(x, y) {
    return new Shape(x, y); // 🔹 정적 메서드
  }

  name = "Shape"; // 🔹 클래스 필드 → 각 인스턴스에 독립적으로 저장됨

  constructor(x, y) {
    this.move(x, y); // 🔹 prototype에 저장된 move()를 실행
  }

  move(x, y) { // 🔹 prototype에 저장됨 (모든 인스턴스 공유)
    this.x = x;
    this.y = y;
  }

  area() { // 🔹 prototype에 저장됨 (모든 인스턴스 공유)
    return 0;
  }
}

var s = new Shape(0, 0);
console.log(s.area()); // ✅ 0

```

✔ **`name = "Shape";`** → **클래스 필드, 각 인스턴스에 독립적으로 저장됨!**

✔ **`static create()`** → **정적 메서드, `Shape.create()`로만 호출 가능!**

✔ **`move()` & `area()`** → **클래스 메서드(= `prototype`에 저장됨, 모든 인스턴스 공유!)**

---

### **📌 정리: ES5와 ES6 차이점**

| **구분** | **ES5 (생성자 함수 + prototype)** | **ES6 (class 사용)** |
| --- | --- | --- |
| **정적 메서드** | `Shape.create = function() {...}` | `static create() {...}` |
| **클래스 필드** | `this.name = "Shape";` (constructor 내부) | `name = "Shape";` (클래스 필드) |
| **인스턴스 메서드** | `Shape.prototype.move = function() {...}` | `move(x, y) {}` (자동으로 prototype에 저장됨) |
| **코드 가독성** | 상대적으로 복잡함 | 더 직관적이고 간결함 |

🔥 **즉, ES6 `class` 문법이 더 가독성이 좋고, 직관적이며, prototype을 자동으로 활용할 수 있다!** 🚀

---

### **📌 결론**

✅ **"클래스 필드는 개별 인스턴스에 저장!"**

✅ **"클래스 메서드는 `prototype`에 저장되어 모든 인스턴스가 공유!"**

✅ **"정적 메서드는 클래스에서만 사용 가능!"**

✅ **"생성자 함수(ES5)와 `class`(ES6)의 차이를 확실히 구분함!"**