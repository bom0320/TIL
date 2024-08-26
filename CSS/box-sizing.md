모르면 곤란한 box-sizing
===

## 레이아웃은 어떻게 배치하지?
![](https://velog.velcdn.com/images/nalsae/post/5f1a97c5-b56c-4440-9cca-b1bb61e6e509/image.png)

우리는 보통 **사각형 모양**의 구획을 나눠서 전체적인 레이아웃을 설계하곤 한다. CSS 에서도 유사한 맥락으로 **box model** 이라는 것이 존재한다. 

쉽게 말하면 box model 은 **HTML 요소가 웹 페이지에서 차지하는 영역**을 정의한 것이다. 

HTML 요소들은 각각 자신만의 영역을 차지하고, 이 영역은 다시 하위 요소에 따라 여러 개의 작은 영역으로 나뉜다.

## box model 을 파헤쳐보자

![](https://velog.velcdn.com/images/nalsae/post/7f050cc0-aaac-43be-b75b-c2ff55829a6c/image.png)
개발자 도구에 있는 Style 탭의 스크롤을 최하단으로 내리면 위와 같은 그림이 보일 것이다. 
그림을 통해 한 요소의 box model 크기를 계산하면 다음과 같다.

> **💡 box model의 전체 크기**
> : 콘텐츠 크기 +  `padding` 값 + `border` 값 + `margin` 값

콘텐츠 크기는 말 그대로 콘텐츠 자체의 width 값과 height 값일 텐데, 나머지는 정확히 무엇을 의미하는지 잠깐 살펴보고 가자

> **💡 border**
> : border 는 요소를 감싸는 **테두리**를 의미함
> : 값이 커질수록 테두리의 굵기는 두꺼워짐

> **💡 padding**
> : padding 은 **요소 내부의 여백**, 콘텐츠와 border 사이즈의 여백

> **💡 margin**
> : margin 은 **요소 외부의 여백**, border 밖의 여백

결국 `padding` 과 `margin`은 `border`를 **기준으로 내부인지 외부인지**에 따라 여백을 설정하는 속성이라고 보면 된다. 

![](https://velog.velcdn.com/images/nalsae/post/3d9d7c10-de5a-43b1-bed7-3471b1837c6e/image.png)

```
div{
    background: pink;
    padding: 30px;
    margin: 30px;
    border: 30px solid rgb(162, 90, 162);
    width: 300px;
}
```

간단한 예시로 `width` 값이 300px 인 `div` 를 하나 만들어보았다. 개발자 도구를 사용하여 위 그림의 box model 을 살펴보면 다음과 같다.

![](https://velog.velcdn.com/images/nalsae/post/1175c550-aa5b-400e-8939-a715d0e470ca/image.png)

 box model의 전체 `width` 값을 계산해보면 '300(콘텐츠 크기) + 60(좌우 padding 값) + 60(좌우 border 값) + 60(좌우 margin 값)'으로 480px이 된다. 

## 🤔 엥? 왜 이렇게 되지?
그런데 box model 에 따라 레이아웃 배치를 하다 보면, **사이즈를 조절할 때 불편한 경우**가 종종 발생한다. 앞서 예시로 생성한 `div` 를 통해 이를 구현해보겠다.

![](https://velog.velcdn.com/images/nalsae/post/fde13f33-ee15-43e2-91bb-e920cfe8a634/image.png)

개발자 도구의 요소 선택 툴로 `div` 를 확인해보면 `width` 값은 약 420px 임을 확인할 수 있다. 

외부 여백인 `margin` 을 제외하고 420px 인 것은 알겠다. 그러나 코드를 작성할 때 `div` 의 `width` 값은 분명 300px 로 작성했었다.

**300px 의 `div`를 생성하려고 했었는데, 막상 스타일링을 하고 나니 420px** 이 되어버린 것이다. 왜 이런결과가 발생하는 것일까?

**이러한 현상에 관여하는 CSS 속성이 바로 `box-sizing` 이다.** `box-sizing` 은 **요소의 너비와 높이를 계산하는 방법을 지정** 하는 속성이라고 할 수 있다.
위와 같은 현상이 발생하는 이유를 `box-sizing` 을 설명하는 공식 문서에서 찾아보겠다.

![](https://velog.velcdn.com/images/nalsae/post/d6cca981-19e9-4a6c-bd77-dba40c7b6e83/image.png)

스크롤을 내리다 보면 초기값이 `content-box` 로 지정되어 있는 것을 볼 수 있다. 즉, `box-sizing` 을 따로 지정해주지 않는다면 알아서 `content-box` 방식으로 요소의 너비와 높이를 계산한다는 것이다.

그렇다면 구체적으로 `content-box` 는 **어떤 방식으로 너비와 높이를 계산**하는지 `box=sizing`의 또 다른 값인 border-box 와 함께 살펴보도록 하겠다.


>💡 content-box
>
>: 설정한 width와 height 값이 곧 **요소 내부의 콘텐츠 크기**

>💡 border-box
>
>: 설정한 width와 height 값이 **안쪽 여백과 테두리까지 포함**


위의 정의만 봐서는 직관적으로 이해하는 데 다소 어려움이 있기 때문에 앞서 생성한 `div` 를 다시 예씨로 사용하자면 다음과 같다.

```
div{
background: pink;
padding: 30px;
margin: 30px;
border: 30px solid rgb(162, 90, 162);
width: 300px;
box-sizing: content-box;
}
```
![](https://velog.velcdn.com/images/nalsae/post/39539408-4bbf-4c32-8e7a-38a2a7161c75/image.png)

![](https://velog.velcdn.com/images/nalsae/post/82c06cb6-74ba-47c0-9f5d-b7a1f2af2986/image.png)

CSS 로 `box-sizing` 속성 값을 `content-box` 로 설정해주었다. 처음의 예시와 다를바가 없다. `box-sizing` 의 기본값은 `content-box` 이기 때문에 **따로 설정하지 않아도 `content-box` 가 적용된 상태** 였던 것이다.

```
div{
 background: pink;
 padding: 30px;
 margin: 30px;
 border: 30px solid rgb(162, 90, 162);
 width: 300px;
 box-sizing: border-box;
}
```
![](https://velog.velcdn.com/images/nalsae/post/32e9ef16-9a6d-4126-94e7-26c158b858d4/image.png)

![](https://velog.velcdn.com/images/nalsae/post/779e33fc-5bf9-4d4c-b9f5-d41e13016628/image.png)

이번에는 `box-sizing` 값을 `border-box` 로 설정해보았다. 그래픽만 봐도  `content-box`로 설정한 경우보다 너비가 훨씬 짧아보인다. 개발자 도구의 구체적인 수치를 확인해보면 설정한 `width` 값인 300px 에 맞춰서 **콘텐츠의 크기를 180px 로 알아서 축소시켰음**을 알 수 있다.

![](https://velog.velcdn.com/images/nalsae/post/97a024c0-72f0-48ab-a617-77f3abe60365/image.png)
요소 선택 툴로 확인해보면 `div` 의 너비는 더이상 420px 이 아니라 300px 이다. 

즉 `border-box`로 설정하면 `width` 값은  **'콘텐츠 크기 + 좌우 `padding` 값 + 좌우 `border 값`'**으로 계산되는 것이다. 

그러므로 요소의 크기는 `width` 값과 동일하게 설정하고 싶다면 box-sizing 값을 `border-box` 로 설정해 놓는 것이 바람직하다.

## ⭐ 기본값 확인의 중요성!
이처럼 `box-sizing` 속성의 기본값을 모르고 있다면, 앞선 예시에서도 살펴 봤듯 생각했던 대로 레이아웃 배치가 구현되지 않는 결과를 초래할 수도 있다. 이는 비단 `box-sizing` 뿐 아니라 어떤 속성이든 공식 문서의 **기본값을 항상 잘 읽어봐야 한다** 는 교훈을 준다.

보편적으로 계산의 편리성을 위해 `border-box` 값을 사전에 적용하는 경우가 많지만, 상황에 따라 `content-box` 값으로 설정하는 경우도 있을 것이다. 따라서 유동적으로 **어떤 값을 설정하는 것이 합리적인지** 판단할 수 있어야겠다.