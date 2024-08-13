React-Query 의 대표적인 기능들
===

### 대표적인 기능들

React-Query 는 데이터를 가져오기와 조작을 위해 다양한 훅을 제공한다. (여기서는 useQuery 와 useMutation 을 중심으로 설명)

## 1. ‘useQuery’

- ‘useQuery’ 는 **데이터를 가져올 때 사용**된다. 예를 들어, 서버에서 데이터를 받아오는 GET 요청을 처리할 때 사용된다.

### 기본 구조

**첫 번째 파라미터**

- **쿼리의 고유 키**와 **파라미터를 포함한 배열**이다.
- 이 키를 사용하여 쿼리를 고유하게 식별한다.

**두 번째 파라미터**

- **데이터를 가져오기 위한 비동기 함수**
- 이 함수는 ‘promise’ 를 반환해야한다.

EX)

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

- **ispending :** 데이터가 로딩 중인지 확인할 수 있다.
- **error :** 에러가 발생했을 때의 에러 객체이다.
- **data:** 성공적으로 데이터를 받아왔을 때의 데이터이다.

### 동기적 실행

‘useQuery’ 의 옵션 중 enabled 를 사용하여 **특정 조건이 충족될 때만** 쿼리를 실행할 수 있다.

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

### 2. ‘useQueries’

여러 개의 ‘useQeury’ 를 한 번에 실행할 수 있도록 도와준다. ‘promise.all()’ 처럼 여러 쿼리를 묶어서 실행할 수 있다.

ex)

```jsx
const ids = [1, 2, 3]
const results = useQueries({
  queries: ids.map((id) => ({
    queryKey: ['post', id],
    queryFn: () => fetchPost(id),
    staleTime: Infinity,
  })),
})

```

여러 쿼리의 결과를 배열로 묶어서 반환한다.

### 3. useMutation

‘useMutation’ 은 데이터를 변경하는 요청(PUT, UPDATE, DELETE 등) 을 처리할 때 사용된다. 

ex)

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

- **mutaion.isLoading:** 요청이 진행 중인지 확인
- **mutation.isError:** 요청이 실패했을 때의 에러 객체
- **mutation.isSuccess:** 요청이 성공했을 때의 상태

‘mutation.mutate’ 를 사용하여 데이터를 변경하는 요청을 실행한다.