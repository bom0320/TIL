ES6 모듈의 기본 문법
===
ES6 모듈의 기본 문법은 코드를 **모듈화**해서 서로 다른 파일에서 공유하고 사용할 수 있게 해주는 규칙이다. 이를 통해 코드를 더 **효율적이고 체계적으로 관리**할 수 있다. ES6 모듈의 두 핵심 개념은 `export`(내보내기) 와 `import`(가져오기) 이다.

## 1. Export (내보내기)
`export` 는 하나의 파일에서 변수를 함수, 클래스를 다른 파일에서 사용할 수 있도록 내보내는 기능이다. 두 가지 방식이 있다.

### 1.1 Named Export (이름 있는 내보내기)
- 한 파일에서 **여러 개의 함수, 변수, 객체** 등을 내보낼 수 있다.
- 내보낼 때 각각을 `export` 키워드로 지정한다.

```js
// math.js
export const pi = 3.14;

export function add(a, b) {
  return a + b;
}

export function subtract(a, b) {
  return a - b;
}
```

### 1.2 Default Export (기본 내보내기)
- 한 파일에서 **단 하나의 값**만 기본으로 내보낼 수 있다.
- `export default` 키워드를 사용해 내보낸다.

```js
// greet.js
export default function greet(name) {
  return `Hello, ${name}!`;
}
```

## 2. Import (가져오기)
`import` 는 다른 파일에서 `export` 된 값을 가져와 사용할 수 있는 기능이다. 가져오는 방식은 Named Export 와 Default Export 에 따라 다르다.

### 2-1 Named Import
- `export` 로 내보낸 값들을 **이름을 그대로** 가져온다. 여러 개를 가져올 때는 중괄호 `{ }` 를 사용한다.

```js
// main.js
import { pi, add, subtract } from './math.js';

console.log(pi);  // 3.14
console.log(add(2, 3));  // 5
console.log(subtract(5, 2));  // 3
```

### 2.2 Default Import 
- `export default` 로 내보낸 값을 가져올 때는 **중괄호 없이** 가져온다. 이름은 자유롭게 지정할 수 있다.

```js
// main.js
import greet from './greet.js';

console.log(greet('Alice'));  // "Hello, Alice!"
```

## 3. Named Export 와 Default Export 함께 사용하기
하나의 파일에서 **Name Export** 와 **Default Export** 를 동시에 사용할 수 있다.

```js
// utils.js
export const pi = 3.14;

export default function multiply(a, b) {
  return a * b;
}
```

```js
// main.js
import multiply, { pi } from './utils.js';

console.log(pi);  // 3.14
console.log(multiply(2, 3));  // 6
```

## 4. 모듈 파일을 전체로 가져오기 (Namespace Import)
모든 내보낸 값들을 하나의 객체로 가져와 사용할 수도 있다.

```js
// math.js
export const pi = 3.14;
export function add(a, b) {
  return a + b;
}
export function subtract(a, b) {
  return a - b;
}

// main.js
import * as math from './math.js';

console.log(math.pi);  // 3.14
console.log(math.add(2, 3));  // 5
console.log(math.subtract(5, 2));  // 3
```

## 5. Import 할 때 이름 바꾸기 (Alias)
이름이 길거나 충돌을 피하기 위해 **별칭(Alias)** 을 사용할 수 있다.

```js
// math.js
export function add(a, b) {
  return a + b;
}
export function subtract(a, b) {
  return a - b;
}

// main.js
import { add as addition, subtract as subtraction } from './math.js';

console.log(addition(2, 3));  // 5
console.log(subtraction(5, 2));  // 3
```

## 6. 모듈의 특징
- **모듈의 독립성 :** 각 파일은 독립된 스코프를 가진다. 따라서 다른 파일에서 정의된 변수나 함수는 `import` 를 하지 않는 한 접근할 수 없다.
- **자동 엄격 모드 :** ES6 모듈은 기본적으로 strict mode 에서 실행된다. 즉, 코드에서 안전성을 더 강화한다.

### 요약
- `export` : 데이터를 내보내는 키워드. `Named Export` 와 `Default Export` 가 있다.
- `import` : 다른 파일에서 데이터를 가져오는 키워드. `Named Import` 는 중괄호 `{ }` 를 사용하고, `Default Import` 는 중괄호 없이 가져온다.
- 모듈은 코드의 재사용성, 유지보수성, 가독성을 향상시키는 중요한 도구이다.

