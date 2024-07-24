Github 로 로컬 저장소 생성부터 merge 까지
===

### 로컬 저장소 생성 (일반적인 디렉토리를 git working tree로)

일반적인 디렉토리를 git working tree로 만드는 방법은 cd를 통해 원하는 경로에 접속한 후 git init을 해주는 것이다.

- 나는 Analyst 폴더에 git_practice 폴더를 만들어서 이 폴더를 git working tree로 바꿔주었다.

```
#Input
cd /Users/sseozytank/Analyst/git_practice/.git/#경로 수정
git init

#Output
Initialized empty Git repository in /Users/sseozytank/Analyst/git_practice/.git/
```

**로컬 저장소를 원격 저장소에 연결하는 방법**

- remote-name 은 원격 저장소에 대한 별칭
- git address 는 생성한 레파지토리의 URL 을 복사한 뒤  .git 을 올려주면 된다.

```
git remote add <remote-name> <git address>

# 예시
git remote add git_test http:// github.com/sseozy/github_text.git
git push -u
```

**연결된 원격 저장소 확인하려면**

```
git remote --verbose
```

``

**원격 저장소 이름을 변경하려면**

```
git remote rename <old-remote-name> <new-remote-name>

#예시git remote rename git_text new _git_test
```

**원격 연결을 삭제하려면**

```
git remote remove <remote-name>
```

### Staging Area 에 파일 올리기

local 에서 Staging Area 에 파일 올리기

![img1.daumcdn.png](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbeOlZA%2FbtsafeV9iFP%2FYu9ke60Fv5LqxvKoKzmJVk%2Fimg.png)

(Git Working Direcoory 로 설정한 git_practice 에 한줄 코드를 적어 git_text.ipyb(jupter) 파일을 작업함)

```
git add <filename>

#example
git add git_test.ipynb
```

**git status 명령어를** 통해 잘 되었는지 확인하면 잘 올라간 것을 확인할 수 있다.

![img1.daumcdn.png](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fc1NqBi%2FbtsahLlkOAW%2FuXq7lkeucNRIMgYqxzAFxK%2Fimg.png)

**한번에 stage 에 올리고 싶다**

```
git add .
git add --all
#둘이 같은 명령어
```

**특정 디렉토리에 있는 문서나, py 파일만 올리고 싶다**

```
# * 라는 와일드카드를 활용하면 된다.
git add /new/*
git add *.py
```

**한 파일 내에 수정 사항만 준비 영역에 넣고 싶을 때**

(기존 stage 에 올린 파일에 print 문 한줄을 추가해서 다시 add 해봄)

```
git add --patch git_test.ipynb
```

![img1.daumcdn.png](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbtmvVv%2FbtsahJVmQTJ%2Fktkbp3vzIOPSnOx7foWVXK%2Fimg.png)

결과가 이렇게 뜨는 것을 확인할 수 있는데, 수정된 부분마다 옵션을 선택해주면 된다.

```
**Stage this hunk [y,n,a,d,/,j,J,g,e,?]? ?
y - stage this hunk
n - do not stage this hunk
a - stage this and all the remaining hunks in the file
d - do not stage this hunk nor any of the remaining hunks in the file
g - select a hunk to go to
/ - search for a hunk matching the given regex
j - leave this hunk undecided, see next undecided hunk
J - leave this hunk undecided, see next hunk
k - leave this hunk undecided, see previous undecided hunk
K - leave this hunk undecided, see previous hunk
s - split the current hunk into smaller hunks
e - manually edit the current hunk
? - print help**
```

나는 이것도 넣고 싶으니 y를 입력해주었다. 그럼 스테이지에 올라간 파일은 print("추가한 부분을 찾아야해요") 또한 반영돼서 올라간 것이다!

**staging Area 에 올라간 파일을 Commit 해보자**

```
git commit -m "깃 처음 사용했어요"
```

**커밋 메세지를 수정하고 수정하고 싶을때**

```
git commit --amend
```

i를 눌러 수정한 후, ESC(에디터 모드에서 명령 모드로 변경) → :wq(저장 및 종료 모두 입력) → Enter 순으로 클릭

### Commit 한 파일을 Push  해서 원격 저장소로 보내자

```
git push <remote_name> <branch_name>

#example
git push git test main
```

![img1.daumcdn.png](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FAfikE%2Fbtsah97y0qA%2FKyyqVKIbXGVzABNggopQJ0%2Fimg.png)

푸쉬 후 잘 땡겨온 것을 확인할 수 있다.