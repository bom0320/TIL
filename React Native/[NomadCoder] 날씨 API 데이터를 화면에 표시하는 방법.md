날씨 API 데이터를 화면에 표시하는 방법
===

강의에서 사용한 API 와 내가 사용한 API 가 다르기에, API에서 날씨 데이터를 다루는 방법과, React Native UI 에 표시하는 패턴이 전혀 달랐었다.

#### 3-hour Forecast 5 days 데이터

```json
 LOG  [
  {
    "dt": 1730764800,
    "main": {
      "temp": 10.65,
      "feels_like": 9.34,
      "temp_min": 10.65,
      "temp_max": 10.65,
      "pressure": 1023,
      "sea_level": 1023,
      "grnd_level": 1021,
      "humidity": 60,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 804,
        "main": "Clouds",
        "description": "overcast clouds",        
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 100
    },
    "wind": {
      "speed": 1.97,
      "deg": 352,
      "gust": 6.12
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-05 00:00:00"
  },
  
  
  {
    "dt": 1730851200,
    "main": {
      "temp": 10.37,
      "feels_like": 9.03,
      "temp_min": 10.37,
      "temp_max": 10.37,
      "pressure": 1026,
      "sea_level": 1026,
      "grnd_level": 1024,
      "humidity": 60,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 803,
        "main": "Clouds",
        "description": "broken clouds",
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 59
    },
    "wind": {
      "speed": 2.26,
      "deg": 350,
      "gust": 7.01
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-06 00:00:00"
  },
  {
    "dt": 1730937600,
    "main": {
      "temp": 7.11,
      "feels_like": 6.12,
      "temp_min": 7.11,
      "temp_max": 7.11,
      "pressure": 1030,
      "sea_level": 1030,
      "grnd_level": 1027,
      "humidity": 50,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 803,
        "main": "Clouds",
        "description": "broken clouds",
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 63
    },
    "wind": {
      "speed": 1.71,
      "deg": 36,
      "gust": 2.54
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-07 00:00:00"
  },
  {
    "dt": 1731024000,
    "main": {
      "temp": 11.11,
      "feels_like": 9.92,
      "temp_min": 11.11,
      "temp_max": 11.11,
      "pressure": 1030,
      "sea_level": 1030,
      "grnd_level": 1027,
      "humidity": 63,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 804,
        "main": "Clouds",
        "description": "overcast clouds",        
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 98
    },
    "wind": {
      "speed": 1.34,
      "deg": 60,
      "gust": 1.98
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-08 00:00:00"
  },
  {
    "dt": 1731110400,
    "main": {
      "temp": 12.74,
      "feels_like": 11.85,
      "temp_min": 12.74,
      "temp_max": 12.74,
      "pressure": 1030,
      "sea_level": 1030,
      "grnd_level": 1027,
      "humidity": 68,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 804,
        "main": "Clouds",
        "description": "overcast clouds",        
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 97
    },
    "wind": {
      "speed": 1.45,
      "deg": 47,
      "gust": 2.58
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-09 00:00:00"
  }
]
 LOG  [
  {
    "dt": 1730764800,
    "main": {
      "temp": 10.65,
      "feels_like": 9.34,
      "temp_min": 10.65,
      "temp_max": 10.65,
      "pressure": 1023,
      "sea_level": 1023,
      "grnd_level": 1021,
      "humidity": 60,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 804,
        "main": "Clouds",
        "description": "overcast clouds",        
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 100
    },
    "wind": {
      "speed": 1.97,
      "deg": 352,
      "gust": 6.12
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-05 00:00:00"
  },
  {
    "dt": 1730851200,
    "main": {
      "temp": 10.37,
      "feels_like": 9.03,
      "temp_min": 10.37,
      "temp_max": 10.37,
      "pressure": 1026,
      "sea_level": 1026,
      "grnd_level": 1024,
      "humidity": 60,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 803,
        "main": "Clouds",
        "description": "broken clouds",
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 59
    },
    "wind": {
      "speed": 2.26,
      "deg": 350,
      "gust": 7.01
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-06 00:00:00"
  },
  {
    "dt": 1730937600,
    "main": {
      "temp": 7.11,
      "feels_like": 6.12,
      "temp_min": 7.11,
      "temp_max": 7.11,
      "pressure": 1030,
      "sea_level": 1030,
      "grnd_level": 1027,
      "humidity": 50,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 803,
        "main": "Clouds",
        "description": "broken clouds",
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 63
    },
    "wind": {
      "speed": 1.71,
      "deg": 36,
      "gust": 2.54
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-07 00:00:00"
  },
  {
    "dt": 1731024000,
    "main": {
      "temp": 11.11,
      "feels_like": 9.92,
      "temp_min": 11.11,
      "temp_max": 11.11,
      "pressure": 1030,
      "sea_level": 1030,
      "grnd_level": 1027,
      "humidity": 63,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 804,
        "main": "Clouds",
        "description": "overcast clouds",        
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 98
    },
    "wind": {
      "speed": 1.34,
      "deg": 60,
      "gust": 1.98
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-08 00:00:00"
  },
  {
    "dt": 1731110400,
    "main": {
      "temp": 12.74,
      "feels_like": 11.85,
      "temp_min": 12.74,
      "temp_max": 12.74,
      "pressure": 1030,
      "sea_level": 1030,
      "grnd_level": 1027,
      "humidity": 68,
      "temp_kf": 0
    },
    "weather": [
      {
        "id": 804,
        "main": "Clouds",
        "description": "overcast clouds",        
        "icon": "04d"
      }
    ],
    "clouds": {
      "all": 97
    },
    "wind": {
      "speed": 1.45,
      "deg": 47,
      "gust": 2.58
    },
    "visibility": 10000,
    "pop": 0,
    "sys": {
      "pod": "d"
    },
    "dt_txt": "2024-11-09 00:00:00"
  }
]
```

