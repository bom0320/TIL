React Navigation 알아보기
===
이 코드는 react Navigation 을 익히기 위한 간단한 코드 구조이다.

```lua
CLIENT
├── .expo
├── assets
├── node_modules
├── pages
│   ├── HomeScreen.js
│   └── DetailsScreen.js
├── App.js
├── app.json
├── babel.config.js
├── package-lock.json
├── package.json
└── README.md
```
`pages` 폴더 안에 파일들을 생성한 후, `App.js` 에서 `import` 하면 된다. 파일 생성 후 `npx expo start` 로 앱 실행해보자

### App.js
```js
import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import HomeScreen from './pages/HomeScreen';
import DetailsScreen from './pages/DetailsScreen';

const Stack = createStackNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName="Home">
        <Stack.Screen name="Home" component={HomeScreen} />
        <Stack.Screen name="Details" component={DetailsScreen} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}
```

### HomeScreen.js
`pages/HoneScreen.js` 파일을 생성하고 아래 내용 추가

```js
import React from 'react';
import { View, Text, Button } from 'react-native';

export default function HomeScreen({ navigation }) {
  return (
    <View>
      <Text>Home Screen</Text>
      <Button title="Go to Details" onPress={() => navigation.navigate('Details')} />
    </View>
  );
}
```

### DetailsScreen.js
`pages/DetailsScreen.js` 파일을 생성하고 아래 내용 추가

```js
import React from 'react';
import { View, Text } from 'react-native';

export default function DetailsScreen() {
  return (
    <View>
      <Text>Details Screen</Text>
    </View>
  );
}
```