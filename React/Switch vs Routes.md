Switch vs Routes
===
`Switch` 와 `Routes` 는 모두 `react-router-dom` 라이브러리에서 사용하는 라우팅 컴포넌트이며, 이들의 역할을 매우 유사하지만, 버전에 따라 조금 다르다.

둘의 관계를 이해하려면 각각의 역할과 차이점을 살펴보는 것이 중요하다.

Switch
---
**(react-router-dom v5까지 사용)**

### 역할 : 
`Switch` 는 여러 개의 Route 중에서 처음으로 매칭되는 경로에 해당하는 컴포넌트만 렌더링한다. 즉, 경로를 일치시키는 가장 첫 번째 Route 를 찾아 그 컴포넌트만 화면에 표시하고, 나머지는 무시한다.

### 사용 방식 :
```jsx
<Switch>
  <Route exact path="/" component={Home} />
  <Route path="/about" component={About} />
  <Route path="*" component={NotFound} />
</Switch>
```
-  이 코드에서, `Switch` 는 URL 이 `/about` 일 때, `/` 와도 일치하지만 첫 번째 경로 (`/about`) 에서 매칭되므로 `About` 컴포넌트만 렌더링 된다.

Routes
---
**(react-router-dom v6 이상에서 사용)**

### 역할 :
`Routes` 는 `Switch` 의 대체 기능으로 등장한 컴포넌트이다. 마찬가지로 여러 `Route` 중 처음으로 매칭되는 경로에 해당하는 컴포넌트만 렌더링한다.

그러나 `Routes` 는 몇 가지 새로운 특징을 도입하여 더 간결하고 직관적인 방식으로 라우팅을 설정할 수 있다.

### 사용 방식 :
```jsx
<Routes>
  <Route path="/" element={<Home />} />
  <Route path="/about" element={<About />} />
  <Route path="*" element={<NotFound />} />
</Routes>
```
- `Routes` 에서는 `Route` 컴포넌트에서 **`component` 대신 `element` 속성을 사용하여 렌더링할 컴포넌트를 지정**한다. JSX 형태로 직접 컴포넌트를 전달할 수 있어 더 유연하다.

주요 차이점
---

### 버전 차이 :
- `Switch` 는 `react-router-dom` v5 에서 사용되었으며, v6 에서는 `Routes` 로 대체되었다.

### 구문 차이 :
- `Switch` 에서는 `Route` 에 `component` 속성을 사용하거나 JSX 로 렌더링을 설정한다.
- `Routes` 에서는 `Route` 에 `element` 속성을 사용하여 JSX 를 직접 전달하는 방식으로 설정한다.

### 동작 방식의 차이:
- `Routes` 는 `Switch` 에 비해 더 간결한 방식으로 라우팅을 처리하고, 중첩된 라우팅 등 새로운 기능을 더 효율적으로 처리할 수 있게 설계되었다.

## 결론
- `Switch` 는 `react-router-dom` v5 까지 사용되었고, `Routes` 는 v6 에서 새롭게 도입되어 `Switch` 를 대체하는 역할을 한다.
- 두 컴포넌트는 기본적으로 같은 역할을 하지만, `Routes` 는 더 현대적이고 간결한 문법을 사용하며, `Routes` 컴포넌트의 사용 방식도 더 직관적이다. 

