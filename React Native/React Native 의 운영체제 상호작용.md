React Native 운영체제 상호작용
===

## React native 개요
- **React native** 는 ios 와 Android 와 같은 **운영체제와 상호작용하기 위해** 만들어진 프레임워크이다.
- 단순히 화면을 구성하는 React 와는 달리, React Native 는 네이티브 컴포넌트와 연결되어 모바일 장치의 기능을 활용할 수 있다.

## 운영체제와의 소통을 위한 컴포넌트
- React Native 에서는 단순히 화면에 표시하기 위한 컴포넌트 외에도 운영체제와 직접 소통하는 역할을 하는 컴포넌트들이 있다.
- 예시로, `<StatusBar style="auto" />` 와 같은 컴포넌트는 상태바와 상호작용하며, 화면에 직접적인 UI 요소로 나타나지 않는다. **이런 컴포넌트들은 네이티브 운영체제의 UI 요소에 영향을 준다.**

**Example Code**
```js
import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';

export default function App() {
  return (
    <View style={styles.container}>
      <Text style={styles.text}>Hello! I made a RN App!</Text>
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
  text: {
    fontSize: 28,
  }
});
```
- 위 코드에서 `<StatusBar style="auto" />` 는 화면에 보이지 않지만, 상태바의 스타일을 변경한다.
    - `style="auto"` 를 `style="light"` 로 변경하면 상태바의 색상이 흰색으로 바뀐다.
    - 이는 이 컴포넌트가 운영체제의 상태바와 상호작용한다는 것을 보여준다.

## React Native 와 React 의 차이점
- React 는 웹을 위한 프레임워크로, 모든 컴포넌트가 화면에 렌더링되며 브라우저에서 실행된다.
- React Native 는 모바일 운영체제(ios, Android) 와 통신할 수 있는 컴포넌트를 제공하며, 일부 컴포넌트는 화면에 직접 표시되지 않고 운영체제와의 소통을 담당한다. 이는 React Native 의 네이티브 기능과 모바일 특화 프레임 워크의 특징을 보여준다.