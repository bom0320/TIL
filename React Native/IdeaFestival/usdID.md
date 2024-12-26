useID
===
현재 코드에서 `useID` 를 입시로 `1`로 설정한 상태에서는 `isNewUser` 여부와 관계없이 다음과 같이 동작한다.

```js
import React, { useState, useEffect } from 'react';
import { View, Image, Text, StyleSheet, ScrollView, TouchableOpacity, Alert } from 'react-native';
import ProfileCard from '../components/ProfileCard';
import axios from 'axios';

function HomeScreen({ route }) {
  const { character, userId: passedUserId, isNewUser } = route.params || {}; // userId와 isNewUser를 전달받음
  const userId = passedUserId || 1; // 임시로 1을 기본값으로 사용 (테스트 중)

  const [missions, setMissions] = useState([]);
  const [loading, setLoading] = useState(true);

  const BASE_URL = 'https://port-0-server-lz1cq56f81af005d.sel4.cloudtype.app';

  // 미션 데이터 가져오기
  useEffect(() => {
    const fetchMissions = async () => {
      try {
        if (isNewUser && character?.major) {
          // 회원가입한 사용자: major 값을 포함한 POST 요청
          console.log('POST 요청 URL:', `${BASE_URL}/home/${userId}/mission`);
          const postResponse = await axios.post(
            `${BASE_URL}/home/${userId}/mission`,
            { major: character.major },
            { headers: { 'Content-Type': 'application/json' } }
          );
          console.log('POST 요청 응답:', postResponse.data);
        }

        // 모든 사용자: GET 요청으로 미션 데이터 가져오기
        console.log('GET 요청 URL:', `${BASE_URL}/home/${userId}/mission`);
        const getResponse = await axios.get(`${BASE_URL}/home/${userId}/mission`);
        console.log('GET 요청 응답:', getResponse.data);

        // 미션 데이터 세팅
        const missionData = getResponse.data.mission.map((mission, index) => ({
          id: `M${index}`,
          text: mission,
          completed: false,
        }));
        setMissions(missionData);
      } catch (error) {
        handleError(error);
      } finally {
        setLoading(false);
      }
    };

    fetchMissions();
  }, [userId, character, isNewUser]);

  // 미션 완료 처리
  const completeMission = async (missionId) => {
    try {
      // 로컬 상태 업데이트
      setMissions((prevMissions) => {
        const updatedMissions = prevMissions.map((mission) =>
          mission.id === missionId ? { ...mission, completed: true } : mission
        );

        const completedMissions = updatedMissions.filter((mission) => mission.completed);
        const incompleteMissions = updatedMissions.filter((mission) => !mission.completed);

        return [...incompleteMissions, ...completedMissions];
      });

      console.log(`${missionId} 미션 완료됨`);

      // `today` 배열 생성
      const today = missions.map((mission) =>
        mission.id === missionId || mission.completed ? 1 : 0
      );

      console.log('today 배열:', today);

      // 서버로 완료된 미션 데이터 전달
      const requestData = { today };
      const response = await axios.post(
        `${BASE_URL}/home/${userId}/mission/value`,
        requestData,
        { headers: { 'Content-Type': 'application/json' } }
      );

      console.log('미션 완료 POST 요청 성공:', response.data);
    } catch (error) {
      handleError(error);
    }
  };

  // 에러 처리 함수
  const handleError = (error) => {
    if (error.response) {
      console.error('응답 오류:', error.response.data);
      Alert.alert('오류', `서버 오류: ${error.response.data.message || '요청 실패'}`);
    } else if (error.request) {
      console.error('요청 오류:', error.request);
      Alert.alert('오류', '서버에 응답이 없습니다. 네트워크를 확인하세요.');
    } else {
      console.error('설정 오류:', error.message);
      Alert.alert('오류', '요청을 보내는 중 문제가 발생했습니다.');
    }
  };

  if (loading) {
    return (
      <View style={styles.loadingContainer}>
        <Text style={styles.loadingText}>미션 로딩 중...</Text>
      </View>
    );
  }

  return (
    <ScrollView contentContainerStyle={styles.scrollContainer}>
      {/* 상단 캐릭터와 프로필 */}
      <View style={styles.imageWrapper}>
        <ProfileCard />
        <Image source={character.homeImage} style={styles.image} />
      </View>

      {/* 하단 스크롤 가능한 미션 창 */}
      <View style={styles.missionContainer}>
        <Text style={styles.missionTitle}>미션 리포트</Text>
        {missions.map((mission) => (
          <View key={mission.id} style={styles.missionContent}>
            <Text style={styles.missionText}>{mission.text}</Text>
            <TouchableOpacity
              style={[
                styles.completeButton,
                mission.completed && styles.completedButton,
              ]}
              onPress={() => completeMission(mission.id)}
              disabled={mission.completed} // 완료된 미션은 버튼 비활성화
            >
              <Text
                style={[
                  styles.completeText,
                  mission.completed && styles.completedText,
                ]}
              >
                {mission.completed ? '완료됨' : '완료하기'}
              </Text>
            </TouchableOpacity>
          </View>
        ))}
      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  scrollContainer: {
    flexGrow: 1, // 스크롤 가능한 영역 확장
    backgroundColor: '#000',
    paddingBottom: 1, // bottomBar 공간만큼 여백 추가
    marginTop: 24,
  },
  imageWrapper: {
    alignItems: 'center', // 이미지 가로 정렬
    marginBottom: 20, // 아래 여백
  },
  image: {
    width: 200, // 이미지 가로 크기 설정
    height: 500, // 이미지 세로 크기 설정
    resizeMode: 'cover', // 비율 유지하며 크기 조정
  },
  missionContainer: {
    width: '98%',
    alignSelf: 'center',
    backgroundColor: '#2B2A2A',
    borderRadius: 26,
    padding: 16,
    marginTop: -120,
    paddingBottom: 100,
    paddingTop: 20,
  },
  missionTitle: {
    marginTop: 10,
    color: '#fff',
    fontSize: 18,
    fontWeight: 'bold',
    marginBottom: 20,
    left: 10,
  },
  missionContent: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    backgroundColor: '#444',
    borderRadius: 10,
    padding: 34,
    marginBottom: 14,
  },
  missionText: {
    color: '#fff',
    fontSize: 20,
    right: 10,
  },
  completeButton: {
    backgroundColor: '#ADA209',
    paddingVertical: 8,
    paddingHorizontal: 18,
    borderRadius: 18,
    left: 14,
  },
  completedButton: {
    backgroundColor: '#555', // 완료된 버튼 색상 변경
  },
  completeText: {
    color: 'white',
    fontWeight: 'bold',
    fontSize: 16,
  },
  completedText: {
    color: '#aaa', // 완료된 버튼 텍스트 색상 변경
  },
  loadingContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#000',
  },
  loadingText: {
    color: '#fff',
    fontSize: 18,
    fontWeight: 'bold',
  },
});

export default HomeScreen;

```

