웹페이지 안에다가 css 를 삽입하는 2가지 방법
===
**1. style 태그 사용**
**2. style 속성 사용 -> 태그를 통해서 하는것이 아니라 속성을 이용**

**css 텍스트를 파란색으로 표시하고 싶을 때 -> css 를 감싸고 있는 a 태그에 직접 css 코드를 넣기**
```
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <title>WEB - CSS</title>
    <meta charset="utf-8">
    <style>
      a{ 
        color:red;
      }
    </style>
  </head>
  <body>
    <h1><a href="index.html">WEB</a></h1>
    <ol>
      <li><a href="1.html">HTML</a></li>
      <li><a href="2.html" style=" color:red">CSS</a></li>
      <li><a href="3.html">JavaScript</a></li>
    </ol>
  </body>
</html>
```
```
<li><a href="2.html" style=" color:red">CSS</a></li>
```
```style= "     "``` : HTML의 속성(property)
---

- 스타일이라는 속성은 그 값으로 반드시 css 의 효과가 들어 온다라고 약속되어 있음

```<style> ~~ </style> ``` 태그
---
- style 속성과는 반대로 속성 효과만 있어서는 저 효과를 누구에게 지정할지를 설명할 수가 없기 때문에 a{} 라는 코드가 추가로 필요한 것 -> 웹페이지에서 주고 싶은 효과를 누구에게 줄것인가를 선택한다, 라는 점에서 저것을 **선택자(Selector)** 라고 부름
```
 a{ 
    color:red;
   }
```
- 선택자에게 지정될 효과 : **color: red**
- 효과라고도 하고  **Decoration(선언)** 이라고도 함
    - style 태그를 직접 사용한 경우에는 style 태그가 위치하고 있는 태그에게 효과를 줄 것이기 때문에 **선택자를 사용할 필요가 없다**

밑줄 없앨 때: text-decoration: none; 
---

```
 a{ 
    color:black;
    text-decoration: none;

   }
```

- 밑줄을 만들고 또는 없애는 속성은 텍스트에 꾸밈, 장식(decoration)이 없다, 라고 하면이 웹페이지에 있는 모든 a 태그에 대하여 장식 즉 밑줄이 없어지게 된다.
- **세미콜론( ; )** : 디스크립션이 시작되고 끝나는 것을 구분하기 위해서 구분자로 세미콜론이라는 것이 존재하는 것이기 때문에 효과를 지정한 다음에는 항상 세미콜론 적기! -> 코드가 한줄에 있어도 적용잘 됨

CSS 라고 되어있는 웹페이지 만큼은 밑줄을 긋고 싶을때:  text-decoration:underline
---

```
  <li><a href="2.html style="color:red; text-decoration:underline">CSS</a></li>
```

CSS 선택자의 기본
---
예) 사이즈 변경시 검색어 : 'css text size property'
```
h1 {
    font-size:40px;
}
```
예) 가운데 정렬시 : 'css text center proterty' or aline(정렬)
```
h1 {
    font-size:40px;
    text-align: center;
}
```

