브라우저와 DOM: HTML을 트리화하고 동적으로 조작하기
===

## DOM 이란?
**DOM (Document Object Model)** 은 HTML 문서를 구조화된 트리 형태로 표현한 모델로, 브라우저가 HTML 문서를 읽고 이해하여 자바스크립트를 통해 조작할 수 있도록 제공하는 인터페이스이다. 

DOM 은 HTML 문서의 각 요소를 노드(Node) 로 변환하여 트리 구조를 만든다.

### DOM 의 역할

#### 1. HTML 문서 트리화:
- 브라우저는 HTML 파일을 읽고 DOM 트리를 생성한다.
- 이 트리를 통해 HTML의 각 요수 간의 부모-자식 관계를 정의한다.

#### 2. 자바스크립트와의 연결:
- 자바스크립트가 DOM 트리에 접근하여 요소를 동적으로 조작할 수 있게 한다.


### DOM의 구조
DOM 트리는 HTML 문서의 계층적 구조를 반영한다. 예를 들어, 다음 HTML 문서를 살펴보자

```html
<!DOCTYPE html>
<html>
  <head>
    <title>문서 제목</title>
  </head>
  <body>
    <h1>Hello, World!</h1>
    <p>This is a paragraph.</p>
  </body>
</html>
```
위 HTML 문서는 다음과 같은 DOM 트리로 표현된다.

```
Document
├── html
     ├── head
     │    └── title
     └── body
          ├── h1
          └── p
```

## DOM API란?
DOM API는 브라우저가 제공하는 자바스크립트 인터페이스로, DOM 트리에 접근하고 조작할 수 있는 다양한 메서드와 속성을 포함한다.

### 주요 DOM API 메서드

#### 1. 요소 선택:
- `document.getElementById('id')` : 특정 ID 를 가진 요소를 선택한다.
- `document.querySelector('.class')` : CSS 선택자를 사용하여 요소를 선택한다.

#### 2. 요소 생성 및 추가:
- `document.createElement('tag')` : 새로운 요소를 생성한다.
- `parent.appendChild(child)` : 부모 요소에 자식 요소를 추가한다.

#### 3. 내용 수정:
- `element.textContent` : 요소의 텍스트 내용을 변경한다.

#### 4. 이벤트 처리:
- `element.addEventListener('event', handler)` : 특정 이벤트 발생 시 실행할 코드를 정의한다.

### 예제: DOM API 로 HTML 조작하기

#### HTML:

```html
<!DOCTYPE html>
<html>
  <body>
    <h1 id="title">Hello</h1>
    <button id="change">Click Me</button>
  </body>
</html>
```

#### 자바스크립트:

```js
// DOM 요소 선택
const title = document.getElementById('title');
const button = document.getElementById('change');

// 버튼 클릭 이벤트 처리
button.addEventListener('click', () => {
  title.textContent = 'Hello, DOM!';
});
```
결과적으로 버튼을 클릭하면 `<h1>` 요소의 텍스트가 "Hello, DOM!" 으로 변경된다.

## 브라우저의 역할과 DOM 의 자동 생성
브라우저는 HTML 문서를 읽을 때 자동으로 DOM 트리를 생성한다. 즉, **크롬과 같은 브라우저는 DOM 기능을 내장하고 있으며,** 별도의 설정 없이 DOM API 를 사용할 수 있따.

### 동작 과정
1. HTML 파일을 읽어 DOM 트리 생성
2. CSS 를 적용하여 렌더링 트리 구성
3. DOM 트리와 자바스크립트를 연결하여 동적 조작 가능

## 정리
DOM 은 브라우저가 HTML 문서를 동적으로 조작할 수 있도록 제공하는 핵심적인 기술이다. 이를 통해 개발자는 HTML 요소를 동적으로 추가, 삭제, 수정하며, 사용자와 상호작용할 수 있는 웹 페이지를 만들 수 있다.

DOM API 는 브라우저 내장 기능이므로 별도의 설치 없이 사용할 수 있으며, 이를 이해하면 웹 개발에서 HTML,CSS, 자바스크립트 간의 연결을 더 잘 활용할 수 있다.