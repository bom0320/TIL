SafeAreaView란
===
`SafeAreaView` 는 React Native 에서 제공하는 기본 컴포넌트로, **화면의 안전 영역을 고려하여 콘텐츠가 겹치지 않도록 해주는 역할**을 한다. `safeAreaView` 는 특히 **노치가 있는 기기**나 **상단 상태 바, 하단 바가 있는 기기** 에서 유용하게 사용된다.

## 역할과 특징

#### 안전한 영역 보장
- ios 에서는 홈 화면의 상단이나 하단에 카메라나 센서가 있는 기기(예: iphone X 이후 모델)에서 콘텐츠가 겹치지 않도록, Android 는 상태 바와 겹치지 않도록 한다.

#### 자동 레이아웃 조정
- `SafeAreaView`  를 사용하면, 기기별로 안전 영역을 자동으로 계산해주기 때문에 추가적인 레이아웃 설정이 없어도 콘텐츠가 안전하게 표시된다.

#### 배경색 설정
- `SafeAreaView` 의 스타일을 통해 배경색을 설정할 수 있어, 전체 화면의 배경색을 설정할 때 유용하다.

```js
import { SafeAreaView, StyleSheet } from 'react-native';

export default function App() {
  return (
    <SafeAreaView style={styles.container}>
      {/* 앱의 내용이 안전 영역 안에 위치하게 됩니다 */}
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#000',
  },
});
```

### `SafeAreaView` 가 필요한 이유
- 모든 기기가 동일한 화면 레이아웃을 가지고 있지 않기 때문에, `SafeAreaView` 를 사용해 안전 영역 내에서 콘텐츠가 표시되도록 하는 것이 중요하다. 특히 ios 기기에서는 상단 노치나 하단 제스처 바가 있는 경우가 많아서 `SafeAreaView` 가 없으면 콘텐츠가 겹치게 되어 UI 가 엉망이 될 수 있다.


#### 요약
`SafeAreaView` 는 기기마다 다른 안전 영역을 고려해 콘텐츠가 화면 내에서 안전하게 배치되도록 하는 레이아웃 컨테이너이다. 특히 배경색을 적용할 때도 유용하다.