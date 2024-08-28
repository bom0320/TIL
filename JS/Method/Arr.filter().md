filter()
===
```js
filter(callbackFn);
filter(callbackFn, thisArg);
```
- `Array` 인스턴스의 filter() 메서드는 주어진 배열의 일부에 대한 얕은 복사본을 생성하고, 주어진 배열에서 제공된 함수에 의해 구현된 테스트를 통과한 요소로만 필터링 한다.

단, 어떤 요소도 통과하지 못하면 빈 배열을 반환한다.

```js
const swords = ['spray', 'elite', 'exuberant', 'destruction' , 'present'];

const result = words.filter((word) => word.length > 6);

console.log(result);
// Expected output: Array ["exuberant", "destruction", "present"];
```
