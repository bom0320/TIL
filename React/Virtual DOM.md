Virtual DOM
===


> Virtual DOM 이란?

가상 DOM(Document Object Model)은 실제 DOM 을 **추상화한 DOM** 을 말한다. 

![](https://miro.medium.com/v2/resize:fit:1100/format:webp/1*NAVnGO5p8bzfIzTIv3ijRA.jpeg)

리액트에서는 컴포넌트가 **처음 렌더링** 될 때,

가상 DOM 트리를 생성하고, 

이후 상태나 속성이 변경되면 비교(Diffing) 와 조정 (Reconciliation) 절차를 통해 변경된 부분만 

실제 DOM 에 반영(patch) 한다. 

리액트를 이렇게 가상 DOM 을 이용하여 불필요한 **DOM 조작을 최소화**한다.