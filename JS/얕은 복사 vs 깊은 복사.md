얕은 복사 vs 깊은 복사
===
얕은 복사(shallow copy) 와 깊은 복사(deep copy)는 **객체를 복사할 때 발생하는 두 가지 다른 방식**이다.

이 두 개념은 특히 js 와 같은 프로그래밍 언어에서 객체의 속성(또는 참조) 에 대한 복사에 방식에 따라 다르다.

## 1. 얕은 복사 (Shallow Copy)
얕은 복사는 **객체의 1단계 속성들만 복사** 하는 방식이다. 

즉, 객체의 참조(Reference) 만 복사하며, 객체 내부의 중첩된 객체나 배열의 경우 **같은 메모리 주소를 참조**하게 된다. 

얕은 복사를 하면 원본 객체와 복사된 객체가 일부 데이터를 공유하게 되며, 한쪽을 변경하면 다른 쪽에도 영향을 미칠 수 있다.

```js
const original = { a: 1, b: { c: 2 } };
const shallowCopy = Object.assign({}, original);

// shallowCopy와 original은 별개의 객체입니다.
console.log(shallowCopy === original); // false

// 그러나, 내부 객체 'b'는 같은 메모리 주소를 참조합니다.
console.log(shallowCopy.b === original.b); // true

// shallowCopy의 내부 객체를 변경하면, original에도 영향을 미칩니다.
shallowCopy.b.c = 3;
console.log(original.b.c); // 3

```
위의 코드에서 `shallowCopy` 는 `original` 객체의 얕은 복사본이다. `original` 의 `b` 속성은 객체이기 때문에, `shallowCopy` 의 `b` 속성은 `original.b` 와 동일한 객체를 참조한다.

따라서 `shallowCopy.b.c` 를 변경하면 `original.b.c` 도 변경된다.

## 2. 깊은 복사 (Deep Copy)
깊은 복사는 **객체의 모든 중첩된 객체나 배열까지 재귀적으로 복사**하는 방식이다. 이 경우, 원본 객체와 복사된 객체는 완전히 독립된 메모리 공간을 가지며, 어떤 객체의 변경도 다른 객체에 영향을 미치지 않는다.

```js
const original = { a: 1, b: { c: 2 } };
const deepCopy = JSON.parse(JSON.stringify(original));

// deepCopy와 original은 별개의 객체입니다.
console.log(deepCopy === original); // false

// deepCopy의 내부 객체도 별개의 객체입니다.
console.log(deepCopy.b === original.b); // false

// deepCopy의 내부 객체를 변경해도, original에는 영향을 미치지 않습니다.
deepCopy.b.c = 3;
console.log(original.b.c); // 2
```
위으 코드에서 `JSON.parse(JSON,stringify(original))` 을 사용하여 `original` 의 깊은 복사를 만들었다. 

이제 `deepCopy` 는 `original` 과 완전히 독립적인 객체가 되며, 어떠한 변경도 서로 영향을 미치지 않는다.

### 결론
- **얕은 복사** 는 최상위 객체만 새롭게 생성하고, 내부의 중첩 객체나 배열은 기존 참조를 그대로 사용한다.
- **깊은 복사** 는 객체의 모든 중첩된 구조를 재귀적으로 복사하여 원본과 완전히 독립적인 복사본을 만든다.

이 두 개념은 데이터의 불변성 유지, 성능 최적화 및 버그 방지를 위해 중요한 역할을 한다. 어떤 방식이 더 적절한지 선택하는 것은 상황에 따라 다르다. 