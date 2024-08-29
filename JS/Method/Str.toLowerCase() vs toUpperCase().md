toLowerCase()와 toUpperCase()
===
- 이는 js에서 문자열(string) 객체에 사용되는 메서드로, 각각 문자열을 소문자나 대문자로 변환하는 데 사용된다. 이 메서드들은 원본 문자열을 변경하지 않고, 변환된 새로운 문자열을 반환한다.

## 1. toLowerCase() 메서드
`toLowerCase()` 메서드는 문자열 내의 모든 대문자를 소문자로 변환한 새로운 문자열을 반환한다.

```js
string.toLowerCase();
```
- `string` : 소문자로 변환할 대상 문자열이다.

### 반환 값
- 변환된 **새로운 소문자 문자열** 을 반환한다.
- 원본 문자열은 변경되지 않는다.

### 특징
- **대소문자를 구분하는 비교**에 사용될 수 있다. 예를 들어, 문자열 비교 시 대소문자를 무시하고 비교하고자 할 때 사용한다.

#### 예제
```js
let str = "Hello, WORD!";
let lowerStr = str.toLowerCase();

console.log(lowerStr); // 'hello, word!'
console.log(str); // 'Hello, WORD!' (원본 문자열은 변경되지 않음)
```

## 2. toUpperCase() 메서드
- `toUpperCase()` 메서드는 문자열 내의 모든 소문자를 대문자로 변환한 새로운 문자열을 반환한다.

### 사용법
```js
string.toUpperCase();
```
- `string` : 대문자로 변환할 대상 문자열이다.

### 반환값
- 변환된 **새로운 대문자 문자열** 을 반환한다.
- 원본 문자열은 변경되지 않는다.

### 특징
- **대문자로 변환할 문자열을 비교하거나, 일관적으로 대문자를 표현하고자 할 때** 유용하게 사용된다.

#### 예제
```js
let str = "Hello, world!";
let upperStr = str.toUpperCase();

console.log(upperStr); // 'HELLO, WORLD!'
console.log(str);      // 'Hello, world!' (원본 문자열은 변경되지 않음)
```

### 주요 차이점
- **toLowerCase()**는 문자열의 모든 문자를 소문자로 변환한다.
**toUpperCase()**는 문자열의 모든 문자를 대문자로 변환한다.

### 용도
대소문자 구분 없이 문자열을 비교할 때, 두 문자열을 모두 toLowerCase()나 toUpperCase()로 변환한 다음 비교할 수 있다.

일관된 대소문자 형식을 유지하고자 할 때, 사용자 입력을 모두 소문자나 대문자로 변환하여 저장할 수 있다.
### 결론
toLowerCase()와 toUpperCase() 메서드는 문자열의 대소문자를 변환하는 매우 기본적이고 유용한 메서드들이다. 이 메서드들은 원본 문자열을 변경하지 않고, 변환된 문자열을 새롭게 반환하여 다양한 문자열 처리 작업에 사용될 수 있다고 한다.






