React-Query 가 데이터를 다루는 방법
===


**React Context API 기반:** 

- React-Query 는 React의 Context API 를 기반으로 동작한다.
    - Context API 는 **리액트 컴포넌트 트리 전체에 걸쳐 데이터를 전달할 수 있게 해주는 기능**이다.

**QueryClient :** 

- React-Query 의 핵심 요소는 ‘**QueryClient**’ 라는 객체이다.
- 이 객체는 서버에서 불러온 데이터를 저장하고 관리함 → 쉽게 말해, **데이터를 관리하는 큰 저장소**라고 생각하면 됨

**데이터 저장 방식:**

- ‘QueryClient’ 는 데이터를 저장할 때, 각 데이터를 고유한 키(key) 를 사용해 저장한다.
    - 이 키는 우리가 데이터를 요청할 때 사용한 쿼리(Query) 와 연관된다.

- 예를 들어, **특정한 사용자 데이터를 가져오는 쿼리에 대해 ‘user123’ 이라는 키를 사용**했다면, 이 키를 기반으로 **데이터를 저장하고 관리**함

**다양한  메서드:** 

‘QueryClient’ 는 데이터를 관리하기 위한 다양한 메서드를 제공한다. 주요 메서드 몇 가지를 살펴보면,

- **‘getQueryData’** : 특정 키에 저장한 데이터를 가져옴
- ‘**setQueryData’** : 특정 키에 데이터를 **저장**하거나 **업데이트**한다.
- **‘fetchQuery’ :** 특정 키에 대해 서버로부터 데이터를 가져오고, 이를 QueryClient 에 저장한다.

### 예시를 통해 이해하기

생각해볼 수 있는 상황:

- 우리가 사용자 프로필 데이터를 서버에서 가져오려고 한다.
- 이 데이터를 React-Query 를 사용해 관리하려고 한다.
    
    
    1. **데이터 가져오기**: 처음 데이터를 가져올 때 ‘**fetchQuery**’ 메서드를 사용함 
        
        ex) ‘fetchQuery(’userProfile’ , fetchUserProfile) 은 ‘useProfile’ 키를 사용해 서버에서 데이터를 가져오고 이를 저장
        
    2. **데이터 사용하기:** 가져온 데이터는 ‘**getQueryData(’userprofile’)**’ 을 통해 언제든지 가져와 사용할 수 있다.
    3. **데이터 업데이트:** 만약 프로필 데이터를 업데이트하고 싶다면, **‘setQueryData(’userProfile’, newData)’** 를 사용해 새로운 데이터를 저장할 수 있다. 

### 효율적인 데이터 관리

- **캐싱:** React-Query 는 데이터를 캐싱하여, 동일한 데이터를 다시 요청할 때 서버로의 요청을 줄이고 빠르게 데이터를 제공할 수 있다.
- **비동기/동기 관리:** React-Query 는 비동기 데이터 요청을 쉽게 관리할 수 있게 해주며, 데이터를 언제 어떻게 가져오고 저장할지에 대한 다양한 옵션을 제공한다.

### 번들 사이즈

React-Query 는 기능이 많아서 라이브러리 자체가 비교적 큰 편에 속한다. 따라서 프로젝트에 React-Query 를 사용할 때는, 불필요하게 메모리를 낭비하지 않도록 주의해야한다. 제공하는 다양한 도구와 메서드를 제대로 이해하고 활용하는 것이 중요하다