React Native 동작 원리
===

> React Native 는 개발자와 운영 체제(Android, ios)를 이어주는 인터페이스이다.

React Native 가 동작하는 방식은 다음과 같다.

![](https://velog.velcdn.com/images/seoltang/post/17299d47-4c64-459a-9119-90d0223791d7/image.png)

1. (터치 등) 이벤트가 발생한다.
2. 발생한 이벤트를 **Native** (안드로이드/ ios) 에서 감지한다.
3. 브릿지를 통해 JS 로 전송한다.
4. JavaScript 에서 이벤트를 처리한다.
5. JavaScript 에서 native method 를 호출하거나 UI 업데이트 요청을 보낸다.
6. 브릿지를 통해 Native 로 전송한다.
7. Native (안드로이드/ ios) 에서 요청을 수행한다.
8. Native 가 UI 를 업데이트하여 그린다.

## React Native : Infrastructure

![](https://velog.velcdn.com/images/seoltang/post/845d144d-68c4-4d7b-be2c-d210cdd3075e/image.png)

- App 은 위 구조 전체를 포함한다. react native 로 작성한 코드는 ios 코드와 안드로이드 코드로 변환되어 그려진다.
- react native 는 브라우저를 이용하지 않는다. 대신 bridge 를 통해 native(안드로이드, ios) 에 요청을 보낸다.
- 앱을 만들기 위해서는 JS, Markup/Styling 뿐만 아니라 위 그림에 나온 모든 인프라를 설치해야 하지만, 테스트용으로 이 모든것을 대신해주는 `Expo` 를 설치하면 react native 에서 작성한 코드를 안드로이드/ ios 에서 바로 실행해 볼 수 있다. `Expo`  는 위 그림에서 파란색 영역(JS, Markup/Styling) 만 비워 놓은 App 과 같아서, 우리가 JS 와 Markup/Styling 코드만 작성해 넣으면 앱을 실행할 수 있다. 다만 실제 앱을 만들어 배포하려면 Java, Xcode 등 필요한 인프라를 설치해야 한다.