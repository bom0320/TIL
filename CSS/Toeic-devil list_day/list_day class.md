list_day 클래스 
===
```
.list_day {
    display:flex;
    flex-wrap:wrap;
}
```
`display: flex;` : list_day 클래스가 적용된 ul 은 이제 Flexbox 레이아웃을 사용한다. Flexbox 는 리스트 아이템들이 한 줄에 나란히 배치되도록 해준다.

`flex-wrap: wrap` : 이 속성은 리스트 아이템들이 한 줄에 다 들어가지 않으면 다음 줄로 넘어가도록 한다.

ex) 화면이 좁아지면 항목들이 다음 줄로 넘어가면서 반응형으로 정렬된다.


