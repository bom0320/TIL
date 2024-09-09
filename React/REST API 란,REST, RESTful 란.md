[네트워크] REST API 란? REST,RESTful 이란?
===

## REST API
> REST API (Representational State Transfer API)

**REST API 란 REST를 기반으로 만들어진 API를 의미한다 REST API 를 알기 위해 REST 부터 알아보도록 하자**

---
### REST 란?
- REST (Representational State Transfer)의 약자로 자원을 이름으로 구분하여 해당 자원의 상태를 주고 받는 모든 것을 의미한다. 
- REST 는 자원을 URL 로 식별하고 그 자원의 상태를 클라이언트와 서버 간에 주고 받는 모든 행위를 의미한다.

## 즉 REST 란
1. HTTP URL(Uniform Resource Identifier)를 통해 자원(Resource)을 명시하고,
2. HTTP Method(POST,GET,PUT,DELETE,PATCH 등) 를 통해
3. 해당 자원(url) 에 대한 CRUD Operation 을 적용하는 것을 의미한다.

> **CRUD Operation 이란**
>
> CRUD 는 대부분의 컴퓨터 소프트웨어가 가지는 기본적인 데이터 처리기능인 Create(생성), Read(읽기), Update(갱신), Delete(삭제)를 묶어서 일컫는 말로 REST 에서의 CRUD Operation 동작 예시는 다음과 같다.

```
Create : 데이터 생성(POST)
Read : 데이터 조회(GET)
Update: 데이터 수정(PUT,PATCH)
Delete: 데이터 삭제(DELETE)
```

## REST 구성 요소
REST는 다음과 같은 3가지로 구성이 되어 있따.

1. **자원(Resource) : HTTP URI**
2. **자원에 대한 행위(verb) : HTTP Method**
3. **자원에 대한 행위의 내용(Representations) : HTTP Message Pay Load**
