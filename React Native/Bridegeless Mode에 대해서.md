Brideless Mode 에 대해서
===

![](https://private-user-images.githubusercontent.com/167315197/387881575-67aff140-b2ee-4fa4-b2ea-a3f6715da409.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzIwNjI1ODksIm5iZiI6MTczMjA2MjI4OSwicGF0aCI6Ii8xNjczMTUxOTcvMzg3ODgxNTc1LTY3YWZmMTQwLWIyZWUtNGZhNC1iMmVhLWEzZjY3MTVkYTQwOS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTEyMFQwMDI0NDlaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xYTcxMGI0ZmZkMWU5OGQxMzM1Zjg3N2NiMDBhMWE1MjNmNmExMmRiZDk3MzM2N2M5MTY1NTViNmQxYzMzZmQ1JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.ABqXumacO5rIuvhoOMOK2XnV5l5JVH-oevGLiobSRD0)
먼저 이 사진을 보면 **Brideless mode is enabled** 라는 메시지가 나타나고 있다. 이는 **React Native New Architecture** 에서 **Bridgeless Mode** 가 활성되어있다는 것을 의미하며, New Architecture 가 정상적으로 작동 중임을 알려준다. 하지만 이 설명으론 이런 메시지가 왜 떴는지 등을 제대로 이해할 수가 없다..! 먼저 Birdeless Mode 가 뭔지 부터 차근차근 알아보도록 하자

---

## 1. 기존 React Native 의 구조 (Bridge 방식)
- 기존 React Native 앱은 JavaScript 와 **네이티브 코드 (Android, ios)** 가 **Bridge(브릿지)**를 통해 서로 통신한다.
    - JavaScipt 에서 네이티브 기능(Android, ios 의 하드웨어나 API 등)을 호출하거나 데이터를 전달하려면 브릿지를 통해야 했다.
    - 예를 들어, 화면 전환 요청이나 GPS 데이터를 가져오는 등의 작업은 브릿지를 통해 이루어졌다.


### 문제점
- 브릿지는 일종의 "중간 다리" 역할을 하기 때문에, 통신 속도에 제한이 생기고 대량의 데이터 전송 시 성능 문젝, 발생할 수 있다.
- 브릿지가 동작하는 동안 JavaScript 스레드와 네이티브 스레드 간의 동기화 문제로 인해 지연(Lag) 이나 버그가 발생할 가능성이 있다.

---

## 2. Bridgeless Mode 란?
- Brideless Mode 는 브릿지 없이 **JavaScript 와 네이티브 코드** 간에 직접 통신하도록 설계된 새로운 방식이다.
- **React Native New Architecutre** 에서 제공하는 기능으로, 브릿지의 병목 현상을 없애고 성능을 개선하는 것이 목표이다.

### 장점 
1. **더 빠른 통신 속도 :**
- 브릿지 없이 JavaScript 와 네이티브 코드가 직접 통신하므로 통신 속도가 빨라진다.

2. **성능 향상 :**
- 앱의 성능이 더 부드러워지고 반응 속더가 빨라진다.

3. **더 나은 개발 경험 :**
- 네이티브 코드와 JavaScript 간 통신 구조가 단순해져 디버깅이 쉬워진다.

### 단점
- **호환성 문제 :**
- 일부 오래된 라이브러리나 패키지가 Bridgeless Mode 를 지원하지 않을 수 있다.

- New Architecture 를 기반으로 하기 때문에 아직 완전히 안정화되지 않았을 수 있다.

---

## 3. 지금 왜 활성화되었나?
- **New Architecuture** 를 활성화하면서 Bridegeless Mode 도 자동으로 활성화되었다.
- 이는 Expo New Architecutre 를 기본으로 지원하며, 최신 React Native 의 성능을 체험할 수 있도록 설계했기 때문이다.

---

## 4. 해야 할 일

### 1. 테스트
- 앱이 정상적으로 실행되고, 기능에 문제가 없다면 Bridegeless Mode 를 유지해도 괜찮다.

### 2. 비활성화 (문제가 발생한 경우):
- 만약 앱 실행 중 특정 라이브러리와 호환성 문제가 있거나 에러가 발생한다면 Bridegeless Mode 를 비활성화할 수 있다.
- 이를 위해 `app.json` 파일에서 `"newArchEnabled" : false` 로 설정한다.

```json
{
  "expo": {
    ...
    "newArchEnabled": false
  }
}
```

설정 변경 후 Expo 서버를 다시 시작한다.

```bash
npx expo start -c
```

#### 결론
Bridegeless Mode 는 성능 개선을 위해 React Native 에서 제공하는 최신 기능이다. 현재 앱이 정상적으로 작동하고 있다면 걱정할 필요 없이 그대로 사용하면 된다.