form VS fieldset,legend 태그의 차이점
===
`<form>`, `<fieldset>` 그리고 `<legend>` 태그는 HTML 에서 주로 폼을 구성할 때 사용되며, 각각의 역할과 목적이 다르다.

## 1. `<form>` 태그

### 목적
- 사용자가 입력한 데이터를 서버로 전송하기 위한 영역을 정의

### 역할
- 하나의 폼(submit 가능한 데이터 블록)을 정의
- `action` 속성을 통해 데이터를 전송할 서버의 URL을 지정
- `method` 속성을 통해 전송 방식을 지정 (`GET`, `POST` 등)

#### 사용 예:
```html
<form action="/submit" method="POST">
    <input type="text" name="username" placeholder="Username">
    <button type="submit">Submit</button>
</form>

```
---


## 2. `<fieldset>` 태그

### 목적
- 관련된 입력 필드(input fields) 를 그룹화

### 역할
- 논리적으로 연결된 폼 요소들을 묶어 사용자와 개발자 모두에게 폼 구조를 명확히 전달
- 기본적으로 테두리(border) 로 시각적인 그룹을 나타냄
- 접근성 향상: 스크린 리더가 그룹화된 영역임을 인식 가능

#### 사용 예:
```html
<form>
    <fieldset>
        <legend>Personal Information</legend>
        <input type="text" name="firstname" placeholder="First Name">
        <input type="text" name="lastname" placeholder="Last Name">
    </fieldset>
</form>
```

---

## 3. `<legend>` 태그

### 목적
- `<fieldset>` 태그의 제목을 정의

### 역할
- `<fieldset>` 안의 내용에 대한 간략한 설명 제공
- `<legend>` 텍스트는 `<fieldset>` 의 상단에 표시되며, 브라우저에 따라 중앙 정렬되기도 함
- 접근성 향상: 스크린 리더가 제목으로 인식해 사용자에게 그룹의 목적을 알림

#### 사용 예:

```html
<fieldset>
    <legend>Contact Information</legend>
    <input type="email" name="email" placeholder="Email">
    <input type="tel" name="phone" placeholder="Phone Number">
</fieldset>
```

---

## 차이점 요약
| 태그 | 역할 및 목적 | 특징 |
| --- | --- | --- |
| `<form>` | 데이터를 서버로 전송하는 전체 폼 정의 | `action`과 `method` 속성을 사용해 전송 경로와 방식을 설정 가능 |
| `<fieldset>` | 관련 입력 필드를 그룹화해 구조적으로 구분 | 기본 테두리 제공, `<legend>`와 함께 사용 시 의미론적 그룹화 가능 |
| `<legend>` | `<fieldset>`의 제목 정의 | `<fieldset>` 상단에 제목 표시, 접근성 향상 |

---

## 사용 시 주의점
1. `fieldset` 과 `legend` 는 필수는 아니지만, 복잡한 폼에서 사용하면 접근성과 가독성을 크게 향상시킬 수 있다.
2. `form` 은 데이터 전송 시 반드시 사용해야 하며, `fieldset` 과 `legend` 는 구조적, 시각적 그룹화를 위해 사용한다.
3. `fieldset` 을 남발하면 UI 가 복잡해질 수 있으니 필요할 때만 사용하도록 하자