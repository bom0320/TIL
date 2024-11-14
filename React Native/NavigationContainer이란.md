NavigationContainer
===
- `NavigationContainer` 는 React Navigation 라이브러리에서 제공하는 컴포넌트로, **앱의 네비게이션을 관리하는 최상위 컨테이너** 역할을 한다.
- 이 컴포넌트는 `Stack Navigator` , `Tab Navigator`, `Drawer Navigator` 와 같은 내비게이션 구조를 감싸고 있어야 하며, 이 안에서 모든 화면 이동이 이루어진다.

## 역할과 특징

#### 앱의 내비게이션 상태 관리:
- 네비게이션 컨텍스트를 제공하여 앱 내의 모든 화면이 `NavigationContainer` 를 통해 화면을 전환할 수 있도록 설정된다.

#### 테마 설정:
- `theme` prop 을 통해 **앱 전체의 테마**를 지정할 수 있다. 
- 예를 들어, 다크 모드를 설정하면 모든 화면의 배경색이 기본적으로 어두운 색상으로 설정된다. 
- 이 부분이 `NavigationContainer` 에 배경색을 설정하는 이유가 된거다.

#### 네비게이션 상태 복원:
- `NavigationContainer` 는 앱이 다시 열릴 때 마지막 내비게이션 상태를 기억하고 복원하는 기능을 제공한다.

```js
import { NavigationContainer, DefaultTheme } from '@react-navigation/native';

const MyDarkTheme = {
  ...DefaultTheme,
  colors: {
    ...DefaultTheme.colors,
    background: '#000',
  },
};

export default function App() {
  return (
    <NavigationContainer theme={MyDarkTheme}>
      {/* 여기서 BottomTabNavigator와 같은 내비게이션 구조를 감싸줌 */}
    </NavigationContainer>
  );
}
```

**Note :** `NavigationContainer` 는 React Navigation 라이브러리를 사용한 경우에만 필요한 컴포넌트이다.  내비게이션 없이 단일 화면 앱이라면 `NavigationContainer` 가 필요하지 않다.

