📌 querySelector() vs getElementById() 정리
===

## 1. `querySelector()` 사용법

```js
var heading = document.querySelector('#heading');
heading.onclick = function() {
    heading.style.color = 'red';
}
```
✔ `querySelector()` 는 CSS 선택자를 사용해  요소를 선택할 수 있다.
✔ `#id`, `.class`, `태그명` 등 다양한 선택자가 가능하다.
✔ 첫 번째로 일치하는 요소만 선택한다.

## 2. `getElementById` 사용법

```js
var heading = document.getElementById('heading');
heading.onclick = function() {
    heading.style.color = 'red';
}
```
✔ `getElementById` 는 **ID** 속성을 이용해 요소를 찾는다.
✔ **ID 는 문서에서 고유해야 하므로 하나의 요소만 반환**한다.
✔ `querySelector()` 보다 속도가 빠르다.


---

## 🚀 querySelector() vs getElementById() 비교
| 메서드 | 사용법 | 특징 |
| --- | --- | --- |
| `querySelector('#id')` | CSS 선택자 사용 가능 | `.class`, `#id`, `h1` 등 다양한 선택자 활용 |
| `getElementById('id')` | ID를 직접 검색 | ID 선택만 가능하지만 속도가 더 빠름 |

### ❗ 언제 어떤 걸 써야 할까?
✅ ID만 찾을 경우 → `getElementById()`
✅ CSS 선택자를 활용해야 할 경우 → `querySelector()`

---

### 💡 추가로 알면 좋은 것
- `querySelectorAll()` 사용하면 여러 개 선택 가능!

```js
var paragraphs = document.querySelectorAll('p');
console.log(paragraphs); // 모든 <p> 요소 리스트(NodeList)
```
- `querySelectorAll()` 은 일치하는 모든 요소를 가져온다.
- 반환 값이 **NodeList(유사 배열)** 이므로 `.forEach()` 를 사용할 수 있다.
ㄴ