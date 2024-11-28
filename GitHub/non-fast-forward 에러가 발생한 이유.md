non-fast-forward 에러가 발생한 이유
===

```bash
PS C:\Users\user\Documents\Client\Client-2-3> git push origin main

To https://github.com/FourLeaves4/Client-2.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/FourLeaves4/Client-2.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```
여기 terminal 을 보면, `git push origin main` 이 실패해, none-fast-forward 에러가 발생한 걸 볼 수 있다.

## 왜 `git push` 가 실패했을까?

### 1. 원격 브랜치가 더 앞서 있음
- PR 병합으로 인해 원격 `main` 브랜치에 새로운 커밋이 추가되었다.
- 하지만 로컬 `main` 브랜치는 PR 병합 후 업데이트(`git pull`) 되지 않은 상태였다.
- 이 상황에서 `git push` 를 시도하면, Git 은 **원격 브랜치에 내가 모르는 커밋이 있으니 덮어쓰지 마라**라고 거부하게 된다.

### 2. non-fast-forward 에러
- Git 은 기본적으로 브랜치 히스토리가 뒤쳐진 상태에서 원격 브랜치를 덮어쓰지 못하게 설계되어 있다.
- 덮어쓰기 허용은 협업 중 실수를 방지하기 위한 중요한 안전 장치이다.


## 문제 해결 과정

### `git pull origin main` 으로 원격 브랜치 업데이트
- `git pull` 을 실행하여 원격 `main` 브랜치의 변경 사항을 로컬로 가져왔다.
- 이 과정에서 Fast-forward 병합이 이루어졌다.
- 결과적으로, 로컬과 원격 브랜치가 동일한 상태가 되었다.

### 2. `git push origin main` 재실행
- 이제 로컬 브랜치가 최신 상태이므로, `git push` 가 성공적으로 실행된다.

## 교훈
PR 병합 후에는 **항상 로컬 브랜치를 먼저 업데이트**해야 한다. 다음과 같은 워크플로우를 기억하자

### 1. PR 병합 후 로컬 업데이트
PR 병합 후 반드시, `git pull origin main` 을 실행하여 최신 상태로 업데이트 하자

### 2. 로컬 작업 후 푸쉬
로컬에서 작업을 완료하고 커밋한 후, `git push origin main` 으로 원격 브랜치에 푸쉬한다.

### 3. 작업 전에도 동기화
협업 중이라면 작업 시작 전에 항상 원격 브랜치와 로컬 브랜치를 동기화하도록 하자

```bash
git pull origin main
```

### 결론
맨 처음에 `git pull` 없이 바로 `git push` 를 시도했기 때문에 non-fast-forward 에러가 발생했다. 이 문제는 `git pull` 로 원격 브랜치와 로컬 브랜치를 동기화함으로써 해결되었다.