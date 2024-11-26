`npm install` 과 `npm ci` 의 차이
===

## npm install

### 1. 동작 원리:
- `package.json` 과 `package-lock.json` 을 참고하여 의존성 설치
- **`package.json`의 버전 조건**(`^`, `~`) 에 따라 허용된 최신 버전을 설치하려고 시도
- `package-lock.json` 을 업데이트할 수도 있다.

### 2. 특징

#### ⭐ 쓰기 권한 있음
- 새로운 의존성을 추가하거나, 기존 의존성을 변경하면, `package-lock.json` 과 `package.json` 이 함께 업데이트 된다.
- 팀원 간의 **Node.js/NPM 버전 차이**로 인해, 서로 다른 의존성 버전이 설치될 가능성이 있다.

## npm ci

### 1. 동작 원리:
- **오직 `package-lock.json`** 을 기준으로 의존성 설치
- `package.json` 은 **검증용**으로만 사용
    - `package-lock.json` 과 `package.json` 간의 버전이 불일치하면 에러 발생
- `node_modules` 를 삭제한 뒤, 새롭게 설치

### 2. 특징

#### ⭐ 쓰기 권한 없음
- 기존 파일(`package-lock.json` 과 `package.json`) 을 수정하지 않고, 읽기 전용으로 작동
- 모든 팀원이 동일한 의존성 버전을 사용하도록 보장
- `package-lock.json` 이 없으면 동작 X

## 협업 환경에서는 `npm ci` 가 더 적합
### **문제: `npm install`의 불안정성**

- **팀원 간 Node.js/NPM 버전 차이**로 인해, `npm install`이 의존성을 대체 설치하거나, `package-lock.json`을 업데이트하는 상황 발생.
- 결과적으로, 팀원들 간 환경 불일치로 인해 프로젝트에서 오류가 발생할 가능성이 높음.

### **해결: `npm ci` 사용**

- **`npm ci`는 `package-lock.json`에 기록된 버전을 철저히 준수**하여 의존성을 설치.
- 이로써, 모든 팀원이 **동일한 의존성 환경**에서 작업하도록 보장.

## 왜 협업 시 `npm ci` 가 더 적합할까?
### **1) `package-lock.json` 기반 설치**

- `npm ci`는 오직 `package-lock.json`을 기준으로 작동하므로:
    - 불필요한 의존성 변경이 발생하지 않음.
    - 팀원 간 동일한 환경 보장.

### **2) Node.js/NPM 버전 차이에도 안전**

- `npm ci`는 설치 과정에서 `package-lock.json`에 기록된 내용을 그대로 설치하기 때문에:
    - Node.js/NPM 버전이 다르더라도, 동일한 의존성 환경 유지.

### **3) CI/CD 환경에서 적합**

- `npm ci`는 항상 `node_modules`를 삭제하고 새로 설치하므로:
    - 깨끗한 환경에서 의존성을 설치.
    - 이전에 캐싱된 의존성 때문에 발생할 수 있는 문제를 방지.


### 결론
협업 환경에서는 `npm install` 대신 `npm ci` 를 사용하도록 하자 이유는 요약하자면 첫번째, `npm install` 은 의존성을 대체하거나 업데이트할 가능성이 있어, 환경 불일치를 초래할 수 있다. 두번째는 `npm ci` 는 `package-lock.json` 을 기준으로 작동하므로, 팀원 간 동일한 환경을 보장한다 정도로 정리할 수 있을 것 같다.      