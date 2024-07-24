튜플(Tuple)
===
- 리스트와 비슷한 자료

**두 변수의 값을 서로 바꿀시 보통 다음과 같은 방법 사용**

```python
>>> a = 10
>>> b = 20
>>> temp = a               # a 값을 temp에 저장   (temp = 10)
>>> a = b                  # b 값을 a에 저장      (a = 20)
>>> b = temp               # temp 값을 b에 저장   (b = 10)
>>> print(a, b)
20 10
```

이렇게 두 변수 값을 맞바꾸기 위해서는 또 다른 변수 temp 가 필요하다. → 파이썬에서는 이런일을 간단하게 할 수 있는 방법 존재

```python
>>> c = 10
>>> d = 20
>>> c, d = d, c
>>> print(c, d)
20 10
```

- 세 번째 줄
    - 등호 왼쪽은 `c`, `d`라는 변수가 담긴 튜플
    - 오른쪽은`d`와 `c`의 값이 담긴 튜플
- 그래서 `d`의 값은 `c`로 들어가고, `c`의 값은 `d`로 들어감
- 이런 일들이 차례차례 일어나는 것 X → 동시에 처리

**아래 함수는 인자(매개변수)를 주는 대로 받아먹는 함수**

```python
>>> def magu_print(x, y, *rest):        # 마구 찍어 함수
...     print(x, y, rest)
...
>>> magu_print(1, 2, 3, 5, 6, 7, 9, 10)
1 2 (3, 5, 6, 7, 9, 10)
```

- 위 함수는 인자를 두개 이상만 주면 나머진 알아서 처리
- 함수를 정의할 때 인사에 별표를 붙여두면 그 이후에 들어오는 것은 모두 튜플에 집어 넣는 것
- 위에선 `(3, 5, 6, 7, 9, 10)`가 하나의 튜플로 묶임

## 튜플의 문법

```python
>>> t = ('a', 'b', 'c')
```

- 튜플을 만들 때는 위와 같이 괄호를 써도 되고 안 써도 된다
- 다만, 원소가 없는 튜플을 만들 때는 괄호 꼭 써주기!!!

```python
>>> empty = ()
```

원소를 하나만 가진 튜플을 만들 땐 원소 뒤에 콤마( , )를 꼭 찍기!!

```python
>>> one = 5,
>>> one
(5,)
```

튜플은 리스트와 달리 원소값을 직접 바꿀 수 없기 때문에, 문자열에서 했던 것처럼 오려붙이는 방법을 써야한다는 것 알아두기!!

```python
>>> p = (1,2,3)
>>> q = p[:1] + (5,) + p[2:]
>>> q
(1, 5, 3)
>>> r = p[:1], 5, p[2:]
>>> r
((1,), 5, (3,))
```

## 튜플 연습 문제

### 연습 문제: 두수의 사칙 연산 프로그램 만들기

- 두 수를 입력받아서 덧셈, 뺄셈, 곱셈, 나눗셈 결과를 반환하는 프로그램을 작성하세요.
- 단, 입력은 정수로 가정하며, 0으로 나누는 경우 등에 관한 오류를 고려할 필요는 없습니다.

```python
sa, sb = input().split()
na, nb = int(sa), int(sb)

addition = na + nb
subtraction = na - nb
multiplication = na * nb
division = na / nb

print(addition, subtraction, multiplication, division)
```

### 연습 문제: 내일의 날짜 구하기

- 사용자로부터 날짜를 나타내는 세 개의 숫자를 입력받습니다.
    - 첫 번째 숫자는 연도를 나타내는 네 자리 숫자
    - 두 번째 숫자는 월을,
    - 세 번째 숫자는 일을 나타냄
- 입력받은 날짜를 `mm/dd/yyyy` 형식으로 출력합니다.
- 월을 두 자리 숫자(`01`, `02`, `03`, ..., `12`)로,
- 일을 두 자리 숫자(`01`, `02`, `03`, ..., `31`)로, 연도를 네 자리 숫자로 나타냅니다.

입력받은 날짜의 다음 날에 해당하는 날짜도 같은 형식으로 출력합니다. 

단, 윤년은 무시합니다(2월은 항상 28일까지 있다고 가정합니다).

**예)**

입력:

```yaml
2018 12 31

```

출력:

```
12/31/2018
01/01/2019
```

```python
def read_date():
    year, month, day = tuple(map(int, input().split()))
    return year, month, day

def print_date(date):
    year, month, day = date
    print("%02d/%02d/%04d" % (month, day, year))

def advance_day(date):
    year, month, day = date
    
    # end_of_month = (month == 1 and day == 31) or \
               # (month == 2 and day == 28) or \
               # (month == 3 and day == 31) or \
               # (month == 4 and day == 30) or \
               # (month == 5 and day == 31) or \
               # (month == 6 and day == 30) or \
               # (month == 7 and day == 31) or \
               # (month == 8 and day == 31) or \
               # (month == 9 and day == 30) or \
               # (month == 10 and day == 31) or \
               # (month == 11 and day == 30) or \
               # (month == 12 and day == 31)
    
    #end_of_month = (month in [1, 3, 5, 7, 8, 10, 12] and day == 31) or \
    #                     (month in [4, 6, 9, 11] and day == 30) or \
    #                     (month == 2 and day == 28)
    
    end_of_month = (month, day) in [(1, 31), (2, 28), (3, 31), (4, 30), (5,
        31), (6, 30), (7, 31), (8, 31), (9, 30), (10, 31), (11, 30), (12, 31)]
    
    end_of_year = month == 12 and day == 31
    
    if end_of_month:
        if end_of_year:
            year += 1
            month = 1
            day = 1
        else:
            month += 1
            day = 1
    else:
        day += 1
    
    return year, month, day
    
if __name__ == "__main__":
    today = read_date()
    print_date(today)
    tomorrow = advance_day(today)
    print_date(tomorrow)
```