Axios 좀 더 파보기_01
===
토익 웹페이지 중 `Daylist.jsx` 컴포넌트를 공부하던 도중
```jsx
const getData = async () => {
    try {
      const { data: dayListData } = await axios.get(
        "http://localhost:3001/days"
      );
      setDays(dayListData);
    } catch (e) {
      alert(e);
    }
  };

```
이 코드에서 axios 는 분명 URL 에서 정보를 가져오는 얘로 알고 있었는데 왜 이 웹페이지 URL 은 `localhost:3001` 이 아닌, `localhost:3000` 이라고만 뜨는걸까? 라는 의구심이 들었다.

## 왜 `localhost: 3001` 이 사용되는지에 대한 설명

### 서버와 클라이언트의 분리
- `localhost: 3001` 는 우리의 **React 애플리케이션**(프론트엔드)이 실행되고 있는 주소이다.
- `localhost: 3001` 은 **백엔드 서버**(데이터를 제공하는 서버) 가 실행되고 있는 주소이다. 

### 데이터를 어디서 가져오나?
- 이 코드에서 `axios` 는 `http://localhsot:3001/days` 에 요청을 보내 날짜 목록 데이터를 가져온다. 여기서 `localhost:3001` 이 바로 데이터가 저장된 서버의 주소이다.

### 브라우저에는 왜 `localhost: 3000` 만 보이는가?
- 브라우저에서 보이는 `localhost:3000`은 프론트엔드(React 앱)가 실행되는 곳이다. 이 앱 내부에서 `axios` 가 `localhost:3001` 로 데이터를 요청하기 때문에, 브라우저의 주소 창에는 `localhost:3000` 만 보이고 `localhost:3001` 은 보이지 않는 것이다. 

## 핵심 요점
`localhost : 3000` : 우리가 보고 있는 웹페이지(React 앱) 가 실행되는 곳

`localhost: 3001` : 그 웹페이지가 데이터를 요청하는 서버의 주소

즉, 우리가 브라우저에서 보는 주소는 `localhost:3000` 이지만, 웹페이지 내에서 데이터를 가져오기 위해 `localhost:3001` 서버에 요청을 보내고 있는 것이다.

**axios 는 이 요청을 보내기 위해 사용되고 있다.!!!**