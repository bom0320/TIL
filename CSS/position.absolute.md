absolute;
---

- 요소를 일반적인 문서 흐름에서 제거하고, 상위 요소(containing block)  중 가장 가까운 position 지정 요소에 대해 상대적으로 오프셋을 적용함
    - 여기서 이 기준점이 되는 요소는 position: relative, position: absolute, position: fixed 또는 position: sticky 중 하나로 설정된 요소여야 한다.
    - 만약 상위 요소가 없다면, 기준점은 브라우저의 **뷰포트(viewport)** 가 된다. 즉, 화면 자체를 기준으로 위치가 결정됨