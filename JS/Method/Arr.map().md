map()
===

## map 메서드란?
map() 메서드는 배열 내의 모든 요소 각각에 대하여 주어진 함수를 호출한 결과를 모아 새로운 배열을 반환하는 메서드이다.

for of 문이나 forEach문처럼 배열 내 요소들을 반복하는 반복문의 한 종류인데, 조금 독특한 부분은 **매 반복마다 return 되는 결과에 따라 새로운 배열을 만들어 낸다는 것**이다. 

## 문법
```js
const myArr = [1,2,3,4,5];

const newMyArr = myArr.map((currentElement, index, array) => {
    return currentElement * 2;
});

console.log(newMyArr); // [2,4,6,8,10]
```
map 메서드는 파라미터(매개변수)로 콜백함수를 받는데, 그 **콜백 함수의 파라미터는 요소, index, 그리고 현재 map 메서드를 호출한 배열**이다.

세번째 배열은 잘 사용되지 않고, 일반적으로 첫 번째 요소와, 주 번째 index 가 많이 사용된다.

말 그대로 요소는, 반복이 일어날 때마다 0번 index 부터 해당하는 각 요소가 할당되고, index 또한 해당 index 인 것이다.

```js
const myArr = [1,2,3,4,5];

const newMyArr = myArr.map((currentElement, index, array) => {
    console.log(`요소: ${currentElement}`);
    console.log(`index: ${index}`);

    return currentElement * 2
});

console.log(newMyArr); //[2, 4, 6, 8, 10]
```
위 코드를 실행하면 다음과 같은 결과가 출력된다.
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbAFL6D%2FbtqFTUeXbVm%2FQtkHHgjkpLkOn3wKmCO4Ck%2Fimg.png)
여기까지만 보면 forEach 와 다를 것이 없지만, 차이점은 마지막 10번 줄에서 확인한 것처럼 이 메서드가 실행된 자리에 리턴되는 배열이 있느냐이다.

결과적으로 map은 메서드를 호출한 배열의 길이 만큼의 새로운 배열을 만들어내는 게 핵심인데, **콜백 함수의 return 값을 통해 새로운 배열들의 각 요소를 변형할 수 있다**는 특징이 있는것이다.

```js
const myArr = [1,2,3,4,5];
const assignMyArr = myArr;
const mapMyArr = myArr.map((el) => {
    return el;
})

console.log(myArr); // [1,2,3,4,5]
console.log(assignMyArr) // [1,2,3,4,5]
console.log(mapMyArr) // [1,2,3,4,5]
```
3번째 줄에서 map 메서드의 콜백 함수를 실행할 때, 사용하지 않는 파라미터는 생략할 수 있다. 그리고 그냥 요소값들을 return 하게 되면 똑같은 배열이 만들어지는데, 그렇다 하더라고 **map 메서드를 통해 생성된 배열은 말 그대로 새로운 배열** 이기 때문에, 배열의 요소들이 서로 같더라도 아래와 같이 같이 각 배열들을 일치 비교할 경우 결괏값이 서로 차이가 난다.

```js
console.log(myArr === assignMyArr) // true
console.log(myArr === mapMyArr); // false
```

끝으로 만약 map 메서드의 콜백 함수가 아무것도 리턴하지 않을 경우에는, 호출한 배열의 길이만큼의 **undefined** 가 채워진 배열이 리턴된다.
```
const myArr = [1,2,3,4,5];
const mapMyArr = myArr.map(() => {})

console.log(mapMyArr); // [undefined, undefined, undefined, undefined, undefined]
```