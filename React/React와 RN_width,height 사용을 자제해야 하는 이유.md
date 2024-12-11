📚 React와 React Native: width, height 사용을 자제해야 하는 이유
===

## 1. 고정된 크기의 문제점
- `width` 와 `height` 를 픽셀 단위(`px`)로 고정하면, **화면 크기가 다른 디바이스**에서 레이아웃이 깨질 수 있음
- 예: 작은 홤녀에서는 요소가 잘리거나, 부모보다 자식 요소가 더 커지는 문제 발생
- **부모 요소가 반응형**으로 크기를 조정해도, 고정된 자식 요소는 크기를 조정하지 않아 디자인이 **불균형**하게 보일 수 있음

---

## 2. RN 에서의 문제
- React NAtive 는 다양한 모바일 디바이스(화면 크기, 해상도)가 있기 때문에 고정 크기로 인해 레이아웃이 어긋날 가능성이 높음
- 모바일 앱에는 **다양한 화면 크기에 적응**하는 반응형 레이아웃이 필수
- 고정값(`px`) 대신 **Flexbox** 를 사용해 부모와 자식 간의 크기와 배치를 유연하게 설정해야한다.

---

## 3. React 에서의 문제
- React 에서도 데스크톱, 태블릿, 모바일 등 **다양한 화면 크기**를 지원해야 하기 때문에 고정값 사용은 비효율적
- 특히, `width`, `height` 에 고정값을 사용하면 반응형 웹에서 레이아웃이 깨지거나 어색해질 수 있다.
- **미디어 쿼리, Flexbox, CSS Grid** 같은 도구를 사용해 화면 크기에 따라 유연하게 조정해야한다.

---

## 4. Flexbox 를 사용해야 하는 이유

### 1. 부모-자식 간 크기 조정:
- Flexbox 는 부모 요소의 크기를 기준으로 자식 요소의 크기와 위치를 **자동으로 조정**

### 2. 다양한 화면 크기에 적응:
- 고정된 값 대신 비율(`flex`) 을 사용해 반응형 레이아웃을 구현

### 3. 위치 문제 해결:
- 부모와 자식 요소의 정렬, 배치를 효율적으로 관리 가능

---

## 5. 해결 방법

### 1. React 와 RN 에서 고정값 대신 Flexbox 사용

```jsx
<div style={{ display: 'flex', justifyContent: 'space-around', alignItems: 'center' }}>
  <div style={{ flex: 1, backgroundColor: 'lightblue' }}>Box 1</div>
  <div style={{ flex: 1, backgroundColor: 'lightgreen' }}>Box 2</div>
</div>

```

### 2. 반응형 단위 사용 (`%`,`vw`,`vh`):

```jsx
<div style={{ width: '50%', height: '30vh', backgroundColor: 'lightblue' }}></div>
```

### 3. 미디어 쿼리 활용 (React) :

```css
@media (max-width: 768px) {
  .container {
    flex-direction: column;
  }
}
```

---

## 6. 결론
- React 와 RN 에서는 `width`, `height` 의 고정값 사용을 지양하고, **반응형 설계**를 위한 Flexbox, CSS Grid, 또는 유연한 단위를 사용하는 것이 중요
- 고정값을 사용할 경우, 다양한 디바이스에서 레이아웃 문제가 발생할 수 있으므로, **화면 크기에 따라 조정 가능한 방식**으로 레이아웃을 설계해야 함