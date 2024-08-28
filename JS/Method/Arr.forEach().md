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

- `forEach` 는 배열의 각 요소에 대해 **단순히 작업을 수행** 하고 **반환값이 필요 없는** 경우에 적합하다.
- **부작용**(함수가 외부 상태를 변경하는 것) **반환값이 중요하지 않은 경우**에는 `forEach` 를 사용하는 것이 좋지만, 특정 조건이나 반환된 값을 기반으로 새로운 배열을 생성하거나 루프를 제어해야하는 경우에는 다른 배열 메서드나 루프 구조를 사용하는 것이 더 적합하다.

