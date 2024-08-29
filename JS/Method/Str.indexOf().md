indexof()
===
- js 에서 문자열을 다룰 때,**특정 문자나 부분 문자열의 인덱스를 찾고 싶을 때**가 있다.
- 이런 경우에 `indexOf()` 메서드가 유용하게 사용된다. - indexOf() 메서드는 문자열에서 **특정 문자나 부분 문자열의 첫 번째로 등장하는 인덱스를 반환** 한다. 
- 만약 해당 문자열이 문자열 안에 **존재하지 않는 경우에는 -1을 반환**한다.

## indexOf() 메서드의 기본 구조
indexOf() 메서드의 기본 구조는 다음과 같다.
```
let index = string.indexOf(searchValue,startIndex);
```
- `searchValue` : 찾고자 하는 문자열 또는 문자이다. 
- - `startIndex(선택 사항)` : 검색을 시작할 인덱스이다. 이 값을 지정하면 해당 인덱스부터 검색을 시작한다. 기본 값은 0이다.

## 문자열에서 특정 문자의 인덱스 찾기
아래 예시를 통해 indexOf() 메서드를 이해해 보자

```js
let str= "Hello, world!";
let index= str.indexOf("o");

document.writeIn(index);
```
위 코드에서는 `indexOf("o")` 를 사용하여 문자열에서 **'o'문자의 첫 번째로 등장하는 인덱스**를 찾았다. 결과로는 4가 출력된다.

## 부분 문자열의 인덱스 찾기
indexOf() 메서드는 부분 문자열의 첫 번째로 등장하는 인덱스도 찾을 수 있다.

```js
let str = "Hello, world!";
let index = str.indexOf("world");

document.writeIn(index);
```
위 코드에서는 `indexOf("word")` 를 사용하여 문자열에서 **world 부분 문자열의 첫 번째로 등장하는 인덱스**를 찾았다. 결과로는 7이 출력된다.

## 검색 시작 인덱스 지정하기
indexOf() 메서드를 사용할 때 검색 시작 인덱스를 지정할 수도 있다.
```js
let str = "Hello, world!";
let index = str.indexOf("o", 5);

document.writeIn(index);
```
위 코드에서는 `indexOf("o",5)` 를 사용하여 문자열에서 **인덱스 5부터 검색을 시작**하여 'o' 문자의 첫 번째로 등장하는 인덱스를 찾는다. 결과로는 8이 출력된다.

## 문자열이 존재하지 않는 경우
indexOf() 메서드는 검색 대상 문자열이 존재하지 않는 경우 **-1을 반환**한다.
```js
let str = "Hello, world!";
let index = str.indexOf("x"); // -1 반환

document.writeIn(index);
```

## 요약
JS 의 indexOf() 메서드는 문자열에서 특정 문자나 부분 문자열의 첫 번째로 등장하는 인덱스를 찾는데 사용된다. 