CSS를 지배하는 중요한 토대
===
**1.효과**
**2.선택자**

클래스(class) 선택자:  HTML의 속성
---
- 그룹핑(grouping)하다, 하나로 묶는다 라는 뜻이 포함되어 있다.
```
\<<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <title>WEB - CSS</title>
    <meta charset="utf-8">
    <style>
      a{
        color:black;
        text-decoration: none;
      }
      .saw {
        color:gray;
      }
      h1 {
        font-sixe:45px;
        text-align: center;
      }
    </style>
  </head>
  <body>
    <h1><a href="index.html">WEB</a></h1>
    <ol>
      <li><a href="1.html" class="saw">HTML</a></li>
      <li><a href="2.html" class="saw">CSS</a></li>
      <li><a href="3.html">JavaScript</a></li>
    </ol>
    <h2>CSS</h2>
    <p>
      To briefly explain HTML and CSS, HTML is the information displayed on the screen of a website,
       and CSS plays the role of decorating the information displayed on the screen of a website.
      CSS stands for Cascading Style Sheets and is a style sheet language used to style documents
       such as HTML, XHML, and XML.
    </p>
  </body>
</html>
```
- saw라고 하는것은 이 웹페이지의 모든 saw 라는 이름의 태그를 선택하는 선택자 -> class 값이 saw 인 태그 ->**그때 사용하도록 약속된 특수한 기호가 바로 점(.) 이다**
    - saw 앞에 점을 붙이는 순간 저 선택자는 이 웹페이지에 있는 모든 class 가 saw 인 태그를 가르키는 선택자가 됨
```
.saw {
        color:gray;
    }
```
**빨간 색으로 CSS 부분 강조**
```
<li><a href="2.html" class="saw active">CSS</a></li>
```
```
.active{
    color:red;
}
```
- class 라는 저 속성의 값은 여러 개의 값이 들어올 수 있고 띄어쓰기로 구분
- 하나의 태그에는 여러 개의 속성이 들어올 수 있고 여러 개의 선택자를 통해서 하나의 태그를 공동으로 제어할 수 있다. 
- 보다 가까이에 있는 명령이 더 큰 영향력을 가짐 -> 우선순위가 좀 더 높은 것 사용 -> **ID 선택자**

ID 선택자
===
- **id의 값은 단 한번만 등장해야 된다**
    - ID 선택자의 값이 active인 태그가 이 웹페이지에서 한번만 등장하면 그 다음엔 저 active 라고 하는 값은 쓰면 안된다. -> 써도 웹페이지가 동작하지 않지는 않지만 쓰지 말라고 되어 있음
- 예) 주민등록번호, 학번같은.. -> 유일무의한 값 != 이 웹페이지의 모든 ```<a>``` 태그를 가치키는 선택자

```
<li><a href="2.html" class="saw" id="active">CSS</a></li>

```
**웹페이지에서 id 값이 active 인 태그 선택**
```
#active{
    color:red;
}
```
- ```#active``` 가 saw 보다 뒤에 등장했음에도 불구하고, 리로드를 해보면 붉은 색이 되어 있음.
 **ID 선택자 > 클래스 선택자**
**클래스 선택자 > 태그 선택자** 

     ##   [css selector](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Selectors)
