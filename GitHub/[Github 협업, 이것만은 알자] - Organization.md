Organization 기능에 대해
===

## Organization?
Organization 은 깃허브에서 제공하는 협업을 위한 **그룹 기능**이다. 

해당 기능을 통해 여러 사람들과 그룹을 형성하여 효과적으로 프로젝트를 관리할 수 있다. 

## 🤔 개인 Repository로 협업할 수 있는데 굳이 왜 써?
`Repository` 는 하나의 프로젝트를 관리하는 **저장소 단위**이다. 굳이 `Organization` 을 만들지 않고 개인 `Repository`로 관리하는 것도 물론 가능하다.

하지만 협업 시에 프로젝트 저장소를 개인이 관리하게 되면 함께 개발하는 팀원들에게 `파일 추가` 또는 `변경`등에 대한 **권한을 부여할 수 없다.**

`Pull Request` 라는 기능에 대한 처리도 **레포지토리의 주인**만 가능하기 때문에 협업이 지체되며 결국 **레포지토리의 주인**에게 의존성이 높은 구조로 프로젝트가 진행된다.

> `Organization` 을 사용하면 **다수의 관리자**를 설정할 수 있으며, **협업을 위한 몇 가지 소소한 기능**들도 제공받을 수 있다.
>
> 때문에 우리는 협업 시에 `Organization` 을 사용하는 것이다.


## 💭 Organization 생성

![](https://velog.velcdn.com/images/pgmjun/post/1a8c082e-8dd6-4218-9c2a-e07909ea1ea4/image.png)
프로필 우측의 `+ 아이콘` 클릭 후 `New organization` 선택


---

![](https://velog.velcdn.com/images/pgmjun/post/499fa1b4-8707-48d4-a40c-d7eec0aec61e/image.png)

제일 좌측의 무료버전 선택 (무료만으로 협업하기 충분하다.)

> 💡 다른 버전은 Github Codespaces와 같은 편의 기능을 허용하는 등 몇 가지 기능을 더 제공한다.
> 관심있으면 알아보고 사용해보자

---

![](https://velog.velcdn.com/images/pgmjun/post/fecdda8a-993e-4815-a9a3-e652f868d94d/image.png)

`Organization Name` 과 `대표 Email` 을 입력하고 **`My Personal(개인)`** Organization 임을 선택한다.

> **😮 엇,, 저희는 팀 프로젝트인데요!**
> 
> 저희 팀 프로젝튼데 왜 `Personal` 로 설정하는 건가요..!?
>
> 이 부분은 `Organization` 이 **특정 회사나 기관**에 소속되어 관리되는 것인지, 아니면 일반 **개인**이 관리하는 것인지 물어보는 질문이다.

---

![](https://velog.velcdn.com/images/pgmjun/post/ca67c97c-43e9-44f4-9053-e63385408488/image.png)
마지막으로 초대할 사람의 `깃허브 ID` 나 `Email` 입력을 통해, 팀원을 초대하고 셋업을 마무리할 수 있다.

---

![](https://velog.velcdn.com/images/pgmjun/post/8aeac163-4a1a-4937-8264-e63696705554/image.png)

그럼 이렇게 `Organization` 이 생성된다.

이렇게 생성된 `Organization` 은 상단 바의 맨 우측에 있는 `Settings` 에서 `Organization` 의 **대표 이미지, 이름, 설명, URL** 등의 설정이 가능하다.
