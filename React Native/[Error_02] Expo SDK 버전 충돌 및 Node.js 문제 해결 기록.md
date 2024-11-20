02 Expo SDK 버전 충돌 및 Node.js 문제 해결 기록
===
 전에 글을 보면 알듯이, windows 에서 node.js 버전을 확인해보니 `20.16.0` 이였던 반면, 터미널에 `node -v` 를 하니, `18.13.0` 이 뜨는 아주 아이러니한 상황이 발생했었다.

![](https://private-user-images.githubusercontent.com/167315197/387979572-26ff64a6-9a5f-492a-a14f-4c092589498b.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzIwODYxMTEsIm5iZiI6MTczMjA4NTgxMSwicGF0aCI6Ii8xNjczMTUxOTcvMzg3OTc5NTcyLTI2ZmY2NGE2LTlhNWYtNDkyYS1hMTRmLTRjMDkyNTg5NDk4Yi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTEyMFQwNjU2NTFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1kNGIyY2Y1YjM5NDIwMzkwMDFhMWM0Yjk2YTExNjgwNTRlZWU0ODdjYjlmMjg5MjA1MDhjMTdlMGQxOGNhZTNjJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.8LDBJ8h_YGvz43-QY-IW5iwVzMCkmsD8Zoea98OJEI4)

---
보통 이런 문제는 **다중 Node.js 설치로 인한 경로 우선순위 문제**에 의해 발생하는 경우가 파다하다고 한다. (여기에 관련된 내용은 따로 정리하겠다.)하지만 내가 겪은 이 문제는 다중 node.js 설치로 인한 경로 우선순위로 인한 문제와는 약간 다른 가정에서 출발한다. 

## 왜 현재 상황과 다를까?

### 1. 먼저 나는 Node.js 를 다중 설치한 상태가 아니였다.
- `nvm` 이나 다른 경로로 구버전을 설치한 적이 없었으며, **Node.js 가 단일 경로에서만 설치된 상태**였다.
- 다만, Node.js 를 제거했다가 다시 설치했을 때, 환경 변수에 경로가 제대로 추가되지 않아서 터미널이 최신 버전을 인식하지 못한 상태였다.

### 2. 환경 변수의 경로 누락이 주요 원인이었다.
- `Path` 에 `C:\Program Files\nodejs` 경로가 없었기 때문에, 터미널은 이전에 설치되었던 구버전 경로(예: `C:\Users\user\AppData\Roaming\npm`) 또는 잔여 파일이 남은 경로를 참조한 것이다. 

---

## 1. 환경 변수 설정 문제
Windows 운영 체제는 명령어를 실행할 때, **환경 변수의 `Path` 에 등록된 경로를 순서대로 검색**하여 실행 가능한 파일을 찾는다.

#### 왜 구버전이 실행됐을까?
- Node.js 를 제거하거나 다시 설치할 때, **환경 변수의 경로가 제대로 업데이트되지 않았기 때문**이다.
- 예를 들어, `Path` 변수에 최신 Node.js 경로(`C:\Program Files\nodejs`) 가 추가되지 않은 상태에서:

1. 과거에 설치된 구버전 경로가 남아 있는 경우 (ex: `C:\Users\user\AppData\Roaming\npm`)
2. 혹은, 잘못된 경로가 `Path` 에 우선적으로 설정된 경우

이로인해 **터미널이 과거 경로에 참조하여 구 버전을 실행하게 된 것이다.**

## 2. Node.js 잔여 파일 문제
Node.js 를 제거할 때, 구버전의 설치 경로와 파일이 **완전히 제거되지 않는 경우**도 발생할 수 있다. 이 경우,
- 터미널은 여전히 구버전의 `node.exe` 를 참조하며 실행한다.
- 이는 `npm` 이나 기타 Node.js 도구가 설치되었던 경로에 잔여 파일이 남아 있는 경우에 발생할 수 있다.

⭐ **이러한 오류가 발생할 수 있기 때문에, window 에서 node.js 를 확실히 지우고 재설치 하는게 중요함!!!!!**

## 3. 문제의 원인
이 상황은 다음과 같은 이유로 발생했을 가능성이 높다.

### 1. 환경 변수에서 최신 경로 누락
- Node.js 를 설치했지만, `C:\Program Files\nodejs` 경로가 환경 변수 `Path` 에 자동으로 추가되지 않았음

### 2. 이전 경로가 환경 변수에 남아 있었음 
- 과거 Node.js 설치로 인해 생성딘 경로 (예: `C:\Users\user\AppData\Roaming\npm`)가 `Path`에 남아 있었을 수도 있음

### 3. 환경 변수 경로 우선순위
- Windows 는 환경 변수 `Path` 에 등록된 경로를 **순서대로 검색**한다.
- 구버전 경로가 최신 경로보다 상위에 있을 경우, 구버전이 실행된다.

### 결론
이 상황은 Windows 환경 변수 설정 문제와, **Node.js 제거 및 재설치 과정에서 발생한 경로 누락과 잔여 파일 참조로 인해** 발생한 문제였다. `Path` 변수에서 구버전 경로를 삭제하고, 최신 Node.js 경로를 추가하면 문제가 해결될 수 있었다.

---
#### 📌 최종 요약
- Node.js 버전이 제대로 작동하지 않은 이유는 환경 변수 설정 문제와 잔여 파일로 인한 경로 참조 오류 때문.
- 과거 경로를 삭제하고 최신 Node.js 경로를 환경 변수에 추가하여 문제를 해결.
---