### 데이터 확인 방법

데이터가 어떻게 구성되어 있는지 보기 쉽게 확인할 수 있는 주요 필드를 설명해 보겠다.

1. **날짜와 시간** (`dt_txt`):
    - `"2024-11-05 00:00:00"`와 같이 날짜와 시간이 있다.
    - 이 필드는 각 날의 자정 데이터를 나타내므로, 하루를 대표하는 데이터로 사용할 수 있다.
2. **온도** (`main.temp`, `main.feels_like`):
    - `"temp"`: 해당 시간대의 실제 온도.
    - `"feels_like"`: 체감 온도.
    - 예를 들어, `"temp": 10.65`는 이 시간대의 온도가 10.65도임을 나타낸다.
3. **날씨 상태** (`weather`):
    - `"main"`: 날씨의 간략한 설명 (예: "Clouds").
    - `"description"`: 날씨의 자세한 설명 (예: "overcast clouds").
    - `"icon"`: 아이콘 코드(날씨 아이콘을 표시할 때 사용).
4. **바람** (`wind`):
    - `"speed"`: 풍속 (예: `"speed": 1.97`).
    - `"deg"`: 풍향 (예: `"deg": 352`).
5. **구름** (`clouds.all`):
    - `"all"`: 구름량을 나타내며, 0에서 100 사이의 값
6. **기타 정보**:
    - `"humidity"`: 습도.
    - `"pressure"`: 기압.

### UI에 표시할 때 활용 예시

예를 들어, 이 데이터를 `React Native` UI에 표시할 때 다음과 같이 접근할 수 있다.

```jsx
javascript
코드 복사
days.map((day, index) => (
  <View key={index} style={styles.day}>
    <Text style={styles.temp}>{day.main.temp}°C</Text>  {/* 온도 */}
    <Text style={styles.description}>{day.weather[0].main}</Text>  {/* 날씨 상태 */}
    <Text style={styles.tinyText}>{day.weather[0].description}</Text>  {/* 자세한 설명 */}
    <Text style={styles.date}>{day.dt_txt}</Text>  {/* 날짜와 시간 */}
  </View>
))

```

이렇게 하면 `main.temp`, `weather[0].main`, `weather[0].description`, `dt_txt` 등의 필드를 활용해 온도, 날씨 상태, 날짜와 같은 정보를 화면에 표시할 수 있다.