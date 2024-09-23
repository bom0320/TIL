ESM
===
ESM 은 ES6 부터 지원하고 있는 표준 모듈 시스템이다. ES6 이전까지는 브라우저 환경에서 사용할 수 있는 표준 모듈 시스템이 없었기 때문에, 필요한 파일을 만들어서 같이 배포하고, `<script src="script.js">`의 형태로 파일을 직접 불러오는 방법을 사용했다.

---

### export
export는 기본적으로 named export 와 default export 의 두 가지 방식과 export 와 from 을 조합해서 사용하는 방식이 있다.

### named export
named export 는 선언된 변수명을 그대로 export 하는 방식이다. named export 는 모듈 내에 여러 개의 export 가 존재할 수 있고, 변수를 선언함과 동시에 내보내기를 하거나, 먼저 정의된 변수를 모아서 내보내고, 먼저 정의된 함수를 별칭으로 바꿔서 내보낼 수 있다. 

```
export let name1;
export const name2;
export var name3;
export function name4 () {/*...*/}
export class MyClass {/*...*/}
```

```
const var1;
let var2;
var var3;
export { var1, var2, var3 }
```

```
let var4;
export { var4 as var5 }
```

### default export
default export 는 모듈에서 하나만 존재할 수 있고, named export 와 같이 변수를 직접 내보낼 수는 없다. default export 를 default export {const, let, var} 처럼 변수를 직접 내보내는 방식으로 사용하면 에러가 발생한다.

```js
export default expression;
export default function () { /*...*/ }
export default function myFunction() { /*...*/ }
export default class { /*...*/ }
export default class MyClass { /*...*/ }
export default function* () { /*...*/ }

const myModule = { /*...*/ }
const var1 = () => {}
export { myModule as default, var1 }
```

```js
export default function () { /*...*/ }
export default MyClass () { /*...*/ }
Uncaught SyntaxError: Identifier '*default*' has already been declared
```
export default 를 두 번 사용하는 경우도 에러가 발생한다. default 라는 식별자를 export문이 내부적으로 사용하기 때문이다.

### export from
export from 은 import 와 export 를 한 번에 처리할 수 있는 문법이다. 주로 패키지의 다른 모듈들을 한 번에 모아서 일관된 형태로 내보내거나 고나리하고 싶은 경우에 사용한다.

export from 구문을 사용하면 import 와 export 를 한 번에 처리할 수 있는 장점이 있지만, 다 export-from 을 처리하는 파일 스코프에서는 식별자가 바인딩되지 않기 때문에 메서드나 변수에 직접 접근하면 에러가 발생한다. 에러 발생 이유는 해당 메서드가 스코프 내에 존재하지 않기 때문.
