React Navigation에서 BottomTabNavigator와 스택 네비게이션의 문제 해결
===

## 문제

### 😭 이전 방식
`App.js` 에서 Stack.Navigator 에 `HomeScreen` 추가
- `Character.jsx` 에서 `navigation.navigate('Home')` 으로 이동

### 😭 결과적으로..
- `HomeScreen` 이 독립된 스크린으로 작동
- **BottomTabNavigator** 와 연결되지 않음
- 바텀 탭이 표시되지 않아 탭 네비게이션 기능을 사용할 수 없음

## 해결방법

### 1. `App.js` 에서 Home 제거
- `BottomTabNavigator` 를 통해 `HomeScreen` 을 관리하도록 설정
- 모든 `Home` 관련 이동은 `BottomTabNavigator` 로 통합

### 2. `Character.jsx` 에서 명시적으로 `Home` 탭을 지정

```js
onPress={() => navigation.navigate('Main', { screen: 'Home' })}
```
- `Main`(= `BottomTabNavigator`) 네비게이터 내부의 `Home` 탭으로 이동

### 3. `App.js` 에서 스택으로 직접 이동하지 않음
- 스택 네비게이에서 `HomeScreen` 을 독립적으로 관리하지 않고, `BottomTabNavigator` 를 통해 관리


## 현재 구조의 동작

### 1. App.js
- `Main`(`BottomTabNavigator`) 을 통해 바텀 탭 네비게이션을 관리
- 모든 Home 관련 이동은 `BottomTabNavigator` 내부에서 처리

### 2. Character.jsx
- `navigation.navigate('Main', { screen: 'Home' })`로 `HomeScreen`에 정확히 이동.

## 결론

### 🔥 예전 방식
- `Stack.Navigator` 를 통해 `HomeScreen` 으로 직접 이동
- 바텀 탭 네비게이션 무시

### 🔥현재 방식
- `BottomTabNavigator` 를 통해 `HomeScreen` 을 통합적으로 관리
- `Character.jsx`에서 `navigation.navigate('Main', { screen: 'Home' })`로 명시적으로 이동.

#### 이 방식의 장점
1. 바텀 탭이 항상 유지됨
2. 네비 구조가 더 명확하고 일관성 있게 동작

### 적용 후 코드 예시

##### App.js
```js
<Stack.Navigator>
  <Stack.Screen name="Start" component={Start} />
  <Stack.Screen name="Questions" component={Questions} />
  <Stack.Screen name="Character" component={Character} />
  <Stack.Screen name="Main" component={BottomTabNavigator} />
</Stack.Navigator>

```

#### Character.jsx

```js
onPress={() => navigation.navigate('Main', { screen: 'Home' })}
```