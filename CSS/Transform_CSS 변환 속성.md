Transform: CSS 변환 속성
===

## Transform 이란?
- CSS의 `transform` 속성은 **요소를 이동(translate), 회전(rotate), 크기 변경(scale), 기울이기(skew)** 등의 변환을 할 수 있는 속성이다.
- **시각적인 변화를 적용**하지만, 문서의 기본 흐름(레이아웃)에는 영향을 주지 않는다.

## 주요 기능

### 1. 이동 (Translate)
- 요소는 X출 또는 Y 축 방향으로 이동한다.

```css
transform: translateX(20px); /* X축으로 20px 이동 */
transform: translateY(-10px); /* Y축으로 위로 10px 이동 */
transform: translate(20px, -10px); /* X축 20px, Y축 -10px 이동 */
```

### 2. 크기 변경 (Scale)
- 요소의 크기를 조정한다.

```css
transform: scale(1.5); /* 1.5배 확대 */
transform: scale(1, 0.5); /* X축 1배, Y축 0.5배 축소 */
```

### 3. 회전 (Rotate)
- 요소를 시계 방향으로 회전한다.

```css
transform: rotate(45deg); /* 45도 회전 */
transform: rotate(-90deg); /* -90도 반시계 방향 회전 */
```

### 4. 기울이기 (Skew)
- 요소를 X출 또는 Y축 방향으로 기울인다. 

```css
transform: skewX(30deg); /* X축으로 30도 기울임 */
transform: skewY(-20deg); /* Y축으로 -20도 기울임 */
transform: skew(30deg, -20deg); /* X축 30도, Y축 -20도 기울임 */
```

### 5. 복합 변환
- 여러 변환을 조합해서 사용할 수 있다.

```css
transform: translate(20px, -10px) scale(1.2) rotate(45deg)
```

## Transform 의 특징
- **문서 흐름에 영향을 주지 않음 :** 요소가 이동하거나 변환되어도 **기존 공간은 그대로 유지**된다. 
- **정밀한 제어 가능 :** 픽셀(px) 또는 비율(%) 단위로 요소의 이동과 변환을 세밀하게 조정할 수 있다.
- **애니메이션과 잘 어울림 :** `transition` 또는 `@keyframes` 와 함께 사용해 부드러운 변환 효과를 만들 수 있다.

### 예제 코드

```css
<div class="box">Transform Example</div>

<style>
  .box {
    width: 100px;
    height: 100px;
    background-color: lightblue;
    transform: translate(20px, 10px) scale(1.5) rotate(30deg);
  }
</style>
```
- 이 코드는 요소를 X축으로 20px, Y축으로 10px 이동시키고, 크기를 1.5배 확대한 후 30도 회전시킨다.

## Transform VS Position

### Transform
- 문서의 흐름을 깨지 않고 요소의 **시각적 위치와 모양만 변경**한다.
- 위치, 크기, 회전, 기울임 등의 다양한 변환 가능

### Position
- 문서 흐름을 변경하거나, 요소의 배치 기준을 설정하는 데 사용
- `relative`, `absolute` 등과 함께 특정 기준을 활용해 이동

## **사용 사례**

1. UI 요소의 이동, 회전, 확대/축소.
2. 버튼 클릭 시 시각적 강조 효과.
3. 애니메이션을 활용한 인터랙션 디자인.

---

## **추가 학습**

1. `transition`과의 조합으로 부드러운 효과 만들기.
2. 3D 변환(`translateZ`, `rotate3d`)을 활용한 고급 인터페이스 디자인.
3. 반응형 웹에서 `transform`을 활용한 최적화된 레이아웃 조정.

---

### 요약
`transform` 은 요소를 이동, 회전, 확대/축소 등으로 변환해 **시각적 효과를 더하는 강력한 도구**이다. 레이아웃 흐름을 유지하면서도 정밀한 제어가 가능하므로, 애니메이션과 동적 UI 디자인에 특히 유용한다.