## 1. 임시로 `useId` 를 `1` 로 설정한 경우 (현재 상태)
- `useID` 는 항상 `1`이므로, 모든 요청에서 `useID` 가 `1`로 고정된다.

### `isNewUser` 조건:
- 코드에 `isNewUser && character?.major` 조건이 있지만, 실제로는 `useID` 가 `1`이므로 이 조건과 상관없이 요청이 고정된 사용자(ID = 1) 에게 동작한다.

### 동작 흐름:

#### 1. 회원가입 여부 상관없이 실행:
- `isNewUser` 가 `true` 라면 `POST` 요청이 수행된다.
- 이후 `GET` 요청으로 데이터를 가져온다.
- **결과적으로, 매번 `userID=1`을 기준으로 데이터를 처리**한다.

#### 2. 미션 완료:
- 완료된 미션 데이터를 생성한 후, `POST` 요청으로 전달한다.
- 이때도 `useID = 1` 로 고정된 상태로 동작한다.

## 2. `userID` 를 직접 전달받는 경우 (미래 구현 상태)
`userID` 가 실제로 전달되면, 이제 시스템이 사용자 고유의 `userID` 를 기밪으로 동작한다. `isNewUser` 여부에 따라 로직이 달라진다.

### 동작 흐름:

#### 1. 회원가입한 사용자 (`isNewUser` === `true`):
- `POST` 요청으로 `major` 값을 전달
- 이후 `GET` 요청으로 사용자 (`userID`)의 미션 데이터를 가져온다.


**예 :**

- `POST` 요청:

```bash
URL: /home/3/mission
데이터: { major: 3 }
```

- `GET` 요청:

```bash
URL: /home/3/mission
응답 데이터: { mission: ["미션1", "미션2"], today: [0, 0, 0, 0, 0] }
```

### 2. 기존 사용자 (`isNewUser === false`) :

- `GET` 요청만 수행
- 사용자(`userID`) 의 미션 데이터를 바로 가져온다.

**예 :**

- `GET` 요청:

```bash
URL: /home/2/mission
응답 데이터: { mission: ["미션1", "미션2"], today: [0, 1, 0, 0, 0] }
```

### 3. 미션 완료:
- 특정 미션을 완료할 때마다 `today` 배열을 생성하고, 사용자 (`userID`) 고유 데이터를 백엔드로 전달
- 예를 들어, `userID = 3` 인 사용자가 `M0` 을 완료했다면

- `POST` 요청:
```bash

URL: /home/3/mission/value
데이터: { today: [1, 0, 0, 0, 0] }
```

## 코드의 작동 방식 비교

### 현재 (임시 `userID = 1`)
- 모든 사용자와 동작이 동일하게 처리됨
- `POST`, `GET`, 완료된 미션 데이터가 **항상 `userID = 1`** 에 한정되어 동작

### 미래 (`userID` 를 동적으로 전달받는 경우)
- **회원가입 여부와 관계없이 사용자가 고유 ID로 식별됨**
- 요청 URL 과 데이터가 사용자의 `useID` 에 따라 달라짐:
    - 신규 사용자: `POST` → `GET`.
    - 기존 사용자: `GET`만 수행.
    - 미션 완료 시: `POST`로 완료된 미션 데이터 전달.


## 최종 코드의 작동 예시

1. **회원가입 후 신규 사용자 (ID: 5, `isNewUser = true`)**:
    - `POST` 요청: `/home/5/mission` (major 값 전달).
    - `GET` 요청: `/home/5/mission` (미션 데이터 가져오기).
2. **기존 사용자 (ID: 3, `isNewUser = false`)**:
    - `GET` 요청: `/home/3/mission` (미션 데이터 가져오기).
3. **미션 완료 (ID: 3)**:
    - `POST` 요청: `/home/3/mission/value` (완료된 미션 데이터 전달).

## 테스트 시의 상태
현재는 임시로 `1` 을 사용하여 모든 동작이 동일하게 실행되고 있다. 이후 `userID` 를 실제로 동적으로 전달받도록 구현이 완료되면, 현재 코드는 사용자별로 동작하는 상태로 자연스럽게 전환된다. **즉, 지금은 테스트를 위한 고정값이고, 실제로는 동적 `userID` 를 받아 완전하게 작동한다**