Github 기초 사용법
===

**git 이란?**

---

개발자들에겐 소스코드의 버전관리를 위한 시스템이다.

> **목차**
> 
1. git init & status & add
2. Commit
3. Branch
4. Merge
5. 병합(merge) 충돌 관리

## 1. git init & status & add

먼저 작업공간을 정한 후, git Bash 를 열고 git init 을 생성하면 다음과 같이 초기화 

![img1.daumcdn.jpg](https://aipoque.com/wp-content/uploads/2023/12/gitinittogitpush.jpg)

git init 을 완료하면 (master) 가 추가됨을 확인할 수 있고, 내 작업 공간에서 버전 관리를 위한 환경이 구성됨을 의미한다. 하지만 폴더 내에서는 아무 변화가 없어보인다. 

폴더에 파일 하나를 생성해보자. Hello, World 를 출력하는 C 코드를 작성해본다

```c
#include <stdio.h>

int main()
{
	printf("Hello World!");
	return 0;
}
```