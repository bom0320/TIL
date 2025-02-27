API 키 관리의 중요성
===
API 키는 **서비스와 사용자 또는 애플리케이션 간의 인증**을 담당하는 고유한 식별자이다. API 키를 잘 관리하지 않으면 심각한 **보안 문제**와 **비용 문제**가 발생할 수 있다.

## 1. API 키란?

### 정의
API 키는 특정 사용자가 API 에 접근할 권한이 있다는 것을 인증하는 고유 문자열

### 용도
- 특정 API (예: OpenAI API, Google Maps API)에 접근 권한 제공
- 사용량 추적 및 제한
- 인증 및 액세스 권한 관리

## 2. API 키 관리가 중요한 이유

### 1) 보안 문제
API 키가 유츨되면 다음과 같은 보안 위협이 발생할 수 있다.

#### 무단 사용:
- 키를 훔친 사용자가 API 를 무단으로 호출해 비용을 발생시킴
- 사용량 제한 초과로 원래 사용자가 서비스를 사용할 수 없게 됨

#### 데이터 유출:
- 키를 통해 민감한 데이터에 접근하거나 악의적으로 사용할 수 있음

### 2) 비용 문제
- 대부분의 API 서비스는 사용량에 따라 과금된다.
- 유출된 키로 인해 무분별한 사용이 발생하면 높은 과금이 청구될 수 있음

### 3) 신뢰 문제
- 프로젝트 코드에서 API 키가 노출되면 프로젝트의 신뢰도에 타격
- 특히 오픈 소스 프로젝트의 경우 **누구나 코드를 볼 수 있기 때문에** API 키 유출 가능성이 높아진다.

### 4) 서비스 중단 위험
- 키가 유출되면 제공업체(OpenAI 등)가 해당 키를 비활성화하여 서비스가 중단될 수 있음

## 3. API 키 관리 방법

### 1) 코드 하드코딩하지 않기
- 절대 API 키를 소스 코드에 직접 작성하지 말 것

```js
// 나쁜 예: 키를 코드에 직접 작성
const apiKey = "sk-xxxxxx";
```

### 2) 환경 변수 사용
- API 키를 `.env` 파일에 저장하고, 소스 코드에서는 환경 변수를 통해 불러오기

```
// .env 파일
OPENAI_API_KEY=sk-xxxxxx
```

```js
// 코드에서 환경 변수 사용
import { OPENAI_API_KEY } from "@env";
const apiKey = OPENAI_API_KEY;
```

### 3) Git 에 업로드하지 않기
- `.gitignore` 에 `.env` 를 추가해 API 키가 저장된 파일이 Github 에 업로드되지 않도록 해야함

```
# .gitignore
.env
```

### 4) 키를 주기적으로 교체
- API 키를 정기적으로 재발급 받아 교체하여 보안성을 유지

### 5) 사용량 제한 설정
- 대부분의 API 제공업체는 API 키에 대해 **사용량 제한**을 설정할 수 있다.
- 무단 사용으로 인해 과금이 발생하는 것을 방지

### 6) 비상 상황 대비
- 키가 유출된 것을 발견하면 즉시 해당 키를 비활성화하고 새 키를 발급

## 4. API 키 관리 실패 사례

### 1) GitHub 에 키 노출
- 많은 개발자가 `.gitignore` 설정을 하지 않아 **GitHub에 API 키를 업로드**
- 키가 유출되어 서비스 제공업체로부터 높은 과금 청구 발생
    - 예: AWS API 키 노출 -> 서버를 무단으로 사용 -> 수백만 원 과금

### 2) 공개 프로젝트에서 키 노출
- 오픈소스 프로젝트에서 키가 노출되면 **누구나 키를 사용**가능
- 사용량 제한 초과로 프로젝트 자체가 중단되거나, API 키가 비활성화 됨

## 5. OpenAI API 키 관리 Best Practices

### 1. 환경 변수로 관리:
-  `.env` 파일을 사용하고, `react-native-dotenv` 로 키를 불러오기

### 2. GitHub 보안 설정 활용:
- **GitHub Push Protection :**
    - 키가 포함된 커밋을 푸시할 때 경고 및 차단

- **Secret Scanning :**
    - GitHub 에서 자동으로 API  키를 탐지하고 경고를 제공

### 3. 키 사용 제한:
- OpenAI 콘솔에서 **IP 제한, 도메인 제한**을 설정해 키를 안전하게 사용

### 4. 문제 발생 시 대처:
- 즉시 키를 비활성화하고 새로운 키로 교체
- 노출된 기록은 `git filter-repo` 등을 사용해 제거

## 6. 실제 적용 예시

### 1) `.env` 파일에 API 키 저장

```
OPENAI_API_KEY=sk-xxxxxx
```

### 2) React Native 에서 환경 변수 사용

```js
import { OPENAI_API_KEY } from "@env";

// API 키 사용
const apiKey = OPENAI_API_KEY;
console.log("Loaded API Key:", apiKey);
```

### 3) `.gitignore` 설정

```
# .gitignore
.env
```

## 7. 결론
- **API 키 관리**는 개발자의 기본적인 책임이다.
- 적절한 관리 방법(환경 변수, `.gitignore`, 키 제한 설정 등)을 따르면 보안 문제를 예방할 수 있다.