find()
===
- `find()` 메서드는 배열에서 **특정 조건을 만족하는 첫 번째 요소의 값을 반환**해준다.

arr.find() 메서드의 기본 구문은 다음과 같다
```
arr.find(callback[], thisArg)
```

`number`이라는 숫자 배열을 선언하고 find() 를 사용하는 예시이다.
```js
const numbers = [1,2,3,4,5];

const selectNumber = numbers.find(num => num >3);
document.writeIn(selectNumber); // 4
```
이 예제에서 find()는 numbers 배열에서 현재 요소가 3보다 큰지 확인하는 콜백함수를 반복한다.

**'number' 배열에서 3보다 큰 첫번재 요소는 4이므로, selectNumber의 값에 4가 반환**된다.

만약 지정된 조건을 만족하는 요소가 없다면 find() 메서드는 실행 결과 `undefined` 를 반환한다.