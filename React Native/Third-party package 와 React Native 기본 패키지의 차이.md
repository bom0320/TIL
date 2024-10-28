Third-party package와 React Native 기본 패키지의 차이
===

## 1. Third-party package 란?
- Third-party package 는 React Native 기본 패키지에 포함되지 않은 **외부 라이브러리** 또는 **모듈**을 뜻한다.
- 주로 **커뮤니티** 나 **다른 개발자들**에 의해 제작되었으며, React Native 의 기능을 **확장** 하거나 **특정 기능을 더 쉽게 구현** 할 수 있도록 돕는 역할을 한다.
- 이러한 패키지는 필요에 따라 프로젝트에 추가할 수 있다.

## 2. Third-party package 의 목적과 기능
- React Native 에는 **기본적인 UI 컴포넌트**(예: `Button`, `Text`, `Image`) 와 몇 가지 주요 기능만 포함되어 있다. 
- Third-party package는 이 외의 **추가 기능** 을 제공하거나, **복잡한 기능을 간편하게 구현**할 수 있도록 한다. 
    - **React Navigation :** 복잡한 네비게이션 (탭, 스택, 드로어 등) 을 쉽게 구현
    - **Axios :** 서버와 데이터 통신을 위해 네티워크 요청을 처리
    - **Redux :** 글로벌 상태 관리를 위한 라이브러리
    - **react-native-gesture-handler :** 다양한 제스처 (스와이프, 드레그 등) 을 지원.


## 3. Third-part package 와 React Native 기본 패키지의 차이점 
- **React Native 기본 패키지 :** React Native 가 기본적으로 제공하는 컴포넌트와 기능, 추가 설치 없이 기본적으로 사용할 수 있는 컴포넌트들로, 주로 간단한 UI 요소들로 구성
- **Third-party package :** 프로젝트에 필요한 기능을 추가할 수 있는 외부 라이브러리, `npm`이나 `yarn` 을 통해 설치하고 사용

## 4. 혼동하지 않기 위한 포인트
- Third-party package 는 React Native 의 주요 컴포넌트를 제외하고 주요 기능만 포함한것이 아니다. 
- 오히려 React Native 의 기본 기능을 확장해주고, 운영 체제와 소통하는 추가 기능을 제공하는 외부 라이브러리이다. 