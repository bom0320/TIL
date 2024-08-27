map()
===
```
arr.map(callback(currentValue[, index[, array]])[, thisArg])
```
- 배열의 각 요소에 대해 제공된 함수를 호출하고 결과를 새로운 배열로 반환한다.

```
const array1 = [1,4,9,16];

// Pass a function to map
const map1 = array1.map((x) => x*2)

console.log(map1);

```