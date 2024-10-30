주 축, 교차 축, 정렬 속성 요약 정리
===

## 1. `flex-direction`
- **주 축** 을 수평(row) 으로 할지, 수직(column) 으로 할지 **!!여부!!!** 를 결정하는 속성이다.
- 예를 들어, `flex-direction: row;` 로 설정해주면 주 축이 **가로 방향** 이 되어 아이템들이 가로로 정렬된다.


- 그니까 `flex-direction` 을 책을 꽃는 **책꽃이의 방향**이라고 생각해보자. 
    - 책꽃이가 가로로 놓여 있으면(`flex-direction: row`), 책들이 가로로 줄지어 배치된다.
    - 책꽃이가 세로로 세워져 있으면(`flex-direction: column`), 책이 세로로 위아래로 쌓이며 배치된다.

---

## 2. `justify-content`
- 주 축을 따라 아이템을 어디에 배치할지 결정한다.
- 예를 들어, `flex-direction: row;` 상태에서 `justify-content: flex-start` 로 설정하면 아이템들이 **주 축의 시작 시점(왼쪽)**에 정렬된다.
- 반대로 `justify-content: flex-end;` 로 설정하면 아이템들이 **주 축의 끝 지점(오른쪽)**에 정렬된다.

- **`justify-content`**: 책꽂이 안에서 책의 가로 위치를 정하는 속성 (왼쪽, 오른쪽, 가운데).

---

## 3. `align-items`
- 교차 축을 따라 아이템을 어디에 배치할지 결정한다.
- 만약 `flex-direction: row;` 상태에서 `align-items: flex-end;` 를 설정하면, **교차 축(세로 방향)의 끝 지점(하단)**에 아이템들이 정렬된다.

- **`align-items`**: **책꽂이 안에서 책의 세로 위치**를 정하는 속성 (위, 아래, 중앙).