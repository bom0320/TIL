charAt()
===
- charAt 메서드는 js 에서 **문자열(String) 객체의 특정 인덱스에 있는 문자를 반환**하는 메서드이다.
- 이 메서드는 문자열에서 지정된 위치에 있는 단일 문자를 추출하는 데 사용된다.

### 사용법
```js
string.charAt(index);
```
- `string` : 문자를 추출하는 문자열
- `index` : 반환할 문자 위치를 나타내는 정수이다. 인덱스는 0부터 시작한다.

## 특징
1. **0부터 시작하는 인덱스 :** `charAt` 메서드의 인덱스는 0부터 시작한다. 즉, 첫 번째 문자의 인덱스는 0, 두 번째 문자의 인덱스는 1, 세번째 문자의 인덱스는 2와 같다.
2. **범위를 벗어난 인덱스 :** 만약 `index` 가 문자열의 길이보다 크거나 음수일 경우, 빈 문자열 '' 을 반환한다.
3. **불변성 :** `charAt` 메서드는 문자열 자체를 변경하지 않고, 새로운 문자열을 반환한다.

### 예제
```js
let str = 'Hello, World!';

console.log(str.charAt(0));  // 'H'
console.log(str.charAt(7));  // 'W'
console.log(str.charAt(13)); // '!' (문자열의 마지막 문자)
console.log(str.charAt(20)); // '' (범위를 벗어난 인덱스)
console.log(str.charAt(-1)); // '' (음수 인덱스)

```
위 예제에서 `charAt` 메서드는 문자열 str 의 특정 인덱스에 있는 문자를 반환한다. 인덱스가 문자열의 길이를 벗어나면 빈 문자열을 반환하는것을 볼 수 있다.

`charAt` 메서드는 간단하고 직관적인 방식으로 문자열의 개별 문자를 추출할 수 있도록 도와주는 유용한 메서드이다. 
