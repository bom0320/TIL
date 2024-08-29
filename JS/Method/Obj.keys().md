keys()
===
- 객체를 만들다 보면 상황에 따라서는 객체의 key 값만 가지고 오고 싶을 때도 있다.
- `Object.keys()` 메서드는 객체(typeof 연산자로 확인했을 때 object가 반환되는)의 프로퍼티들 중에서 key 값, 다른 말로 프로퍼티 네임들만 묶어서 배열로 반환하는 메서드이다.

### 문법
```
Object.keys(obj);
```
Object.keys 메서드의 기본 문법은 그냥 메서드 그대로 Object 객체에 keys 메서드를 호출하고 파라미터로 Key 값을 알아내고자 하는 객체를 전달해주면 된다.

```js
const myObject = {
    name: '봄',
    enName: 'SSAK3',
    members: ['드래곤', '린다G', '비룡'],
    genre: 'Dance & pop',
    agency: 'MBC',
    making: '놀면뭐하니?'
}

const myKeys = Object.keys(myObject);

console.log(myKeys);
// (6) ["name", "enName", "members", "genre", "agency", "making"]
```

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FNjnlS%2FbtqF15tBS4I%2FbCmxZ3zi7XA4tGNaul9b50%2Fimg.png)
주의 해야할점은 object.keys() 메서드는 객체가 가지고 있는 메서드를 사용하는 것이 아니라, Object 라는 내장 객체의 메서드로 사용하고, 파라미터로 우리가 만든 객체를 집어넣어줘야 하기 때문에 myObject.keys() 처럼 사용하지 않도록 주의해야한다. -> 니 맘대로 메서드 손질하지 말라는 거 (pop()을 pap() 으로 쓰지 않듯이)

```js
const myObject = {
    name: '봄',
    enName: 'SSAK3',
    members: ['드래곤', '린다G', '비룡'],
    genre: 'Dance & pop',
    agency: 'MBC',
    making: '놀면뭐하니?'
}

const myKeys = myObject.keys();

console.log(myKeys);
```
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fq2xuO%2FbtqF3b1aj0q%2Fue68w6Gt51RNLZuKDtIgXK%2Fimg.png)
일반적으로 생성한 객체에는 key 라는 메서드는 존재하지 않는다. 

## 배열에도
```js
const myArray = ['스타', '유산슬', '유라', '유리', 'DJ', '유샘', '닭터유', '드래곤'];

const myKeys = Object.keys(myArray);

console.log(myKeys);
// (8) ["0", "1", "2", "3", "4", "5", "6", "7"]
```
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbNxTzJ%2FbtqF0ZnMVUV%2FRAEIHEYKkMLkv8CC5ADO8K%2Fimg.png)
배열도 객체이기 때문에 배열도 얼마든지 활용할 수 있다.

배열에 사용할 경우에는 대상이 되는 배열의 각 인덱스가 담긴 배열이 리턴된다.
