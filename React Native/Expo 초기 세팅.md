Expo 초기 세팅 정리
===

## Expo 프로젝트 생성 방법

### 1. 파일 탐색기에서 폴더를 생성한 후:
해당 폴더로 이동하여 터미널에서 다음 명령어 실행:

```bash
npx create-expo-app .
```
(`.` 은 현재 폴더에 프로젝트를 생성하겠다는 의미)

## 프로젝트 생성 후
다음으로 VS Code 를 열어 Terminal 을 열고 이 명령어 실행

```bash
npx expo start
```

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbg20ET%2Fbtr96OwbcRa%2FavU2QrPfqQ43ZieEcO3w31%2Fimg.png)

`npx expo start` 명령어를 실행하게 되면 아래의 그림과 같이 QR 코드가 나오게 된다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FqsIOa%2Fbtr94uSGUfC%2FREEFRq2rKR0ykvyNsCo7vk%2Fimg.png)

휴대폰 expo go 의 Scan QR code 를 통해 해당 QR 을 찍어준다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FxOXWs%2Fbtr93k3UQ0B%2FUT31462zPaKSBKbzgRf300%2Fimg.png)
QR 코드를 찍고 앱을 다운로드하여 아래의 화면이 나오게되면 된다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F3I8KF%2Fbtsaeoqp0yd%2F2fpGvXrksuhMeCimPTxpjk%2Fimg.png)

만약 작업을 **노트북** 으로 하고 **와이파이**를 사용한다면 휴대폰도 **같은 와이파이** 를 사용해야한다.


다음으로 **Web 화면** 을 열어보겠다.

다시 **Visual Studio Code Terminal** 에서 **W** 를 눌러준다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FyBfQS%2Fbtr95pp3YqS%2F7E9fdSk4LMGfw7tGYMVAw0%2Fimg.png)


그럼 아래와 같이 해당 문구가 나오게 된다.
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcKFD6U%2Fbtsae7n9ty0%2FuDLQYaUIUJ1dVfyhow7JKk%2Fimg.png)

**Terminal** 에서 **CTRL + c** 키를 눌러 종료시키고 해당 라이브러리를 설치해준다.

```bash
npx expo install react-dom react-native-web @expo/webpack-config
```

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FchY9GL%2FbtsaeTjxvbb%2FFheKPDm1KTF8DJqcoAMD0K%2Fimg.png)

라이브러리 설치가 완료되면 다시 expo 를 실행하고 expo go 에서 다시 앱을 실행시켜 준다.

```bash
npx expo start
```

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FJePfY%2Fbtsae6QpKUK%2FB1xodoST35j8DbPoBPxqK0%2Fimg.png)

expo go 에선 최근에 열었던 앱에 존해하여 해당 앱을 클릭해준다.

만약 접속이 끝어진 문구 **(Cannot connect to Metro. Try the followin...)** 가 나오면

앱 **(test001)** 을 닫고 다시 실행시켜 준다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FrpHIH%2Fbtsacge62yk%2FRs1fvfgSaKcusdwQ06xSx1%2Fimg.png)

다시 Terminal에서 `W` 키를 눌러 **Web 화면** 을 열어보겠다.

W 키를 누르면 **http://localhost:19006/** 의 URL 와 함께 **web** 이 자동으로 열리게 된다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbdY8gV%2FbtsafOu4Oht%2F6W8wVk7yl2UxSA66A9Fw9k%2Fimg.png)


열린 web 화면
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FnRebm%2Fbtsaeoxnnng%2F4IY6usl6KLQD2IfjfKucZK%2Fimg.png)