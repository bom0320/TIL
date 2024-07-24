추천 CI/CD
===
루빗 같은 크로스 플랫폼 네이티브 앱을 개발할 때 적합한 CI/CD 도구를 선택하는 것은 중요하다. Flutter 와 같은 크로스 플랫폼 프레임워크를 사용할 때는 여러 CI/CD 도구가 잘 지원되며, 각각의 도구는 특정 장점과 기능을 가지고 있다. 여기서는 몇 가지 주요 CI/CD 도구를 비교하고, 루빗같은 앱이 적합한 도구를 추천하겠다.

### 주요 CI/CD 도구 비교

1. **GitHub Actions**
- **장점:**
    - GitHub 리포지토리와 직접 통합되어 설정이 간편하다.
    - 다양한 워크플로우 템플릿과 예제가 제공된다.
    - 강력한 커뮤니티 지원 및 문서화
- **단점:**
- 복잡한 파이프라인 설정 시 처음에는 다소 학습 곡선이 있을 수 있다.
- **추천이유:** Github 를 코드 저장소로 사용 중이라면 자연스럽게 통합되고, 강력한 커뮤니티와 풍부한 예제 덕분에 쉽게 시작할 수 있다.
- **2. CircleCI**
    - **장점**:
        - 빠른 설정과 높은 커스터마이징 가능성.
        - 다양한 언어와 프레임워크 지원.
        - UI가 직관적이며 사용하기 편리합니다.
    - **단점**:
        - 무료 플랜의 제한이 있을 수 있습니다.
    - **추천 이유**: 복잡한 빌드 및 배포 파이프라인을 쉽게 설정할 수 있으며, 다양한 통합 옵션을 제공합니다.
- **3. Travis CI**
    - **장점**:오픈 소스 프로젝트에 무료로 제공됩니다.설정이 간단하고 YAML 파일을 사용하여 쉽게 구성할 수 있습니다.**단점**:유료 플랜에서 제공되는 빌드 리소스가 제한적일 수 있습니다.**추천 이유**: 오픈 소스 프로젝트에 적합하며, 간단한 설정으로 빠르게 CI 파이프라인을 구축할 수 있습니다.
    - 
- **4. Jekins**
    - **장점**:
        - 매우 유연하고 강력한 플러그인 시스템을 제공합니다.
        - 모든 종류의 프로젝트와 워크플로우를 지원합니다.
    - **단점**:
        - 설정과 유지보수가 복잡할 수 있으며, 자체 호스팅이 필요합니다.
    - **추천 이유**: 고도의 커스터마이징이 필요하고, 자체 인프라를 사용하는 경우 적합합니다.

### 추천 도구: GitHub Actions

GitHub Actions 는 루빗 같은 크로스 플랫폼 네이티브 앱에 매우 적합하다. GitHub 와 직접 통합되어 코드 저장소와 CI/CD 파이프라인을 하나의 플랫폼에서 관리할 수 있으며, 다양한 템플릿과 예제가 제공되어 설정이 용이하다. 또한 GitHub Actions 는 강력한 커뮤니티 지원과 문서화를 제공하여 빠르게 시작할 수 있다. 

### GitHub Actions 설정 예시

1. **프로젝트에 GitHub Actions 설정 파일 추가**
    
    프로젝트 루트 디렉토리에 `.github/workflows` 디렉토리를 생성하고, `ci-cd.yml` 파일을 추가한다.
    
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
            flutter-version: 'latest'
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
            flutter-version: 'latest'
        - run: flutter build apk --release
        - name: Upload to Firebase App Distribution
          uses: wzieba/Firebase-Distribution-Github-Action@v1
          with:
            appId: ${{ secrets.FIREBASE_APP_ID }}
            token: ${{ secrets.FIREBASE_TOKEN }}
            groups: testers
            file: build/app/outputs/flutter-apk/app-release.apk
    
    ```
    
    1. **환경 변수 설정**
    
    GitHub 리포지토리의 Settings > Secrets 에서 `FIREBASE_APP_ID`와 `FIREBASE_TOKEN`을 설정합니다.
    
    ### 3. 워크플로우 설명
    
    - **on**: `push` 및 `pull_request` 이벤트를 트리거로 설정합니다.
    - **jobs**:
        - **build**: Ubuntu 환경에서 Flutter 빌드 및 테스트를 실행합니다.
            - `actions/checkout@v2`: 코드를 체크아웃합니다.
            - `subosito/flutter-action@v1`: Flutter 환경을 설정합니다.
            - `flutter pub get`: 의존성을 설치합니다.
            - `flutter test`: 테스트를 실행합니다.
        - **deploy**: 빌드 작업이 완료된 후 APK 파일을 Firebase App Distribution에 업로드합니다.
            - `actions/checkout@v2`: 코드를 체크아웃합니다.
            - `subosito/flutter-action@v1`: Flutter 환경을 설정합니다.
            - `flutter build apk --release`: 릴리즈 APK를 빌드합니다.
            - `wzieba/Firebase-Distribution-Github-Action@v1`: Firebase에 APK를 업로드합니다.
    
    ### 결론
    
    루빗 같은 크로스 플랫폼 네이티브 앱을 개발할 때는 GitHub Actions를 사용하는 것이 좋습니다. 이는 GitHub 리포지토리와 직접 통합되어 설정이 간편하고, 다양한 템플릿과 예제를 통해 쉽게 시작할 수 있기 때문입니다. CI/CD 파이프라인을 구축하여 코드 변경 시 자동으로 빌드, 테스트, 배포가 이루어지도록 하면, 빠른 피드백과 안정적인 배포를 유지할 수 있습니다.