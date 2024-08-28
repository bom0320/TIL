includes()
===
- `includes` 메서드는 js에서 문자열(string) 과 배열(Array) 객체에서 사용되는 메서드로, **특정 요소나 문자열이 포함되어 있는지 여부를 확인하는 데 사용**된다.

## 1. 문자열(String) 에서 `includes()`
#### 사용법
```js
string.includes(searchString, position)
```
- `searchString` : 검색할 문자열이다.
- `position` (옵션): 검색을 시작할 인덱스 위치이다. 기본값은 0이다. 

#### 반환 값
- **true :** `searchString` 이 문자열에 포함되어 있으면 반환된다. 
- **false :** 포함되어 있지 않으면 반환된다.

#### 특징
- 대소문자를 구분한다. ("Hello"와 "hello" 는 다르게 취급된다.)
- `position` 인수를 사용하면, 검색을 특정 위치에서부터 시작할 수 있다.

**예제**
```js
let str = 'Hello, Word!';

console.log(str.includes('Hello')); // true
console.log(str.includes('hello')); // false (대소문자 구분)
console.log(str.includes('World', 5)); // true (5번째 인덱스 이후에 'World'가 있음)
console.log(str.includes('World', 8)); // false (8번째 인덱스 이후에는 'World'가 없음)
```

## 2. 배열(Array) 에서 `includes()`

#### 사용법
```js
array.includes(searchElement, fromIndex)
```
- `searchElement` : 배열에서 찾고자 하는 요소이다.
- `fromIndex` (옵션) : 검색을 시작할 인덱스이다. 기본 값은 0이다. 음수인 경우 배열의 끝에서 부터 역으로 계산한다.

#### 반환값
- true: `searchElement` 가 배열에 포함되어 있으면 반환된다.
- false: 포함되어 있지 않으면 반환된다.

#### 특징
- 엄격한 일치(===)를 사용하여여 요소를 비교한다 (즉, 데이터 타입과 값이 모두 일치해야한다)
- `fromIndex` 가 음수이면, 배열의 길이에서 `fromIndex` 의 절대값을 빼서 검색을 시작한다.

**예제**
```js
let arr = [1, 2, 3, 4, 5];

console.log(arr.includes(3)); // true
console.log(arr.includes(6)); // false
console.log(arr.includes(3, 3)); // false (3번째 인덱스 이후에 3이 없음)
console.log(arr.includes(2, -3)); // true (배열의 길이 -3부터 검색 시작)
```

### 요약
- **`includes()` 메서드는 문자열과 배열에서 모두 사용** 할 수 있으며, 특정 문자열이나 요소가 포함되어 있는지 확인하는 기능을 제공한다.
- **문자열에서 사용**될 때는 검색할 문자열과 싲가 위치를 인수로 받으며, 대소문자를 구분한다.
- **배열에서 사용**될 때는 찾을 요소와 시작 인덱스를 인수로 받으며, 요소는 엄격한 일치(===)로 비교된다.

이 메서드는 문자열이나 배열에서 특정 값의 존재 여부를 쉽게 확인할 수 있게 해주는 편리한 메서드이다.