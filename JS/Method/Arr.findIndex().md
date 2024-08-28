findIndex()
===
- 배열에서 주어진 조건을 만족하는 **첫 번째 요소의 인덱스** 를 반환한다.
- 이는 배열에서 조건에 맞는 요소의 위치(인덱스)를 찾고 싶을 때 사용한다.

```js
const numbers = [5, 12, 8, 130, 44];

// 10보다 큰 첫 번째 요소의 인덱스를 찾음
const foundIndex = numbers.findIndex((element) => element > 10);

console.log(foundIndex); // 출력: 1

```
이 예제에서 `findIndex` 메서드는  10보다 큰 첫 번째 요소의 **인덱스**인 1을 찾고, 그 인덱스를 반환한다.
 
+ find 는 조건을 만족하는 첫 번째 객체 `{id: 2, name: 'Bob' }`을 반환하는 반면, findIndex 는 조건을 만족하는 첫 번째 객체의 인덱스 1을 반환한다.