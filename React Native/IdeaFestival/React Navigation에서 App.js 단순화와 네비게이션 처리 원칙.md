React Navigation에서 App.js 단순화와 네비게이션 처리 원칙
===

## 1. App.js 의 역할
App.s 는 **앱의 전체 네비게이션 구조를 정의**한다. 

네비게이터를 생성하고, 각각의 화면(스택)을 추가하는 역할을 한다. 앱의 **"큰 틀"**을 잡는 부분이기 때문에, **복잡한 로직이나, 페이지 간의 세부적인 네비게이션 처리**는 포함하지 않는 것이 좋다.

### App.js 의 구성 요소

#### 🍅 NavigationContainer
- 앱에서 사용할 네비게이션을 정의하는 최상위 컨테이너이다. 
- 모든 네비게이터를 감싸는 역할을 한다.

#### 🍅 Stack.Navigator
- 스택 네비게이터를 사용해 화면을 쌓고, 이동한다.

#### 🍅 각 화면의 Stack.Screen 정의
- 화면을 등록하고, 어떤 컴포넌트를 렌더링할지 결정한다.

## 2. 네비게이션 처리의 적절한 위치
`App.js` ***는 큰틀에서 네비게이션을 정의**하는 역할만 하고, 구체적인 동작은 각 컴포넌트(페이지)에서 처리해야 한다.

### 이유:
1. 코드가 복잡해지는 것을 방지
2. 각 컴포넌트에서 자신만의 동작을 처리할 수 있도록 분리
3. 유지보수와 확장이 더 쉬워짐

## 3. 네비게이션 처리의 흐름

#### App.js
```js
<Stack.Navigator>
  <Stack.Screen name="Start" component={Start} />
  <Stack.Screen name="Questions" component={Questions} />
  <Stack.Screen name="Character" component={Character} />
  <Stack.Screen name="Main" component={BottomTabNavigator} />
</Stack.Navigator>
```
- `Start`, `Questions`, `Character`, `Main` 을 등록
- 각 화면은 페이지로 이동하는 "큰 틀"을 제공한다.

### 각 페이지에서 네비게이션 처리
예를 들어, `Character.jsx` 에서는
```js
onPress={() => navigation.navigate('Main', { screen: 'Home' })}
```
- `navigation.navigation()` 를 사용하여 화면 전환을 처리한다.
- `Main`(= `BottomTabNavigator`) 로 이동하면서, `screen: 'Home'` 으로 특정 탭을 명시한다.

## 4. 단순하고 효율적인 App.js 구성
현재처럼 `App.js` 를 간단히 구성하고, **각 페이지에서의 네비게이션 처리**를 맡기는 방식이 이상적이다. 


### 장점
1. **구조가 명확**
- `App.js` 는 네비게이터만 정의
- 각 페이지는 자신의 동작만 관리

2. **유지보수 용이**
- 페이지 간의 복잡한 논리를 페이지 자체에서 관리하기 때문에, 특정 페이지의 동작을 수정할 때, 전체 네비게이터를 건들일 필요가 없음

3. **확장성 :**
- 새로운 페이지나 네비게이터를 추가할 때 구조가 단순하므로 쉽게 확장 가능

## 5. 결론

🔥**`App.js` 는 최대한 간단하게 유지하자 !**
App.js 에는 네비게이터 구조만 정의하고, 페이지 간 이동의 "큰 틀"만 설정한다.

🔥**페이지 간 네비게이션은 각 페이지에서 처리 !**
`navigation.navigate()` 등으로 처리할 수 있고, 페이지 간 네비는 각 페이지에서 처리하면, 명확하고 직관적인 코드 작성이 가능하다.