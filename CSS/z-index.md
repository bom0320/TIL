z-index (가로와 세로만 있는게 X)
===
- 요소의 쌓임 선서(stack order)를 정의할 수 있음
- 정수 값을 지정하여 쌓임 맥락(stacking context)에서의 레벨을 정의하는 방식으로 적용
- 위치 지정 요소에 대해 적용할 수 있는 속성
- 위치 지정 요소란? = position 속성이 정의되어 있는 요소
- 동일한 위치에 요소들이 배치되면, 요소들은 z축에 쌓이게 됨!
- z-index 의 기본값은 auto 이다.
- auto는 새로운 쌓임 맥락이 형성되지 않은 자연스러운 상태.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FJ9RId%2Fbtry9o0UWo6%2F53KWWXNTGibIRqtjeZCj41%2Fimg.png)

### 요약
- z-index 는 요소가 쌓이는 순서를 결정할 수 있음
- 기본값은 auto이며, 정수값으로 정의
- 정수값은 쌓임 맥락에서의 레벨을 의미하며, 값이 클수록 전면에 표시