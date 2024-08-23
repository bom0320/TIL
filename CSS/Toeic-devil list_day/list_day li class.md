list_day li 클래스
===
```
.list_day li {
    flex: 20% 0 0;
    box-sizing: border-box;
    padding:10px;
}
```
`flex: 20% 0 0;` : 각 li 항목은 부모인 ul 의 너비의 20% 를 차지한다. 즉, 한 줄에 최대 5개의 li 항목이 들어갈 수 있다.
`box-sizing: border-box;` : 이 속성은 요소의 패딩과 테두리를 요소의 너비와 높이에 포함시켜, 레리아웃을 예측 가능하게 만든다. 
`padding: 10px` : 각 li 항목 내부에 10px 의 여백을 추가하여, 콘텐츠와 경계 사이에 공간을 둔다.

