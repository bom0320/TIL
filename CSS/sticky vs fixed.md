position: sticky 와 position: fixed 의 차이
===

> position 속성에 대해 공부하다보니 sticky 가 스크롤 이동으로 요소가 움직여도 sticky 요소는 고정된 상태를 유지한다고 했다. 그럼 그냥 fixed 로 position 속성값을 줘도 되지 않나? 라는 의문점이 생기기 시작했다.

이 둘 모두 요소를 특정 위치에 고정시키는 데 사용되지만, 동작 방시고가 목적이 다르다. 이 두 속성의 차이를 이해하는 것이 중요하다.

## 이 둘의 차이점

### position: fixed
- 요소가 뷰포트에 항상 고정됨
- 페이지 스크롤과 상관없이 **항상** 지정된 위치에 있다.
- 고정된 배너, 헤더, 사이드바 등에 적합함

### position: sticky
- 요소가 특정 스크롤 위치에 도달할 때까지는 일반적인 문서 흐름을 따른다.
- 지정된 스크롤 위치에 도달하면 그 자리에 고정되며, 부모 요소의 범위를 벗어나면 다시 문서 흐름에 따라 움직인다.
- 표의 헤더, 섹션 내 고정된 내비게이션 바 등에 적합함.

## 예시로 이해하기

**position: fixed 예시**
```
<div class="fixed-box">Fixed 요소</div>
<div class="content">많은 내용...</div>
```

```
.fixed-box {
  position: fixed;
  top: 10px;
  left: 10px;
  background-color: pink;
  padding: 10px;
}
.content {
  height: 2000px;  /* 긴 내용 */
}

```
- 이 예시에서, `.fixed-box` 는 페이지를 스크롤해도 **항상** 뷰포트의 왼쪽 상단에 고정된 상태로 남아있다.

**position: sticky 예시**
```
<div class="sticky-container">
  <div class="sticky-box">Sticky 요소</div>
  <p>많은 내용...</p>
</div>
```

```
.sticky-container {
  height: 1000px;
  background-color: lightgray;
}

.sticky-box {
  position: sticky;
  top: 10px;  /* 스크롤 시 상단에서 10px 떨어진 곳에 고정 */
  background-color: lightgreen;
  padding: 10px;
}
```
- 이 예시에서, `sticky-box` 는 스크롤 페이지의 상단에서 10px 떨어진 위치에 도달할 때까지는 스크롤과 함께 움직인다. 
- 그 위치에 도달하면 고정됨
- but 부모 요소인 `.sticky-container` 의 끝을 넘어서면 다시 스크롤과 함께 움직이기 시작한다.
