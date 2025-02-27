CSS 선택자 #1
===

```
선택자 {
    속성명:속성값;
}
```

선택자: 어떤 요소에 스타일을 적용 할 것인지에 대한 정보
- 기본 선택자
- 그룹 선택자
- 특성 선택자
- 결합 선택자
- 의사 클래스
- 의사 요소

전체 전택자
---
- 모든 요소를 선택
- *(에스터리스크)는 '문서 내의 모든 요소'를 의미하는 부호

```
*{
    color:blue;
}
```
-> 문서 내 모든 요소의 글자 색을 파란색으로 지정

태그 선택자
---
- 주어진 이름을 가진 요소를 선택
- "유형 선택자"라고도 함
- 주어진 이름을 가진 요소가 다수일 경우, 해당 요소들을 모두 선택

```
p{
    color:blue;
}
```
-> 문서 내 모든 p 태그 요소의 글자색을 파란색으로 지정

클래스 선택자
---
- 주어진 class 속성값을 가진 요소를 선택
- 주어진 class 속성값을 가진 요소가 다수일 경우, 해당 요소를 모두 선택

```
.text{
    color:blue;
}
```
-> 문서 내 class 가 "text"인 모든 요소의 글자 색을 파란 색으로 지정!

아이디 선택자
---
- 주어진 id 속성값을 가진 요소를 선택
- id 는 고유한(unique) 식별자 역할을 하는 전역 속성

```
#topic {
    color:blue;
}
```
-> 문서 내 id 가 "topic"인 요소의 글자 색을 파란 색으로 지정!

그룹 선택자
---
- 다양한 유형의 요소를 한꺼번에 선택하고자 할 때 사용
- 쉼표(,)를 통해 선택자를 그룹화 함

```
h1, p, div{
    color:blue;
}
```
-> 문서 내 모든 h1,p,div  태그 요소의 글자 색을 파란 색으로 지정!

선택자가 겹치는 경우
---
- 선택자가 겹치는 경우, **기본적으로 나중에 작성된 스타일이 적용.**
- 선택자가 다르지만 요소가 겹치는 경우, 선택자 우선순위에 의해 적용될 스타일이 결정

★ 선택자 우선순위?
---
**아이디 선택자 > 클래스 선택자 > 태그 선택자**

### 5줄요약

1. 선택자는 어떤 요소에 대한 스타일을 정의할 것인지에 대한 정보
2. 기본 선택자로는 전체 선택자, 태그 선택자, 클래스 선택자, 아이디 선택자 등이 있음.
3. 그룹 선택자는 여러 개의 선택자를 그룹화할 수 있는 선택자
4. 문서 내에 동일한 선택자가 존재하는 경우 뒤에 작성 스타일이 적용!
5. 서로 다른 선택자가 동일한 요소를 선택한 경우, 우선순위(아이디>클래스>태그) 고려!
