React Native Navigation 기본 패키지
===
React Navigation 을 사용하기 위해서는 React Navigation 관련 패키지를 설치해야한다. 다음 명령어들을 차례대로 실행하여 필요한 패키지들을 설치해보자

### 1. React Navigation 핵심 패키지 설치:

```bash
npx expo install @react-navigation/native
```

### 2. 필요한 추가 패키지들 설치:
-  React Navigation 은 네비게이션과 관련된 추가 패키지가 필요하다.

```bash
npx expo install @react-navigation/stack
```

### 3. React Navigation 이 필요로 하는 종속성 설치:
- `@react-navigation/native` 패키지는 추가적인 Expo 패키지 종속성이 필요하다.

```bash
npx expo install react-native-screens react-native-safe-area-context
```