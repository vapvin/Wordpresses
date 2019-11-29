#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define p 112
#define P 80
#define ESC 27

#define false 0
#define true 1

#define ACTIVE_BLOCK -2
#define CEILLING -1
#define EMPTY 0
#define WALL 1
#define INACTIVE_BLOCK 2

#define MAIN_X 11
#define MAIN_Y 23
#define MAIN_X_ADJ 3
#define MAIN_Y_ADJ 1

#define STATUS_X_ADJ MAIN_X_ADJ + MAIN_X + 1

int STATUS_YGOAL;
int STATUS_Y_LEVEl;
int STATUS_Y_SCORE;

int blocks[7][4][4][4] = {
    {{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}},
    {{0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0}},
    {{0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0}},
    {{0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0}},
    {{0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0}}};

int b_type;
int b_rotation;
int b_type_next;

int main_org[MAIN_Y][MAIN_X];
int main_cpy[MAIN_Y][MAIN_X];

int bx, by;

int key;

int speed;
int level;
int level_goal;
int cnt;
int score;
int last_score = 0;
int best_score = 0;

int new_block_on = 0;
int crush_on = 0;
int level_up_on = 0;
int space_key_on = 0;

void title(void);
void reset(void);
void reset_main_cpy(void);
void draw_map(void);
void draw_main(void);
void new_block(void);
void check_key(void);
void drop_block(void);
int check_crush(int bx, int by, int rotation);
void move_block(int dir);
void check_line(void);
void check_level_up(void);
void check_game_over(void);
void pause(void);

void gotoxy(int x, int y)
{
    COORD pos = {2 * x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef eunm{NOCURSOR, SOLIDCURSOR, NORMALCURSOR} CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c)
{
    CONSOLE_CURSOR_INFO CurInfo;

    switch (c)
    {
    case NOCURSOR:
        Curinfo.dwSize = 1;
        CurInfo.bVisible = FALSE;
        break;
    case SOLIDCURSOR:
        CurInfo.dwSize = 100;
        CurInfo.bVisble = TRUE;
        break;
    case NORMALCURSOR:
        CurInfo.dwSize = 20;
        CurInfo.bVisible = TRUE;
        break;
    }
    SetConsoleCursorinfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

int main()
{
    int i;

    srand((unsigned)time(NULL));
    setcursortype(NOCURSOR);
    title();
    reset();

    while (1)
    {
        for (i = 0; i < 5; i++)
        {
            check_key();
            draw_main();
            Sleep(speed);
            if (crush_on && check_crush(bx, by + 1, b_rotation) == false)
                Sleep(100);

            if (space_key_on == 1)
            {
                space_key_on = 0;
                break;
            }
        }
        drop_block();
        check_level_up();
        check_game_over();
        if (new_block_on == 1)
            new_block();
    }
}

void title(void)
{
    int x = 5;
    int y = 4;
    int cnt;

    gotoxy(x, y + 0);
    printf("■□□□■■■□□■■□□■■");
    Sleep(100);
    gotoxy(x, y + 1);
    printf("■■■□  ■□□    ■■□□■");
    Sleep(100);
    gotoxy(x, y + 2);
    printf("□□□■              □■  ■");
    Sleep(100);
    gotoxy(x, y + 3);
    printf("■■□■■  □  ■  □□■□□");
    Sleep(100);
    gotoxy(x, y + 4);
    printf("■■  ■□□□■■■□■■□□");
    Sleep(100);
    gotoxy(x, y + 5);
    printf("      blog.naver.com/azure0777");
    Sleep(100);
    gotoxy(x + 5, y + 2);
    printf("T E T R I S");
    Sleep(100);
    gotoxy(x, y + 7);
    printf("Please Enter Any Key to Start..");
    gotoxy(x, y + 9);
    printf("  △   : Shift");
    gotoxy(x, y + 10);
    printf("◁  ▷ : Left / Right");
    gotoxy(x, y + 11);
    printf("  ▽   : Soft Drop");
    gotoxy(x, y + 12);
    printf(" SPACE : Hard Drop");
    gotoxy(x, y + 13);
    printf("   P   : Pause");
    gotoxy(x, y + 14);
    printf("  ESC  : Quit");
    gotoxy(x, y + 16);
    printf("BONUS FOR HARD DROPS / COMBOS");

    for (cnt = 0;; cnt++)
    {
        if (kbhit())
            break;
        if (cnt % 200 == 0)
        {
            gotoxy(x + 4, y + 1);
            printf("★");
        }
        if ((cnt % 200 - 100) == 0)
        {
            gotoxy(x + 4, y + 1);
            printf("  ");
        }
        if ((cnt % 350) == 0)
        {
            gotoxy(x + 13, y + 2);
            printf("☆");
        }
        if ((cnt % 350 - 100) == 0)
        {
            gotoxy(x + 13, y + 2);
            printf("  ");
        }
        Sleep(10);
    }

    while (kbhit())
        getch();
}

void reset(void)
{

    FILE *file = fopen("score.dat", "rt");
    if (file == 0)
    {
        best_score = 0;
    }
    else
    {
        fscanf(file, "%d", &best_score);
        fclose(file);
    }

    level = 1;
    score = 0;
    level_goal = 1000;
    key = 0;
    crush_on = 0;
    cnt = 0;
    speed = 100;

    system("cls");
    reset_main();
    draw_map();
    draw_main();

    b_type_next = rand() % 7;
    new_block();
}