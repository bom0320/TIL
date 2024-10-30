Flexbox 정렬 속성
===

## `justify-content` (주 축 정렬)
- **기능 :** 주 축을 따라 아이템들을 어떻게 배치할지 결정
- **사용 상황 :** 주 축 방향에서 아이템 간의 간격을 조정할 때
- **주요 값:**
    - `flex-start` : 시작 지점에 정렬
    - `flex-end` : 끝 지점에 정렬
    - `center` : 중앙에 정렬
    - `space-between` : 아이템 사이에 동일한 간격
    - `space-around` : 아이템 주변에 동일한 간격

## `align-items` (교차 축 정렬)
- **기능:** 교차 축을 따라 아이템들을 어떻게 배치할지 결정
- **사용 상황 :** 교차 축 방향에서 아이템들이 위, 아래 또는 중앙에 정렬되도록 할 때,
- **주요 값:**
    - `flex-start` : 시작 지점에 정렬
    - `flex-end` : 끝 지점에 정렬
    - `center` : 중앙에 정렬
    - `stretch` : 교차 축에 맞게 아이템 크기 늘리기 (기본 값)

--- 

### Flexbox 기본 설정
- `display: flex;` : Flexbox 레이아웃 활성화
- `flex-direction` : 주 축 방향 설정
    - `row` : 가로 방향 (기본값)
    - `column` : 세로 방향

#### Example Code

#### 1. 가로 방향 + 왼쪽 정렬

```css
.container {
  display: flex;
  flex-direction: row;
  justify-content: flex-start;
}
```


#### 2. 세로 방향 + 중앙 정렬

```css 
.container {
    display: flex;
    flex-direction: column;
    justify-content: center;
}
```

#### 3. 가로 방향 + 가로 정렬, 교차 축 중앙 정렬

```css
.container {
  display: flex;
  flex-direction: row;
  justify-content: center;
  align-items: center;
}
```