trim()
===
-`trim()`함수는  **문자열 좌우에서 공백을 제거**하는 함수이다.
- 대부분의 언어에서 기본 제공하고 있고, 좌/우 측만 trim 하는 함수를 제공하기도 한다.

- js 에서는 IE8 이하에서는 trim() 을 제공되지 않음 => 이걸 해결하기 위해 jQuery 를 사용해 jQuery 의 $.trim(); 메소드를 사용하여 처리하는 방법이 있다.

### 예제
```js
var str = " test ";
var trimStr = str.trim();
```
jQuery 를 사용할때 코드이다.
```js
var str = " test ";
var trimStr = $.trim(str);
```
