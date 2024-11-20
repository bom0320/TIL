03 버전 에러, 에러를 고치기 까지의 여정
===

앞 글에서 설명한 이유로 **Node.js 를 제거한 후 최신 버전을 다시 설치**하기로 했다. (이게 제일 확실한 해결책이라고 함.. 왜냐? 내 node.js 는 문제가 줜나 많기 때문!)

## 첫번째, 제거 및 재설치 

### 1. 제거하기"
- 이미지에서 보이는 "제거(U)" 버튼을 클릭하여 Node.js를 완전히 제거한다.
- 제거가 완료되면, 설치 경로(C:\Program Files\nodejs)에 남아 있는 잔여 파일이 있다면 수동으로 삭제한다.

삭제를 했으면, 그 다음 Node.js 가 완전히 제거되었는지 **확인 작업**을 한다.

Node.js가 완전히 제거되었는지 확실히 하기 위해 아래 단계를 따라 확인

1. **폴더 확인**
    - 파일 탐색기에서 직접 `C:\Program Files`로 이동하여 **`nodejs` 폴더가 존재하는지** 확인한다.
    - 폴더가 존재하지 않으면, Node.js와 관련된 파일이 모두 삭제된 상태임
2. **환경 변수 확인**
    - "환경 변수 편집"에서 `Path` 변수에 **Node.js 관련 경로**가 남아 있는지 확인한다.
    - 만약 **`C:\Program Files\nodejs`** 경로가 남아 있다면 삭제한다.
    - 확인 후 "확인" 버튼을 눌러 저장한다.
3. **캐시 정리 (선택 사항)**
- 명령 프롬프트에서 아래 명령어로 npm 캐시를 정리한다.

```bash
npm cache clean --force
```

### 캐시 정리 명령어를 실행했다면... 
---

```bash
Microsoft Windows [Version 10.0.22631.4460]
(c) Microsoft Corporation. All rights reserved.

C:\Users\user>npm cache clean --force
'npm'은(는) 내부 또는 외부 명령, 실행할 수 있는 프로그램, 또는
배치 파일이 아닙니다.

C:\Users\user>

```
⭐ **이게 나오면 성공!** 
- npm 명령어가 작동하지 않는 이유는 Node.js를 제거한 후, Node.js와 함께 제공되는 npm이 삭제되었기 때문이다. 따라서 이 메시지는 정상


---

## 두번째, Node.js 재설치

- **Node.js 최신 버전 설치**
    - [Node.js 공식 웹사이트](https://nodejs.org/)로 이동하여 **LTS(Long-Term Support)** 버전을 다운로드한다.
    - 다운로드한 설치 파일을 실행하고 기본 설정으로 설치한다.
- **환경 변수 자동 설정**
    - 설치 중에 Node.js 설치 프로그램이 `C:\Program Files\nodejs`를 환경 변수에 자동으로 추가한다.

---

## 세번째, 설치 확인
- 설치가 완료되면, 새 터미널을 열고 다음 명령어를 실행해 설치가 올바르게 되었는지 확인한다.

### 1. node 버전 확인       
```bash
    node -v
```
LTS 버전(`22.11.0`)이 출력되면 정상적으로 설치된 것이다.

### 2. npm 버전 확인

```bash
npm -v
```
`npm` 버전이 출력되면 설치가 완료된 것이다.

### 3. Expo CLI 실행 확인
Node.js 와 npm 이 제대로 설치 되었으면, Expo CLI 를 정상적으로 사용할 수 있는지 확인해본다.

1. **Expo CLI 설치 여부 확인**    
아래 명령어로 Expo CLI가 이미 설치되어 있는지 확인해보자.
    
```bash
    npx expo --version
```    
- Expo CLI 버전이 출력되면 설치된 상태이다.
- 만약 에러가 발생하거나 설치되어 있지 않다면, 아래 명령어로 설치를 진행한다.

2. **Expo 프로젝트 실행**    
프로젝트 디렉토리로 이동한 뒤 Expo 프로젝트를 실행한다.
    
```bash
    npx expo start
```
    
---

#### **만약 Expo CLI가 설치되지 않은 경우**

아래 명령어로 설치 후 사용하기:

```bash
npm install expo-cli --global
```
설치가 완료되면 Expo 프로젝트를 실행하면 된다.

```bash
Microsoft Windows [Version 10.0.22631.4460]
(c) Microsoft Corporation. All rights reserved.

C:\Users\user>node -v
v22.11.0

C:\Users\user>npm -v
10.9.0

C:\Users\user>npx expo --version
Need to install the following packages:
expo@52.0.7
Ok to proceed? (y) y

npm warn deprecated inflight@1.0.6: This module is not supported, and leaks memory. Do not use it. Check out lru-cache if you want a good and tested way to coalesce async requests by a key value, which is much more comprehensive and powerful.
npm warn deprecated @babel/plugin-proposal-class-properties@7.18.6: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-class-properties instead.
npm warn deprecated @babel/plugin-proposal-nullish-coalescing-operator@7.18.6: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-nullish-coalescing-operator instead.
npm warn deprecated rimraf@2.6.3: Rimraf versions prior to v4 are no longer supported
npm warn deprecated @babel/plugin-proposal-optional-chaining@7.21.0: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-optional-chaining instead.
npm warn deprecated rimraf@3.0.2: Rimraf versions prior to v4 are no longer supported
npm warn deprecated glob@7.2.3: Glob versions prior to v9 are no longer supported
npm warn deprecated glob@7.2.3: Glob versions prior to v9 are no longer supported
npm warn deprecated glob@7.2.3: Glob versions prior to v9 are no longer supported
npm warn deprecated glob@7.2.3: Glob versions prior to v9 are no longer supported
npm warn deprecated glob@7.2.3: Glob versions prior to v9 are no longer supported
npm warn deprecated @xmldom/xmldom@0.7.13: this version is no longer supported, please update to at least 0.8.*
0.21.5

C:\Users\user>
```
🎉 이게 뜨면 설치가 모두 완료되었고, 마지막에 **0.21.5**라는 Expo CLI 버전이 출력된 것을 보면 성공적으로 설치된 상태임을 알 수 있다. 

---
### 현재 상황 요약
1. **Node.js**: `v22.11.0` - 정상 설치됨.
2. **npm**: `v10.9.0` - 정상 설치됨.
3. **Expo CLI**: `0.21.5` - 정상적으로 설치되었음.
---

---
### **경고 메시지에 대한 설명**

설치 과정에서 표시된 경고는 특정 패키지가 더 이상 지원되지 않거나 새로운 버전으로 대체되었다는 내용을 알려준다.  **이는 설치에 영향을 주지 않으며, 무시해도 괜찮다.**

경고 내용:
- **deprecated**: 패키지가 오래되었고 유지보수가 중단되었음을 의미.
- 대체 옵션이 명시되어 있지만, Expo CLI 설치와 실행에는 문제가 없다.
---


### 이제 `npx expo start` 를 하면 프로젝트를 시작할 수 있다~~!!!🎉🎉