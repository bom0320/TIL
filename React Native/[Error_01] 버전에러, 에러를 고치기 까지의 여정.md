01 버전 에러, 에러를 고치기 까지의 여정
===

expo 로 개발을 하고 있던 도중, 다음날 expo 를 들어가 보니 갑자기 이런 오류가 발생했다. 이번 글에서는 이 오류를 어떻게 해결했고, 왜 이런 오류가 발생했는지 등에 대해서 설명해보고자 한다.

<img src="https://private-user-images.githubusercontent.com/167315197/387953293-86c2d2c0-84d5-4867-b27b-61cc52c57084.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzIwODE2OTQsIm5iZiI6MTczMjA4MTM5NCwicGF0aCI6Ii8xNjczMTUxOTcvMzg3OTUzMjkzLTg2YzJkMmMwLTg0ZDUtNDg2Ny1iMjdiLTYxY2M1MmM1NzA4NC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTEyMFQwNTQzMTRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05MDk1YzUyZTdhOGFjOThjM2U5Y2RjMTllOGRlMTYxZTUwY2I2YjY5MzY3MzNhN2I5NzNjYTliMzkzYTFiMDA0JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.VzxBB6pejCy6wSjjShOCET2U6oF79947Se8jHPo6_mg" height="400" />


먼저 해당 오류에 대해 분석을 해보면, 

해당 오류는 현재 프로젝트가 **Expo SDK 51** 을 사용하고 있는데, 설치된 Expo Go 앱은 **Expo 52** 를 요구하고 있기 때문에 발생하는 호환성 문제하고 한다. 즉, 최신 Expo Go 앱은 이전 SDK 버전을 지원하지 않으므로 발생하는 문제라고 할 수 있다. 

그리고 이 문제를 해결하기 위해선 4가지 방법이 있었다.

---
1. Expo SDK 버전 업그레이드 
2. 이전 버전의 Expo Go 사용 (권장 X)
3. ios 시뮬레이터에서 실행
4. 프로젝트 SDK 다운그레이드 (비추천)
---

2번 Expo Go 앱의 이전 버전을 설치하는 방법은 ios 에서는 공식적으로 이전 버전을 설치하는 것이 불가능 하므로, 이 방법은 현실적이지 않기 때문에 권장하지 않는다.

그리고 4번 프로젝트 SDK 를 다운그레이드 하는건 이 버전문제가 발생했을때 많은 사람들이 이 방식으로 오류를 해결했다. 이 방법은 Expo Go 앱 버전을 변경할 수 없을 때 프로젝트를 이전 버전인 SDK 51 에 맞게 다운그레이드 하는 방법이다. 하지만 이는 **최신 기능을 사용할 수 없게 되므로 추천하지 않는다.**


그래서 나는 **1번 (SDK 업그레이드)** 를 해보기로 했다.


---

### 첫번째 방법: expo upgrade 실행
챗 gpt 한테 물어보니.. Expo SDK 를 업그레이드를 하기 위해선 `expo upgrade` 명령어를 터미널에서 실행해야했었다. 하지만...

