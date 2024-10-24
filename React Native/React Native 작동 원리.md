React Native 작동 원리
===

React Native
---
React Native 는 Facebook 에서 개발한 오픈 소스 프레임 워크로, JavaScript 와 React 를 사용하여 ios 개발 및 Android 애플리케이션을 개발할 수 있도록 도와준다. React Native 는 네이티브 앱과 거의 동일한 사용자 경험을 제공하면서도 JavaScript 로 개발할 수 있는 크로스 플랫폼 프레임워크다.

> Native 는 토종의, 천연 그대로의 등의 뜻을 가지고 있다.
> 기초적인? 뭐 그런 뜻인 것 같다.

Android 개발에서 Kotlin 또는 Java 로 뷰를 작성한다. ios개발에서는 Swift 또는 Objective-C 를 사용한다.

React Native 를 사용하면 React 컴포넌트를 사용하여 JavaScript 로 이러한 View 를 호출할 수 있다.

**런타임에 React Native는 해당 컴포넌에 해당하는 Android 및 ios View를 생성**한다.

React Native 컴포넌트는 Android 및 ios 와 동일한 View 로 지원되기 때문에 다른 앱과 동일하게 작동한다. 이러한 플랫폼 지원 커포넌트를 **Native Components** 라고 한다.

## React Native 특징

### 1. 크로스 플랫폼 개발:
- 단일 코드 베이스로 ios와 Android 애플리케이션을 개발할 수 있다.
- 개발자는 JS 와 React 를 사용하여 앱을 작성하고, React Native 는 이를 네이티브 코드로 변환하여 실행한다.

### 2. 네이티브 성능:
- 네이티브 컴포넌트와 함께 작동하므로 애플리케이션은 실제 네이티브 앱과 비슷한 성능을 제공할 수 있다.
- React Native 의 가상 DOM 은 변경 사항을 효율적으로 제공하고, 네이티브 모듈을 사용하여 기기의 하드웨어 및 기능에 접근할 수 있다.

### 3. 재사용 가능한 컴포넌트:
- React 의 개념을 채택하여 컴포넌트 기반 개발을 지원한다.

### 4. 빠른 개발과 리로딩:
- Hot Reloading 및 Fast Refresh 와 같은 기능을 제공하여 개발자가 코드 변경 사항을 실시간으로 확인하고 빠르게 반영할 수 있다.

React Native 는 다양한 기업과 애플리케이션에서 사용되고 있으며, 크로스 플랫폼 앱 개발에 대한 수요가 높아지고 있다. 개발자는 Js와 React 의 기술 스택을 활용하여 React Native 를 사용하여 효율적이고 성능이 우수한 모바일 앱을 개발할 수 있다.

## React Native 작동 원리 
React Native의 작동 원리는 크게 세 가지 요소로 이루어져 있다.

![](https://velog.velcdn.com/images/ajm0718/post/ca46cb05-cc18-4dfd-96e8-3b16eeb2ff40/image.png)

## JavaScript Thread
React Native **애플리케이션의 로직과 UI 조작은 JS Thread 에서 실행**된다.

JS Thread는 JS 엔진에 의해 처리되며, JavaScript 코드의 실행, 가상 DOM 업데이트, 비즈니스 로직 처리 등을 담당한다. JavaScript Thread 는 **싱글 스레드**로 동작하기 때문에 비동기 작업이 중요하다. 

+ **JS의 싱글 스레드**: JS 엔진이, 한 번에 하나의 작업만 처리할 수 있다. 즉, 동기적으로 작업 수행 (!= 멀티 스레드)

UI 업데이트 등의 작업은 브릿지(Bridge) 를 통해 네이티브 UI Thread 로 전달된다.

## Bridge
**Bridge** 는 JavaScript Thread 와 Native UI Thread 사이의 **통신 역할**을 담당한다.

JS Thread 에서 발생한 UI 업데이트 요청이나 이벤트 처리 등은 Bridge 를 통해 네이티브 모듈로 전달된다. Bridge 는 이를 처리하고 필요한 UI 업데이트를 네이티브 UI Thread 에 전달한다. 

반대로, 네이티브 UI Thread 에서 발생한 이벤트나 데이트는 Bridge 를 통해 JavaScript Thread로 전달된다. Bridge 는 이를 효율적으로 처리하기 위해 **비동기 통신 방식을 사용**한다.

## Native UI Thread
**Native UI Thread** 는 **UI 업데이트 요청 및 사용자 이너터렉션에 대한 처리**를 담당한다. Bridge 를 통해 전달 받은 UI 업데이트 요청이나 이벤트를 처리하여 실제 네이티브 UI 를 업데이트 한다. 

이는 플랫폼별 UI 컴포넌트와 상호 작용하여 최종저긍로 화면에 렌더링된다.

## JS 로 앱개발이 가능한 이유
React Native 의 장점 중 하나는 네이티브 UI 스레드와 JavaScript 스레드 간의 **비동기 통신**이다. 이를 통해 UI 업데이트와 사용자 인터렉션은 네이티브 성능을 유지하면서 JS 로 개발할 수 있다.

또한 UI 상태를 **가상 DOM** 에 유지하여 필요한 업데이트만 처리하므로 성능을 최적화할 수 있다.

 JavaScript 와 네이티브 코드 간의 상호 작용을 가능하게 하는 **브릿지**를 통해 네이티브 긴으과 API 에 접근할 수 있다. 이를 통해 개발자는 JS 를 사용하여 애플리케이션의 비즈니스 로직을 구현하고, 필요한 경우 네이티브 모듈을 작성하여 플랫폼 별 기능을 사용할 수 있다.

 이러한 작동 원리를 통해 React Native 는 크로스 플랫폼 개발을 간편하게 만들어주고, 네이티브 앱과 유사한 성능과 사용자 경험을 제공한다.