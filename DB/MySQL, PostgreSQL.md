MySQL
=== 
**MySQL**은 오픈 소스 관계형 데이터베이스 관리 시스템(RDBMS)으로, 웹 애플리케이션에서 널리 사용된다.

**특징:**

- **ACID 준수**: 원자성, 일관성, 고립성, 지속성을 보장.
- **SQL 사용**: 구조화된 쿼리 언어(SQL)를 사용하여 데이터를 관리.
- **광범위한 사용**: 다양한 플랫폼과의 호환성 및 커뮤니티 지원.

**장점:**

- **성능**: 빠른 읽기 성능.
- **신뢰성**: 데이터 무결성 보장.
- **확장성**: 수직 및 수평 확장이 가능.

**사용 예시:**

```sql
-- 일기 테이블 생성
CREATE TABLE Diaries (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    content TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- 일기 삽입
INSERT INTO Diaries (title, content) VALUES ('My First Diary', 'Today was a good day!');

-- 일기 조회
SELECT * FROM Diaries;

```

### PostgreSQL

**PostgreSQL**는 오픈 소스 객체-관계형 데이터베이스 관리 시스템(ORDBMS)으로, 강력한 기능과 확장성을 제공함

**특징:**

- **ACID 준수**: 원자성, 일관성, 고립성, 지속성을 보장.
- **SQL 및 JSON 지원**: SQL과 함께 JSON 데이터를 저장하고 쿼리할 수 있음.
- **확장성**: 사용자 정의 함수, 데이터 타입, 인덱스 등을 지원.

**장점:**

- **강력한 기능**: 고급 쿼리, 트랜잭션, 서브쿼리, 윈도우 함수 등 지원.
- **확장성**: 대규모 데이터베이스에 적합.
- **오픈 소스**: 자유롭게 사용 및 수정 가능.

**사용 예시:**

```sql
sql코드 복사
-- 일기 테이블 생성
CREATE TABLE Diaries (
    id SERIAL PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    content TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- 일기 삽입
INSERT INTO Diaries (title, content) VALUES ('My First Diary', 'Today was a good day!');

-- 일기 조회
SELECT * FROM Diaries;

```

### NoSQL 데이터베이스

**NoSQL 데이터베이스**는 비정형 데이터를 저장하는 데 최적화된 데이터베이스 시스템. 스키마가 고정되지 않아 다양한 데이터 구조를 유연하게 저장할 수 있다. Firebase의 Firestore가 대표적인 NoSQL 데이터베이스

### Firebase Firestore

**Firestore**는 Firebase에서 제공하는 클라우드 기반 NoSQL 문서 데이터베이스. 실시간 동기화와 오프라인 지원을 제공하여 모바일 및 웹 애플리케이션에서 널리 사용된다.

**특징:**

- **문서-컬렉션 모델**: 데이터를 문서(Document)로 저장하고, 문서는 컬렉션(Collection) 내에 존재.
- **실시간 동기화**: 클라이언트 간의 데이터 변경 사항을 실시간으로 동기화.
- **오프라인 지원**: 네트워크가 끊겨도 로컬에 데이터를 저장하고, 나중에 동기화 가능.

**장점:**

- **유연성**: 스키마가 고정되지 않아 다양한 데이터 구조를 저장 가능.
- **확장성**: 수평적으로 확장 가능.
- **실시간 기능**: 실시간 데이터 동기화가 가능하여 동적 애플리케이션에 적합.

**사용 예시:**

```jsx
javascript코드 복사
// Firestore 초기화
const db = firebase.firestore();

// 일기 컬렉션에 새 문서 추가
db.collection("diaries").add({
    title: "My First Diary",
    content: "Today was a good day!",
    created_at: firebase.firestore.FieldValue.serverTimestamp()
})
.then((docRef) => {
    console.log("Document written with ID: ", docRef.id);
})
.catch((error) => {
    console.error("Error adding document: ", error);
});

// 일기 컬렉션에서 문서 조회
db.collection("diaries").get().then((querySnapshot) => {
    querySnapshot.forEach((doc) => {
        console.log(`${doc.id} => ${doc.data().title}`);
    });
});

```
