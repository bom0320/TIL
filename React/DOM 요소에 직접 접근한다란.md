DOM 요소에 직접 접근한다란?
===
DOM 은 웹 페이지에서 우리가 보는 HTML 요소들(버튼, 입력창, 텍스트 등) 이다. DOM 에 접근한다는 건, HTML 요소를 JS 로 직접 조작하거나, 그 값을 읽어오는 것을 의미한다.

예를 들어, 화면에 나타난 입력창에 **커서를 자동으로 넣고 싶다거나, 스크롤을 특정 위치로 자동으로 이동**시키고 싶을 때, 이런 건 **DOM 에 직접 접근**해서 조작해야 한다. => React 상태는 이런 **특정한 작업**을 바로 도와주지 않기 때문에, **Ref** 로 직접적으로 그 HTML 요소에 접근해야 한다.

## 왜 상태(state) 로는 해결할 수 없는 걸까?
React 의 상태(state) 는 **데이터나 UI 의 모습**을 관리한다. React 가 상태를 통해 "무엇을 보여줄지" 를 결정하지만, **어떻게 그려지는지**(예: 커서를 어디에 넣을지, 스크롤 위치를 어디로 할지 등)는 직접적으로 관리하지 않는다.

DOM 을 직접 만지는 건 **React의 상태로는 할 수 없는 일이기** 때문이다.

**여기서 제일 중요한건 React는 상태로 "무엇을 보여줄지"는 관리하지만, "어떻게 그려지는지"는 관리하지 않는다는게 핵심인듯 싶다.**