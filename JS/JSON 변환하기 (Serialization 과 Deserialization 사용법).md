JSON 변환하기 (Serialization과 Deserialization 사용법)
===

## 1. `JSON.stringify()` - 직렬화
JavaScript 객체를 JSON 문자열로 변환하는 메서드이다.

```js
const obj = { name: "Alice", age: 25 };
const jsonString = JSON.stringify(obj);
console.log(jsonString); 
// 결과: '{"name":"Alice","age":25}'
```
- **사용 목적 :** 객체를 JSON 문자열로 변환하여 네트워크로 전송하거나 파일로 저장할 수 있다.

## 2. `JSON.parse()` - 역직렬화
JSON 문자열을 JavaScript 객체로 변환하는 메서드이다.

```js
const jsonString = '{"name":"Alice","age":25}';
const obj = JSON.parse(jsonString);
console.log(obj); 
// 결과: { name: "Alice", age: 25 }
```
- **사용 목적 :** 서버에서 받은 JSON 데이터를 JavaScript 객체로 변환하여 프로그램에서 바로 활용할 수 있다.
