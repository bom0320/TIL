absolute;
---

- 요소를 일반적인 문서 흐름에서 제거하고, 상위 요소(containing block)  중 가장 가까운 position 지정 요소에 대해 상대적으로 오프셋을 적용함
    - 여기서 이 기준점이 되는 요소는 position: relative, position: absolute, position: fixed 또는 position: sticky 중 하나로 설정된 요소여야 한다.
    - 만약 상위 요소가 없다면, 기준점은 브라우저의 **뷰포트(viewport)** 가 된다. 즉, 화면 자체를 기준으로 위치가 결정됨

- position 지정 요소란?
  = position속성에 속성값이 정의되어 있는 요소!

ex)
**HTML 코드 :**
```
<div class="container">
  <div class="relative-box">
    <div class="absolute-box">나는 절대 위치 요소!</div>
  </div>
</div>

```

**CSS 코드 :**
```
.container {
  width: 500px;
  height: 500px;
  background-color: lightblue;
  padding: 20px;
}

.relative-box {
  position: relative;  /* 기준점이 되는 요소 */
  width: 300px;
  height: 300px;
  background-color: lightgreen;
}

.absolute-box {
  position: absolute;  /* 상대적 위치가 적용되는 요소 */
  top: 50px;  /* 기준점으로부터 50px 아래로 이동 */
  left: 100px;  /* 기준점으로부터 100px 오른쪽으로 이동 */
  width: 150px;
  height: 150px;
  background-color: pink;
  text-align: center;
  line-height: 150px; /* 텍스트를 수직으로 가운데 정렬 */
}

```

- 여기서 기준점을 .relative-box 로 지정해준다는 명령어는 작성할 필요가 없다고함 => 그 이유는, position:absolute 로 설정된 요소는 자동으로 가장 가까운 position 속성이 설정된 상위 요소를 기준점으로 삼기 때문