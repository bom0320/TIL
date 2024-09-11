Props.name
===

Day.jsx
```jsx
{wordList.map((word) => (
    <Word key={word.id} word={word} />
))}
```
토익 웹페이지를 만들어보면서 props 의 name 이 특정 데이터들을 명확하게 식별하기 위함이라고 했는데 그게 무슨 말인지 잘 모르겠어서 더 자세히 공부를 해보고자 했다.

### props name 을 지정하는 이유
HTTP 요청에서 특정 조건에 맞춰 걸러진 데이터를 props 로 넘겨줄 때, 그 데이터를 구분하기 위해 props 의 이름을 지정하는 것이다. 

그리고 그 이름이 `props.name` 이 되는것이다.

## 다시 정리하면:

### 1. HTTP 요청을 통해 데이터를 가져옴:
```js
const { data } = await axios.get(`http://localhost:3001/words?day=${day}`);
```
- 여기서 `http://localhost:3001/words?day=${day}` 는 특정 날짜(day) 에 해당하는 단어들만 가져오기 위한 **필터링된 데이터**를 요청하는 것이다.
- 예를 들어, `day=3` 을 요청하면 3일차에 해당하는 단어들만 서버에서 받아온다.

### 2. 받아온 데이터를 `map` 으로 반복:

```jsx
{wordList.map((word)=>(
    <Word key={word.id} word={word} />
))}
```
- `wordList` 는 서버에서 가져온 **특정 조건(예: day) 에 맞는 데이터 배열** 이다.
- 이 배열의 각 항목을 `map` 으로 반복하며, 각 단어(`word`) 를 `Word` 컴포넌트에 전달한다.

### 3. props 로 데이터 전달:

```jsx
<Word key={word.id} word={word} />
```
- 여기서 `word={word}`는 부모 컴포넌트(`Day.jsx`) 가 자식 컴포넌트(`Word.jsx`) 로 **단어 데이터를 전달**하는 방식이다.
- `word` 라는 **props 의 이름을 지정**하여, 자식 컴포넌트가 이 데이터에 접근할 수 있게 해준다.

### 4. props 이름의 역할:
- `word` 라는 props 이름을 지정함으로써, 자식 컴포넌트는 **명확하게 전달받은 데이터를 구분**할 수 있다.
- 예를 들어, `Word` 컴포넌트는 `props.word` 를 통해 전달된 특정 단어 데이터에 접근한다.

## 예시:

#### 부모 컴포넌트 (`Day.jsx`) :

```jsx
{wordList.map((word) => (
  <Word key={word.id} word={word} />
))}

```
- 여기서 `word={word}`는 **props의 name(이름)을 `word` 로 지정한 것** 이다. 이 props 에서는 `wordList` 배열에서 `map` 을 돌며 걸러진 단어 객체가 들어간다.

#### 자식 컴포넌트 (`Word.jsx`) :

```jsx
const Word = ({ word }) => {
  return (
    <tr>
      <td>{word.eng}</td>
      <td>{word.kor}</td>
    </tr>
  );
};
```
- 자식 컴포넌트는 `props.word` 를 통해 **부모로부터 전달받은 단어 데이터에 접근**할 수 있다. 여기서 `word` 는 props 로 전달받은 단어 객체를 의미한다.

### 결론
- `http://localhost:3001/words?day=${day}` 요청은 서버에서 특정 조건(여기서는 `day`값) 에 맞는 데이터를 필터링해서 가져온다.
- **필터링된 데이터를 `map`으로 반복하면서,** 각 데이터 항목을 **props 로 자식 컴포넌트에 전달**한다.
- 이때 **props 의 이름을 지정**하는 것은, 자식 컴포넌트가 **전달된 데이터를 명확하게 구분ㄴ하고 사용할 수 있도록**하기 위함이다.

