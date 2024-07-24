CI/CD 란?
===

- 지속적 통합(CI)과 지속적 배포(CD)는 소프트웨어 개발의 중요한 프로세스이다. 이 두가지 개념은 개발과 운영을 연결하여 소프트웨어의 품질과 개발 속도를 높이는 데 도움을 준다.

## 지속적 통합(CI: Continuous Integration)

**목적:** 개발자들이 각자의 작업 내용을 빈번하게 공유하고 통합하여 코드베이스의 품질을 유지한다.

**핵심 개념:**

- **자주 통합:** 개발자들이 작성한 코드를 중앙 저장소에 자주 통합한다.(예: 하루에 여러번)
- **자동화된 빌드:** 코드가 통합될때마다 자동으로 빌드 프로세스가 실행된다.
- **자동화된 테스트:** 빌드 후에 자동으로 테스트가 실행되어 코드의 품질을 검증한다.

**장점:**

- 버그를 조기에 발견하고 수정할 수 있다.
- 코드베이스가 항상 최신 상태로 유지된다.
- 개발자 간의 충돌을 최소화한다.

**예시:**

1. 개발자가 새로운 기능을 구현하고 로컬에서 테스트한 후 코드를 중앙 저장소(GitHub 등)에 푸쉬한다.
2. CI 서버(GitHub Actions, jenkins, CircleCI 등) 가 코드를 자동으로 빌드하고 테스트한다.
3. 빌드나 테스트에서 문제가 발견되면 즉시 개발자에게 알림이 전송되낟.

### 지속적 배포(CD: Continuous Deployment)

**목적:** 코드 변경 사항이 자동으로 프로덕션 환경에 배포되어 사용자가 새로운 기능을 빠르게 이용할 수 있도록 한다.

**핵심 개념:**

- **자동 배포:** CI 과정이 완료되면, 자동으로 프로덕션 환경에 코드가 배포된다.
- **연속적인 배포 파이프라인:** 빌드,테스트, 배포 과정이 하나의 파이프라인으로 연결되어 있다.
- **모니터링 및 피드백:** 배포된 애플리케이션을 모니터링하여 문제를 즉시 감지하고 대응한다.

**장점:**

- 사용자에게 새로운 기능이나 수정 사항을 빠르게 제공할 수 있다.
- 배포 과정이 자동화되어 인적 오류를 최소화할 수 있다.
- 반복 가능한 배포 프로세스를 통해 안정성과 신뢰성을 높일 수 있다.

**예시:**

1. CI 과정에서 모든 빌드와 테스트가 성공하면, CD 파이프라인이 실행된다.
2. 새로운 빌드가 스테이징 환경에 배포되어 추가 테스트와 검증을 거침
3. 모든 검증이 완료되면 자동으로 프로덕션 환경에 배포된다
4. 배포 후 모니터링 도구를 통해 애플리케이션 상태를 지속적으로 감시한다.

### CI/CD 파이프라인 예시

1. **GitHub Actions 를 사용한 CI/CD 파이프라인 설정**

```yaml
# .github/workflows/ci-cd.yml
name: CI/CD Pipeline

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v2
    - name: Set up Flutter
      uses: subosito/flutter-action@v1
      with:
        flutter-version: '2.2.3'
    - run: flutter pub get
    - run: flutter test

  deploy:
    needs: build
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v2
    - name: Set up Flutter
      uses: subosito/flutter-action@v1
      with:
        flutter-version: '2.2.3'
    - run: flutter build apk --release
    - name: Upload to Firebase App Distribution
      uses: wzieba/Firebase-Distribution-Github-Action@v1
      with:
        appId: ${{ secrets.FIREBASE_APP_ID }}
        token: ${{ secrets.FIREBASE_TOKEN }}
        groups: testers
        file: build/app/outputs/flutter-apk/app-release.apk
```

### 결론

CI/CD 는 소프트웨어 개발의 품질과 속도를 높이기 위한 중요한 프로세스이다. CI 는 개발자들이 자주 코드를 통합하고 자동으로 빌드와 테스트를 실행하여 코드베이스의 품질을 유지하는데 중점을 둔다. CD는 코드 변경 사항을 자동으로 프로덕션 환경에 배포하여 사용자가 새로운 기능을 빠르게 이용할 수 있도록 한다. 이를 통해 소프트 웨어 개발의 반복 가능성과 신뢰성을 높일 수 있다.