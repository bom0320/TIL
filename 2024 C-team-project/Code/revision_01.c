#include <stdio.h>
#include <stdlib.h> // 일반적인 유틸리티 함수들을 사용하기 위해 포함
#include <time.h>
#include <math.h>

void display_manual(void); // 사용자 메뉴얼을 출력하는 함수
void practice_piano(void); // 피아노 연습을 위한 함수
int calc_frequency(int octave, int inx); // 주어진 옥타브와 음계 인덱스에
                                         // 따른 주파수를 계산하는 함수
void arrow_key_control(int code, int* base_octave, int* time_delay); 
// 화살표 키 입력에 따라 옥타브 및 지연 시간을 조절하는 함수
int main(void)
{
    display_manual(); // 프로그램 사용 방법 설명
    practice_piano(); // 피아노 연습 루프를 실행
    return 0;
}

// 프로그램의 사용 방법을 콘솔에 출력
void display_manual(void)
{
    printf("키보드의 숫자를 누르면\n");
    printf("해당 건반에 대한 옥타브와 지연시간이 표시됩니다.\n\n");
    printf(" 키↑: 한 옥타브 위로\n");
    printf(" 키↓: 한 옥타브 아래로\n");
    printf(" 키←: 음의 지연시간 짧게\n");
    printf(" 키→: 음의 지연시간 길게\n\n");
    printf("ESC를 누르면 프로그램이 종료됩니다.\n\n");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┗━┛ ┗━┛  ┃  ┗━┛ ┗━┛ ┗━┛  ┃  ┗━┛ ┗━┛  ┃    ");
    puts("  ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃    ");
    puts("  ┃ 1 ┃ 2 ┃ 3 ┃ 4 ┃ 5 ┃ 6 ┃ 7 ┃ 8 ┃   ┃   ┃    ");
    puts("  ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛    ");
}

// 피아노 연습을 위하 메인 루프
void practice_piano(void)
{
    int index[] = { 0, 2, 4, 5, 7, 9, 11, 12 };
    int freq[8], code, i;
    int base_octave = 4, time_delay = 500;  // 초기 옥타브와 지연시간 설정

    for (i = 0; i < 8; i++)
        freq[i] = calc_frequency(base_octave, index[i]);

    do
    {
        code = _getch(); 
        //_getch()를 사용하여 키 입력을 받고, 
        // 키 입력에 따라 음을 재생하거나 옥타브와 지연 시간을 조정

        if ('1' <= code && code <= '8')
        {
            code -= 49;
            Beep(freq[code], time_delay); // 주파수에 따라 소리 재생
        }
        else
        {
            arrow_key_control(code, &base_octave, &time_delay);
            for (i = 0; i < 8; i++)
                freq[i] = calc_frequency(base_octave, index[i]);
        }

        printf("\r현재 옥타브: %d  현재 지연시간: %4.2f초", base_octave, time_delay / 100.0);
        fflush(stdout);  // 버퍼를 비워서 즉시 콘솔에 출력되도록 함
    } while (code != 27); // 27(ESC 키)이 입력되면 루프를 종료
}

// 화살표 키 입력에 따라 옥타브와 지연 시간 조절
void arrow_key_control(int code, int* base_octave, int* time_delay)
{
    switch (code)
    {
    case 72:  // 키 ↑ // 위쪽 화살표 키로 옥타브를 한 단계 올림
        *base_octave += 1;
        if (6 < *base_octave)
            *base_octave = 6;
        break;
    case 75:  // 키 ← // 왼쪽 화살표 키로 지연 시간 줄임
        *time_delay -= 250;
        if (*time_delay < 250)
            *time_delay = 250;
        break;
    case 77:  // 키 → // 오른쪽 화살표 키로 지연 시간 늘림
        *time_delay += 250;
        if (1000 < *time_delay)
            *time_delay = 1000;
        break;
    case 80:  // 키 ↓ // 아래쪽 화살표 키로 옥타브를 한 단계 내림
        *base_octave -= 1;
        if (*base_octave <= 2)
            *base_octave = 2;
        break;
    default:
        break;
    }
}

// 주어진 옥타브와 음계 인덱스에 따른 주파수를 계산
int calc_frequency(int octave, int inx)
{
    double do_scale = 32.7032;
    double ratio = pow(2., 1 / 12.), temp;
    int i;
    temp = do_scale * pow(2, octave - 1);
    for (i = 0; i < inx; i++)
    {
        temp *= ratio;
    }
    return (int)temp;
}