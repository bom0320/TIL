React에서 ES6 모듈을 사용하는 방식
===

## 1. 컴포넌트 분리:
React 에서 웹페이지는 여러 컴포넌트로 이루어진다. 

ES6 모듈 시스템을 사용하면 각 컴포넌트를 **개별 파일로 분리**하고, 이를 필요할 때 불러와 사용할 수 있다. 즉, 코드의 **모듈화** 를 통해 각 컴포넌트가 독립적으로 관리되고, 유지보수가 쉬워진다.

- 예를 들어, **Header, Footer, MainContent** 같은 컴포넌트를 각각 다른 파일로 분리한 후, 메일 파일에서 이를 가져와 웹페이지를 구성할 수 있다.

```js
// Header.js
export default function Header() {
  return <header>This is the Header</header>;
}

// Footer.js
export default function Footer() {
  return <footer>This is the Footer</footer>;
}

// App.js
import Header from './Header';
import Footer from './Footer';

function App() {
  return (
    <div>
      <Header />
      {/* 다른 컴포넌트들 */}
      <Footer />
    </div>
  );
}

export default App;
```

## 2. 코드 재사용성 증가:
모듈화된 컴포넌트는 **필요한 곳에서 재사용** 할 수 있다. 한 번 작성한 컴포넌트를 여러 페이지나 여러 곳에서 재활용할 수 있기 때문에, 같은 코드를 반복 작성할 필요가 없다.

## 3. 구조화된 프로젝트 관리:
ES6 모듈을 사용하면 프로젝트 **구조** 가 더 명확해진다. 각 파일이 어떤 역할을 하는지 쉽게 알 수 있기 때문에, 프로젝트가 커지더라도 유지보수가 쉬워진다. 

React 에서는 흔히 컴포넌트를 **폴더별로 분리**하여 관리한다.
- 예: `components/Header.js`,`components/Footer.js`, `pages/HomePage/js` 등

## 4. 컴포넌트 간의 의존성 관리:
`import` 와 `export` 를 사용해 컴포넌트 간의 **의존성**을 관리할 수 있다. 각각의 컴포넌트가 다른 컴포넌트에 의존한다면, `import` 문법을 사용해 필요한 부분만 가져와 사용한다.

# React 에서 ES6 모듈이 중요한 이유
- **웹페이지 컴포넌트를 어떻게 분배할지** 를 고민하면서, 각 컴포넌트를 독립적으로 만들고, 이를 쉽게 연결할 수 있게 해준다.
- 작은 단위를 코드로 쪼개서 웹 애플리케이션을 구축하기 때문에, 코드 관리와 재사용성이 훨씬 좋아진다.

## 결론적으로:
React 에서 ES6 모듈을 공부한다는 것은 웹페이지를 구성하는 **여러 컴포넌트를 파일별로 분리하고** 필요할 때 `import` 를 통해 조립하는 과정을 배우는 것과 같다. 이는 큰 규모의 애플리케이션을 만들 때 필수적인 기술이며, 효율적인 코드 관리를 가능하게 한다.