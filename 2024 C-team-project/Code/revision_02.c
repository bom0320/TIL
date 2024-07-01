#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <math.h>

void display_manual(void);
void practice_piano(void);
int calc_frequency(int octave, int inx);
void arrow_key_control(int code, int* base_octave, int* time_delay);
void play_song(char song_key);

// 주파수를 정의합니다. (도, 레, 미, 파, 솔, 라, 시, 도)
#define C4  261
#define D4  294
#define E4  329
#define F4  349
#define G4  392
#define A4  440
#define B4  493
#define C5  523

int main(void)
{
    display_manual();
    practice_piano();
    return 0;
}

void display_manual(void)
{
    printf("키보드의 숫자를 누르면 해당 건반에 대한 옥타브와 지연시간이 표시됩니다.\n\n");
    printf(" 키↑: 한 옥타브 위로\n");
    printf(" 키↓: 한 옥타브 아래로\n");
    printf(" 키←: 음의 지연시간 짧게\n");
    printf(" 키→: 음의 지연시간 길게\n");
    printf(" T: Twinkle Twinkle Little Star 재생\n");
    printf(" H: Happy Birthday 재생\n\n");
    printf(" ESC를 누르면 프로그램이 종료됩니다.\n\n");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃ ┃ ┃  ┃  ┃ ┃ ┃ ┃  ┃    ");
    puts("  ┃  ┗━┛ ┗━┛  ┃  ┗━┛ ┗━┛ ┗━┛  ┃  ┗━┛ ┗━┛  ┃    ");
    puts("  ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃    ");
    puts("  ┃ 1 ┃ 2 ┃ 3 ┃ 4 ┃ 5 ┃ 6 ┃ 7 ┃ 8 ┃   ┃   ┃    ");
    puts("  ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛    ");
}

void practice_piano(void)
{
    int index[] = { 0, 2, 4, 5, 7, 9, 11, 12 };
    int freq[8], code, i;
    int base_octave = 4, time_delay = 500;

    for (i = 0; i < 8; i++)
        freq[i] = calc_frequency(base_octave, index[i]);

    do
    {
        code = _getch();

        if ('1' <= code && code <= '8')
        {
            code -= 49;
            Beep(freq[code], time_delay);
        }
        else if (code == 'T' || code == 't')
        {
            play_song('T'); // 'T' 키를 누르면 "Twinkle Twinkle Little Star" 노래 재생
        }
        else if ( code == 'h')
        {
            play_song('h'); // 'H' 키를 누르면 "Happy Birthday" 노래 재생
        }
        else if (code == 27) // ESC 키를 누르면 종료
        {
            break;
        }
        else
        {
            arrow_key_control(code, &base_octave, &time_delay);
            for (i = 0; i < 8; i++)
                freq[i] = calc_frequency(base_octave, index[i]);
        }

        printf("\r현재 옥타브: %d  현재 지속시간: %4.2f초", base_octave, time_delay / 1000.0);
        fflush(stdout);
    } while (code != 27);
}

void arrow_key_control(int code, int* base_octave, int* time_delay)
{
    switch (code)
    {
    case 72:  // 키 ↑
        *base_octave += 1;
        if (6 < *base_octave)
            *base_octave = 6;
        break;
    case 75:  // 키 ←
        *time_delay -= 250;
        if (*time_delay < 250)
            *time_delay = 250;
        break;
    case 77:  // 키 →
        *time_delay += 250;
        if (1000 < *time_delay)
            *time_delay = 1000;
        break;
    case 80:  // 키 ↓
        *base_octave -= 1;
        if (*base_octave <= 2)
            *base_octave = 2;
        break;
    default:
        // 방향키 이외의 입력은 무시합니다.
        break;
    }
}

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

void play_song(char song_key)
{
    int song_notes_Twinkle[] = { C4, C4, G4, G4, A4, A4, G4, F4, F4, E4, E4, D4, D4, C4 };
    int song_durations_Twinkle[] = { 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000 };

    int song_notes_Happy[] = { C4, C4, D4, C4, F4, E4, C4, C4, D4, C4, G4, F4, C4, C4, C5, A4, F4, E4, D4, B4, B4, A4, F4, G4 };
    int song_durations_Happy[] = { 400, 400, 800, 800, 800, 1600, 400, 400, 800, 800, 800, 1600, 400, 400, 400, 400, 800, 400, 400, 800, 800, 400, 400, 800 };

    int* song_notes;
    int* song_durations;
    int song_length;

    // 노래 선택에 따라 노래 배열과 지속 시간 배열 설정
    if (song_key == 'T' || song_key == 't') {
        song_notes = song_notes_Twinkle;
        song_durations = song_durations_Twinkle;
        song_length = sizeof(song_notes_Twinkle) / sizeof(song_notes_Twinkle[0]);
    }
    else if (song_key == 'h') {
        song_notes = song_notes_Happy;
        song_durations = song_durations_Happy;
        song_length = sizeof(song_notes_Happy) / sizeof(song_notes_Happy[0]);
    }
    else {
        printf("잘못된 노래 키입니다.");
        return;
    }

    for (int i = 0; i < song_length; i++)
    {
        Beep(song_notes[i], song_durations[i]);
        Sleep(100); // 각 음 사이에 약간의 지연을 추가하여 음이 겹치지 않도록 함
    }
}