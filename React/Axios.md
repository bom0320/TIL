Axios
===
## Axios 란?

- Axios 는 프론트엔드에서 백엔드와 통신을 쉽게 하기 위한 HTTP 클라이언트 라이브러리이다.
- 간단히 말해, 웹, 브라우저나 Node.js 환경에서 HTTP 요청을 보낼 때 사용하는 도구이다. 주로 API 와의 통신을 간편하게 만들어준다.

## Axios 특징

- **Promise 기반**으로 비동기 처리를 간편하게 한다.
- **GET, POST, PUT, DELETE** 요청을 쉽게 보낼 수 있다.
- **요청과 응답 인터셉터**를 통해 데이터를 가공할 수 있다.

## 기본 사용법

Axios  를 사용하기 위해서는 먼저 라이브러리를 설치해야 한다. npm 을 사용하여 설치할 수 있다.

```bash
npm install axios
```

이후, Axios 를 import 하여 사용할 수 있다.

```jsx
import axios from 'axios';
```