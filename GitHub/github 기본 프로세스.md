github 기본 프로세스
===

Github의 프로세스는 다음과 같다.

- 자신의 수정 내역을 원격 저장소에 내보내려면 git add → git commit → git push 의 과정을 거쳐야 함
- 수정 내역을 받아올 때는 git fetch 수행
- 이 과정에서, 내가 수정한 내역이 원격 저장소에 있는 내역과 다를 수 있기 때문에   git merge 를 수행하여 자신의 컴퓨터에 있는 소스코드를 원격지정소와 맞추는 것
    
    
    ![img1.daumcdn.jpg](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fk9OtY%2FbtsaeodSLNy%2FCKcl3nPgpXn8kH0VG7P8sK%2Fimg.jpg)
    
    **staging area는 왜 거치는건지?**
    
    1) 작업 트리의 모든 변경 사항을 한 번에 커밋하는 대신 변경 사항을 분리할 수 있다. 
    
    2) 개발자가 다른 브랜치로 변경사항을 이동하는 것도 더 쉬워진다.
    
    → 변경 사항을 분리하고 더 효율적으로 관리하는 데 매우 유용한 도구이다.