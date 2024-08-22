justify-content
===
- 배치하는 **방향과 나란한 축**의 배치를 결정하는 속성이다.
- 기본은 왼쪽이니까 가운데와 오른쪽의 경우만 만들어 보면 될듯
```
.hbox(center) {
    display:flex;
    flex-direction: row;
    align-items:center;
    justify-content:center;
}

.hbox(right) {
    display: flex;
    flex-direction: row;
    align-items: center;
    justify-content: flex-end;
}
```

justify-content: space-between
===

![](https://velog.velcdn.com/images%2Fteo%2Fpost%2F6a465396-e890-4df2-b894-66d88f205d7f%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-04%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%209.21.20.png)

나란한 축의 특징은 **space-between** 이라는 스펙이 존재한다는 것이다. 이는 조립해서 쓰기 좋은 속성이므로 따로 만들어주자.
`justify-content` 와 `space-between` 을 세트로 외워두면 align-items 과 헷갈리지 않을 것

```
.space-between {
    justify-content: space-between;
}
```
```
<div class="hbox(top) space-between"></div>
```

