Component 와 API
===

React Native 에서는 Component 와 API 라는 두 가지 개념이 중요하게 사용된다. 

Component 는 **화면에 렌더링할 항목**이며, 일반적으로 `View`, `Text`, `Image` 등과 같은 것들이 있다. Component 는 JSX 형태로 작성되며, return 안데 포함되어 
있어야 한다. BUT! return 안에 있는 것이 화면에 반드시 렌더링 되어야 하는 것은 아니다.


반면에, API 는 **자바스크립트 코드로 작성된 기능을 의미**한다. 예를 들어, Vibration API 는 사용자 디바이스를 진동시키는 기능을 제공한다. 이러한 API 는 React Native 애플리케이션에서 자주 사용된다.

다음은 React Native의 Vibration API 를 사용하여, 디바이스를 진동시키는 코드 예시이다.

```js
import React from 'react';
import { View, Button, Vibration } from 'react-native';

const VibrationExample = () => {
  const handleVibrate = () => {
    Vibration.vibrate([500, 1000, 500, 2000]); // 진동 패턴 설정
  };

  return (
    <View>
      <Button title="Vibrate" onPress={handleVibrate} />
    </View>
  );
};

export default VibrationExample;
```
- 위 코드에서는, `Vibration` 모듈을 import 하고, `Button` Component 를 렌더링한다.
- `Button` Component 를 클릭하면 `handleVibrate` 함수가 실행된다.
- `handleVibrate` 함수에서는 `Vibration.vibrate` 메서드를 호출하여, 디바이스를 진동시키는 패턴을 설정한다.
- 이 예제에서는 `[500, 1000, 500, 2000]` 와 같이 배열 형태로 진동 패턴을 설정하였다.
    - 이 배열은 짝수 인덱스에서는 진동이 울리는 시간(ms) 을, 홀수 인덱스에서는 진동이 멈추는 시간(ms) 을 의미한다.
- 위 코드를 실행하면, 화면에 `Vibrate` 라는 버튼이 보이고, 버튼을 클릭하면 설정한 진동 패턴에 따라 디바이스가 진동한다.


위 예시에서 사용된 Component 는 `View` 와 `Button` 이다. 
- **`View` Component :** React Native 에서 가장 기본적인 Component 중 하나이며, UI 를 구성하는 데 사용된다. 
- **`Button` component :** 사용자와 상호작용할 수 있는 클릭 가능한 버튼을 만드는 데 사용된다.

API 로는 `Vibration` 모듈이 사용되었다.

`Vibration` 모듈은 React Native 에서 제공하는 API 중 하나로, 디바이스를 진동시키는 기능을 제공한다. `vibrate` 메서드를 사용하여, 진동 패턴을 설정하고, 디바이스를 진동시킬 수 있따. 이러한 API 를 사용하여, React Native 애플리케이션에서 다양한 기능을 추가할 수 있다.

## return 안에 잇어도 화면에 렌더링되지 않는 Component?
React Native 의 일부 Component 는 return 안에 있어도 화면에 렌더링 되지 않는다.

이러한 Component 는 ios 및 Android 운영 체제와 소통하는 역할을 담당한다. 예를 들어, Expo 에서 제공하는 `expo-status-bar` 패키지가 그렇다.

`expo-status-bar` 패키지는
```
expo install expo-status-bar
```
이 명령어를 사용하여 설치할 수 있다.

다음은 스테이터스 바(Status Bar) 를 구현하는 코드 예시이다.

```js
import React from 'react';
import { View } from 'react-native';
import { StatusBar } from 'expo-status-bar';

const MyScreen = () => {
  return (
    <View>
      <StatusBar style="auto" />
      {/* 나머지 컴포넌트들 */}
    </View>
  );
};

export default MyScreen;
```
- 위 코드에서는, `expo-status-bar` 패키지에서 제공하는 `StatusBar` Component 를 import 하고, `View` Component 내부에서 `StatusBar` Component 를 사용하여 스테이터스 바를 구현한다. 
- `StatusBar` Component 의 `style` prop 에 `auto`를 전달하여, 스테이터스 바의 색상을 자동으로 설정하도록 한다.


`StatusBar` Component는 React Native 에서 화면에 표시되지 않고, ios 와 Android 운영체제와 소통하는 역할을 한다. 따라서, `StatusBar` Component 를 사용하여 설정한 스테이터스 바의 스타일은 앱의 전반적인 UI 에 영향을 미치지만, 화면에 직접적으로 표시되지는 않는다.


React Native 애플리케이션에서는 `StatusBar` Component 를 사용하지 않아도 기본적으로 상단에 스테이이터스 바가 표시된다. 하지만, `StatusBar` Component 를 사용하면 스테이터스 바의 색상, 밝기, 투명도 등 다양한 스타일을 설정할 수 있다. 또한, `hidden` prop 을 사용하여 스테이터스바를 숨길 수도 있다. 따라서, `StatusBar` Component 를 사용하면 기본적인 스테이터스 바 이외의 스타일을 적용하거나, 숨길 수 있어서 좀 더 세밀한 UI 조작이 가능해진다.

### 마무리
React Native 에서 Component 와 API 는 애플리케이션 개발에서 중요한 역할을 한다. Component 는 화면을 구성하고, API는 자바스크립트를 통해 다양한 기능을 제공한다. 그리고 특정 Component 는 화면에 표시되지 않을 수 있지만, ios 및 Android 운영체제와 상호작용하는 역할을 맡는다.