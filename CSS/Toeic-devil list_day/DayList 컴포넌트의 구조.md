DaList 컴포넌트의 구조
===
```
<ul className="list_day">
  {days.map((day) => (
    <li key={day.id}>
      <Link to={`/day/${day.day}`}>Day {day.day}</Link>
    </li>
  ))}
</ul>
```
`<ul classNAme="list_day">` : 이 부분은 HTML 의 리스트 요소인 ul 을 나타내며, list_day 라는 CSS 클래스를 적용하고 있다.

`days.map((day)=>...` : 이 부분은 days 라는 배열의 각 요소를 반복하면서, li 태그와 그 안의 링크(link) 를 생성한다. 예를 들어 days 배열에 7개의 날이 있다면, 7개의 li 항목이 생성된다.

`<Link to={`/day/${day.day}`}>Day {day.day}</Link>` : 이 부분은 각 리스트 항목에 대해 Day 1, Day 2 등의 텍스트를 가진 링크를 생성하게 된다. 이 링크를 클릭하면, 사용자는 /day/1 , /day/2 와 같은 페이지로 이동하게 된다.
