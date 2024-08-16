피그마 프론트 협업
===

Figmas 에서 텍스트를 선택하고 우축에 표시된 정보는 웹페이지를 구현할 때 매우 중요한 역할을 한다. 이 정보들을 React 컴포넌트의 스타일링에 반영하면, 디자인과 일치하는 결과를 얻을 수 있다. 이제 이미지에서 보이는 각 정보를 어떻게 반영할 수 있는지 설명하겠다.

## 1. 위치 및 크기 (X, Y, W, H)

- **X(24PX) :** 텍스트 요소의 왼쪽이 페이지 왼쪽으로부터 24px 떨어져 있다는 것을 의미한다.
- **Y(350px) :** 텍스트 요소의 상단이 페이지 상단으로부터 350px 떨어져 있다는 것을 의미한다.
- **W(92px) :** 텍스트 요소의 너비가 92px 이다.
- **H(26px) :** 텍스트 요소의 높이가 26px 이다.

이 정보를 바탕으로 CSS 에서 position, margin 또는 padding 을 설정할 수 있따. 만약 요소가 absolute 로 위치할 필요가 있다면 top, left, width, height 등을 설정할 수 있다.

```jsx
position: absolute;
left: 24px;
top: 350px;
width: 92px;
height: 26px;
```

## 2. Text(글꼴 스타일)

```jsx
font-family: 'Inter', sans-serif;
font-weight: 600; /* Semi Bold */
font-size: 20px;
line-height: 130%; /* 이 경우 20px * 1.3 = 26px */
letter-spacing: 0;
text-align: center;
```

- **Font**: Inter 폰트가 사용됨
- **Weight :** Semi Bold (600 정도의 굵기)
- **Font size :** 글자 크기는 20px 이다.
- **Line Height :**  줄 간격(Line height) 이 130% 로 설정되어 있다.
- **Letter Spacing :** 글자 사이의 간격이 0% 이다.
- **Text Alignment**: 텍스트 정렬이 수평으로 가운데 정렬

## 3. Fill(텍스트 색상)

- 색상: 텍스트 색상이 #426B1F 으로 설정되어 있음

css 에서 색상을 다음과 같이 설정한다.

```jsx
color: #426B1F;
```

## 4. Constraints (제약 조건)

- Left, Bottom: 이 설정은 디자인에서 요소의 위치가 부모 요소에 대해 왼쪽과 하단에 고정되어 있음을 의미한다. 이는 반응형 디자인에서 유용할 수 있으며, css 에서는 position 과 관련된 스타일로 처리된다.

```jsx
position: absolute;
left: 24px;
bottom: 0;
```

## 5. Layer 설정

- Opacity: 100% 로 설정되어 있어, 불투명하게 표시된다는 것을 의미한다.
- 이를 css 에서 opacity: 1 로 설정할 수있다.

## 6. 예제 구현

이제 이 정보를 바탕으로 React 에서 해당 텍스트 요소를 구현하는 예제를 보여주겠다.

```jsx
import React from 'react';

function TextComponent() {
  return (
    <div style={styles.container}>
      <p style={styles.text}>Your Text Here</p>
    </div>
  );
}

const styles = {
  container: {
    position: 'absolute',
    left: '24px',
    top: '350px',
    width: '92px',
    height: '26px',
  },
  text: {
    fontFamily: 'Inter, sans-serif',
    fontWeight: 600, // Semi Bold
    fontSize: '20px',
    lineHeight: '130%',
    letterSpacing: '0',
    textAlign: 'center',
    color: '#426B1F',
    opacity: 1,
  },
};

export default TextComponent;

```