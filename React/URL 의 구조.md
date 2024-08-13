URL 의 구조
===

URL 의 각 부분은 특정 의미를 가지며, 그 중 일부가 파라미터로 사용될 수 있다. URL 은 일반적으로 다음과 같은 구조를 가진다. 

```bash
protocol://hostname:port/path?query#fragment
```

## URL 의 구성 요소

**1. 프로토콜(protocol) :** 통신규약을 나타냄

ex) http, https

```bash
https://
```

1. **호스트네임(hostname) :** 서버의 도메인 이름이나 IP 주소를 나타낸다. 

```bash
example.com
```

1. **포트(port) :** (선택 사항) 서버의 특정 포트를 지정한다. 기본적으로 http 는 80 번 포트, https 는 443번 포트를 사용한다.

```bash
:3001
```

1. **경로(path) :** 서버의 리소스를 지정한다. 보통 첫 번째 ‘/’ 이후에 나오는 부분이다. 

```bash
/users/123
```

1. **쿼리(query) :** (선택 사항) 추가적인 매개변수를 제공하며. ‘?’ 로 시작하고 `key=value` 형식으로 나타낸다. 여러 쿼리 파라미터는 & 로 구분됨

```sql
?search=keyword&sort=asc
```

1. **프래그먼트(fragment) :** (선택 사항) 리소스 내의 특정 섹션을 지정한다.  # 으로 시작한다.

```bash
#section2
```