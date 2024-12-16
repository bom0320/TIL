Position: CSS 위치 속성 정리
===

### 1. **`relative`**

- **특징**:
    - 요소의 "원래 위치"를 기준으로 이동.
    - 이동 후에도 **원래 자리를 유지**.
    - `top`, `left`, `right`, `bottom`으로 위치를 조정 가능.
- **사용 사례**:
    - 요소를 살짝 이동시키고, 원래 자리를 유지해야 할 때.
    - 툴팁, 강조 표시 등.
- **코드 예시**:

```html
<div class="box relative">
    position: relative
</div>
<style>
    .relative {
        position: relative;
        top: 20px; /* 아래로 20px */
        left: 10px; /* 오른쪽으로 10px */
    }
</style>

```

- **결과**:
    - 요소가 이동하지만 원래 자리 공간은 남아 있음.

---

### 2. **`absolute`**

- **특징**:
    - "부모 요소"를 기준으로 위치를 지정.
    - 부모 요소에 `position: relative`나 `absolute`가 있어야 기준이 생김.
    - 기준 부모가 없으면 \*\*문서 전체(`<html>`)\*\*를 기준으로.
    - 요소는 **문서 흐름에서 벗어나고 원래 자리는 사라짐**.
- **사용 사례**:
    - 특정 부모 요소를 기준으로 겹치는 배치를 만들 때.
- **코드 예시**:

```html
<div class="parent">
    부모 요소
    <div class="child">자식 요소</div>
</div>
<style>
    .parent {
        position: relative; /* 기준이 되는 부모 */
    }
    .child {
        position: absolute;
        top: 50px; /* 부모의 위에서 50px */
        left: 30px; /* 부모의 왼쪽에서 30px */
    }
</style>

```

- **결과**:
    - 부모 요소를 기준으로 자식 요소가 이동.
    - 원래 자리는 사라짐.

---

### 3. **`fixed`**

- **특징**:
    - \*\*브라우저 화면(뷰포트)\*\*을 기준으로 위치를 고정.
    - 스크롤해도 움직이지 않음.
    - 문서 흐름에서 벗어나 원래 자리는 사라짐.
- **사용 사례**:
    - 고정된 네비게이션 바, 항상 보이는 버튼 등.
- **코드 예시**:

```html
<div class="navbar">고정된 네비게이션 바</div>
<style>
    .navbar {
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        background-color: navy;
        color: white;
    }
</style>

```

- **결과**:
    - 네비게이션 바가 화면 상단에 고정되고, 스크롤해도 따라오지 않음.

---

### 4. **`sticky`**

- **특징**:
    - 특정 지점에 도달하기 전까지는 `relative`처럼 동작.
    - 특정 지점에 도달하면 **스크롤을 따라가지 않고 고정**.
    - 부모 요소를 기준으로 작동.
- **사용 사례**:
    - 긴 문서에서 섹션 제목이나 표 헤더를 고정할 때.
- **코드 예시**:

```html
<div class="section">
    <div class="sticky-header">섹션 제목</div>
    <p>내용...</p>
</div>
<style>
    .sticky-header {
        position: sticky;
        top: 0;
        background-color: lightblue;
    }
</style>

```

- **결과**:
    - 제목이 섹션 상단에 도달하면 고정되고, 섹션을 벗어나면 다시 흐름대로 이동.

---

### **`relative`**\*\* vs **`absolute`** vs **`fixed`** vs **`sticky`** 비교\*\*

| 속성 | **`relative`** | **`absolute`** | **`fixed`** | **`sticky`** |
| --- | --- | --- | --- | --- |
| **기준** | 원래 자리 | 부모 요소 (`relative` 설정된 요소) | 브라우저 화면(뷰포트) | 부모 요소 |
| **자리 유지** | 원래 자리를 유지 | 원래 자리에서 완전히 벗어남 | 원래 자리에서 완전히 벗어남 | 특정 지점 이전에는 원래 자리를 유지 |
| **스크롤 반응** | 스크롤과 함께 움직임 | 스크롤과 함께 움직임 | 스크롤해도 고정 | 특정 지점에서 고정됨 |
| **사용 사례** | 툴팁, 강조 표시 등 | 부모 기준 위치 지정, 레이아웃 조정 | 고정된 네비게이션, 항상 보이는 버튼 | 섹션 제목, 표 헤더 |

---

### **노트 작성 이유**

- HTML/CSS는 기본적으로 **스택 구조**를 제공하지만, `position` 속성을 활용하면 이 구조를 마음대로 변경 가능.
- `absolute`, `fixed`, `sticky`는 모두 문서 흐름에서 벗어나지만 **동작 방식과 기준**이 다름.
- 프로젝트에 따라 어떤 `position` 속성을 사용할지 결정할 때 이 표를 참고.

---

**추가적으로 학습할 것:**

- `z-index`와의 연관성: `position`이 설정된 요소의 쌓임 순서.
- 반응형 디자인에서 `position` 활용 시 주의점.
- Flexbox, Grid와 함께 사용할 때의 효과.