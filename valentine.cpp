#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#define MAX 13
// Function to change cursor position in console screen
void gotoxy(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD g = {x, y};
    SetConsoleCursorPosition(h, g);
}
// Function to change text color (color code from 0 to 12)
void textcolor(int x)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

// Console screen resize function
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Function to write the title text
void Begin()
{

    gotoxy(28, 2);
    textcolor(12);
    printf("CONNECTING FROM LOVE SEVER");
    gotoxy(13, 4);
    textcolor(12);
    printf("%c%c%c", 3, 3, 3);
    gotoxy(65, 4);
    printf("%c%c%c", 3, 3, 3);
    gotoxy(16, 4);
    textcolor(11);
    printf(" Send to...........Nguoi con gai toi tham thuong");
    // gotoxy(18,6); textcolor(14); printf("____________________________________________");
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......10%%");
    gotoxy(18, 7);
    textcolor(14);
    printf("____________________________________________");
}

// function draw heart
void drawHeart(int save)
{

    // heartMatrix
    int heartMtrix[MAX][MAX] = {
        {0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}};
    // Change the heart drawing color
    textcolor(save % 14 + 1);

    // draw heart matrix
    if (save == 0)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                Sleep(10);
                if (heartMtrix[i][j])
                {
                    gotoxy(j + 20, i + 10);
                    printf("%c", 3);
                }
                else
                {
                    gotoxy(j + 20, i + 10);
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                Sleep(10);
                if (heartMtrix[i][j])
                {
                    gotoxy(j + 33, i + 10);
                    printf("%c", 3);
                }
                else
                {
                    gotoxy(j + 33, i + 10);
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                Sleep(10);
                if (heartMtrix[i][j])
                {
                    gotoxy(j + 46, i + 10);
                    printf("%c", 3);
                }
                else
                {
                    gotoxy(j + 46, i + 10);
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    if (save % 2 == 0)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (heartMtrix[i][j])
                {
                    gotoxy(j + 20, i + 10);
                    printf("%c", 3);
                }
                else
                {
                    gotoxy(j + 20, i + 10);
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (heartMtrix[i][j])
                {
                    gotoxy(j + 33, i + 10);
                    printf("%c", 3);
                }
                else
                {
                    gotoxy(j + 33, i + 10);
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (heartMtrix[i][j])
                {
                    gotoxy(j + 46, i + 10);
                    printf("%c", 3);
                }
                else
                {
                    gotoxy(j + 46, i + 10);
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    textcolor(12);
    gotoxy(26, 14);
    printf("14");
    gotoxy(38, 14);
    printf("02");
    gotoxy(51, 14);
    printf("2023");
}
int main()
{
    resizeConsole(900, 450);
    //function call Begin
    Begin();

    // Write the text to the Console screen
    gotoxy(10, 10);
    textcolor(10);
    printf("Cau a!! To co dieu muon noi voi cau.....");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......15%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("Truoc khi gap cau....to co nhieu  thoi gian ranh roi lam");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......21%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("Nhung tu sau khi gap cau....Nhung khoang thoi gian do khong con nua");
    gotoxy(10, 12);
    textcolor(10);
    printf("  ma no bi lop day boi noi nho, tuong tu, va nhung nghi suy ve cau");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......26%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("Co le 'To thich cau that roi......'                                              ");
    gotoxy(10, 12);
    textcolor(15);
    printf("                                                                              ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......35%%");
    gotoxy(10, 10);
    textcolor(15);
    printf("...                                                                          ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......41%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("To khong duoc dep trai, nha to cung khong giau, to cung khong hoc gioi                  ");
    gotoxy(10, 12);
    textcolor(10);
    printf("    nhu bao nguoi con trai khac                                            ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......49%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("To chi la 1 thang con trai me Game online, hoc dot, bat tai......             ");
    gotoxy(10, 12);
    textcolor(15);
    printf("                                               ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......55%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("Nhieu luc thuc su to muon lay het can dam tien lai gan cau va noi                  ");
    gotoxy(10, 12);
    textcolor(11);
    printf("   'TO THICH CAU'                                                 ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......61%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("Nhung to khong lam duoc....                                        ");
    gotoxy(10, 12);
    textcolor(10);
    printf("   To khong co diem gi noi bat de co the ngo loi voi cau");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......68%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("va cau cung khong co ly do gi de co the chap nhan 1 nguoi nhu to....");
    gotoxy(10, 12);
    textcolor(15);
    printf("                                                                         ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......85%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("Vi vay....Thich cau, to van se giu trong long, chi minh to biet!!           ");
    gotoxy(10, 12);
    textcolor(10);
    printf("                to se chi luon ngam nhin cau tu phia sau!!                          ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......93%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("  Yeu don phuong, nhieu luc cung hanh phuc lam vi                              ");
    gotoxy(10, 12);
    textcolor(10);
    printf("                        to se khong bao gio bi cau tu choi....                     ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......99%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("To chi can moi ngay den truong deu duoc nhin thay cau                        ");
    gotoxy(10, 12);
    textcolor(10);
    printf("          cung du lam cho to vui roi!!!                            ");
    Sleep(500);
    gotoxy(32, 6);
    textcolor(13);
    printf("Loading......100%%");
    gotoxy(10, 10);
    textcolor(10);
    printf("Va hien tai hy vong duy nhat cua to chi la                         ");
    gotoxy(10, 12);
    textcolor(10);
    printf("    1 ngay nao do cau biet duoc rang                 ");
    gotoxy(10, 14);
    textcolor(10);
    printf("     da tung co 1 thang con trai tham thuong cau rat nhieu                      ");
    Sleep(500);
    system("cls");
    int save = 0;
    while (1)
    {
        drawHeart(save);
        save++;
        Sleep(300);
    }

    getch();
}
