shift()
===
- shift() 메서드는 **배열의 첫 번째 요소를 제거**하고, 그 요소를 반환한다. 나머지 요소는 인덱스가 하나씩 앞으로 이동한다.

### 특징
- 원본 배열을 변경한다.
- 첫 번째 요소를 제거하며, 배열이 비어있을 경우 `undefined` 를 반환한다.

```
let fruits = ['apple' , 'banana', 'orange'];
let first = fruits.shift();
console.log(fruits) // ['banana', 'orange']
console.log(first) // ['apple']
```
