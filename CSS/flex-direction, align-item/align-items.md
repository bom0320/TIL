align-items
===
![](https://velog.velcdn.com/images%2Fteo%2Fpost%2Fef254325-a342-4875-ac99-e418b29aa9d7%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-04%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%209.15.29.png)

두 번째는 어디에 배치하는 것인가 이다.

배치하는 방향과 **cross한 축의 위치**(교차축)를 결정하는 것이 **align-item** 이다.

hbox 의 경우 대부분이 Toolbar 와 같은 UI이므로 대부분 가운데 정렬이니 hbox 를 아래와 같이 만들겠다. 

```
.hbox {
    display:flex;
    flex-direction: row;
    align-items: center /* hbox 는 가운데 정렬이 default 이면 편하다! */
}
```
**cross한 축의 위치** 라고 했으니 남은 곳의 위 아니면 아래이다.


> `align-items: flex-start` 면 위,
> `align-items: flex-end` 면 아래이다.

```
.hbox\(top\) {
    display: flex;
    flex-direction: row;
    align-items: flex-start;
}

.hbox\(bottom\) {
    display: flex;
    flex-direction: row;
    align-items: flex-end;
}
```
위, 아래가 아니라 꽉 채우는 방식도 있다.

```
.hbox\(fill\) {
    display: flex;
    flex-direction: row;
    align-items: stretch;
}
```
stretch 는 오타를 많이 내서 fill이라고 이름을 지음

