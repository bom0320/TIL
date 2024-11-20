04 Expo SDK 버전 충돌 및 Node.js 문제 해결 기록
===
만약 Node.js 에 문제가 없고 환경 변수도 올바륵 설정되어 있다면, 아래와 같은 **`expo upgrade` 명령어 관련 오류**는 다음과 같은 이유로 발생했을 가능성이 높다.

![](https://private-user-images.githubusercontent.com/167315197/387963040-cd9083aa-aa75-443e-be10-6bc896dd1c5f.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzIwODMzNDUsIm5iZiI6MTczMjA4MzA0NSwicGF0aCI6Ii8xNjczMTUxOTcvMzg3OTYzMDQwLWNkOTA4M2FhLWFhNzUtNDQzZS1iZTEwLTZiYzg5NmRkMWM1Zi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTEyMFQwNjEwNDVaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1iYzc2YTljYzc4YjlkNjlkMTgwMzAxYTQ2Mjg3MmVhNWUyYWZiZjRjYzk4MzYxZDI4NjQ5NDkzNjg1ZWIwMDc2JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.sbMIAtINRzmIMgF8oCU-tlFS5ypxAmY0K9Z-Ij5GUFw)

### 원인:

1. **레거시 Expo CLI 사용 중**:
    - 이 메시지는 기존 **레거시 Expo CLI** (`expo-cli`)를 사용하고 있을 때 나타난다..
    - 최신 Expo CLI는 `expo upgrade` 명령어를 지원하지 않으므로, 대신 **수동으로 Expo SDK를 업그레이드**해야 한다.
2. **로컬 Expo CLI 사용 요구**:
    - Expo SDK 52 이상에서는 레거시 CLI 대신 **로컬 CLI** (`npx expo`)를 사용해야 한다.
    - `expo-cli`를 통해 실행하려고 할 때 지원되지 않아 발생한 문제이다.

---

### 해결 방법:

Node.js에 문제가 없다는 전제하에, 아래의 단계를 따라 해결할 수 있다.

### 1. **`package.json`에서 Expo 버전 수동 변경**

- `package.json` 파일을 열고 Expo 버전을 직접 수정한다.

```json
"expo": "~52.0.0"
```

### 2. **필수 종속성 설치**

- Expo SDK 버전 변경 후, 필요한 패키지를 설치한다.

```bash
npx expo install
```

이 명령어는 Expo SDK에 맞는 종속성 패키지들을 자동으로 설치한다.

### 3. **캐시 정리**

- 만약 이전 종속성 충돌로 문제가 발생했다면 캐시를 정리한 뒤 실행한다:

```bash
expo start -c
```

---

### 결론:

- Node.js 문제가 없다면, 위 해결 방법을 사용해 **수동으로 Expo SDK 버전을 업데이트하고 필수 패키지를 설치**하면 문제가 해결된다.
- `expo upgrade` 명령어는 더 이상 레거시 CLI에서 지원되지 않으므로, 수동 업데이트가 필요하다.

---
#### 📌 최종 요약
Node.js에 문제가 없다면, 아래처럼 해결:

1. package.json에서 Expo 버전을 최신 버전으로 수동 수정.
2. npx expo install로 종속성 설치.
3. expo start -c로 캐시 정리 후 실행.
---