slice 더 파보기
===

## slice 간단 한 줄 정리
- **slice :** 배열의 원하는 시작점부터 원하는 마지막 시점까지 값에 대한 얕은 복사본을 새로운 배열 객체로 반환한다. 이때 원본 배열은 바뀌지 않는다. (주의할 점! 각각의 값은 얕은 복사이기 때문에 배열 요소 중 참조형 데이터는 수정하면 값이 변경된다.)

### slice 정의
- slie : 썰다, 베다

> slice() 메서드는 어떤 배열의 begin 부터 end까지 (end 미포함) 에 대한 얕은 복사본을 새로운 배열 객체로 반환한다. 원본 배열을 바뀌지 않는다.
>
>splice() 메서드는 배열의 기존 요소를 삭제 또는 교체하거나 새 요소를 추가하여 배열 내용을 변경한다.

```js
const animals = ['ant', 'bison', 'camel', 'duck', 'elephant']; 
console.log(animals.slice(2)); //["camel", "duck", "elephant"]
console.log(animals.slice(2, 4)); //["camel", "duck"]
console.log(animals.slice(1, 5)); //["bison", "camel", "duck", "elephant"]
console.log(animals.slice(-2)); //["duck", "elephant"]
console.log(animals.slice(2, -1)); //["camel", "duck"]
console.log(animals.slice()); //["ant", "bison", "camel", "duck", "elephant"]
```
위의 예제와 MDN 사이트의 정의와 사전적인 의미로 보아 slice 는 **기존 배열은 변경하지 않고 기존 배열에서 원하는 데이터를 잘라내어 잘라낸 데이터들을 새로운 배열에 담아 반환하는 것을**알 수 있다.

여기서, 위에서 생각한 의문에 대해서 짚고 넘어가겠다.


## slice() 주의사항
**도대체 왜?? slice 는 얕은 복사인데 왜 원본 배열이 바뀌지 않는다고 하는 것일까?**

배열 A를 slice를 한다고 하면, 각각의 배열 A의 요소들을 얕은 복사를 한다는 의미이고, 배열 A의 길이 자체는 바뀌지 않는다고 하는 것이다. 하지만 **배열 A를 slice 한 배열 B의 값을 변경한다면 각각의 값은 얕은 복사를 했기 때문에 배열 A의 값은 변경될 수 있다.**

---

### 기본형 데이터를 갖는 배열

```js
const animals = ['ant', 'bison', 'camel', 'duck', 'elephant'];
const animalsSlice1 = animals.slice();

animalsSlice1[0] = 'ant25';

console.log('');
console.log(animalsSlice1); // ['ant25', 'bison', 'camel', 'duck', 'elephant']
console.log(animals); // [ 'ant', 'bison', 'camel', 'duck', 'elephant' ]
```
위의 예제를 보면 animals 와 animalsSlice1 의 배열은 서로 독립적으로 보인다.

참고로 위에서 설명했지만, 기본형 변수는 얕은 복사의 의미가 없다.

---

### 참조형 데이터를 갖는 배열(1)

```js
const objects = [{ name: 'tang' }, { name: 'min' }, { name: 'jae' }];
const objectSlice1 = objects.slice();

objectsSlice1[0].name = 'tang25';

console.log('');
console.log(objectsSlice1); // [{ name: 'tang25' }, { name: 'min' }, { name: 'jae' }]
console.log(objects); // [{ name: 'tang25' }, { name: 'min' }, { name: 'jae' }]
```
하지만, 위의 예제에서 objects 와 objectsSlice1의 배열은 값이 동시에 변하는 것을 볼 수 있다.

이유는 생각보다 간단하다.

slice 는 배열을 얕은 복사 하는 게 아니라 **각각의 값들을 얕은 복사 해서 새로운 배열에 담고 해당 배열을 리턴** 해준다.

**혹여나 slice는 원본 배열이 변경 안된다 해서 막 사용하더가 위와 같은 상화잉 발생하지 않게 주의하기!!**

---
### 참조형 데이터를 갖는 배열(2)

```js
const objects = [{ name: 'tang' }, { name: 'min' }, { name: 'jae' }];
const objectSlice1 = objects.slice();

// 아래처럼 데이터를 변경하면 ObjectsSlices1[0]에 새로운 메모리가 할당되어 objectsSlice1[0]와 Objects[0]은 독립적인 데이터가 된다.
objectsSlice1[0] = { name: 'godTang' }

console.log('');
console.log(objectsSlice1); // [{ name: 'godTang' }, { name: 'min' }, { name: 'jae' }]
console.log(objects); // [{ name: 'tang25' }, { name: 'min' }, { name: 'jae' }]

```
하지만 위와 같이 데이터를 변경하게 되면 objectsSlice1 [0] 에 '새로운 메모리 주소 값'이 할당되어 objects [0] 와 독립적인 데이터가 된다.
