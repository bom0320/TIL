flex-direction
===
![](https://velog.velcdn.com/images%2Fteo%2Fpost%2Fbcae6193-ae2c-4d08-b66f-c8eeb8978cb4%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-04%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%209.12.47.png)
가로로 배치하는 flexbox 를 만들어보자
row 라는 이름보다는 horizontal 로, horizontal 은 너무 기니 **h**orizontal flex**box**를 따와서 hbox 로 지었다.

```
.hbox {
    display: flex;
    flex-direction: row;
}
```
마찬가지 방법으로 세로도 만들어보자
```
.vbox {
    display: flex;
    flex-direction: column;
}
```
