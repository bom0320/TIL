React-Query 개념잡기
===


## React-Query 란?

> fetching, caching, 서버데이터와의 동기화를 지원해주는 라이브러리
> 
- 간단히 말해 React 환경에서의 비동기 Query(질의) 과정을 도와주는 라이브러리이다.

### React-Query 의 이점

1. React Query 는 React Application 에서 서버상태를 불러오고, 캐싱하며, 지속적으로 동기화하고 업데이트를하는 작업을 도와주는 라이브러리이다.
2. 복잡하고 장황한 코드가 필요한 다른 데이터를 불러오기 방식과 달리 React Component 내부에서 간단하고 직관적으로 API 를 사용할 수 있다.
3. 더 나아가 React Query 에서 제공하는 캐싱, Window Focus Refetching 등 다양한 기능을 활용하여 API 요청과 관련된 번잡한 작업 없이 “핵심 로직” 에 집중할 수 있다.

 즉, React-Query 는 프론트엔드에서 비동기 데이터를 불러오는 과정 중 발생하는 문제들을 해결해준다는 건데, 어떤 문제들을 어떻게 해결한다는 걸까?

---

## 1. 캐싱( Caching)

React-Query 의 장점 중 하나는 **데이터를 캐싱**한다는 점이다.

> 캐싱이랑 특정 데이터의 복사본을 저장하여, 이후 동일한 데이터의 재접근 속도를 높이는 것을 말한다!
> 

React-Query 는 캐싱을 통해 동일한 데이터에 대한 **반복적인 비동기 데이터 호출을 방지**하고, 이는 불필요한 API 콜을 줄여 **서버에 대한 부하를 줄이는 좋은 결과**를 가져온다.

> 최신의 데이터인지 어떻게 판별하는데?
> 
- 여기서 궁금한 것은 데이터가 최신의 것인지 아닌지에 대한 것이다.
    
    만일 서버의 데이터를 불러와 캐싱한 후, 실제 데이터를 확인했을 때 서버 상에서 데이터의 상태가 변경되어있다면, 사용자는 실제 데이터가 아닌 변경 전의 데이터를 바라볼 수 밖에 없게 된다. 이는 사용자에게 잘못된 정보를 보여주는 에러를 낳는다. 
    

> 참고로, React-Query 에서는 **최신의 데이터를 fresh 한 데이터**, **기존의 데이터를 stale 한 데이터**라고 한다.
> 

### 언제 데이터를 갱신해야하지?

위와 같은 에러를 발생시키지 않는 좋은 캐싱 기능을 제공한다는 것은 결국 **필요한 상황에 적절하게 데이터를 갱신**해줄 수 있다는 말과 같다. 그럼 그런 상황은 언제일까?

```
1. 화면을 보고 있을 때
2. 페이지의 전환이 일어났을 때
3. 페이지 전환 없이 이벤트가 발생해 데이터를 요청할 때
```

크게 보면 위의 3가지로 나눌 수 있다. 이를 위해 React-Query  에서는 기본적인 아래의 옵션들을 제공한다.

```
refetchOnWindowFocus, // default : true
refetchOnMount, // default: true
refetchOnReconnect, // defulat: true
staleTime, // default: 0
cacheTime, // defualt: 5분 (60 * 5 * 1000)
```

위의 옵션들을 통해 우리는 React-Query 가 어떤 시점에 데이터를 Refetching 하는지 알 수 있다.

```
1. 브라우저에 포커스가 들어온 경우(refetchOnWindowFocus)
2. 새로운 컴포넌트 마운트가 발생한 경우(refetchOnMount)
3. 네트워크 재연결이 발생한 경우(refetchOnFeconnect)
```

### staleTime ? cacheTime ?

### staleTime

