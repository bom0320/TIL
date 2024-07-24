딕셔너리(dict)
===

**딕셔너리 자료형 만들고, 원소 추가하는 방법**

```python
>>> dic = {}               # dic이라는 이름으로 비어있는 딕셔너리를 만든다.
>>> dic['dictionary'] = '1. A reference book containing an ...'
>>> dic['python'] = 'Any of various nonvenomous snakes of the ...'
>>> dic['dictionary']      # dic아, 'dictionary'가 뭐니?
'1. A reference book containing an ...'
```

- 처음에  dic 라는 사전을 하나 만듬
- 둘째, 셋째 줄에서는 dic 에다가 자료를 좀 집어넣음
- 그리고 마지막 줄에서는 dictionary의 뜻이 뭔지 조회

이와 같이 딕셔너리 자료형은 키(key)와 값(value)의 쌍으로 이루어짐

| 키 | 값 |
| --- | --- |
| dictionary | 주절주절... |
| python | 궁시렁궁시렁... |
| zoo | 동물원 |
- 문자열, 리스트, 튜플→ 숫자로 된 인덱스를 이용헤 값을 조회
- 딕셔너리 → 키를 이용한다는것이 큰 차이점
- 딕셔너리 자료형은 해싱(hashing) 기법을 이용하기 때문에 자료가 순서대로 저장 되지 X

## 해싱(hashing) 기법이란?

- 한마디로 말해서 많은 양의 데이터들을 그보다 작은 크기의 테이블(table)로 대응(mapping)시켜 저장할 수 있도록 하는 일종의 데이터 관리 기법이다.

**딕셔너리 원소 삭제시**

```python
>>> del smalldic['dictionary']
```

예)

 **`family`라는 딕셔너리 만들기**

```python
>>> family = {'mom': 'Kim', 'dad': 'Choi', 'baby': 'Choi'}
>>> family
{'mom': 'Kim', 'dad': 'Choi', 'baby': 'Choi'}
```

`family`의 키들을 얻으려면 딕셔너리 이름 뒤에 `.keys()`를 쓰면 됨

```css
>>> family.keys()
dict_keys(['mom', 'dad', 'baby'])
```

`family`의 값들을 얻으려면 딕셔너리 이름 뒤에 `.values()`를 쓰면 됨

```css
>>> family.values()
dict_values(['Kim', 'Choi', 'Choi'])
```

`family`의 원소(키/값 쌍)들을 얻으려면 이름 뒤에 `.items()`를 쓰면 됨

```css
>>> family.items()
dict_items([('mom', 'Kim'), ('dad', 'Choi'), ('baby', 'Choi')])

```

딕셔너리에 어떤 키가 있는지 없는지는 `in`을 써서 알아볼 수 있음

있으면 True, 없으면 False라고 대답

```python
>>> 'dad'in family
True
>>> 'sister'in family
False
```

## 딕셔너리 연습 문제

### 연습 문제: 숫자 읽기(0~9)

- 매개변수로 입력받은 정수에 해당하는 한글 문자열을 반환하는 함수 `korean_number()`를 **if 문을 사용하지 말고** 작성하세요.
- 단, 사용자는 0 이상 9 이하의 정수 중 하나를 입력한다고 가정합니다.

**예)**

```python
>>> korean_number(3)
'삼'
>>> korean_number(6)
'육'
>>> korean_number(9)
'구'
```

```python
def korean_number(num):
    d = {0: '영', 1: '일', 2: '이', 3: '삼', 4: '사', 5: '오', 6: '육', 7: '칠', 8: '팔', 9: '구'}
    return d[num]
```

### 연습 문제: 한자 성어

- 한자 성어와 뜻을 모두 출력하는 파이썬 프로그램 작성

```python
```python
idiom = {
    '江湖之樂(강호지락)': '자연을 벗 삼아 누리는 즐거움',
    '欲速不達(욕속부달)': '빨리 하고자 하면 이루지 못함',
    '積小成大(적소성대)': '작은 것을 쌓아 큰 것을 이룸',
    '勤儉節約(근검절약)': '부지런하고 알뜰하게 재물을 아낌',
    '經世濟民(경세제민)': '세상을 다스리고 백성을 구제함',
    '塞翁之馬(새옹지마)': '인생의 길흉화복은 변화가 많아서 예측하기가 어려움',
    '好事多魔(호사다마)': '좋은 일에는 흔히 방해되는 일이 많음',
    '桑田碧海(상전벽해)': '세상일의 변천이 심함',
    '自業自得(자업자득)': '자기가 저지른 일의 결과를 자기가 받음',
    '因果應報(인과응보)': '원인과 결과가 상응하여 보답한다',
    '愚公移山(우공이산)': '어떤 일이든 끊임없이 노력하면 반드시 이루어짐',
}

for k, v in idiom.items():
    input('Enter를 누르세요...')
    print(f'{k}\n{v}\n')
```
```