content-box vs border-box
===

## box-sizing
CSS 속성중 `box-sizing`은 **너비(width)와 높이(height) 를 계산하는 방법을 지정**하는 것!

**예시 코드 (img 태그)**
```
{
	box-sizing: ?????????
	height: 100px;
    width: 100px;
    border: 10px solid;
    padding: 10px;
    margin: 10px;
}
```
예시 이미지는 크롬 개발자 도구의 스타일 박스로 가져옴

## content-box
> 너비와 높이가 "content" 기준인 것!

중앙의 컨텐츠(이미지)를 100x100 으로 기준을 잡고, 겉의 padding, border, margin 은 width,height 에 영향을 받지 않고 쌓아진다. 

따라서 padding, border, margin 의 사이즈를 어떻게 주어도 이미지의 크기는 고정이 되고 겉으로만 사이즈가 커지게 된다.

예시에서는 padding, border, margin 에 관계 없이 지정한 그대로 이미지의 사이즈는 100x100 이다. 

## border-box

![](https://velog.velcdn.com/images/sumnii/post/a580658f-22cc-4e9a-a6d6-5daf25464077/image.png)

> 너비와 높이가 "border" 기준인 것!

`border`까지 포함된 사이즈를 100x100 으로 기준을 잡고, 거거의 margin 은 width 나 height 에 영향을 받지 않고 쌓여진다. 

따라서 margin 의 사이즈와 관계 업싱 이미지의 크기는 고정이 되고 겉으로만 사이즈가 커지게 되고, padding, border 사이즈는 이미지의 크기에 영향을 주어 작아질 수 있다.

예시에서는 padding 과 border 를 각 10px 씩 주었으므로 이미지의 사이즈가 60x60 이 되었다.

# 결론

`content-box` : `box-sizing` 속성의 기본값
- width/height 지정 사이즈 = content 사이즈
- **전체 영역 사이즈 :** 지정 사이즈(width*height) + padding + border + margin

`border-size`
- width/height 지정 사이즈: content + padding + border
- content 사이즈: 지정 사이즈 - border - padding
- 전체 영역 사이즈: 지정 사이즈(width*height) + margin

**margin 은 모든 박스 사이징의 지정 사이즈 및 content 사이즈에 영향을 주지 않는다! 단지 전체 영역 사이즈에만 영향을 줄 뿐!**