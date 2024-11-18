Issue 기반 작업 흐름
===
Issue는 프로젝트에서 작업이나 문제를 관리하는 중요한 도구이다. Issue 기반 작업 흐름에 대해 알아보기 이전 Issue 의 개념에 대해 간단히 짚고 넘어가자

#### Issue 개념
- **Issue 란?**
    - 프로젝트에서 발생하는 작업(기능 추가, 버그 수정 등) 을 기록하고 관리하는 도구
    - 팀원들이 작업의 흐름을 이해하고, 협업을 원활히 할 수 있게 도와줌

- **왜 필요한가?**
    - 작업 내용을 명확히 하고, 진행 상황을 공유하며, 팀원들과 협력을 쉽게 만들기 위해

---

## Issue 기반 작업 흐름

### 1. Issue 생성 :
- 프로젝트에서 "`A` 기능 개발하기" 라는 작업이 필요하다면, **Issue 를 생성**한다.
ex) **"A" 기능 추가 (#1)**

### 2. 브랜치 생성 :
- Issue 번호를 기반으로 브랜치를 생성한다.
ex) `feature/A` 브랜치를 `develop` 브랜치를 기준으로 생성

**명령어 예시 :**
```bash
git checkout develop
git checkout -b feature/A
```

### 3. 작업 및 커밋:
- `feature/A` 브랜치에서 A 기능을 개발하고 커밋을 작성한다.
- 커밋 메시지에 Issue 번호를 추가하여 해당 작업이 어떤 Issue 와 관련이 있는지 명시 

ex)
```bash
git add .
git commit -m "Add feature A (close #1)"

```
- `close #1` : PR 이 병합되면 Issue #1 이 자동으로 닫힌다.

### 4. Pull Request 생성:
- 작업이 완료되면 `develop` 브랜치로 병합 요청을 위한 **Pull Request** 를 생성한다. 
- PR 설명에 `close #1` 을 추가하여 Issue 와 연결

### 5. Issue 상태 변경:
- PR 이 병합되면 Issue 가 자동으로 닫히며, 작업 완료 상태가 된다.

---

### 정리
- Issue 는 **작업을 정의**하고 관리하는 도구
- **브랜치를 Issue 에 맞게 생성**하여 작업을 진행
- **커밋 메시지에 Issue 번호를 명시**하여 연관 작업임을 표시
- PR 에서 `close #1` 등을 사용해 **Issue 를 자동으로 닫음**

---

### 추가 팁
1. **커밋 메시지 템플릿 :**
    - 항상 Issue 번호를 포함시키는 습관을 들이자
    ex) `Fix bug in login logic (#123)` 또는 `Implement feature B (close #45)`

2. **브랜치 네이밍 규칙 :**
    - `feature/` , `fix/` 등 **네이밍 규칙을 정리**하여 팀원들이 같은 규칙을 따르도록 한다.

3. **Issue와 PR 연계 :**
    - PR 생성 시, 오른쪽 사이드바에서 **Development** 섹션에 관련된 Issue 를 직접 연결할 수도 있다.