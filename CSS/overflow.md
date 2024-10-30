overflow
===

CSS 의 overflow 프로퍼티는 요소내의 컨텐츠가 너무 커서 요소내에 모두 보여주기 힘들때 그것을 어떻게 보여줄지를 지정한다. 

기본적으로 컨텐츠를 포함하고 있는 요소의 크기가 고정되어 있지 않다면 컨텐츠를 모두 포함할 수 있도록 요소의 크기가 커진다. 크기가 고정되어 있다면 overflow 프로퍼티에 지정된 값에 따라 보여지게 된다.

overflow 에 사용할 수 있는 값은 네가지가 있다.

- **visible :** 기본 값이다. 넘칠 경우 컨텐츠가 상자 밖으로 보여진다.
- **hidden :** 넘치는 부분은 잘려서 보여지지 않는다.
- **scroll :** 스크롤바가 추가되어 스크롤할 수 있다. (가로, 세로 모두 추가 된다.)
- **auto :** 컨텐츠 량에 따라 스크롤바를 추가할지 자동으로 결정된다. (필요에 따라 가로, 세로 별도로 추가될 수도 있다.)

## 1. overflow: visible;

기본 값이다. 넘친 컨텐츠는 상자 밖으로 보여진다.

```css
<style>
div.container {
overflow: visible;
    border:solid 1px green;
    height: 200px;
    width: 200px;
}
</style>

<div class="container">
    <p>CSS의  overflow 프로퍼티는.. </p>
</div>
```

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F9944E2445AF3006616)

## 2. overflow: hidden;

넘친 컨텐츠는 잘려지고 보여지지 않는다.

```css
<style>
div.container {
overflow: hidden;
    border:solid 1px green;
    height: 200px;
    width: 200px;
}
</style>

<div class="container">
    <p>CSS의  overflow 프로퍼티는... </p>
</div>
```

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F99635E425AF3007830)

## 3. overflow: scroll;
넘친 컨텐츠는 잘리고, 스크롤바가 생겨서 스크롤해서 볼 수 있다. 필요하던, 하지않던간에 가로/ 세로 스크롤바가 모두 생긴다.

```css
<style>
div.container {
overflow: scroll;
    border:solid 1px green;
    height: 200px;
    width: 200px;
}
</style>

<div class="container">
    <p>CSS의  overflow 프로퍼티는... </p>
</div>
```
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F99FCAC4E5AF3008D01)

## 4. overflow: auto;
넘칠경우 스크롤바가 자동으로 생긴다. 가로/세로 필요한 부분에만 생긴다

```css
<style>
div.container {
overflow: auto;
    border:solid 1px green;
    height: 200px;
    width: 200px;
}
</style>

<div class="container">
    <p>CSS의  overflow 프로퍼티는... </p>
</div>
```

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F9927D8435AF3009C0C)

## 5. overflow-x, overflow-y
가로, 세로 overflow 를 각각 제어하고자 한다면 overflow-x 와 overflow-y 를 사용한다.

```css
<style>
div.container1 {
    overflow-x: scroll;
    overflow-y: hidden;
    display: inline-block;
    border:solid 1px green;
    height: 200px;
    width: 200px;
}
div.container2 {
    overflow-x: auto;
    overflow-y: scroll;
    display: inline-block;
    border:solid 1px green;
    height: 200px;
    width: 200px;
}
</style>

<div class="container1">
    <p>CSS의  overflow 프로퍼티는... </p>
</div>
<div class="container2">
    <p>CSS의  overflow 프로퍼티는... </p>
</div>
```
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F992390485AF300AD23)