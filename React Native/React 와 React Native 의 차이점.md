React 와 React Native 의 차이점
===

### React (리액트)
- **웹 애플리케이션** 을 만들기 위해 만들어진 라이브러리이다.
- HTML, CSS, JS 를 사용해서 웹사이트의 UI 를 만들 때 사용한다.
- 컴포넌트 기반으로 되어 있어서, 재사용 가능한 UI 조각들을 쉽게 만들고 관리할 수 있다.
- 예를 들어, 웹사이트에서 버튼, 텍스트, 이미지 등을 만드는 데 사용한다.

### React Native (리액트 네이티브)
- **모바일 애플리케이션(ios, Android)**을 만들기 위해 만들어진 프레임워크이다.
- React와 비슷한 방식으로 코딩하지만, 웹이 아니라 **네이티브 모바일 앱** 을 만들 수 있게 해준다.
- HTML, CSS 대신, **네이티브 컴포넌트** ( ex) `<View>` , `<Text>` , `<Button>`) 을 사용해서 모바일 UI 를 만든다.
- React 처럼 컴포넌트 기반으로 되어 있어서 코드의 재사용성이 높고, 웹 개발자도 쉡게 적응할 수 있다.


## 코드의 차이점


 #### React(웹용 코드)
 ```js
function App() {
  return (
    <div>
      <h1>Hello, World!</h1>
      <button>Click Me</button>
    </div>
  );
}
 ```
 - 여기서 `<div>` , `<h1>` , `<button>` 같은 태그는 **HTML**이다. 웹페이지에서 사용하는 코드이다.

 #### React Native (모바일용 코드)
 ```js
 import { View, Text, Button } from 'react-native';

function App() {
  return (
    <View>
      <Text>Hello, World!</Text>
      <Button title="Click Me" />
    </View>
  );
}
 ```
- React Native 에서는 **HTML 태그를 사용하지 않는다.** 대신, `<View>`, `<Text>` , `<Button>` 같은 **네이티브 컴포넌트**를 사용한다.
- 이 컴포넌트들은 모바일 앱에서 직접 작동하는 기능들을 제공해서, 진짜 네이티브 앱처럼 보여지고 동작한다.

## 같은 점

#### 컴포넌트 기반:
둘 다 작은 UI 조각들(컴포넌트) 을 만들어서 재사용할 수 있게 하는 구조이다. 따라서, 로직을 짜는 방식이나 상태를 관리하는 방법(ex) `useState`, `useEffect`) 은 비슷하다.

#### JS 언어:
둘 다 JS 코드를 작성하므로, JavaScript 를 알면 둘 다 쉽게 배울 수 있다.

#### React 의 개념 활용:
props, state, hooks 등 React 의 개념들이 그대로 React Native 에서도 사용된다.

### 정리하자면..
React 는 웹 개발을 위해, React Native 는 모바일 앱 개발을 위해 사용된다.

코드 작성 방식이 비슷하지만, 실제 사용하는 컴포넌트가 다르고, 목적도 다르다. 그래도 React 를 알면 React Native 를 배우기 쉽고, 그 반대도 가능한다.