효율적인 Git 워크플로우
===

![](https://private-user-images.githubusercontent.com/167315197/390282265-91a63d4e-50ca-4b93-b848-1dc41f724118.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzI2ODc1OTcsIm5iZiI6MTczMjY4NzI5NywicGF0aCI6Ii8xNjczMTUxOTcvMzkwMjgyMjY1LTkxYTYzZDRlLTUwY2EtNGI5My1iODQ4LTFkYzQxZjcyNDExOC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMTI3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTEyN1QwNjAxMzdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04ZDM3MGI1MTZhN2NhMWIzMGMxNTlmZmIxODY3NzZlMmNmOTNmNmVlNmM1ZmU4ZDQ5ZjgwN2YxNmVkNTZjMTBmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.KaA4Xtsrdezx8O918AAPGNFhmhJaRimQplxg6XFVdxU)
위 사진을 보면 중복 폴더가 엄청나게 많은걸 볼 수 있다. 애초에 깃이 제공하는 핵심 기능은 크게 버전 관리, 백업, 협업으로 알고 있는데, 난 그 핵심 기능중 버전관리를 제대로 사용하지 못했던걸로 볼 수 있다.. 즉, git 의 장점을 제대로 못 살리고 있었던것..! 

**폴더가 이렇게 된 이유는..**

 원격 저장소에 변경사항이 생길때 마다, 클론을 해왔기 때문..🥲 그리고 나서 npm install, npm ci 무한 반복..

 ## 왜 `git clone` 을 반복하면 안될까?

### 👎🏻 중복 저장소 문제:
첫번째, `git clone`은 **원격 저장소 전체를 새로 복사**하기 때문에, 동일한 저장소가 로컬에 여러 개 생기게 된다. 때문에 불필요한 파일과 폴더가 늘어나고, 관리가 복잡해진다.

### 👎🏻 작업 연속성 문제:
내가 작업하던 로컬 변경 사항이나 브랜치가 다른 복사본에는 반영되지 않는다. 즉 로컬 작업을 한 폴더에서만 해야 효율적으로 관리할 수 있다.

즉, 위 사진의 구조는 **관리가 매우 어렵다.** 또한 변경사항을 반영하려면 어디서 작업했는지 헷갈릴 수 있다.

> 📝 그러니, `git clone` 은 단 한번만 사용하도록 하자.
>
> 📝 이후 모든 변경 사항은 **`git pull`** 을 사용해 동기화하자. 
>
> 📝 그리고 폴더를 하나로 유지해 작업 환경을 깔끔하게 관리하도록 하자.

## 앞으로는 이렇게 해보자

### 1. 프로젝트를 처음 시작할 때:
처음에만 `git clone` 으로 원격 저장소를 복사:

```bash
git clone https://github.com/username/repository.git
cd repository
```
한 번만 하면 끝! 이후 새로운 클론은 **필요 없다.**

### 2. 수정사하잉 있을 때:
누군가가 원격 저장소에 변경 사항을 올리면, `git pull`:

```bash
git pull origin 가져오고 싶은 브랜치명
```
현재 작업 폴더에서 바로 최신 상태로 업데이트!

### 3. npm 설치는 필요한 경우에만:
만약 새로운 패키지가 추가되었다면, **`package.json`** 이 업데이트될 테니 `git pull` 후:

```bash
npm install
```

### 징점

#### 👍🏻 시간 절약
매번 `git clone` 을 하지 않아도 되니까 폴더를 정리하고, npm 설치를 반복할 필요가 없다.

#### 👍🏻 작업 연속성
기존에 작업하던 로컬 브랜치나 변경 사항을 유지하면서도 최신 코드를 가져올 수 있다.

#### 👍🏻 폴더 정리
복잡한 클론 폴더 구조가 없어지고, 하나의 폴더에서 모든 작업을 관리할 수 있다.

### 추가 꿀팁
- `git pull` 을 정기적으로 해주면 동기화 상태를 유지할 수 있다.
- 변경 사항을 확인하고 싶으면 **git fetch + git status** 로 원격 상태를 미리 보는 것도 좋다.

```bash
git fetch --all
git status
```