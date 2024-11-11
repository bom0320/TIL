구조분해 (Destructuring assignment)
===
최근 자바스크립트 함수형 프로그래밍을 공부하다 구조분해에 대한 개념이 조금 부족하여 따로 정리하여 작성했다.

## 1. 문법
구조분해의 기본 문법은 아래와 같다.

```js
const [a, b] = [1, 2];
console.log(a); // 1
console.log(b); // 2 

const [c, d, ...rest] = [1, 2, 3, 4, 5, 6, 7];
console.log(c); // 1
console.log(d); // 2
console.log(rest); // [3, 4, 5, 6, 7]

const { e, f } = { e: 1, f: 2 };
console.log(e); // 1
console.log(f); // 2

const x = [1, 2, 3, 4, 5];
const [y, z] = x;
console.log(y); // 1
console.log(z); // 2
```
구조분해 할당의 **좌변**은 **값을 담을 변수**, **우변**에는 **값을 넣은 변수**가 된다. 

이 문법을 처음보게 된다면 조금 혼란스러울 수 있다. 다시 천천히 생각해보고 직접 사용해본다면 너무 당연한 문법 같기도 하다.

## 2. 배열 구조분해

### 기본 변수 할당
배열 구조분해 변수에 값을 할당하는 기본 방법은 아래와 같다.

```js
var foo = [`one` , `two` , `three`];
var [one, two, three] = foo;

console.log(one); // "one"
console.log(two); // "two" 
console.log(three); // "three"
```
foo에 one, two, three 를 각각 저장한 후, 변수 one, two, three 에 구조분해 할당되어 출력되는 것을 확인할 수 있다.

### 선언에서 분리한 할당
변수선언과 할당을 분리하여 배열 구조분해 할당을 할 수 있다.

```js
var a,b;

[a, b] = [1, 2];
console.log(a);  // 1
console.log(b); // 2
```


### 기본값 설정
배열 구조분해는 기본값 설정이 가능하다.

```js
var a, b;

[a=5, b=7] = [1];
console.log(a); // 1
console.log(b); // 7
```
a=5, b=7 로 기본값을 할당하였다. a에는 1이 할당되었고, b 에는 값이 할당되지 않았기 때문에 기본값인 7이 할당된 것을 확인 할 수 있다.


### 값 교환 (스와핑)
스와핑, 두개의 값 교환을 배열 구조분해를 사용하면 한줄로 표현이 가능하다.

```js
var [a, b] = [1, 3];

[a, b] = [b, a];
console.log(a); // 3
console.log(b); // 1
```

### 함수의 반환된 배열
함수에서 반환된 배열로도 구조분해 할당이 가능하다. => 자바스크립트 함수는 **1급 함수**이기 때문이다.

```js
function foo() {
  return [1, 2];
}

var [a, b] = foo();
console.log(a); // 1
console.log(b); // 2
```
`foo()` 에서 배열 [1,2] 를 리턴한다. 이 리턴 값으로 구조분해 할당을 하여 변수 a와 b에 값이 출력되는 것을 확인할 수 있다.

### 값 무시하기

```js
function foo() {
  return [1, 2, 3];
}
var [a, , b] = foo();
console.log(a); // 1
console.log(b); // 3

[a, , b] = [4, 5, 6];
console.log(a); // 4
console.log(b); // 6
```
리턴된 값 2와 할당된 값 5를 무시한 상태로 할당되는 것을 확인할 수 있다. 모든 값을 무시하는 것도 가능하다.

```js
[,,] = [1, 2, 3, 4, 5];
```

### 전개 연산자를 이용한 저장
