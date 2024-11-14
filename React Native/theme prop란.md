theme prop란
===
- `theme` prop 는 React Navigation 의 `NavigationContainer` 에서 **앱의 전체적인 스타일 테마**를 설정할 수 있는 속성이다.
- 이를 통해 **앱의 색상, 배경 등 UI 스타일을 전역적으로 조정**할 수 있다. 
- `theme` prop 을 사용하며느 앱 내의 모든 화면에 걸쳐 일관된 스타일을 유지하는 데 도움이 된다. 

- React Navigation 에는 **기본 제공 테마**로 `DefaultTheme` (라이트 테마) dhk `DarkThem` (다크 테마)가 있으며, 이 테마들은 `colors` 라는 속성을 통해 색상 팔레트를 포함하고 있다. 
- `theme` prop 을 사용하여 이 기본 테마들을 적용하거나, 직접 **커스텀 테마**를 만들어 사용할 수 있다.

### `theme` prop 의 구성 요소
React navigation 의 테마는 크게 colors 라는 객체를 통해 앱의 다양한 부분에 색상을 지정할 수 있따. 기본적으로 제공되는 색상 속성은 다음과 같다.
- `background` : 화면의 기본 배경색
- `primary` : 기본 강조 색상 (예: 버튼이나 링크의 기본 색상)
- `card` : 카드나 상단 바의 배경색
- `text` : 텍스트의 색상
- `border` : 테두리 색상
- `notification` : 알림의 색상 (예: 알림 배지)

## `theme` prop 사용 예시
아래는 `theme` prop 을 이용해 다크 테마를 기본으로 적용하고, 일부 색상을 커스터마이징하는 예시이다.

#### 기본 테마를 커스텀 하고자 할 때는 `DefaultTheme` 사용
```js
import { NavigationContainer, DefaultTheme } from '@react-navigation/native';

const MyDarkTheme = {
  ...DefaultTheme, // 기본 테마 설정을 가져오고
  colors: {
    ...DefaultTheme.colors, // 기본 테마 색상들을 복사한 후
    background: '#000',      // 배경색을 검정색으로 변경
    text: '#FFFFFF',         // 텍스트를 흰색으로 변경
    primary: '#FBF15B',      // 강조 색상을 사용자 지정 색상으로 설정
  },
};

export default function App() {
  return (
    <NavigationContainer theme={MyDarkTheme}>
      {/* 하위 내비게이터와 화면들이 여기 포함됨 */}
    </NavigationContainer>
  );
}
```

#### 다크 테마를 적용하고자 할 때는 `DarkTheme` 사용

```js
import { NavigationContainer, DarkTheme } from '@react-navigation/native';

const MyCustomDarkTheme = {
  ...DarkTheme, // 기본 다크 테마 설정을 가져오고
  colors: {
    ...DarkTheme.colors, // 다크 테마의 색상을 복사한 후
    background: '#000',   // 배경색을 더 어둡게 설정
    text: '#FFFFFF',      // 텍스트를 흰색으로 설정
    primary: '#FBF15B',   // 주요 색상을 사용자 지정 색상으로 설정
  },
};

export default function App() {
  return (
    <NavigationContainer theme={MyCustomDarkTheme}>
      {/* 하위 내비게이터와 화면들이 여기 포함됨 */}
    </NavigationContainer>
  );
}
```


## 언제 `theme` prop 을 사용하는가?
- 앱 전체에서 **일관된 색상 스타일**을 유지하고 싶을 때
- 앱의 **다크 모드** 또는 **라이트 모드**를 쉽게 전환할 수 있도록 하고 싶을 때
- **커스텀 테마**를 통해 앱만의 개성 있는 스타일을 부여하고자 할 때

## 커스텀 테마를 사용하는 장점
`theme` prop 을 통해 테마를 설정하면, 앱의 모든 화면과 내비게이션 관련 요소들이 이 테마가 자동으로 적용된다. 이렇게 하면 매 화면마다 별도로 스타일을 지정할 필요 없이, `NavigationContainer` 에서 지정한 테마가 일괄적으로 적용되므로 **코드의 간결성**과 **유지보수성**이 높아진다.
