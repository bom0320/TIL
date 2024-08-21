flexbox #2
===
**주측 배치 방법** 
justify-content: center /flex-start /flex-end /space-around /space-between
**교차축 배치 방법**
align-items: 위와 같음
**교차축 개별요소 배치 방법**
align-self  >> div class 에 self 개별 self 넣어주고 설정
**줄 바꿈 여부**
flex-wrap / flex-wrap-reverse

### 요약
1. justify-content는 flexbox 주축에서의 요소 배치 방법 정의
2. align-items 는 flexbox 교차축에서의 요소 배치 방법 정의
3. align-self 는 flexbox 내 개별 요소의 교차축 배치 방법을 정의
4. flex-wrap 은 개별 요소들의 도합 크기가 컨테이너 주축 길이보다 커졌을 때의 처리 방법 및 방향 정의
