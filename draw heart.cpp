
// IN RA M�N H�NH, H�NH TR�I TIM C� K�CH THU?C MxN=6x7
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// vi?t h�m
void drawHeart(int N)
{
    system("color 2");
    int i, j;
    char c = 3;
    // kh?i t?o 2 v�ng l?p for l?ng nhau
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
// chuong tr�nh ch�nh
int main()
{
    int M = 6, N = 7;
    char c = 3;
    // l?i g?i h�m
    drawHeart(N);
    return 0;
}
