s 태그와 del 태그의 차이
===

## `<s>` 태그
- s 태그는 의미론적으로 문서에서 더이상 유효하지 않거나 무효가 된 텍스트를 표시할 때 사용된다.
- 예를 들어, 할인된 가격 표시에서 이전 가격에 가로줄을 긋고 싶을 떼 s 태그를 사용한다.
- 단순히 시각적으로 "취소선" 의 의미로 사용되며, 내용의 삭제를 의미하진 않음

**할인된 가격에 대한 예시 (`<s>`):**

```html
<p>원래 가격: <s>₩30,000</s> 현재 가격: ₩25,000</p>
```

## `<del>` 태그
- del 태그는 의미론적으로 문서에서 삭제된 내용을 나타낸다.
- 이 태그는 `<ins>` 태그와 자주 함께, 사용되며, 수정 기록을 표현하는 데 유용하다.
- 브라우저나 보조 기술은 `<del>` 을 문서에서 실제로 제거된 것으로 인식할 수 있어, `<s>` 와 달리 의미론적인 삭제로 해석된다.

**삭제된 내용에 대한 예시 (`<del>`):**
```html
<p>이 문장에서 <del>삭제된 내용</del>과 <ins>추가된 내용</ins>을 확인할 수 있습니다.</p>
```

따라서 `<s>` 는 단순히 시각적 변경에 가깝고, `<del>` 은 의미적이로 내용이 삭제된 것을 나타내는 차이가 있다.