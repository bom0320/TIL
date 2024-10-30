Flexbox 사용법
===
Flexbox 를 사용하려면 CSS 에 아래와 같은 속성을 추가해주면 된다.

```css
display: flex;
```

> **Flexbox 란?**
> 유동적으로 각 요소들을 배치하는 기법

단, 주의해야할 점은 flexbox 를 적용하고 싶은 요소에다가 직접 추가하는 것이 아니라 그 요소의 **부모요소(flex container)** 에 추가하여야 한다.

```css
.father {
    display: flex;
    justify-content: space-between;
    align-items : center;
    width: 100%;
    height: 100vh;
}

.child {
    width: 100px;
    height: 100px;
    background-color: aquamarine;
    color: white;
}
```
'