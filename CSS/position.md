position
===
- 문서 상에 요소를 배치하는 방법을 정의
- position이 요소의 배치 방법을 결정하면, top/bottom/right/left 가 최종 위치를 결정하는 방식

    - position: 난 이렇게 배치할거야
    - top: 윗면에서부터 얼만큼 떨드뜨릴거야
    - right: 오른쪽면에서부터 얼만큼 떨어뜨릴거야
    - left: 왼쪽면에서부터 얼만큼 떨어뜨릴거야
    - bottom: 아랫변에서부터 얼만큼 떨어뜨릴거야
    - =상화좌우 위치 지정은 필요에 따라 선택적으로 사용!
    
    - static: 기본값, 요소의 일반적인 문서 흐름에 따라 배치
    - relative: 일반적인 문서 흐름에 따라 배치하되, 상하좌우 위치 값에 따라 오프셋을 적용
    - absolute: 일반적인 문서 흐름에서 제거하고, 가장 가까운 position 지정 요소에 대해 상대적으로 오프셋 적용!
    - fixed: 일반적으로 문서 흐름에서 제거하고, 지정한 위치에 고정
    - sticky: 일반적인 문자 흐름에서 제거하고, 스크롤 동작이 존재하는 가장 가까운 요소에 대해 오프셋 적용!
