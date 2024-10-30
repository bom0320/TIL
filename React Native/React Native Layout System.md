React Native Layout System
===

## 1. 기본 Flex Container
- React Native 의 모든 `view` 는 **기본적으로 Flex Container** 이다.
- **Flex Direction 기본값 :** `column` (웹의 기본값이 `row` 인 것과 다름).

## 2. 반응형 디자인 고려
- 다양한 기기에서 **일관된 레이아웃** 을 위해 `width` 와 `height` 를 사용하지 않고, 반응형으로 디자인해야함 
- 아이콘이나 아바타 같은 **작은 요소**에 `width` 나 `height` 를 쓸 수 있지만, 레이아웃 전체에는 피해야 함
- 스크린 크기가 다양하기 때문에 `width`와 `height` 가 아닌 **비율**에 기반한 레리아웃 설계가 중요

## 3. Flex 기반 레이아웃
- React Native 에서 **숫자만 사용해도 비율 설정이 가능**하다.
- 모든 `View` 는 Flex Container 이므로, `flex` 속성만으로 영역을 차지하게 할 수 있음 
- ex) 부모 `View` 안에 자식 `View` 3개가 이다면 각각 `flex: 1` 로 설정해 **동일한 비율** 을 차지하게 만들 수 있음

## 4. 중요한 규칙
- **부모의 Flex 설정**이 중요함. 부모 `View` 에 `flex: 1` 을 설정해 기준을 정해줘야 함
- 부모의 `flex` 값이 자식보다 크면 안 됨. 이 규칙을 지켜야 **비율이 제대로 적용**됨

## 5. 모바일 레이아웃의 편리함
- React Native 는 모든 `View` 가 **기본적으로 Flex Container** 로 설정되어 있어 `display: flex` 를 지정할 필요가 없음
- Flex Direction 은 기본 `column` 이지만 필요에 따라 `row` 로 변경할 수 있다.
