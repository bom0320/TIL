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

