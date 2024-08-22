pack
===
컨텐츠를 가운데에 배치하는 것은 매우 빈번한 작업이다 `hbox(center)` 와 같이 쓸 수도 있겠지만 빈도를 고려해서 더 짧은 이름의 유틸리티를 두고 사용하면 좋다.
```
.pack {
    display: flex;
    align-items: center;
    justify-content:center;
}
```
> `margin:auto` 를 이용해서 가운데 정렬을 하는 방법도 배울텐데 가급적 margin 을 쓰지 않는다는 원칙에 따라 위 방식을 추천