![](https://private-user-images.githubusercontent.com/167315197/387963040-cd9083aa-aa75-443e-be10-6bc896dd1c5f.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzIwODMzNDUsIm5iZiI6MTczMjA4MzA0NSwicGF0aCI6Ii8xNjczMTUxOTcvMzg3OTYzMDQwLWNkOTA4M2FhLWFhNzUtNDQzZS1iZTEwLTZiYzg5NmRkMWM1Zi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTEyMFQwNjEwNDVaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1iYzc2YTljYzc4YjlkNjlkMTgwMzAxYTQ2Mjg3MmVhNWUyYWZiZjRjYzk4MzYxZDI4NjQ5NDkzNjg1ZWIwMDc2JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.sbMIAtINRzmIMgF8oCU-tlFS5ypxAmY0K9Z-Ij5GUFw)

이런 오류가 발생했다.. ㅜㅜ 이 오류의 원인은 `npx expo upgrade` 명령어가 **로컬 Expo CLI 에서 지원되지 않아서 발생**한 것이라고 한다. 기존 **레거시 Expo CLI** 는 더 이상 Node.js 17 이상을 지원하지 않으며, 새로운 **로컬 Expo CLI** 를 사용하는 것이 필요했다.
해결 방법은 `expo upgrade` 명령어를 사용하는 대신, 아래와 같이 **수동으로 Expo SDK 를 업그레이드**하는 방법이 있었다.


1. `package.json` 파일에서 Expo 버전 수정.
2. `npx expo install` 명령어로 종속성 업데이트.
2. `node_modules` 삭제 후 재설치.
3. 캐시 정리 후 실행.

---

### 두번째 방법: Expo SDK 수동으로 업그레이드

 먼저 나는 프로젝트의 `package.json `파일에 가서 expo 버전을 확인해보니, 난 **Expo SDK 51 (`"expo" : "~51.0.28"`)** 을 사용중이였다. 하지만 내 핸드폰에 설치된 **Expo Go 앱은 SDK 52 이상**을 요구하기 때문에 프로젝트를 실행하는데 문제가 발생했던 것이다. 그리고 이를 해결하기 위해선 **Expo SDK 를 52 이상으로 업그레이드** 해야했었다.


그래서 나는 `"expo" : "~51.0.28"` 을 찾아서 그 버전을 수동으로 변경했다. 

```json
"expo": "~52.0.0"
```

` "expo": "~52.0.0"` 를 변경했으면 이제 필요한 종속성과 관련 패키지를 설치하고 프로젝트를 실행해야한다.

---
#### 종속성 업데이트
- SDK 버전 변경 후, 필요한 패키지를 업데이트:

```bash
npx install
```
---


하지만.. `npx expo install` 을 실행하니, 

```json
PS C:\Users\user\Documents\FourLips\client-2> npm install 
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'undici@6.21.0',       
npm WARN EBADENGINE   required: { node: '>=18.17' },  
npm WARN EBADENGINE   current: { node: 'v18.13.0', npm: '8.19.3' }
npm WARN EBADENGINE }

added 29 packages, removed 120 packages, changed 41 packages, and audited 1045 packages in 42s

79 packages are looking for funding
  run npm fund for details

6 high severity vulnerabilities

To address all issues (including breaking changes), run:
  npm audit fix --force

Run npm audit for details.
PS C:\Users\user\Documents\FourLips\client-2
```
이런 에러가 났다.. ㅎ 

여기서 짚고 넘어가야할 건 `expo install` 은 Expo SDK 버전에 맞는 종속성 패키지를 자동으로 설치하지만, 종속성이 깨지거나 이전 버전의 패키지가 설치되어 충돌할 가능성이 있다는 것이다.

이 오류가 발생한 원인을 간단하게 요약해서 말하면 **`package.json` 업데이트 후 종속성 설치 과정에서 Node.js 버전 문제와 종속성 충돌 문제**가 겹쳐서 나타난것이다. 

---

### 왜 문제가 겹쳤는가?

#### 1. Node.js 버전 불일치
- `package.json` 에서 Expo SDK 또는 다른 종속성을 업데이트하면서 **특정 패키지가 더 높은 Node.js 버전을 요구**하게 되었다. 즉, 쉽게 말하면 내가 수동으로 바꾼게 문제가 된듯..?
- 현재 Node.js 버전(`18.13.0`) 은 요구사항(`>=18.17`) 을 충족하지 못하므로 **`npm WARN EBADENGINE`** 이라는 경고가 발생하게 되었다. 하.. 아마 node.js 를 지웠다 깔게 된 계기가 된 문제인듯..?

#### 2. 종속성 충돌
- Expo SDK 를 업그레이드 한 후, 기존에 설치된 다른 패키지들과 **의존성 버전 충돌**이 발생했다.
- 이로 인해 추가적인 보안 취약점 경고나 패키지 설치 실패 문제가 나타날 수 있다.

근데 정말 신기한게 windows 에서 node.js 버전을 확인해보니 `20.16.0` 이였음. 하지만 터미널에 `node -v` 를 하니, `18.13.0` 이 뜨는 아주 아이러니한 상황................

여기에 대해선 다음 글에서 설명하겠다. (할말이 정말 많아유 ^_T)