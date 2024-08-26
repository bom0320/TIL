pop()
===
- pop() 메서드는 배열의 마지막 요소를 제거하고, 그 요소를 반환한다.

**특징**
- 원본 배열을 변경한다.
- 제거된 요소를 반환하며, 배열이 비어있을 경우 `undefined` 를 반환한다.

```
let fruits = ['apple', 'banana', 'orange'];
let last = fruits.pop();
console.log(fruits); // ['apple', 'banana']
console.log(last); // 'orange'
```