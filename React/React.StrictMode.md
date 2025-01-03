React.StrictMode
===
`React.StrictMode` 는 React 에서 제공하는 **개발 모드** 전용 기능으로, 애플리케이션의 코드에서 잠재적인 문제를 감지하고 경고를 표시하는 역할을 한다. 주로 **비효율적인 코드** 나 **미래의 React 기능과 충돌할 수 있는 코드**를 개발 단계에서 미리 감지할 수 있게 도와준다.

## 1. React.StrictMode 의 역할
`React.StrictMode` 는 앱의 특정 문제를 감지하고 경고하는 **개발 도구**로서, 애플리케이션의 코드가 더 안정적이고 미래의 React 버전에 호환되도록 돕는다. 

그러나 중요한 점은, 이 기능은 **오직 개발 모드에서만 활성화**된다. **프로덕션 빌드에서는 아무런 영향을 미치지 않으며, 사용자에게는 보이지 않는다.**

`React.StrictMode` 가 하는 주요 작업은 다음과 같다.

### 1.1. Deprecated(더 이상 권장되지 않는) API 감지
React 에서는 **더 이상 사용되지 않는 API** 가 있으면 경고를 표시한다. 

예를 들어, `componentWillMount` 와 같은 lifecycle 메서드는 미래의 React 버전에서 제거될 예정이기 때문에, `StrictMode` 가 활성화되면 콘솔에 경고를 띄워 준다.

### 1.2. 비동기화 안정성 검사
React 18에서 도입된 **동시성 모드 (Concurrent Mode)** 는 애플리케이션의 성능을 향상시키고, 렌더링 중간에 업데이트 작업을 할 수 있게 한다. 

`React.StrictMode` 는 이 동시성 모드에서 문제가 발생할 수 있는 코드를 감지하고, 애플리케이션이 이에 안전하게 대응할 수 있도록 돕는다.

### 1.3. 의도하지 않는 부작용 감지
`StrictMode` 는 의도하지 않은 부작용(side effects) 을 감지하기 위해 `useEffect` **및 다른 생명 주기 메서드를 두 번 호출한다.** 예를 들어, `useEffect` 에서 의도하지 않게 **동기적 작업**이 포함되어 있다면, 이 작업이 잘못된 동작을 초래할 수 있다. 두 번 호출함으로써 이를 발견하고 수정할 수 있게 한다.

### 1.4. Legacy 방식의 확인
React가 **미래의 업데이트**에서 더 이상 지원하지 않으려는 특정 방식이나 동작을 감지한다.

예를 들어, 클래스형 컴포넌트에서 `UNSAFE_` 로 시작하는 생명주기 메서드가 포함된 경우, `StrictMode` 이를 경고로 알려준다.

## 2. 프로덕션에서는 사용하지 않는 이유
`React.StrictMode` 는 **개발 도구** 이기 때문에, 프로덕션 환경에서는 **성능 저하**를 일으킬 수 있는 불필요한 동작을 하지 않는다. 다음 이유로 프로덕션에서는 사용하지 않는다:
    -**부작용 감지로 인한 중복 렌더링 :** `StrictMode` 는 `useEffect` 와 같은 훅을 **두 번 호출** 한다. 이는 개발 시에는 유용하지만, 프로덕션에서는 성능이 불리할 수 있다. 프로덕션에서는 한 번만 실행되어야 하므로 `StrictMode` 는 비활성화 된다.
    - **경고 메시지 :** `StrictMode` 는 경고를 콘솔에 출력하지만, 이러한 경고는 실제 사용자가 보는 화면이나 동작에는 영향을 미치지 않는다. 경고는 개발자가 코드를 개선하도록 돕는 용도로만 사용된다.

## 3. StrictMode 의 예시

```jsx
import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App";

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);
```
위 코드에서 `StrictMode` 는 `App` 컴포넌트와 그 자식 컴포넌트에서 발생할 수 있는 문제를 감지한다. 개발 도중 잘못된 코드나 비효율적인 동작을 콘솔에서 알려주기 때문에, 더 나은 품질의 코드를 작성할 수 있게 도와준다.

## 4. StrictMode 를 사용해야하는 이유
- **개발 단걔에서 더 안전한 코드 작성 :** `StrictMode` 는 개발 중에 문제를 미리 알려주기 때문에, 프로덕션에서 발생할 수 있는 오류를 사전에 방지할 수 있다.
- **미래 호환성 :** React 의 향후 버전에서 호환되지 않을 수 있는 코드를 미리 감지하여, 미래의 업데이트에 대비할 수 있다.

### 결론
`React.StrictMode` 는 **개발 중에만** 유용하게 사용되는 도구이며, 애플리케이션의 품질을 높이고 잠재적인 문제를 미리 감지할 수 있게 도와준다. 그러나 프로덕션에서는 불필요한 작업을 하지않도록 비활성화되어 성능에 영향을 미치지 않는다.