- staleTime 은 **데이터가 fresh → stale 상태로 변경**되는 데 걸리는 시간
- fresh 상태일 때는 Refetch 트리거(위의 3가지 경우) 가 발생해도 Refetch 가 일어나지 않는다.
- 기본값이 0 이므로 따로 설정해주지 않는다면, Refetch 트리거가 발생했을 때 무조건 Refetch 가 발생한다.

### cacheTime

- cacheTime 은 데이터가 inactive 한 상태(데이터가 현재 사용되지 않거나, 접근되지 않는 상태)일 때 캐싱된 상태로 남아있는 시간이다.
- 특정 컴포넌트가 unmount(페이지 전환 등으로 화면에서 사라질 때) 되면 사용된 데이터는 inactive 상태로 바뀌고, 이때 데이터는 cacheTime 만큼 유지된다.
- cacheTime 이후 데이터를 가비지 콜렉토로 수집되어 메모리에서 해제된다.
- 만일 cacheTime 이 지나지 않았는데 해당 데이터를 사용하는 컴포넌트가 다시 mount 되면, 새로운 데이터를 fetch 해오는 동안 캐싱된 데이터를 보여준다.
- 즉, 캐시된 데이터를 계속 보여주는게 아니라 fetch 하는 동안 임시로 보여준다는 것이다.

## 2. Client 데이터와 Server 데이터 간의 분리

프로젝트의 규모가 커지고 관리해야할 데이터가 넘치다 보면, Client 에서 관리하는 데이터와 Server 에서 관리하는 데이터가 분리될 필요성을 느낀다. 

> **Client Data:** 모달 관련 데이터, 페이지 관련 데이터 등등..
**Server Data:** 사용자 정보, 비즈니스 로직 관련 정보 등등..

간단하게 생각해서 **비동기 API 호출을 통해 불러오는 데이터**들을 Server 데이터라고 할 수 있다.
> 

실제 Client 데이터 경우, Redux, Recoil, mobX 와 같은 **전역 상태 관리 라이브러리**들을 통해 잘 관리되어오고 있으나, 문제는 이러한 라이브러리들이 Server 데이터까지도 관리를 해야하는 상황이 발생한다는 것이다. 

위의 상태 관리 라이브러리에서도 비동기 함수를 처리하는 로직이 존재하거나, 서드 파티를 라이브러리를 지원하는 것이 많다. 그러나 이들이 Client 데이터와 Server 데이터를 완벽히 분리하여 관리에 용이하도록 충분히 기능이 지원된다고 보기 어렵다.  즉, 위의 라이브러리들은 Client 데이터를 관리하는 데 로직이 집중되어있기 때문에, Server 데이터까지 효율적으로 관리하는 데는 한계가 분명하다.

React-Query 는 이러한 문제에 대한 해결책 또한 제시해 줌 

```jsx
// 해당 내용은 v4의 문법을 기반으로 한 내용입니다. 
// 단순히 개념적인 예시를 설명하기 위함입니다. 
// v5 예시는 아래에서 확인하실 수 있습니다.
const { data, isLoading } = useQueries({
	['unique-key'],
	() => {
		return api({
			url: URL,
			method: 'GET',
		});
	},
	{
		onSuccess: (data) => {
			// data로 이것저것 하는 로직
		}
	},
	{
		onError: (error) => {
			// error로 이것저것 하는 로직
		}
	}
})
```

예시에서는 컴포넌트 내부에서 위와 같은  로직을 통해 Server 데이터를 가져오고 있는데, 이때 onSuccess 와 onError 함수를 통해 fetch 성공과 실패에 대한 분기를 아주 간단히 구현할 수 있다. 이는 Server 데이터를 불러오는 과정에서 구현해야할 추가적인 설정들을 진행할 필요가 없다는 이야기이다. 

**즉, Client 데이터는 상태 관리 라이브러리가 관리하고, Server 데이터는 React-Query 가 관리하는 구조라고 생각하면 된다!! 이를 통해 우리는 Client 데이터와 Server 데이터를 온전하게 분리할 수 있다.**

