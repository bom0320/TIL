unshift(element)
===
- unshift() 메서드는 **배열의 시작 부분에 하나 이상의 요소를 추가**하고, 배열의 새로운 길이를 반환한다.

### 특징
- 원본 배열을 변경한다.
- 배열의 앞부분에 새로운 요소를 추가하며, 추가된 요소 수만큼 기존 요소들이 뒤로 밀린다.

```js
let fruits = ['banana', 'orange'];
let newLength = fruits.unshift('apple', 'mango');
console.log(fruits); // ['apple', 'mango', 'banana', 'orange']
console.log(newLength); // 4
```