space
===
- margin 을 안쓰고 우리에겐 **gap** 이 있지만 그럼에도 디자인에 따라 다른 간격을 넣어야 하는 경우가 생긴다.
- 그래서 이것 때문에 사실 또 마진을 써야하되는 경우가 생긴다.
- 하지만 우리는 margin 을 쓰지 않을 거기 때문에 2가지 해결법을 제시한다.

## 1. gap 방식을 쓰기 위해서 둘 엘리먼트만 묶어서 별도의 컨테이너를 만든다
조금 귀찮지만 figma 에서는 이러한 방법 밖에 없기도 하고 좋은 방법이다.

```
<style>
  .gap\(4\) { gap: 4px; } /* 표준 스펙 */
  .gap\(8\) { gap: 8px; } /* 표준 스펙 */ 

  .hgap\(4\) > * + * { margin-left: 4px; } /* IE, Safari 14 지원용 polyfill */
  .hgap\(8\) > * + * { margin-left: 8px; } /* IE, Safari 14 지원용 polyfill */
</style>

<div class="hbox gap(4)"> <!-- 최신 브라우저에는 gap을 쓰자. -->
  <div>h</div>
  <div>b</div>
  <div class="hbox hgap(8)"> <!-- IE, Safari 14이하를 지원해야 한다면 hgap형태로 쓰자! -->
    <div>o</div>
    <div>x</div>
  </div>
</div>
```

## 2.그냥 빈 <div></div> 를 만들고 width 나 height 를 입력한다.
이것도 전혀 나쁘지 않은 방법이다. 간격을 위한 빈 엘리먼트를 만드는 것에 대해서 부정적일 수있지만 사실 전혀 분제 되지 않는다.

대부분 디자인 명세는 엘리먼트와 엘리먼트 사이의 간격을 표기해준다.

코드상으로도 그렇게 구현되어 있다면 더 직관적으로 여기에 대한 간격이 얼만큼 떨어져 있구나라는 것를 좀 알 수 있기 때문에 좋다.

```
<style>
  .hspace\(4\) { width:4px }
  .hspace\(8\) { width:8px }
</style>

<div class="hbox">
  <div>h</div>
  <div class="hspace(4)"/>
  <div>b</div>
  <div class="hspace(4)"/>
  <div>o</div>
  <div class="hspace(8)"/>
  <div>x</div>
</div>

```
