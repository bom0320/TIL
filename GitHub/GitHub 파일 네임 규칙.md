GitHub 파일 네임 규칙
===
GitHub 는 특정 이름과 경로를 가진 파일들을 **자동으로 탐지**해서 특별한 기능으로 사용하도록 설계되어 있다. 이 규칙은 **템플릿, 문서화, 프로젝트 설정** 등을 표준화하고, 개발자 간 협업을 효율적으로 도와준다.

아래에서 GitHub 에서 자주 사용되는 주요 파일 이름 규칙을 정리해보자

## GitHub 의 주요 파일 이름 규칙
GitHub 가 자동으로 인식하고 특별한 용도로 사용하는 파일 이름은 다음과 같다.


| **파일 이름** | **위치** | **역할/설명** |
| --- | --- | --- |
| **README.md** | 프로젝트 루트 | 프로젝트 설명, 설치 방법, 사용법 등을 표시. GitHub 리포지토리 메인 페이지에 자동 표시. |
| **PULL_REQUEST_TEMPLATE.md** | `.github` 폴더 또는 루트 | Pull Request 작성 시 기본 내용을 제공하는 템플릿. |
| **ISSUE_TEMPLATE.md** | `.github` 폴더 또는 루트 | Issue 작성 시 기본 내용을 제공하는 템플릿. |
| **CONTRIBUTING.md** | 프로젝트 루트 또는 `.github` 폴더 | 프로젝트에 기여하는 방법에 대한 가이드라인 제공. |
| **CODE_OF_CONDUCT.md** | 프로젝트 루트 또는 `.github` 폴더 | 프로젝트의 행동 강령을 설정. 협업에서의 올바른 행동과 규칙을 명시. |
| **SECURITY.md** | 프로젝트 루트 또는 `.github` 폴더 | 보안 문제를 보고하거나 처리하는 방법에 대한 정보를 제공. |
| **FUNDING.yml** | `.github` 폴더 | 프로젝트에 대한 후원 정보를 추가(GitHub Sponsors 등). |
|  |  |  |

## 템플릿 파일 이름 규칙
GitHub 는 **PR 과 Issue 템플릿**을 다루기 위한 추가적인 규칙을 가지고 있다.

### PR 템플릿

1. **파일 이름 :** 

- `PULL_REQUEST_TEMPLATE.md`

2. **위치 :**
- `.github/` 폴더 내부
- 또는 프로젝트 루트 디렉토리

3. **여러 템플릿 지원 :**
- 여러 PR 템플릿을 지원하려면 `.github/PULL_REQUEST_TEMPLATE/` 폴더를 생성하고, 템플릿들을 각각 파일로 저장한다.
    - EX) `.github/PULL_REQUEST_TEMPLATE/bug_fix.md`, `.github/PULL_REQUEST_TEMPLATE/feature.md.`

---

### Issue 템플릿

1. **파일 이름 :**
- `ISSUE_TEMPLATE.md`

2. **위치 :**
- `.github/` 폴더 내부

3. **여러 템플릿 지원 :**
- `.github/ISSUE_TEMPLATE/ ` 폴더 안에 다양한 템플릿을 생성 가능
- ex) `.github/ISSUE_TEMPLATE/bug_report.md`, `.github/ISSUE_TEMPLATE/feature_request.md`

## GitHub 설정 파일의 규칙

GitHub는 템플릿 외에도 프로젝트 설정을 위해 특정 이름의 설정 파일을 사용한다.

| **파일 이름** | **위치** | **역할/설명** |
| --- | --- | --- |
| **.gitignore** | 프로젝트 루트 | Git이 무시할 파일/폴더를 정의. |
| **.gitattributes** | 프로젝트 루트 | Git 속성(예: 줄바꿈 스타일, 바이너리 파일 등)을 설정. |
| **FUNDING.yml** | `.github` 폴더 | 프로젝트 후원 정보(GitHub Sponsors)를 제공. |
| **CODEOWNERS** | `.github` 폴더 | 특정 파일/폴더의 기본 리뷰어를 설정. |

---

## GitHub 파일 네임 규칙의 목적

1. **자동화**:
    - GitHub는 특정 파일을 탐지해서, 별도의 설정 없이도 자동으로 해당 기능을 활성화.
    - 예: `README.md`는 프로젝트 메인 페이지에 표시.
2. **협업 표준화**:
    - 모든 개발자가 동일한 규칙을 따르므로, 템플릿과 가이드라인이 일관적.
    - 협업 효율성과 커뮤니케이션 개선.
3. **문서화**:
    - `CONTRIBUTING.md`, `CODE_OF_CONDUCT.md` 같은 파일은 팀 내 규칙을 명확히 전달.

### 결론
GitHub 파일 네임 규칙은 협업과 프로젝트 관리를 효율적으로 만들어 주는 **표준화된 시스템**이다. 
