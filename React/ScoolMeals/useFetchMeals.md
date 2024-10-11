useFetchMeals
===
`useFetchMeals` 코드는 **React 의 커스텀 훅**을 사용하여 API 요청을 보내고, 그 결과를 데이터로 받아와서 로딩 상태와 에러 상태를 관리하는 역할을 한다.

```js
import { useState, useEffect } from 'react';

const useFetchMeals = (API_URL) => {
  const [meals, setMeals] = useState([]); // 급식데이터 저장
  const [loading, setLoading] = useState(true); // 로딩 상태
  const [error, setError] = useState(null); // 에러 정보 저장
  
  useEffect(() => {
    // APT_URL 변경될 때마다 useEffect 가 실행되며, 새로운 API 요청으로 보낸다.
    
    // fetchMealData : API로 부터 데이터를 가져오는 역할을 함
    const fetchMealData = async () => {
      try {
        const response = await fetch(API_URL);
        const data = await response.json();
        if (data.mealServiceDietInfo) {
          // data 에 nealServiceDietInfo 가 있으면 그 안에서 급식 정보를 추출해 meals 상태에 저장
          setMeals(data.mealServiceDietInfo[1].row[meal]);
        } else {
          setMeals([]); // 급식 정보 없으면 meals 를 빈 배열로 설정
        }
        setLoading(false);
      } catch (error) {
        setError(error);
        setLoading(false);
      }
    };
    
    fetchMealData();
  }, [API_URL]);

  return { meals, loading, error }; 
  // meals, loading, error 라는 세 가지 값을 객체 형태로 반환
  // 이 값들은 App.js 에서 구조 분해 할당을 통해 각각의 변수에 할당되고, 
  // App 컴포넌트에서 API 응답 상태를 기반으로 화면에 데이터를 표시하거나 로딩 상태,
  // 에러 메시지를 처리할 수 있다.
};

export default useFetchMeals;

```