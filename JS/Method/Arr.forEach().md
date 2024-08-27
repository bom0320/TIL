forEach(callback)
===
- 배열의 각 요소에 대해 제공된 **콜백 함수를 한 번씩 실행**한다.

### 구문
```
forEach(callbackFn)
forEach(callbackFn, thisArg)
```
#### ex)
```js
const array1 = ['a','b','c'];

array1.forEach((element) => console.log(element));

// Expected output: "a"
// Expected output: "b"
// Expected output: "c"

```