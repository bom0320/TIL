entries()
===
- `Object.entries()` : 메서드는 객체의 각 속성을 `[키, 값]` 쌍을 배열 형태로 반환한다.
- 반환된 배열은 이중 배열 형태로, 각 배열의 첫 번째 요소는 키, 두 번째 요소는 값이다.

### 사용법
```js
Object.entries(객체);
```

### 예제
```js
const person = {
  name: 'Alice',
  age: 30,
  job: 'Developer'
};

const entries = Object.entries(person);
console.log(entries);
```
위 예제를 실행하면
```
[
  ['name', 'Alice'],
  ['age', 30],
  ['job', 'Developer']
]
```

## `Object.entries` 메서드의 사용 이유
1. **객체를 순회할 때 유용 :** `object.entries()`를 사용하면 객체의 모든 속성을 **[키, 값]**형태로 쉽게 순회할 수 있다.
2. **배열 메서드와 함께 사용하기 편리 :** 객체의 속성을 배열 형태로 변환하면, `map()`, `filter()`,`reduce()` 와 같은 배열 메서드를 사용할 수 있어 더 다양한 작업을 수행할 수 있다.

### 객체를 순회하는 예제
```js
const person = {
  name: 'Alice',
  age: 30,
  job: 'Developer'
};

for (const [key, value] of Object.entries(person)) {
  console.log(`${key}: ${value}`);
}
```
위 코드는 다음과 같이 출력된다.
```
name: Alice
age: 30
job: Developer

```

## `Object.entries()`와 다른 메서드의 비교
- `object.keys()`: 객체의 **모든 키**를 배열로 반환한다.
- `object.values` : 객체의 **모든 값**을 배열로 반환한다.
- `object.entries()` : 객체의 **모든 [키,값] 쌍**을 배열로 반환한다.

### 실용적인 예제
`object.entries()` 를 사용하면 객체의 데이터를 쉽게 변환할 수 있다. 예를 들어, 객체를 쿼리 문자열로 변환할 때 사용할 수 있다.
```js
const params = {
  search: 'apple',
  page: 2
};

const queryString = Object.entries(params)
  .map(([key, value]) => `${key}=${value}`)
  .join('&');

console.log(queryString); // 'search=apple&page=2'
```

## 요약
- `Object.entries()` : 객체의 **모든 [키,값] 쌍**을 배열 형태로 반환하는 메서드이다.
- 반환된 배열은 이중 배열로, 각 배열에는 객체의 키와 값이 포함된다.
- 이 메서드는 객체를 쉽게 순회하거나, 객체의 데이터를 변환할 때 유용하다.