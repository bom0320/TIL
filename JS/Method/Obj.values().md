values()
===
- `Object.values()` 메서드는 **객체의 모든 값을 배열로 만들어 반환**하는 메서드이다.

이 메서드를 사용하면 객체에 있는 **모든 값**을 한꺼번에 배열로 얻을 수 있다.

#### object.values() 메서드 사용법
```js
object.values(객체);
```
### 예제
```js
const person = {
  name: 'Alice',
  age: 30,
  job: 'Developer'
};

const values = Object.values(person);
console.log(values); // ['Alice', 30, 'Developer']
```
위 예제에서:
- **`person` 객체 :** 이름, 나이, 직업 정보를 담고 있는 객체이다. 
- **`Object.values(person)`** : person 객체의 모든 값(예: 'Alice', 30, 'Developer')을 배열로 반환한다.
- **출력 결과 :** ['Alice', 30, 'Developer'] — 객체의 모든 값들이 배열로 반환되었다.

## `Object.values()` 메서드를 왜 사용하나요?
`Object.values()` 를 사용하면, **객체에 들어 있는 모든 값**을 쉽게 꺼내서 **배열로 처리**할 수 있기 때문이다. 

예를 들어, 객체의 값을 모두 출력하거나, 값들을 순서대로 처리하고 싶을 때 유용하다.

### 추가 예제
```js
const fruitQuantities = {
  apple: 5,
  banana: 10,
  orange: 3
};

const values = Object.values(fruitQuantities);
console.log(values); // [5, 10, 3]
```
여기서 `Object.values(fruitQuantities)` 는 객체에 있는 **모든 과일의 수**를 배열로 반환한다. [5, 10, 3]

### 요약
- **Object.values()**는 객체에 있는 모든 값을 배열로 만들어 반환하는 JavaScript 내장 메서드이다.
- 객체의 값을 쉽게 **꺼내서 배열로 처리**하고 싶을 때 사용한다.
