박스 모델
===
- 화면 전체를 쓰는 태그들(block level element)
- 자기 자신의 부피, 콘텐츠 크기만큼을 갖는 태그들(inline element)
```
  /*
  block level element
  */
    h1{
        border-width:5px;
        border-color:red;
        border-style:solid;
        display:inline;
      }
  /*
  inline element
  */
    a{
        border-width:5px;
        border-color:red;
        border-style:solid;
        display:block;
     }
```
- block element 라고 하더라도 inline element 처럼 자신의 부피만큼을 쓰게 할 수도 있다 -> **display 속성 사용**
= 즉, block level element 와 inline element 는 display 라는 속성의 기본값일 뿐 그 기본값은 CSS를 통해서 언제든 바꿀 수 있다.