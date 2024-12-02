# TIL - 2024-12-02

## 환경 변수와 React Native 통합

### 오늘 해결한 문제
1. **API 키 노출 문제**:
   - OpenAI API 키가 코드에 하드코딩되어 GitHub에 업로드됨.
   - GitHub의 Push Protection에 의해 푸시가 차단됨.

2. **환경 변수 로드 문제**:
   - React Native에서 `.env` 파일의 키가 로드되지 않아 `undefined` 반환.

---

### 해결 과정
1. **환경 변수 관리**:
   - `.env` 파일 생성 후 API 키 이동.
   - `react-native-dotenv` 라이브러리로 키를 불러옴.
   - `babel.config.js` 설정 추가.

2. **API 키 삭제 및 재발급**:
   - 기존 API 키를 제거하고, 새로운 키를 발급받아 `.env`에 추가.

3. **Git 커밋 수정**:
   - 잘못된 커밋은 `git rebase`로 수정.

4. **React Native에서 디버깅**:
   - `console.log`를 통해 환경 변수가 올바르게 로드되는지 확인.

---

### 배운 점
1. **환경 변수의 필요성**:
   - 민감한 정보는 항상 `.env` 파일로 관리해야 한다.
   - GitHub에 업로드된 키는 보안 문제를 초래한다.

2. **React Native에서 환경 변수 관리**:
   - `react-native-dotenv` 설정과 캐시 초기화(`expo start -c`)가 중요하다.

3. **Git의 유용성**:
   - 잘못된 커밋은 `rebase`로 수정 가능.
