`<button>`과 `<input type="button">`의 차이점
===
`<input type="button">` 과 `<button>` 태그는 비슷해 보이지만, **역할, 유연성, 스타일링** 측면에서 차이가 있다. 

## 1. `<input type="button">`

### 특징
- `<input>` 태그의 한 종류로, 버튼을 생성한다.
- 버튼의 텍스트는 `value` 속성으로 지정한다.
- 클릭 이벤트 처리 시 **JavaScript** 가 필요하다.

### 예시
```html
<input type="button" value="클릭" onclick="alert('Hello!')">
```
### 장점
1. **간단한 사용 :** 버튼 텍스트를 `value` 속성으로 빠르게 설정할 수 있다.
2. **HTML 4와의 호환성 :** 오래된 브라우저에서도 사용 가능

### 단점
1. **유연성 부족 :** 버튼 안에 다른 HTML 요소를 포함할 수 없다. 텍스트만 표시 가능

```html
<input type="button" value="텍스트만 가능">
<!-- 아이콘이나 이미지 추가 불가 -->
```

---

## 2. `<button>` 태그

### 특징
- **더 유연하고 강력**한 버튼을 생성한다.
- 버튼 안에 **텍스트, 이미지, 아이콘 등 다양한 HTML 요소**를 포함할 수 있다.
- `type` 속성을 통해 다양한 버튼 역할(`button`, `submit`, `reset`) 을 지정할 수 있다.

### 예시
```html
<!-- 단순 버튼 -->
<button onclick="alert('Hello!')">클릭</button>

<!-- 이미지와 텍스트 포함 -->
<button>
  <img src="icon.png" alt="아이콘"> 버튼 텍스트
</button>
```

### 장점

1. **유연성 :** 버튼 내부에 HTML 요소를 자유롭게 넣을 수 있다.

```html
<button>
  <span>텍스트</span>
  <img src="icon.png" alt="아이콘">
</button>
```

2. **다양한 `type` 속성 :**
- `type="button"` : 일반 버튼
- `type="submit"` : 폼 제출 버튼
- `type="reset"` : 폼 초기화 버튼

3. **스타일링 :** CSS 로 더 세부적인 스타일링이 가능하다.

### 단점:
1. **복잡한 동작 구현 :** 더 많은 옵션과 유연성 때문에 간단한 작업에는 오히려 과하게 느껴질 수 있다.

---

## 비교 요약
| 특징 | `<input type="button">` | `<button>` |
| --- | --- | --- |
| **유연성** | 텍스트만 표시 가능 | 텍스트, 이미지 등 다양한 요소 포함 가능 |
| **`type` 속성 지원** | `button`만 지원 | `button`, `submit`, `reset` 지원 |
| **스타일링** | 제한적 (CSS 적용 가능, 유연성 낮음) | 유연하고 상세한 스타일링 가능 |
| **역사적 배경** | HTML4부터 사용 가능 (오래된 방식) | HTML5에서 더 선호되는 방식 |
---

## 어떤 것을 사용해야 할까?
 
### 1. 간단한 작업:
- `<input type="button">` 를 사용할 수 있지만, 현재는 거의 사용되지 않고 `<button>` 태그를 선호함

### 2. 유연성과 유지보수:
- `<button>` 을 사용하는 것이 더 추천된다. 버튼 안에 텍스트와 아이콘, HTML 태그를 넣을 수 있기 때문에 확장성과 유연성이 더 높다.

---

### 예제: 같은 동작을 하는 두 코드 비교

**`<input>`**

```html
<input type="button" value="저장" onclick="saveData()">
```

**`<button>`**

```html
<button onclick="saveData()">저장</button>
```

결론적으로, **현대 개발에서는 `<button>` 이 더 많이 사용**된다. 추가적인 유연성과 HTML5 표준을 지원하기 때문이다.