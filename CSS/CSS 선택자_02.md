선택자 #2
===

**선택자의 종류**
- 기본 선택자
- 그룹 선택자
- 특성 선택자
- 결합 선택자
- 의사 클래스
- 의사 요소

특성 선택자(속성 선택자)
---
- 주어진 속성의 존재 여부나 그 값에 따라 요소를 선택함.
- 기호를 추가하여 요소를 선택하는 방식을 다양화 할 수 있음

```
[class] {
    background-color: tomato;
}
```
-> 클래스 속성을 가지고 있는 요소를 선택하기

```
[class="item"] {
    background-color: tomato;
}
```
-> 클래스가 "item" 인 요소를 선택하기

```
[class *="it"]{
    color:white;
}
```
-> 클래스 값에 "it" 가 포함되는 요소를 선택

```
[class $= "it"] {
    color:white;
}
-> 클래스 값이 "it"로 끝나는 요소를 선택하기
```

**EX)**
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbLAVyw%2Fbtry7vs9lRm%2FyVfzE4CVPpwWn0QbONVyYk%2Fimg.png)

결합 선택자
---
- 두 개 이상의 선택자를 결합시켜 결합된 조건을 만족하는 요소를 선택
- 자손 결합자 / 형제 결합자

### 1. 자손 결합자
두 개의 선택자 중 첫 번째 선택자 요소의 자손을 선택할 수 있음

```
div p{color: white;}
```
-> div 요소 안에 위치하는 모든 p 요소를 선택하기

```
div > p{color:white;}
```
-> div 요소의 바로 아래에 위치하는 모든 p 요소를 선택하기

### 2. 형제 결합자
두 개의 선택자 중 첫 번재 선택자 요소의 형제를 선택할 수 있음

```
h1 ~ p{color:red;}
```
-> h1 요소의 뒤에 오는 형제 중 모든 p  요소를 선택하기

```
h1 + p{color:red;}
```
-> h1 요소의 바로 뒤에 오는 형제 p 요소를 선택하기

**EX)**
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FckMnXV%2FbtrzaWvNrLz%2FkWlnXkVv2Om3rvMUVPHJl0%2Fimg.png)

### 요약
- 특성 선택자는 주어진 특성의 존재 여부나 그 값에 따라 요소 선택
- 특성 선택자는 값의 포함 여부, 포함 위치 등을 통해서도 선택할 수 있음
- 결합 선택자는 여러 선택자를 결합하여 요소를 선택
- 자손 또는 형제 중에서 특정 조건을 만족하는 요소를 선택할 수 있음 