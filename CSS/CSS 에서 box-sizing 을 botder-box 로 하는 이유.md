css 에서 box-sizing 을 border-box 로 하는 이유
===

## Box-sizing 이란?
우리가 보통 css 초기 설정할 때 하는 것 중 하나가 아래 설정이다.

```css
box-sizing: border-box;
```

box-sizing 속성은 요소의 전체 너비와 높이를 어떻게 계산하는지 설정한다.

다시 말해, 요소마다 너비와 높이가 있는데, 이걸 늘리거나 줄이거나 혹은 padding 값 등을 추가할 경우에 어떻게 이 요소에 너비와 높이에 적용되는지 여부를 설정하는 것을 의미한다.

## Content-box 와 border-box 의 차이점
box-sizing 속성은 여러가지가 있지만, 대표적으로 아래 두 가지가 있다.

```
1) box-sizing: border-box;

2) box-sizing: content-box;
```


기본적으로 CSS 박스 모델에서, 요소에 할당된 너비와 높이에는 content box 에만 적용이 된다.

다시 말해, 디폴트 값이 **`box-size: content;`** 라는 것이다.

여기서 말한 content box 는 아래 box model 에서 **Content edge 가로(width) X 세로(height)** 로 가장 가운데에 있는 영역이다.


![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbIl6kv%2FbtryZaazTDr%2FtvxXGr2KOvopzxut4LTpJK%2Fimg.png)

**`box-sizing: content;`** 에 border 나 padding 을 추가하면 요소의 너비나 높이에 추가가 되어 해당 box의 크기는 그만큼 더 커지게 된다.

즉, 내가 만약 이 box의 너비나 높이를 설정하려면 예를 들어, 단순히 width: 50px; 혹은 height: 50px; 를 줄 수 있지만, 거기에 border 값이나 padding 값이 더해져야 한다면 width 값은 50px 이 아닌 **50px + (border 값 혹은 padding 값)** 이상이 될 것이다.

> For example,
> .box {width: 350px; border: 10px solid black;}
> renders a box that is 370px wide.

## css 에서 box-sizing: border-box 를 선호하는 이유
예를 들어, 100px 너비에서 border 나 padding 를 추가한다면, 100px + ( border 혹은 padding 값 )px 이 아니라, 100px 안에 padding 값이나 border 값이 포함된다는 것이다. 그리고 그만큼 content-box 는 줄어들게 된다.

이런 성질 때문에, border-box 가 요소의 사이즈를 맞추는 것이 보다 용이하다. 그러므로, 보통 css 속성을 설정할 때 위 속성을 자주 이용한다.