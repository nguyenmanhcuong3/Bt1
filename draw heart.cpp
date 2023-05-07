
// IN RA MÀN HÌNH, HÌNH TRÁI TIM CÓ KÍCH THU?C MxN=6x7
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// vi?t hàm
void drawHeart(int N)
{
    system("color 2");
    int i, j;
    char c = 3;
    // kh?i t?o 2 vòng l?p for l?ng nhau
    for (i = 1; i < N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            // di?u ki?n
            Sleep(100);
            if (!((i == 1 && (j == 1 || j == 4 || j == 7))
                || (i == 4 && (j == 1 || j == 7))
                || (i == 5 && (j <= 2 || j >= 6))
                || (i == 6 && (j <= 3 || j >= 5))))
            { 
                printf(" %c ", c);
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}
// chuong trình chính
int main()
{
    int M = 6, N = 7;
    char c = 3;
    // l?i g?i hàm
    drawHeart(N);
    return 0;
}
