The Rules of Native
===

## 1. React Native는 웹사이트가 아니다.
- HTML 이 아니기 때문에 div 를 쓸 수 없고, View 를 써야됨 ( => 항상 import 해야됨 )

```js
- import { StyleSheet, Text, View } from 'react-native'
```

- View 는 Container 임

## 2. React Native 에 있는 모든 text 는 text Component 에 들어가야 함

## 3. View 에 style 이 있고, 원하는대로 styles 가능
=> 이건 웹의 react.js 에서 할 수 있는 것과 비슷함 (하지만 전부는 X)

## 4. StyleSheet.create
- 이는 object 를 생성하는 데 사용함.
    ### 이유 1)
    - 아주 좋은 자동 완성 기능 제공
    ### 이유 2)
    - 따로 빼줌으로서 style 이 거대해지는 걸 방지 (따라서 일반적으로 스타일을 StyleSheet 에 구분하고, component 를 위에 써줌)

## 5. status bar(상태표시줄) => (시계, 인터넷, 배터리 등을 표시, 운영체제와 소통하는 component라는 증거)