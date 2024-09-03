React Native 인프라
===
React Native 앱은 JS 로만 이루어지지 않는다(js는 앱에서 가장 작은 부분임)

![](https://www.researchgate.net/profile/Andreas-Biorn-Hansen/publication/323381516/figure/fig5/AS:654720431579138@1533108923685/React-Native-Interpreted-approach-architecture.png)

React Native 앱에서 가장 중요한 부분은 Bridge 를 통해서 코드가 운영체제와 통신을 할수 있도록 하는 인프라시설이다. -> 이런 것들이 바로 React Native 앱을 구성하는 것이다.

즉, React Native 앱을 다운받을 때 우리는 only JS 코드만 다운 받는것이 아니고, 이 모든 기본 시설이 있는 앱을 다운 받는것이다. 

그 기본 시설은 JS 코드가 운영체제와 이야기 할 수 있도록 해준다. (이걸 분명히 알고 있어야함!!!)

#### React Native === shall
- 우린 JS 코드를 넣고, 그 코드는 운영체제와 이야기를 할 수 있는 것이다. => 이런 이유로 Java 가 설치되어 있어야하고,  Xcode 가 설치되어 있어야하는 거임 

**우리는 실제로 앱을 만들어야 하기 때문!!**
-> 우리는 이 앱을 compile 시켜줘야 한다. (그리고 보통 사람들은 이런식으로 함)

사람들이 React Native 앱을 만들때, 코드를 쓰고, 모든것이 준비가 되었을 때 이 앱을 compile 시키고, 이 모든 인프라시설들은 안드로이드의 경우에는 apk, ios 의 경우에는 ipa 가 되는것 

 => 이런 이유로 Xcode 가 필요하고 Java 가 필요한 것!! (java 와 Xcode 로 이 인프라를 가져와서 이것들은 apk 와 ipa 안에 넣어준다.) 
 
 => 그리고 나서 app store 에 보내지는 것이다. (그래서 누군가가 너의 앱을 다운받으면 이런 것들을 모두 다운받게 된다.) 이 모든것들을 다운 받고, 거기 위에 추가적으로 너의 JavaScript 와 CSS 코드를 받는다. 


난 compile 을 해서 앱을 만드는게 아닌, 대신에 expo 를 이용할꺼임 expo 는 우리의 React Native 코드를 곧바로 폰으로 전송시켜주는얘이고, expo 는 폰안에 있는 React Native 코드를 실행시켜서, 말 그대로 폰에서 React Native 코드를 바로 미리보기 할 수 있기 때문

### Expo CLI 설치
```
Expo CLI 설치
npm install --global expo-cli

혹시 에러가 있다면 아래와 같이 설치하시면 됩니다.
sudo npm install --global expo-cli

https://docs.expo.dev/
```