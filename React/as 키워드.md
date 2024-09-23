as 키워드
===
여기서 사용되는 `as` 는 **별칭(alias)** 을 지정하는 문법이다. 

즉, 내보내는 모듈의 이름을 변경해서 가져오겠다는 의미이다.

### 예시 설명
```js
export { default as DayListPage } from './DayListPage';
export { default as WordListPage } from './WordListPage';
```
위의 코드는 다음과 같은 작업을 한다:

#### 1. `DayListPage` 를 내보냄:
- `./DayListPage` 파일에서 **기본 내보내기(default export)된 내용을 가져오면서, 이를 `DayListPage` 라는 이름**으로 내보낸다.

#### 2. `WordListPage` 를 내보냄:
- `./WordListPage` 파일에서 기본 내보내기된 내용을 가져오면서, 이를 `wordListPage` 라는 이름으로 내보낸다.

## `as` 의 역할
- **기본 내보내기**는 해당 모듈에서 이름을 정할 수 없다. 따라서 `as`를 사용해서 내보낼 때 원하는 이름으로 **별칭을 정하는 것**이 가능하다.
- 이렇게 하면, `index.js` 파일에서 `DayListPage` 와 `WordListPage` 라는 이름으로 내보낼 수 있고, 이를 다른 파일에서 사용할 때는 이 이름으로 가져올 수 있다.

## 예시 사용
```js
// index.js
export { default as DayListPage } from './DayListPage';
export { default as WordListPage } from './WordListPage';

// App.js에서 가져올 때
import { DayListPage, WordListPage } from './pages';
```

### 요약
- `as` 는 모듈을 내보낼 때 별칭을 지정하는 데 사용된다.
- 이를 통해 **모듈의 기본 내보내기 이름을 변경**하여, 다른 파일에서 사용 시 보다 명확하고 일관된 이름으로 관리할 수 있다.