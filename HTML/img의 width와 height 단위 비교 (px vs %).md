img 의 width와 height 단위 비교 (px vs %)
===
`<img>` 태그에서 사용하는 width 와 height 의 **픽셀(px)** 과 **퍼센트(%)** 단위는 이미지 크기를 조정하는 방식에 차이가 있다. 각 단위의 특징과 적합한 상황을 정리해보자

## 1. 픽셀 ( px )

### 특징:
- 고정된 크기를 지정한다.
- 이미지를 항상 **정확한 크기**로 렌더링한다.
- 화면 크기와 상관없이 동일한 크기로 표시된다.

### 장점
- 크기가 명확하게 고정되므로 예상한 크기로 정확하게 출력된다.
- 레이아웃이 복잡하거나 고정된 디자인에서 유용하다.

### 단점
- 반응형 웹에서 비율을 유지하지 못하면 작은 화면(예: 모바일)에서 크기가 잘리거나 불편할 수 있다.
- 화면 해상도나 디바이스에 따라 고정된 크기가 부자연스럽게 보일 수 있다.

#### 사용 예제:
```html
<img src="example.jpg" width="300px" height="200px">
```
- 이미지 크기를 300px x 200px 로 고정

### 적합한 상황:
- **정확한 크기**가 중요한 경우(예: 아이콘, 썸네일)
- 레이아웃에서 이미지 크기가 변경되지 않아야 할 때

---

## 2. 퍼센트( % )

### 특징
- 이미지를 부모 요소의 크기에 따라 **상대적으로 크기**를 조정한다.
- 반응형 레이아웃에서 유용하다.

### 장점
- 다양한 화면 크기에서 유연하게 크기가 조정된다.
- 반응형 디자인을 구현할 때 효과적이다.

### 단점
- 부모 요소의 크기에 의존하므로 예상치 못한 크기로 렌더링도리 수 있다.
- 부모 요소가 크기 정보를 제대로 가지고 있어야 의도대로 동작한다.

#### 사용 예제:
```html
<img src="example.jpg" width="50%" height="auto">
```
- 부모 요소의 너비의 50%에 맞게 이미지 크기를 조정
- `height="auto"` 를 사용하면 이미지의 비율을 유지하면서 높이가 자동으로 조정된다.

### 적합한 상황:
- **반응형 웹** 디자인
- 화면 크기에 다라 이미지 크기가 유연하게 변해야 할 때

## **3. 픽셀(px) vs 퍼센트(%) 요약**

| **특징** | **픽셀(px)** | **퍼센트(%)** |
| --- | --- | --- |
| **크기** | 고정 크기 | 부모 요소에 상대적인 크기 |
| **반응형** | 반응형에 부적합 | 반응형 디자인에 적합 |
| **적합한 상황** | 고정 크기가 필요한 레이아웃 (예: 아이콘) | 화면 크기에 따라 유동적인 이미지 |
| **유연성** | 유연하지 않음 | 유연함 |
---


## 4. 어떤 상황에 뭘 써야 할까?

### 1. 고정딘 크기(정확한 크기)가 중요할 때:
- **픽셀(px)** 사용
- 예: 로고, 아이콘, 프로필 사진 등

### 2. 반응형 웹 디자인일 때:
- **퍼센트(%)** 사용
- 예: 배너 이미지, 콘텐츠 내 이미지 등 화면 크기에 따라 크기가 유동적으로 변해야 할 때

### 3. 비율 유지가 필요할 때:
- **`width` 와 `height` 를 함께 지정하지 않고, `auto` 를 사용**해 비율을 유지한다.

```html
<img src="example.jpg" width="100%" height="auto">
```
- 부모 요소에 맞춰 이미지 비율 유지