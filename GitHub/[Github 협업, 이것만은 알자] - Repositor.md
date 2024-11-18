[Github 협업, 이것만은 알자] - Repository
===

## Repository 란?
- `repository` 란 프로젝트의 파일과 코드를 업로드해두고 관리할 수 있는 실질적인 프로젝트 저장소이다.

## Repository 생성
이제 방금 생성한 `Organization` 에 `Repository` 를 만들어 보자

![](https://velog.velcdn.com/images/pgmjun/post/4f6220c4-cecf-4291-8710-eb9529fe1921/image.png)

`Organization` 의 상단 **2번째**에 위치한 `Repositories` 를 선택 후, `Create a new repository`  버튼을 클릭한다.

> 💡 `Repository` 는 `Organization` 에만 만들 수 있는 것이 아닌 위에서 말한대로 개인 `Repository` 도 생성이 가능하다.

![](https://velog.velcdn.com/images/pgmjun/post/171970af-5f33-4ea9-b3e3-5eb5016a27ea/image.png)

Repository 생성 페이지는 다음과 같다. 위에서 부터 차근차근 알아보자.

### Owner
`Repository 의 소유주` 를 뜻한다.

**Default** 로 현재 Repository 를 생성하는 Organization 의 이름이 표시되는 것을 볼 수 있다.

이는 위에서 설명했듯이 개인이 관리하는 `Repository` 가 아닌, 단체가 관리하는 `Repository` 를 생성하는 것을 뜻한다.

> 💡 개인 레포를 생성할 때는 Default 로 생성하는 `본인 아이디` 가 표시된다.

### Repository name
말 그대로 레포 이름을 뜻함

`Organization` 에서의 레포 생성은 `Organization` 내의 레포 범위에서 **이름 중복 검사**한다는 특징이 있다.

> 💡 개인 레포의 생성 시에는, Github 상의 모든 개인 레포와 비교하여 이름 중복 검사를 한다.

### Description 
레포의 설명을 적는곳으로 Optional(선택사항)이다.

### Public & Private
레포를 모든 사람에게 공개할지, 아니면 `Organization` 내에 포함된 멤버들만 보게할 지 정하는 설정이다.

> 💡 개인 레포의 경우는 개인만 볼 지, 전체 공개를 할 지 선택하게 된다.

### Add a README file
레포에 처음 입장했을 때, 가장 먼저 화면에 표시되는 파일인 README 페이지를 생성할것인지 선택한다.

> 💡당장 안 만들어도 이후에 레포지토리의 **최상단 경로**에 `README.md` 파일만 생성해주면 똑같이 사용이 가능하다.

### Add..gitIgnore
`.gitIgnore` 란 해당 레포를 `clone` 하여 외부에서 데이터를 수정하고 커밋할 때, 커밋 대상에서 제외시킬 파일의 경로를 정리해두는 파일이다.

앞에 붙은 `.` 은 숨김파일을 의미한다.

`.gitIgnore` 는 로컬에서 프로젝트 폴더에 넣어두고 관리하는 **외부에 노출되어서는 안되는 중요한 정보(ex. AWS 계정) 를 담은 파일**등이 실수로 `Github` 에 커밋되어 불상사가 발생하는 것을 방지해준다.

> 🚨 프로젝트를 진행할 때 AWS 와 관련된 환경변수는 정말 잘 다뤄야한다.

![](https://velog.velcdn.com/images/pgmjun/post/31f3412a-36db-467e-9112-89338eff4a00/image.png)
안그럼 이런일이 발생한다고 함..

### Choose a license
Github 문서에 따르면 `라이센스`가 없으면 `기본 저작권법` 이 적용되지만, `라이센스`를 선택하게 되면 **타인의 코드 복제, 배포, 재생산**등에 대한 권한에 대하여 명시할 수 있다.
