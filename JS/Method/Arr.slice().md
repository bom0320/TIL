slice()
===

```
arr.slice([begin[, end]])
```

- slice 메서드는 어떤 배열의 `begin` 부터 `end`까지(`end` 미포함) 에 대한 얕은 복사본을 새로운 배열 객체로 반환한다. 원본 배열은 바뀌지 않는다.

```
const animals = ['ant', 'bison', 'camel', 'duck' , 'elephant'];

console.log(animals.slice(2));
// Expected output: Array ["camel", "duck", "elephant"]

console.log(animals.slice(2,4));
// Expected output: Array ["camel", "duck"]

console.log(animals.slice(1,5));
// Expected output: Array ["bison", "camel", "duck", "elephant"];

console.log(animals.slice(-2))
// Expected output: Array ["duck", "elephant"]

console.log(animals.slice(2,-1));
// Expected output: Array ["camel", "duck"]

console.log(animals.slice());
// Expected output: Array ["ant", "bison", "camel", "duck", "elephant"]

```

> 왜 slice(-2)와 slice(2,-1) 에 들어가는 음수 인덱스의 동작이 다를까?

### 음수 인덱스의 다른 동작 이유
두 경우에서 음수 인덱스가 다른 이유는 컨텍스트(매개변수 위치) 에 따라 다르기 때문이다.
- **`slice(-1)` 에서 :** -1 은 배열의 마지막 요소를 **시작점** 으로 취급한다.
- **`slice(2,-1)` 에서 :** -1 읍 배열의 마지막 요소를 **끝점** 으로 취급하며, 끝점은 포함되지 않으므로 마지막 요소 바로 전까지의 요소만 미포함

요약하자면, `slice()` 메서드에서 **음수 인덱스는 항상 배열의 끝에서부터 요소를 세지만, start와 end의 역할에 따라** 포함되는 요소가 달라진다. `start` 로 사용될 때는 해당 인덱스에서부터 시작하고, `end` 로 사용될때는 해당 인덱스 **전까지** 의 요소들만 포함하게 되는 것이다. 