> 물론 여기서 React-Query 가 가져온 Server 데이터를 상태 관리 라이브러리를 통해 전역 상태로 가져올 수 잇는 건 사실이다. 그러나 refetch 가 여러 번 일어나는 상황에 매번 Server 데이터를 전역 상태로 가져오는것이 옳은지 판단하는 것은 우리의 몫이다. 개발하는 서비스의 상황에 맞게 잘 선택해보도록 하자!!
> 

## 3. React-Query 가 데이터를 다루는 방법

React-Query 를 사용하면서 에러를 겪은 분들이나, 프론트엔드 라이브러리 코드를 조금이라도 뜯어보신 분들은 쉽게 알 수 있을텐데, React-Query 또한 React 의 ContextAPI 를 기반으로 동작한다. 

전체 Scope 가 되며 하위 컴포넌트들의 server data 를 관리하는 QueryClient 가 존재하는 데, 해당 QueryClient 는 우리가 Query 를 사용할 때 명시하는 Key 를 기반으로 데이터를 저장한다. 

즉, 다시 말해 QueryClient 는 단순히 서버에서 불러온 데이터를 저장하는 곳이라기보다는, 데이터를 저장하는 용도로 사용되는 Context Store 와 동일한 역할을 한다는 것이다. 그 용도가 서버 데이터 관리에 초점을 두는 것일 뿐이기에, 우리는 필요에 따라 QueryClient 또한 단순 데이터 저장소처럼 간주하고 자유자재로 활용할 수 있어야한다. 

> 실제 tanstack/@react-query공식문서를 살펴보면 `getQueryData`, `setQueryData`, `fetchQuery` 등등 QueryClient 라는 저장소를 관리할 수 있는 정말 다양한 메서드가 존재한다. 해당 메서드들은 데이터를 어떠한 방식(비동기/동기, 캐싱 등)으로 관리할지에 따라 나뉘며, 각 메서드의 특징과 활용 용도를 정확하게 파악하고 있어야 이 라이브러리를 제대로 활용하고 있다고 말할 수 있다.

React-query는 타 툴들에 비교하면 덩치가 나름 있는 라이브러리이기 때문에 추후 번들 사이즈에서 단점이 드러날 수 있는 여지가 있다. 따라서 사용하고자 한다면 위와 같은 다양한 도구들을 제대로 활용하여 번들의 메모리를 헛되이하지 않는 현명한 프론트엔드 개발자가 되자.
> 

## 4. 대표적인 기능들

React-Query 에서 data fetching 을 위해 제공하는 대표적인 기능들을 살펴보자

기본적으로 Get 에는 useQuery 가,  PUT, UPDATE, DELETE 에는 useMutation 이 사용된다. 

### useQuery

- 첫 번째 파라미터로 unique key 를 포함한 배열이 들어간다. 이후 동일한 쿼리를 불러올 때 유용하게 사용된다.
- 첫 번째 파라미터에 들어가는 배열의 첫 요소는 unique key 로 사용되고, 두 번째 요소부터는 query 함수 내부의 파라미터로 값들이 전달된다.
- 두 번째 파라미터로 실제 호출하고자 하는 비동기 함수가 들어간다. 이때 함수는 Primise 를 반환하는 형태여야한다.
- 최종 반환 값은 API 의 성공, 실패 여부, 반환값을 포함한 객체이다.

Ex)

```jsx
import {
  QueryClient,
  QueryClientProvider,
  useQuery,
} from '@tanstack/react-query'

const queryClient = new QueryClient()

export default function App() {
  return (
    <QueryClientProvider client={queryClient}>
      <Example />
    </QueryClientProvider>
  )
}

function Example() {
  const { isPending, error, data } = useQuery({
    queryKey: ['repoData'],
    queryFn: () =>
      fetch('https://api.github.com/repos/tannerlinsley/react-query').then(
        (res) => res.json(),
      ),
  })

  if (isPending) return 'Loading...'

  if (error) return 'An error has occurred: ' + error.message

  return (
    <div>
      <h1>{data.name}</h1>
      <p>{data.description}</p>
      <strong>👀 {data.subscribers_count}</strong>{' '}
      <strong>✨ {data.stargazers_count}</strong>{' '}
      <strong>🍴 {data.forks_count}</strong>
    </div>
  )
}
```

