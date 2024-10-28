React Native 개발이 처음인 React 갭라자들을 위해
===

React Native 는 모바일 애플리케이션 개발을 위한 자바스크립트 라이브러리로서, 웹에서 사용되는 React와 유사한 개발 방식을 취하고 있다. 하지만 우베과는 달리 네이티브 환경에서 실행되기 때문에 일부 주요 차이점이 있다. 따라서 React 에 익숙한 개발자가 React Native 로 개발할 때에는 다음과 같은 점에 유의해야 한다.


## 1. `View` 를 사용하고, `div` 를 사용하지 않는다.
React Native 에서는 웹에서 사용되는 `div` 대신 `View` 를 사용해야 한다. 이를 위해 

```js
import { View } from 'react-native'
```
을 추가해준다.

## 2. Text Component 를 사용한다.
React Native 에서는 모든 text 가 Text Component 에 들어가야 한다. `span`, `p` 등의 HTML 태그 대신 `Text`를 사용해야 한다.

## 3. React에서 사용하던 일부 style 을 사용할 수 없다.
React Native 에서는 일부 웹에서 사용하던 style 을 사용할 수 없다. 예를 들어, bolder 등의 스타일은 사용할 수 없다.

## 4. StyleSheet.create 을 사용한다. 
StyleSheet.create 함수는 인자로 전달된 객체를 받아서, 해당 객체 내부의 스타일 정보를 담은 새로운 객체를 반환한다.


StyleSheet.create 를 사용하면 컴포넌트의 스타일 정보를 한 곳에서 모아서 관리할 수 있다. 또한, StyleSheet.create 가 반환하는 객체는 변경되지 않으므로 컴포넌트가 렌더링 될 때마다 스타일 객체를 새로 생성하지 않아도 되어 성능상 이점이 있다.

## 5. Flexbox 를 사용한다
React Native에서는 Flexbox 를 사용해야 한다. `display: block`, `display: inline-block`, `display: grid` 등의 속성은 사용할 수 없으며, **Flex Direction 기본값은 Column**  이다.

## 6. Flex Direction 기본 값은 column
React 의 Flex Direction  기본값은 row 이지만, React Native 의 Flex Direction 기본값은 column 이다.

## 7. View 에 Flex Container 가 되라고 말할 필요가 없다
React Native 에서는 모든 View 가 기본적으로 Flex Container 이므로 `display: flex`를 추가할 필요가 없다.

## 8. Overflow 가 있다고 해서 스크롤할 수 있는 것은 아니다.
React Native 는 브라우저가 아니므로, overFlow 가 있다고 해서 스크롤 할 수 있는 것은 아니다. 

## 9. width 와 height 사용을 지양한다.
React Native 에서 너비와 높이에 기반에서 레이아웃을 만드는 것은 좋지 않다. 대신 Flex Size 를 사용해야 하며, Flex 부모를 만들고 자식을 원하는 비율로 조정할 수 있다. 부모의 Flex Size 가 있어야 디자인이 적용된다.

다음은 위의 유의사항을 적용한 React Native 코드 예시이다.
```js
import React from 'react';
import { StyleSheet, Text, View } from 'react-native';

export default function App() {
  return (
    <View style={styles.container}>
      <View style={styles.box1}>
        <Text style={styles.text}>Box 1</Text>
      </View>
      <View style={styles.box2}>
        <Text style={styles.text}>Box 2</Text>
      </View>
      <View style={styles.box3}>
        <Text style={styles.text}>Box 3</Text>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'row'
  },
  box1: {
    flex: 1,
    backgroundColor: 'red'
  },
  box2: {
    flex: 2,
    backgroundColor: 'green'
  },
  box3: {
    flex: 1,
    backgroundColor: 'blue'
  },
  text: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
    color: '#ffffff'
  }
});
```

위의 코드에서는 container View 가 Flex 부모이고, box1, box2, box3 는 Flex 자식이다. container View 의 flexDirection 속성을 row 로지정해주어서, box1 과 box3 가 container View 의 너비의 1/4 만큼, box2 가 1/2 만큼 차지하도록 하였다. 이렇게 Flex 부모와 자식을 이용해 레이아웃 비율을 조정할 수 있다.