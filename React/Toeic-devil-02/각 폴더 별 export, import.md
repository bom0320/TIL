각 폴더 별 export, import
===
## 1. `index.js` : Name Export (이름 있는 내보내기)
`index.js` 파일에서 `DayListPage` 와 `wordListPage` 를 이름 있는 내보내기(Named Export) 로 내보내고 있다.

```js
// page/index.js
export { default as DayListPage } = './DayListPage';
export { default as WordListPage } = './WordListPage';
```

여기서
- `DayListPage` 와 `WordListPage` 는 각각 **이름을 붙여서** 내보내고 있다.
- 즉, 다른 파일에서는 이 이름들로 **Named Import** 방식으로 가져와야 한다.

## 2. `WordListPage.js` : 기본 내보내기(Default Export)

`WordListPage.js` 파일에서 컴포넌트를 **기본 내보내기(default Export)** 하고 있다.
```js
// WordListPage.js
const WordListPage = () => {
    // 컴포넌트 로직
};

export default WordListPage;
```
여기서:
- **`export default WordListPage;`** 는 **기본 내보내기**이다. 이 파일에서는 `wordListPage` 컴포넌트를 기본으로 내보낸다. 
- 다른 파일에서 이 컴포넌트를 가져올 때는 **중괄호 없이** 가져온다.

## 3. `App.js` : 이름 있는 가져오기 (Named Import)

`App.js` 에서 **Named Import(이름 있는 가져오기)** 를 사용해 `index.js` 에서 내보낸 `DayListPage` 와 `WordListPage` 를 가져온다.

여기서:
- `index.js` 에서 **이름 있는 내보내기(Named Export)** 로 내보낸 `DayListPage` 와 `WordListPage` 는 **중괄호 `{ }`** 로 감싸서 가져온다
- **Named Import** 는 반드시 내보낸 이름과 동일한 이름을 사용해야 한다.

### 요약:
1. `index.js` : **이름 있는 내보내기(Named Export)** 로 여러 컴포넌트를 내보낸다.
2. `WordListPage.js` : **기본 내보내기(Default Export)** 로 컴포넌트를 내보낸다.
3. `App.js` : **이름 있는 가져오기 (Named Import)** 로 `index.js` 에서 내보낸 컴포넌트를 가져온다.

이렇게 구성하면 여러 컴포넌트를 한 번에 쉽게 가져올 수 있어 코드의 관리가 더 편리해진다. 