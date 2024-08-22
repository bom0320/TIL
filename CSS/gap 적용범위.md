gap 적용 범위
===
`gap` 을 어디에 적용할지 결정하는 것은 레이아웃의 구조와 의도에 따라 다르다. `gap` 은 주로 Flexbox 나 CSS Grid 레이아웃의 컨테이너 요소에 적용된다. 아래에서 이 원칙을 구체적으로 살펴봐보자

## 1. 컨테이너(Container) 의 개념 이해하기
- 컨테이너란 다른 요소들이 감싸고 있는 부모 요소를 말한다. 
- Flexbox 와 CSS Gird 레이아웃에서 `gap` 속성은 이 컨테이너에 설정한다.

## 2. 어떤 컨테이너에 `gap` 을 적용할지 결정하기
- **Flexbox 컨테이너에 `gap` 적용:**
    - Flexbox 를 사용하는 경우, `display: flex;` 를 설정한 부모 요소가 컨테이너가 된다.
    - 이 컨테이너에 `gap` 을 설정하면, 그 안에 배치된 모든 자식 요소들 사이에 동일한 간격이 적용된다

```
.flex-container {
    display: flex;
    gap: 20px;
}

```
- 이 예시에서 `.flex-container` 가 컨테이너고, `gap: 20px;` 이 설정되어 있으면, `.flex-container` 안에 있는 모든 자식 요소들 사이에 20px 의 간격이 생긴다.

- **CSS Gird 컨테이너에서 `gap` 적용:**
- CSS Grid 를 사용하는 경우, display: grid; 를 설정한 부모 요소가 컨테이너가 된다.
- 이 컨테이너에 `gap` 을 설정하면, 행과 열 사이에 동일한 간격이 적용된다.
```
.grid-container {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 20px;
}
```
- 이 예시에서 `.grid-container` 는 컨테이너이고, `gap: 20px;` 이 설정되어 있으면, `.grid-container` 안의 모든 그리드 아이템들 사이에 20px 의 간격이 적용된다.

## 3. 어디까지 `gap` 을 적용해야 하는지 결정하기
- **전체 레이아웃의 간격을 조정하려는 경우:**
    - gap 을 레이아웃 전체르의 간격을 조정하고 싶다면, 가장 상위 레벨의 컨테이너에 gap 을 설정한다.
- **특정 요소들 사이의 간격을 조정하려는 경우**
    - 특정 요소 그룹 사이에만 간격을 설정하고 싶다면, 해당 그룹을 감싸는 컨테이너에 gap 을 적용해야 한다.

## 예시로 이해하기:

### 예시 1: 버튼 그룹

만약 여러 개의 버튼이 가로로 나란히 배치된 상황에서 이들 사이의 간격을 조정하고 싶다면, 이 버튼들을 감싸는 컨테이너에 `gap`을 설정한다.

```html
html코드 복사
<div class="button-group">
    <button>Button 1</button>
    <button>Button 2</button>
    <button>Button 3</button>
</div>

```

```css
css코드 복사
.button-group {
    display: flex;
    gap: 10px; /* 버튼들 사이의 간격을 10px로 설정 */
}

```

### 예시 2: 카드 레이아웃

만약 여러 개의 카드를 그리드로 배치하고, 카드들 사이의 간격을 조정하고 싶다면, 카드들을 감싸는 그리드 컨테이너에 `gap`을 설정한다.

```html
html코드 복사
<div class="card-container">
    <div class="card">Card 1</div>
    <div class="card">Card 2</div>
    <div class="card">Card 3</div>
</div>

```

```css
css코드 복사
.card-container {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 20px; /* 카드들 사이의 간격을 20px로 설정 */
}

```

### 결론:

`gap`을 어디에 설정할지는 요소들 사이의 간격을 설정하고자 하는 **컨테이너**가 어디에 있는지에 따라 결정된다. 간단히 말해, **어떤 요소들 사이의 간격을 설정하고 싶은지** 생각하고, 그 요소들을 감싸는 부모 컨테이너에 `gap`을 설정하면 됨