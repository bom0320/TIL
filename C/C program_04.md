## 포인터의 이해

- **포인터(Pointers)**
    - 어떤 저장 공간의 주소(memory address)를 저장하기 위한 변수
    - 포인터는 포인터가 가리키는 저장 공간에 접근하는 데 사용한다.
    - 포인터의 자료형은 포인터가 가리키는 저장 공간의 자료형과 같아야 한다.
    - 포인터는 주소를 저장하는 변수이므로, 포인터에 할당되는 저장 공간의 크기는 프로그램에서 사용하는 주소의 크기와 같다. (현재는 64비트, 즉 8바이트 크기의 주소를 사용)
- 참조 연산자( & )
    - 변수 등에 할당된 저장 공간의 주소를 구하는 연산자
    - 저장 공간의 주소는 저장 공간의 첫 번째 메모리 블록의 주소이다.
- 포인터 연산자( * )
    - 포인터에 저장되어 있는 주소의 저장 공간, 즉 포인터가 가리키는 저장 공간에 접근

## NULL 포인터

- NULL 포인터
    - 주소가 할당되지 않은 포인터(아무것도 가리키지 않는 상태)
    - 포인터는 NULL 로 초기화한다.

```c
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>

#define NULL (void*)0
```

```c
char *ptr= NULL;
printf("ptr = %p\n",ptr);
```

NULL은 stdio.h, stdlib.h, string.h 파일에 정의된 메크로(macro)이다.

## void 포인터를 사용하는 이유

- void 포인터를 사용하는 이유
    - 함수에서 다양한 자료형의 주소를 전달 받기 위해
    - 함수에서 다양한 자료형의 주소를 반환하기 위해
        
        ```c
        int num = 10;
        void *ptr = &num;
        
        num = *ptr; // ERROR!
        ```
        
        num = *ptr:  포인터 연산자로 포인터가 가리키는 저장 공간에 접근하기 위해서는 그 저장 공간의 자료형을 알아야 한다. 그래가 값을 제대로 읽어 올 수 있다. 포인터의 자료형이 포인터가 가리키는 저장공간의 자료형을 의미한다. void 포인터는 자료형이 없기 때문에 포인터 연산자를 사용할 수 없다.
        
        **num=*((int*)ptr);**
        

## void 포인터

- void 포인터
    - 포인터는 자료형을 가져야한다. 그래야 포인터가 가리키는 저장 공간에 접근할 수 있다.
        - 포인터의 자료형은 포인터가 가리키는 저장 공간의 자료형을 나타낸다.
    - void 포인터는 자료형을 지정하지 않는다. 그래서 void 포인터는 단순하게 메모리 주소를 저장하는 역할만 하며, coid 포인터로 저장공간에 접근할 수 없다.
    - 어떤 자료형 저장 공간의 주소이든 void 포인터에 저장할 수 있고, void 포인터를 다른 자료형의 포인터에 대입할 수 있다.
    
    ```c
    int *ptr1=&num;
    char *ptr2;
    void ptr3; // void 포인터 선언
    
    ptr2=ptr1; // 오류
    ptr3=ptr1; // void 포인터에는 다른 자료형의 포인터를 저장할 수 있다.
    ```
    

## 포인터 연산자

- 포인터 연산자(*; 역참조 연산자, 간접 참조 연산자)
    - 포인터에 저장되어 있는 주소의 저장 공간, 즉 포인터가 가리키는 저장 공간에 접근하는 연산자
    - 포인터 연산자의 피연산자는 포인터(저장 공간의 주소)이어야 한다.
        - 이때, 포인터의 자료형과 포인터가 가리키는 저장 공간의 자료형은 같아야 한다.
        
        ```c
        int *ptr;
        int num=10;
        ptr=&num; // 참조 연산자 (값이 저장된 저장공간의 주소를 구하는 연산자)
        
        printf("num = %d\n",num);
        printf("*ptr = %d\n",*ptr);
        ```