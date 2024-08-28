splice()
===
- **splice :** 배열의 기존 요소를 삭제 또는 교체하거나 새 요소를 추가하여 기존 배열의 내용을 변경하고 삭제한 데이터들을 배열로 반환한다.


## splice 정의
- ***splice :** (밧줄의 두 끝을) 잇다, (필름 테이프 등의 두 끝을) 붙이다. 

## splice() 사용법
다음은 splice() 함수 구문이다. 

> **array.splice(start [, deleteCount [, item1 [, item2 [,...]]]])**

### start (필수)
- 배열의 **변경을 시작할 인덱스**이다.
- 배열의 길이보다 큰 값이라면 실제 인덱스는 배열의 길이로 설정된다. 
- 음수인 경우 끝에서부터 요소를 새어 나간다. 단, 절댓값이 배열의 길이보다 크면 0 으로 설정된다. 

### deleteCount(선택)
- 배열에서 제거할 요소의 수이다.
- 생략하거나 array.length - start 보다 크면 start 부터의 모든 요소를 제거한다. 
- 0 이하라면 어떤 요소도 제거하지 않는다. 

### items1, item2. ... (선택)
- 배열에 추가할 요소이다.
- 요소를 지정하지 않으면 splice 는 요소를 제거하기만 한다.

splice 사용법은 간단하다. 위의 내용을 참고해서 splice 함수의 인자 값에 시작 인덱스, 삭제할 개수, 추가할 데이터만 넣어 주면 된다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FdNiCYT%2FbtszGV4gFTv%2FiR4Tyt6JM81VhG8NZQ0z9K%2Fimg.png)
위의 예제를 보면 splice 는 기존 배열을 변형시키고 삭제된 데이터를 반환한다. 

