데이터베이스(DB) 란?
===

- 데이터베이스는 체계적이고 구조적으로 데이터를 저장, 관리, 검색할 수 있는 시스템이다.
-  데이터베이스는 데이터를 효율적으로 저장하고 관리하며, 필요할 때 빠르게 검색하고 업데이트 할 수 있는 기능을 제공한다.
-  데이터베이스는 다양한 형태의 데이터를 저장할 수 있으며, 여러 사용자나 응용 프로그램이 동시에 데이터를 접근하고 조작할 수 있게 한다.

## 데이터 베이스의 주요 구성 요소

1. **데이터:** 
    - 저장되는 정보
    - 예) 사용자 정보, 제품 목록, 주문 내역 등
2. **DBMS (Database Management System):**
- ****데이터베이스를 생성, 관리, 조작하는 소프트웨어
- 예) MySQL, PostgreSQL, PostgreSQL, MongoDB, Firebase 등이 있다.
1. 스키마(Schema)  : 데이터베이스 구조를 정의한 것, 테이블, 필드, 데이터 타입 등을 포함한다.
2. 쿼리(Query) : 데이터베이스에서 데이터를 검색하거나 조작하기 위해 사용하는 명령어 SQL(Structruced Query Language)이 대표적인 쿼리 언어

### 데이터베이스의 종류

데이터베이스는 그 구조와 사용 목적에 따라 여러 종류로 나눌 수 있다. 

주요 데이터 유형
---

### 1. 관계형 데이터베이스 (Relational Database)

관계형 데이터베이스는 데이터를 테이블 형식으로 저장하며, 각 테이블은 행과 열로 구성된다. 테이블 간의 관계를 정의할 수 있어 복잡한 데이터 구조를 쉽게 표현할 수 있다.

- **예시**: MySQL, PostgreSQL, Oracle Database, Microsoft SQL Server.
- **특징**:
    - 데이터를 테이블 형태로 저장.
    - SQL을 사용하여 데이터 조작.
    - 스키마가 고정되어 있어 데이터 무결성을 유지하기 쉽습니다.
    - 트랜잭션을 지원하여 데이터의 일관성과 무결성을 보장.
- **예시 사용**: 사용자 정보, 주문 내역, 재고 관리 등.

```sql
sql코드 복사
-- 사용자 테이블 생성
CREATE TABLE Users (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);

-- 사용자 데이터 삽입
INSERT INTO Users (id, name, email) VALUES (1, 'Alice', 'alice@example.com');

-- 사용자 데이터 조회
SELECT * FROM Users;

```

### 2. NoSQL 데이터베이스

NoSQL 데이터베이스는 비정형 데이터를 저장하기 위해 설계된 데이터베이스로, 스키마가 고정되지 않고 데이터의 유연한 저장이 가능하다. 문서, 키-값, 열 기반, 그래프 데이터베이스 등 다양한 유형이 있다.

- **예시**: MongoDB, Cassandra, Redis, Firebase Firestore.
- **특징**:
    - 유연한 데이터 모델.
    - 스키마가 고정되지 않아 데이터 구조를 쉽게 변경할 수 있음.
    - 수평적 확장성(Scale-out) 지원.
    - 대규모 분산 환경에 적합.
- **예시 사용**: 소셜 미디어 포스트, 로그 데이터, IoT 데이터 등.

```jsx
javascript코드 복사
// Firestore 초기화
const db = firebase.firestore();

// 사용자 문서 생성
db.collection("users").doc("1").set({
    name: "Alice",
    email: "alice@example.com"
});

// 사용자 데이터 조회
db.collection("users").doc("1").get().then((doc) => {
    if (doc.exists) {
        console.log("User data:", doc.data());
    } else {
        console.log("No such document!");
    }
});

```

### 데이터베이스 선택 기준

데이터베이스를 선택할 때 고려해야 할 주요 기준은 다음과 같다.

1. **데이터 구조**: 데이터가 정형화된 구조인지 비정형인지에 따라 관계형 또는 NoSQL 데이터베이스를 선택

2. **확장성**: 데이터베이스의 수평적 확장(Scale-out)과 수직적 확장(Scale-up) 능력을 고려

3. **성능 요구사항**: 읽기/쓰기 성능, 응답 시간 등의 요구사항에 맞는 데이터베이스를 선택

4. **트랜잭션 및 일관성**: 트랜잭션을 지원하고 데이터의 일관성을 보장해야 하는 경우 관계형 데이터베이스가 적합함

5. **개발 및 운영 편의성**: 팀의 기술 스택, 기존 인프라, 개발 및 운영 경험을 고려한다.