push(element)
===
- **push() 메서드는 배열의 끝에 하나 이상의 요소**를 추가하고, **배열의 새로운 길이를 반환**한다.

**특징**
- 원본 배열을 변경한다.
- 추가되는 요소는 하나 이상의 요소일 수 있으며 여러 개의 요소를 한 번에 추가할 수 있다.

```
let fruits = ['apple','banana'];
let newLength = fruits.push('orange','mango')

console.log(fruits); //  ['apple', 'banana', 'orange', 'mango']
console.log(newLength); // 4
```i