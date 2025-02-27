[Github 협업, 이것만은 알자] - Template
===

## Template 이란?

> 🤔 “PR이나 Issue를 작성할 때, 뭘 기준으로 작성해야하지?”

> 🤔 “반복되는 내용도 새로운 Issue나 PR을 생성할 때마다 작성해야하는 거야?”
 
이런 생각을 가진 분들을 위해 깃허브는 `Issue` 와 `PR` 의 `Template` 기능을 제공한다. 미리 정의해 둔 내용을 `PR` 또는 `Issue` 생성 시에 자동으로 입력하여 반복 작업을 줄여준다.

## PR Template
PR 템플릿엔 **무슨 내용을 담아야할까??**

### ⚙️ PR엔 뭘 담아야할까?
`PR` 은 주로 다음과 같은 내용을 담는다.

> - **핵심 추가 사항 또는 변경 사항**
> - **추가 또는 변경을 시도하게 된 이유**
> - **리뷰어들에게 전하는 말**

이처럼 `PR` 은 팀원들이 우리가 작성한 **코드**를 **이해**하는 데에 도움을 받을 수 있는 내용을 주로 담아내야 한다.

때문에 핵심 내용을 보기 쉽게 잘 담아내는 `PR` 은 협업에서 굉장히 중요한 역할을 하며, 팀원과 협의하여 결정된 내용으로 구성된 템플릿은 이러한 `PR` 을 작성하는 것에 큰 도움을 준다.

이때, 파일 이름은 
```
PULL_REQUEST_TEMPLATE.md
```
이거여야 함!!
> 이는 Github 가 Pull Request 템플릿으로 사용하려고 지정한 이름이다.

## Issue Template
`Issue Template` 도 마찬가지로 `.github` 패키지에 파일을 생성하여 관리할 수 있다.

하지만, `Issue Template` 은 `Assignees`, `Labels` 등 설정해줄 내용들이 몇 가지 더 존재하기 때문에 Github  에서 제공하는 Template 생성 기능을 이용하여 만드는게 빠름

