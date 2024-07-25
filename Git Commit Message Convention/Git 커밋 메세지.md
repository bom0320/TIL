Git Commit Message
===

### **1) Git 커밋 메세지 컨벤션이란?**

- Git 커밋 메시지 컨벤션(Git Commit Message Convention) 이란, 프로젝트 참여자들이 **일관된 형식의 커밋 메시지를 작성하기 위한 규칙** → 간단히 줄여서 Git 커밋 컨벤션이라고도 함
- 현재 여러 개발자들 사이엣 관습적으로 통용되는 가이드라인이 있지만, 각 프로젝트에 따라서 별도의 규칙을 만들어 적용하기도 함

### 2) Git 커밋 컨벤션을 지켜야 하는 이유

Git 커밋 메시지 컨벤션을 지키는 것은 프로젝트 관리와 협업에 있어서 중요한 부분이다. 정해진 규칠에 따라 커밋 메시지를 기재함으로써 개발자들이 서로의 작업을 이해하고 효율적으로 대처할수 있는 프로젝트 환경을 만들 수 있다. 특히 다음 두 가지 이유로 Git 커밋 메시지를 작성하면, 프로젝트를 보다 효율적이고 안정적으로 관리할 수 있다.

- **가독성 및 커뮤니케이션 효율성 제고**
    
    일관된 커밋 메세지의 형태를 유지하면 가독성을 높일 수 있으며, 이에 따라 다른 개발자의 작업 내역이나 변경사항을 쉽게 파악할 수 있게 된다. 또한 코드 리뷰 및 버그 수정 과정에서 불필요한 의사소통 과정을 간소화하여, 프로젝트 관리에 들어가는 시간도 줄일 수 있다.
    

- **변경 이력 추적 및 문제 해결 속도 향상**
    
    Git 커밋 컨벤션을 지키면 일관된 커밋 메시지를 통해 소스 변경 이력을 효율적으로 추적할 수 있다. 이를 통해 문제 발생 시 더 빠르게 원인을 찾아 수정할 수 있으며, 전반적인 프로젝트 안정성을 높일 수 있다.
    

## 1. Commit Message Structure

- 기본적인 커밋 메시지 구조 (각 파트는 빈줄로 구분한다.)
    
    
    > **제목** (Type: Subject)
    (한줄 띄어 분리)
    **본문**(Body)
    (한줄 띄어 분리)
    **꼬리말** (Flooter)
    > 

## 2. Commit Type

- 커밋의 타입 구성
    
    > **태그: 제목**
    :(space)제목 으로: 뒤에만 space 를 넣는다.
    > 

| Tag Name | Description |
| --- | --- |
| Feat | 새로운 기능을 추가 |
| Fix | 버그 수정 |
| Design | CSS 등 사용자 UI 디자인 변경 |
| !BREAKING CHANGE | 커다란 API 변경의 경우 |
| !HOTFIX | 급하게 치명적인 버그를 고쳐야하는 경우 |
| Style | 코드 포맷 변경, 세미 콜론 누락, 코드 수정이 없는 경우 |
| Refactor | 프로덕션 코드 리팩토링 |
| Comment | 필요한 주석 추가 및 변경 |
| Does | 문서 수정 |
| Test | 테스트 코드, 리펙토링 테스트 코드 추가, Production Code(실제로 사용하는 코드) 변경 없음 |
| Chore | 빌드 업무 수정, 패키지 매니저 수정, 패키지 관리자 구성 등 업데이트, Production Code 변경 없음 |
| Rename | 파일 혹은 폴더명 수정하거나 옮기는 작업만인 경우 |
| Remove | 파일을 삭제하는 작업만 수행한 경우 |

**프로덕션 코드 리펙토링 :** 이미 운영 중인(프로덕션) 시스템의 코드를 개선하는 과정 → 여기서 “리펙토링” 은 코드의 기능적 변경 없이 내부 구조를 개선하여 유지보수성과 가독성 향상시키는 작업을 말함

추가적인 문맥 정보를 제공하기위한 목적으로 괄호 안에 적을 수도 있다.

```
ex) 
	Feat(navigation)
	Fix(db)
```

## 3. Subject

- 제목은 **50글자 이내**로 작성한다.
- **첫글자**는 **대문자**로 작성한다.
- **마침표** 및 **특수기호**는 사용하지 않는다.
- 영문으로 작성하는 경우 **동사(원형)을 가장 앞에 명령어로 작성**한다.
- **과거시제**는 사용하지 않는다.
- 간결하고 요점적으로 즉, **개조식 구문으로 작성**한다.

```
ex)
Fixed --> fix
Added ---> Add
Modified --> Modify
```

## 4. Body

- **72글자 이내로 작성**한다.
- 최대한 **상세히 작성**한다. (코드 변경의 이유를 명확히 작성할수록 좋다)
- 어떻게 변경했는지보다 **무엇을, 왜 변경했는지 작성**한다.

## 5. Flooter

- **선택사항**
- **issue tracker ID 명시하고 싶은 경우에 작성**한다.
    
    **issue tracked ID란:**  이슈 트래킹 시스템에서 특정 이슈를 식별하기 위해 부여된 고유 식별자를 의미 → 버그, 기능 요청, 작업 항목 등 다양한 이슈를 기록하고 관리하기 위해 사용됨
    
- 유형: #이슈 번호 형식으로 작성한다.
- **여러 개의 이슈번호는 쉼표(,)로 구분**한다.
- 이슈 트래커 유형은 다음 중 하나를 사용한다.
    - **Fixes**: 이슈 수정중 (아직 해결되지 않은 경우)
    - **Resolves:** 이슈를 해결했을 때 사용
    - **Ref:** 참고할 이슈가 있을 때 사용
    - **Related to:** 해당 커밋에 관련된 이슈번호(아직 해결되지 않은 경우)

