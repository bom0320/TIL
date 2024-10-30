Flexbox 란 무엇인가
===

대부분 사이트는 전체 레이아웃이 수직 구성이며 스크롤을 통해 움직인다. 

레이아웃을 구성할 때 가장 많이 사용하는 요소(Elements)들이 기본적으로 블록(Block) 개념으로 표시(Display) 되며 이는 뷰(View) 에 수직(위에서 아래로)으로 쌓이기 때문에 수직 구성은 상대적으로 쉽게 만들 수 있다.
하지만 수평(왼쪽에서 오른쪽으로) 구성의 경우에는 상황이 매우 귀찮다. 프론트엔드 개발을 진행해본 적 있는 사람의 경우 무슨 소리인지 단번에 이해할 수 있을 것이다.

문제는 수평 구조를 만드는 속성이 명확하지 않았기 때문인데, 그래서 많은 경우 float 나 혹은 inline-block 등의 도움을 받았다.

여기서 float 에 대해서 간략하게 짚고 넘어가보자. 말 그대로 둥둥 떠다니는 형태로 element 들을 배치하는 것으로 이해하면 된다.

일반적으로 `img` 태그와 `p` 태그를 사용하게 되면 아래와 같은 결과가 나오게 된다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F3eaf7228-0d86-48f4-b685-4579e7c75e3d%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.15.51.png)

하지만 그림과 문자를 수평으로 나열하기 위해

```html
<img style="float:left" width="200px" height="200px" src="eagle.jpg" />
```
와 같이 스타일을 적용한다면

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F4eb5b831-a854-4df2-9f64-731105c20b73%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.15.59.png)

와 같은 결론을 얻을 수 있다. 즉 사진과 문자가 수평으로 배치가 된다.

```html
<img style="float:left" width="200px" height="200px" src="eagle.jpg" />
<div style="clear:both;"class="eagle">
```

와 같은 형태로 아래 태그에 clear 효과를 준다면 아래와 같이 다시 원래 대로 수직 정렬이 진행된다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F1df70b02-16ee-466a-8d2d-134e23e3f3e5%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.16.10.png)

위에서 설명한 float 을 이용해서 과거에는 수평정렬을 하곤 했다. 하지만 이는 다양한 문제(Clear, White space 등, 해결은 가능하지만...) 를 가지고 있기 때문에 결국 수평 레이아웃 구성의 차선책일뿐이며, 이제 우리는 Flex(Flexible Box) 라는 명확한 개념(속성들)으로 레이아웃을 쉽게 구성할 수 있다.


## CSS3 Flexbox
---

Flex 는 요소의 크기가 불문명하거나 동적인 경우에도, 각 요소를 정렬할 수 있는 효율적인 방법을 제공한다.
우선 Flex는 2개의 개념으로 나눌 수 있다. 

첫 번째는 Container 두번째는 Items 이다. 

Container 는 Items 를 감싸는 부모 요소이며, 각 Item 을 정렬하기 위해선 Container 가 필수라고 할 수 있다.
Container 에는 `display: flex-flow`, `justify-content` 등의 속성을 사용할 수 있으며, Items 에는 `order`, `flex` , `align-self` 등의 속성을 사용할 수 있다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F5fa065b2-17b6-466e-b9d1-4a0b723d797a%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.21.34.png)

## flex Container

flex container 를 위한 속성들은 아래와 같다.
주 축(main - axis) 와 교차 축(Cross - axis) 의 개념은 뒤에서 다시 설명하겠다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2Fa28d2475-d4d0-47f6-b595-a27199afa82c%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.22.24.png)

## display
`display` 속성으로 Flex Container 를 정의내릴 수 있다.
display 를 block, inline-block, none 으로 종종 사용하는 경우가 많은데 이것을 flex, inline-flex 로 표현할 수 있다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F8f23b6b1-51c7-43b3-9e85-3d70680f35dd%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.22.29.png)

`flex` 와 `inline-flex` 의 차이는 단순하다. **수직** 또는 **수평**으로 쌓는 성향을 가진다고 보면 된다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2Fa153d9b0-56a9-4cc1-9723-a0cde9afc85c%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.22.35.png)
![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F1741f75a-85e7-42bd-9171-4a179446f186%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.22.41.png)

## flex-flow
주 축을 설정하고 Items 의 여러 줄 묶음(줄바꿈) 을 설정하는 속성이다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F6d3cb2ae-3934-40c0-8181-88793967a4d7%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.22.47.png)

`flex-direction` 의 경우 아래 표를 보자

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2Fa445c096-6c2b-4b1a-a1c4-f3de5ff65b12%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.22.51.png)

### 주 축과 교차 축이란?
값 `row` 는 Items 를 수평축으로 표시하므로 주 축이 수평이고 교차 축은 수직이 된다. 반대로 `Column` 은 Item 을 수직축으로 표시하므로 주 축은 수직이며, 교차 축은 수평이 된다. 즉 방향에 따라 주 축과 교차 축이 달라진다고 보면 된다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2F18dcaa2e-e948-4804-b880-c6c8ddb8a448%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.23.08.png)

### 시작점과 끝점이란?
주 축이나 교차 축의 시작하는 지점과 끝나는 지점을 지칭한다. 아래 이미지를 참고하면 된다.

![](https://velog.velcdn.com/images%2Flshn1007%2Fpost%2Fb1825ccd-8b5a-4a2d-abea-e29d0e8498ea%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-07-19%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.23.21.png)

