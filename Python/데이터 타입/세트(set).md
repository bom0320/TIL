세트(set)
===

- ‘집합’ 을 표현함

예)

**과일을 나타내는 `fruits` 세트를 만들기**

```python
>>> fruits = {'apple', 'banana', 'orange'}
```

- 사과 ,바나나, 오렌지를 원소로 갖는 `fruits` 세트를 만듬
    - 이와 같이 세트는 중괄호(`{`, `}`)를 사용
    
- .`add()`로 망고 추가

```python
>>> fruits.add('mango')
>>> fruits
{'orange', 'apple', 'mango', 'banana'}
```

**회사 이름을 나타내는 집합**

```python
>>> companies = set()
```

회사 이름→ 일단  `set()`로 빈 세트 지정

```python
>>> companies = {'apple', 'microsoft', 'google'}
```

회사 이름 → apple 과 mircrosoft 와 google 로 지정

이제 `fruits`와 `companies` 세트를 만듬

타입 확인

```python
>>> type(fruits)
<class 'set'>
>>> type(companies)
<class 'set'>
```

세트를 이용해 아래와 같이 집합 연산 사용할 수 있음

```python
>>> fruits & companies           # 교집합
{'apple'}
>>> fruits | companies           # 합집합
{'apple', 'mango', 'microsoft', 'orange', 'google', 'banana'}
```

아래와 같이 여러 세트를 리스트에 답은 뒤 set 의 메서드를 쓸 수도 있음

```python
>>> list_of_sets = [fruits, companies]
>>> set.intersection(*list_of_sets)  # 교집합
{'apple'}
>>> set.union(*list_of_sets)  # 합집합
{'google', 'apple', 'banana', 'mango', 'microsoft', 'orange'}
```

- `apple`은 `fruits`에도 속하고 `companies`에도 속함→ 위 합집합의 결과에 한 번만 나오는 것을 볼 수 있음
- 이와 같이 세트는 중복 원소를 갖지 X
- 또, 원소의 순서가 유지되지 않는 특징도 있음

```python
>>> alphabet = list('google')
>>> alphabet
['g', 'o', 'o', 'g', 'l', 'e']
>>> set(alphabet)
{'e', 'o', 'g', 'l'}
```

집합끼리 뺄셈도 할 수 있음

```python
>>> S1 = {1, 2, 3, 4, 5, 6, 7}
>>> S2 = {3, 6, 9}
>>> S1 - S2
{1, 2, 4, 5, 7}
```

## 세트 연습 문제

### 연습 문제: 주사위 눈의 합

- 주사위 두 개가 있습니다. 한 개는 평범한 주사위인데, 다른 한 개의 각 면에는 2에서 13까지의 소수가 적혀 있습니다. 아래 코드는 두 주사위의 눈을 튜플 `dice1`과 `dice2`로 나타냅니다.

```python
dice1 = (1, 2, 3, 4, 5, 6)
dice2 = (2, 3, 5, 7, 11, 13)

```

두 주사위를 던졌을 때 눈의 합으로 나올 수 있는 숫자를 모두 출력하세요. 단, 같은 숫자는 한 번만 출력합니다.

```python
dice1 = (1, 2, 3, 4, 5, 6)
dice2 = (2, 3, 5, 7, 11, 13)

sum_of_the_two_dice = set()

for x in dice1:
    for y in dice2:
        sum_of_the_two_dice.add(x + y)

print(sum_of_the_two_dice)
```

### 연습 문제: 끝말 잇기

- 컴퓨터와 플레이어는 자기 턴(turn, 차례)이 되면 이전에 상대방이 말한 단어의 끝 글자로 시작하는 단어를 말해야 하며, 이전에 썼던 단어는 말할 수 없습니다.
1. 컴퓨터가 먼저 ‘기차’를 출력합니다.
2. 사용자의 입력을 받습니다. 사용자가 올바로 입력했으면 다음으로 진행하고, 단어를 잘못 입력하거나 ‘졌어’라고 입력하면 컴퓨터가 이기고 끝냅니다.
3. 컴퓨터는 다음의 단어 중 하나를 골라 출력합니다. 마땅한 것이 없으면 사용자가 이기고 끝냅니다.

**예)**

| 턴 | 입출력 |
| --- | --- |
| 컴퓨터 | <시작>끝말잇기를 하자. 내가 먼저 말할게.기차 |
| 플레이어 | 차박 |
| 컴퓨터 | 박쥐 |
| 플레이어 | 쥐구멍 |
| 컴퓨터 | 멍게 |
| 플레이어 | 게시판 |
| 컴퓨터 | 모르겠다. 내가 졌어.<끝> |

```python
voca = """
게맛살
구멍
글라이더
기차
대롱
더치페이
도리
롱다리
리본
멍게
박쥐
본네트
빨대
살구
양심
이빨
이자
자율
주기
쥐구멍
차량
차박
트라이앵글
""".split()

init_word = '기차'
print('끝말잇기를 하자. 내가 먼저 말할게.\n' + init_word)
spoken_words = [init_word]

while True:
    user_input = input('> ')
    
    if not user_input:
        continue
    elif user_input == "졌다":
        print('야호!')
        break
    elif user_input[0] != spoken_words[-1][-1]:
        print('글자가 안 이어져. 내가 이겼다!')
        break
    elif user_input in spoken_words:
        print('아까 했던 말이야. 내가 이겼어!')
        break
    else:
        spoken_words.append(user_input)
        my_word = None
        for word in list(set(voca) - set(spoken_words)):
            if word[0] == user_input[-1]:
                my_word = word
                break
       
        if not my_word:
            print('모르겠다. 내가 졌어.')
            break
        else:
            print(my_word)
            spoken_words.append(my_word)
            continue
    
```