```
ex)
Fixes: #45 Related to: #34, #23
```

## 6. Example

**예시 1**

```
Feat: 회원 가입 기능 구현

SMS, 이메일 중복확인 API 개발

Resolves: #123
Ref: #456
Related to: #48, #45
```

**예시 2**

```
feat: Summarize changes in around 50 characters or less

More detailed explanatory text, if necessary. Wrap it to about 72
characters or so.In some contexts, the first line is treated as the
subject of the commit and the rest of the text as the body. The
blank line separating the summary from the body is critical (unless
you omit the body entirely); various tools like `log`, `shortlog`
and `rebase` can get confused if you run the two together.

Explain the problem that this commit is solving. Focus on why you
are making this change as opposed to how (the code explains that).
Are there side effects or other unintuitive consequences of this
change? Here's the place to explain them.

Further paragraphs come after blank lines.

- Bullet points are okay, too

- Typically a hyphen or asterisk is used for the bullet, preceded
by a single space, with blank lines in between, but conventions
vary here

If you use an issue tracker, put references to them at the bottom,
like this:

Resolves: #123
See also: #456, #789
```

**그 외 자주 쓰이는**

```
Fix: 버그 수정
Fix my test
Fix typo in style.css
Fix my test to return undefined
Fix error when using my function

Updatd: Fix 와 달리 원래 정상적으로 동작했지만 보완의 개념
Update harry-server.js to use HTTPS

Add
Add documentation for the defaultPort option
Add example for setting Vary: Accept-Encoding header in zlib.md

Remove(Clean 이나 Eliminate) : 'unnecessary', 'useless', 'unneeded', 'unused', 'duplicated' 가 붙는 경우가 많음
Remove fallback cache
Remove unnecessary italics from child_process.md

Refactor: 리펙토링 

Simplify: Refactor 와 유사하지만 약한 수정, 코드 단순화

Improve: 호환성, 테스트 커버리지, 성능, 검증 기능, 접근성 등의 향상
Improve ios's accessibilityLabel performance by up to 20%

Implment: 코드 추가보다 큰 단위의 구현
Implement bundle sync status

Correct: 주로 문법의 오류나 타입의 변경, 이름 변경 등에 사용
Correct Grammatical error in BUILDING.md

prevent
precent hello handler from saying Hi in hi.js

Avoid : prevent는 못하게 막지만, Avoid 는 회피(if 등)
Avoid flusing uninitialized traces

Move : 코드나 파일의 이름
Move function from header to source file

Rename: 이름 변경
Rename node-report to report

```

## 7. Commit Message Emoji(gitmoji)

| Emoji | Description |
| --- | --- |
| 🎨 | 코드의 형식 / 구조를 개선 할 때 |
| 📰 | 새 파일을 만들 때 |
| 📝 | 사소한 코드 또는 언어를 변경할 때 |
| 🐎 | 성능을 향상시킬 때 |
| 📚 | 문서를 쓸 때 |
| 🐛 | 버그 reporting할 때, @FIXME 주석 태그 삽입 |
| 🚑 | 버그를 고칠 때 |
| 🐧 | 리눅스에서 무언가를 고칠 때 |
| 🍎 | Mac OS에서 무언가를 고칠 때 |
| 🏁 | Windows에서 무언가를 고칠 때 |
| 🔥 | 코드 또는 파일 제거할 때 , @CHANGED주석 태그와 함께 |
| 🚜 | 파일 구조를 변경할 때 . 🎨과 함께 사용 |
| 🔨 | 코드를 리팩토링 할 때 |
| ☔️ | 테스트를 추가 할 때 |
| 🔬 | 코드 범위를 추가 할 때 |
| 💚 | CI 빌드를 고칠 때 |
| 🔒 | 보안을 다룰 때 |
| ⬆️ | 종속성을 업그레이드 할 때 |
| ⬇️ | 종속성을 다운 그레이드 할 때 |
| ⏩ | 이전 버전 / 지점에서 기능을 전달할 때 |
| ⏪ | 최신 버전 / 지점에서 기능을 백 포트 할 때 |
| 👕 | linter / strict / deprecation 경고를 제거 할 때 |
| 💄 | UI / style 개선시 |
| ♿️ | 접근성을 향상시킬 때 |
| 🚧 | WIP (진행중인 작업)에 커밋, @REVIEW주석 태그와 함께 사용 |
| 💎 | New Release |
| 🔖 | 버전 태그 |
| 🎉 | Initial Commit |
| 🔈 | 로깅을 추가 할 때 |
| 🔇 | 로깅을 줄일 때 |
| ✨ | 새로운 기능을 소개 할 때 |
| ⚡️ | 도입 할 때 이전 버전과 호환되지 않는 특징, @CHANGED주석 태그 사용 |
| 💡 | 새로운 아이디어, @IDEA주석 태그 |
| 🚀 | 배포 / 개발 작업 과 관련된 모든 것 |
| 🐘 | PostgreSQL 데이터베이스 별 (마이그레이션, 스크립트, 확장 등) |
| 🐬 | MySQL 데이터베이스 특정 (마이그레이션, 스크립트, 확장 등) |
| 🍃 | MongoDB 데이터베이스 특정 (마이그레이션, 스크립트, 확장 등) |
| 🏦 | 일반 데이터베이스 별 (마이그레이션, 스크립트, 확장명 등) |
| 🐳 | 도커 구성 |
| 🤝 | 파일을 병합 할 때 |