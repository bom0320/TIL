프로미스(promise) 란?
===

## 프로미스(promise)

> Promise 는 JavaScript 에서 비동기 작업을 처리하기 위한 객체이다
> 

여기서 비동기 작업이란, 시간이 걸리는 작업을 말한다. 예를 들어, 서버에서 데이터를 가져오거나, 파일을 읽는 작업 등이 있다. 이러한 작업을 동기적으로 처리하면, 작업이 완료될 때까지 프로그램이 멈춰버리게 된다. → **이를 해결하기 위해 비동기 작업이 필요!!!!!!**

자바스크립트는 비동기 처리를 위해 콜백 함수를 사용한다. 하지만 콜백을 너무 남용하게 되면 우리가 흔히 부르는 콜백 지옥에 빠질 수 있다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FWM9Hj%2FbtrwgC1SXvh%2F9MTRpsBhz5O46KBxCKkcX0%2Fimg.jpg)

또한 에러처리도 힘들 뿐더러 여러 개의 비동기 처리를 한번에 하는데 한계가 있다. 이런 콜백 함수의 단점을 보완하여 비동기 처리에 사용되는 객체를 **프로미스(promise)** 라 한다. 

### 프로미스의 이점

- **비동기 처리 시점을 명확하게 표현**할 수 있다.
- 연속된 비동기 처리 작업을 수정, 삭제, 추가하기 편하고 **유연**하다.
- **비동기 작업 상태를 쉽게 확인**할 수 있다.
- 코드의 **유지 보수성이 증가**한다.

### Promise 의 주요 개념

promise 는 세 가지 상태를 가진다. 

1. **대기(Pending) :** 초기 상태, 아직 작업이 완료되지 않은 상태.
2. **이행(Fuflled) :** 작업이 성공적으로 완료된 상태
3. **거부(Rejected) :** 작업이 실패한 상태

## Promise 의 사용 방법

promise 객체는 보통 다음과 같이 생성한다.

```jsx
const promise = new Promise((resolve, reject) => {
  // 비동기 작업 수행
  let success = true; // 예시로 성공 여부를 나타내는 변수

  if (success) {
    resolve('작업이 성공했습니다!'); // 성공 시
  } else {
    reject('작업이 실패했습니다.'); // 실패 시
  }
});

```

여기서 **resolve 는 작업이 성공했을 때 호출**되며, **reject 는 작업이 실패했을 때 호출**된다.

## Promise 처리

Promise 가 완료되었을 때(성공하거나 실패했을 때) 무엇을 할지 정의하려면 **then** 과 **catch** 메서드 사용

```jsx
promise
  .then((result) => {
    console.log(result); // '작업이 성공했습니다!' 출력
  })
  .catch((error) => {
    console.error(error); // '작업이 실패했습니다.' 출력
  });

```

- **then 메서드**는 Promise 가 **성공**했을 때 실행할 코드 정의
- **catch 메서드**는 Promise 가 **실패**했을 때 실행할 코드 정의

### EX: 서버에서 데티터 가져오기

다음은 서버에서 데이터를 가져오는 예시이다.

```jsx
function fetchData() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      const success = true; // 데이터 가져오기가 성공했다고 가정
      if (success) {
        resolve({ data: '서버에서 가져온 데이터' });
      } else {
        reject('데이터를 가져오는 데 실패했습니다.');
      }
    }, 1000);
  });
}

fetchData()
  .then((result) => {
    console.log(result.data); // '서버에서 가져온 데이터' 출력
  })
  .catch((error) => {
    console.error(error); // '데이터를 가져오는 데 실패했습니다.' 출력
  });

```

위 예제에서 fetchData 함수는 1초 후에 데이터를 가져오는 Promise 를 반환한다. 데이터가 성공적으로 가져오면  resolve 를 호출하고 실패하면 reject 를 호출한다. 

### 마치며..

- **Promise** 는 비동기 작업의 결과를 나타내는 객체이다.
- **세 가지** 상태를 가진다. : 대기, 이행, 거부
- **then** 과 **catch** 를 사용하여 작업이 성공했을 때와 실패했을 때의 처리를 정의할 수 있다.

이렇게 Promise 를 사용하면 비동기 작업을 더욱 직관적이고 명확하게 처리할 수 있다.