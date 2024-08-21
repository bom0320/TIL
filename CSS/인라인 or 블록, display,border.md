인라인 or 블록
===

## 블록 레벨 요소
- 자기가 속한 영역의 너비를 모두 차지하여 블록 형성
- **ex)** div, p, h1 등

## 인라인 요소
- 자기에게 필요한 만큼의 공간만 차지
- 기본적으로 자기가 필요한 영역만 차지하기 때문에 높이와 너비를 임의로 조정 할 수 없음!!
- 단, inline-block 으로 바꿔주면 변경 가능!!
- **ex)** span, a 등

## display 속성
- display 속성은 요소를 블록과 인라인 요소 중 어느 쪽으로 처리할지 정의
- 미리 정의되어 있는 키워드를 속성값으로 지정

```
inline: 인라인으로 처리
block: 블록레벨로 처리
inline-block: 인라인으로 배치하되, 블록 레벨 요소의 속성을 추가할 수 있도록 처리
none : 디스플레이(표시)하지 않음. (요소에서 사라지진 않음!!)
```

## border 속성
- border 속성을 사용하면 요소가 차지하고 있는 영역에 테두리를 그릴 수 있음
- 속성값으로 테두리의 두께, 모양, 크기 등을 함께 지정할 수 있는데 이를 "단축속성" 이라고 함.
- 지정하는 값들을 따로따로 지정할 수 있음!

```
border-color: color 정의 방식과 동일
border-width: thin,medium, thick 등의 키워드 또는 px,em,rem 등의 단위
border-style: none(기본값), solid(직선), dotted(점선), dashed(긴 점선) 등
```

ex
```
span{border: 2px solid green;}
-> 두께가 2px 인 직선 모양(solid)의 초록(green) 테두리를 만들어줘!
```

### 요약
- display 속성은 요소의 블록 레벨, 인라인 여부를 변경 처리 할 수 있음
- display 속성은 요소를 배치할 레이아웃을 결정할 때 사용될 수 있음
- border 속성은 요소가 차지하는 영역에 테두리를 그릴 수 있음
- border는 여러가지 속성을 함께 정의할 수 있는 "단축속성"
- border의 하위 속성은 border-style, border-width. border-color 가 있음