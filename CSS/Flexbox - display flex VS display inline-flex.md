Flexbox - `display: flex;` 와 `display: inline-flex;` 차이 정리
===

## 1. display: flex
- **컨테이너가 화면의 전체 가로 너비를 차지** 하는 **블록 요소**로 동작.
- 여러 개의 `display: flex;` 컨테이너가 있으면, 각 컨테이너가 **한 줄을 차지**하게 되어 **세로로 쌓인 형태**로 보임
- 주로 큰 섹션을 레이아웃할 때 유용.

## 2. display: inline-flex
- **컨테이너가 필요한 만큼의 공간만 차지**하는 **인라인 요소** 로 동작
- 여러 개의 `display: inline-flex;` 컨테이너가 있으면 **한 줄에 가로로 나란히** 배치될 수 있다.
- 작은 UI 요소들(버튼, 아이콘 등) 배치에 적합

---

### 추가 정보 - 정렬 방향 속성
- **가로 / 세로 정렬 방향** 은 `display` 속성으로 결정되지 않고 `flex-direction` 속성으로 설정됨:
    - `flex-direction: row` -> 아이템이 **가로로 정렬**
    - `flex-direction : column` -> 아이템이 세로로 정렬

---

### 요약
- `display: flex` : 화면 전체 너비를 채우기 때문에 **컨테이너가 세로로 쌓인 형태**
- `display: inline-flex` : 필요한 공강만 차지하여 **가로로 나란히 정렬된 형태**