- useQuery 함수가 반환하는 객체를 보면 isPending 을 통해 로딩 여부를, error 를 통해 에러 발생 여부를, data 를 통해 성공 시 데이터를 반환할 수 있다.
- isPending 과 error 를 이용하여 각 상황 별 분기를 쉽게 진행할 수 있다.

### useQuery 동기적으로 실행

- useQuery 에서 enabled 옵션을 사용하면 비동기 함수인 useQuery 를 동기적으로 사용가능하다.
- useQuery 의 세 번째 인자로 다양한 옵션 값들이 들어가는데, 여기서 enabled 에 값을 대입하면 해당 값이 true 일때 useQuery 를 동기적으로 실행한다.

```jsx
const { data: todoList, error, isFetching } = useQuery({
	queryKey: ["todos"], 
  	queryFn: fetchTodoList,
});
const { data: nextTodo, error, isFetching } = useQuery({
  queryKey: ["nextTodos"],
  queryFn: fetchNextTodoList,
  enabled: !!todoList // true가 되면 fetchNextTodoList를 실행한다
});
```

### useQueries

여러 개의 useQuery 를 한 번에 실행하고자 하는 경우, 기존의 Promise.all() 처럼 묶어서 실행할 수 있도록 도와준다.

```jsx
const ids = [1, 2, 3]
const results = useQueries({
  queries: ids.map((id) => ({
    queryKey: ['post', id],
    queryFn: () => fetchPost(id),
    staleTime: Infinity,
  })),
})

// 두 query에 대한 반환값이 배열로 묶여 반환된다!!

// 만일 반환된 배열에 대해 통합된 값을 불러오고 싶다면, 아래와 같이 combine 설정을 통해 데이터를 한 번에 반환할 수 있다. 이외에도 배열을 다루는 메서드들을 이용해 반환값에 대한 전처리를 수행할 수 있다!

const ids = [1, 2, 3]
const combinedQueries = useQueries({
  queries: ids.map((id) => ({
    queryKey: ['post', id],
    queryFn: () => fetchPost(id),
  })),
  combine: (results) => {
    return {
      data: results.map((result) => result.data),
      pending: results.some((result) => result.isPending),
    }
  },
})
```

### useMutation

- 위에서 언급한 것처럼 PUT, UPDATE, DELETE 와 같이 값을 변경할 때 사용하는 API 이다. 반환값은 useQuery 와 동일하다.

Ex)

```jsx
function App() {
  const mutation = useMutation({
    mutationFn: (newTodo) => {
      return axios.post('/todos', newTodo)
    },
  })

  return (
    <div>
      {mutation.isLoading ? (
        'Adding todo...'
      ) : (
        <>
          {mutation.isError ? (
            <div>An error occurred: {mutation.error.message}</div>
          ) : null}

          {mutation.isSuccess ? <div>Todo added!</div> : null}

          <button
            onClick={() => {
              mutation.mutate({ id: new Date(), title: 'Do Laundry' })
            }}
          >
            Create Todo
          </button>
        </>
      )}
    </div>
  )
}
```

- 위의 코드에서 볼 수 있듯이 반환값은 useQuery 와 동일하지만, 처음 사용 시에 post 비동기 함수를 넣어주었다. 이때 useMutation 의 첫 번째 파라미터에 비동기 함수가 들어가고, 두 번째 인자로 상황 별 분기 설정이 들어간다는 점이 차이이다.
- 실제 사용 시에는 mutation.mutate 메서드를 사용하고, 첫 번째 인자로 API 호출 시에 전달해주어야하는 데이터를 넣어주면 된다.