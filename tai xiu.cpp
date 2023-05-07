/*Trò choi tài x?ux?u
- ngu?i choi l?a ch?n tài ho?c x?u sau dó nh?p s? ti?n d?t cu?c
- sau khi d?t cu?c s? ti?n hi?n t?i = ti?n - s? ti?n cu?c
  + n?u ngu?i choi ch?n tài mà k?t qu? ra x?u thì s? ti?n = s? ti?n - ti?n cu?c -> thua
  + n?u ngu?i choi ch?n dúng thì s? ti?n = s? ti?n + ti?n cu?c -> th?ng
-n?u ketqua = 4 - 10 => Xiu
-n?u  ketqua = 11 - 17 => Tai
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// hàm ki?m tra tu?i c?a ngu?i choi
int checkAgeUser()
{
    int yourAge;
    printf("\nNhap Vao Tuoi Cua Ban (Tuoi >= 18) : ");
    scanf("%d", &yourAge);
    getchar();
    if (yourAge < 18)
    {
        printf("\nBan Khong Du Tuoi De Choi Tro Nay !");
        exit(0);
    }
}

// hàm này s? random các con s? trong m?t xúc s?c (random t? 1 d?n 6)
int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

// hàm x? lí k?t qu? random
int result_random()
{
    int diceOne, diceTwo, diceThree;
    srand((int)time(0));
    // vòng l?p x? lí xúc x?c 1
    for (int i = 1; i < 6; ++i)
    {
        diceOne = random(1, 6);
        diceOne %= 10;
    }
    printf("\n->> Con Xuc Xac 1 :  %d ", diceOne);
    // vòng l?p x? lí xúc x?c 2
    for (int i2 = 1; i2 < 6; ++i2)
    {
        diceTwo = random(1, 6);
        diceTwo %= 10;
    }
    printf("\n->> Con Xuc Xac 2 :  %d ", diceTwo);
    // vòng l?p x? lí xúc x?c 3
    for (int i3 = 1; i3 < 6; ++i3)
    {
        diceThree = random(1, 6);
        diceThree %= 10;
    }
    printf("\n->> Con Xuc Xac 3 :  %d ", diceThree);

    // tr? v? k?t qu? là t?ng sau khi gieo 3 con xúc s?c
    return diceOne + diceTwo + diceThree;
}

// hàm x?a lí ngu?i choi d?t cu?c và tr? v? k?t qu? th?ng ho?c thua
void processing()
{
    int diceOne, diceTwo, diceThree;
    int money = 5000000, tienCuoc;
    int option, luaChon;
    do
    {
        system("cls");
        int a = 5, c = 175; // bi?n in ra các kí t? trong b?ng mã ASCII
        for (int i = 0; i < 45; i++)
        {
            Sleep(50);
            printf("%c", a);
        }
        // Menu d? ngu?i choi ch?n
        printf("\n================Moi Ban Chon=================");
        printf("\n\t(1). Nhan 1 De Chon Tai ");
        printf("\n\t(2). Nhan 2 De chon Xiu ");
        printf("\n\t(0). Thoat");
        printf("\n=============================================");
        printf("\nSo Tien Hien Tai Cua Ban La : %d ", money);
        printf("\n>>> Moi Ban Nhap Lua Chon : ");
        scanf("%d", &option);
        // ki?m tra l?a ch?n c?a ngu?i choi
        switch (option)
        {
        case 1:
        {
            printf("\nNhap So Tien Cuoc(Toi Thieu 10000) : ");
            scanf("%d", &tienCuoc);
            if (tienCuoc > money || tienCuoc < 10000)
            {
                printf("\n=>> Ban Khong Du Tien Choi !");
                exit(0);
            }
            else
            {
                printf("\n=>> So Tien Con Lai Sau Khi Cuoc : %d", money - tienCuoc);
                printf("\n");
                for (int i = 0; i < 45; i++)
                {
                    Sleep(50);
                    printf("%c", a);
                }
                printf("\n=>> BAN DA VAO GAME !\n");
            }
            for (int i = 0; i < 45; i++)
            {
                Sleep(50);
                // printf("\n");
                printf("%c", a);
            }
            printf("\nBan Da Cuoc Tai Vui Long Cho Ket Qua : ");
            // tgian ch? k?t qu?
            for (int i = 0; i < 5; i++)
            {
                Sleep(300);
                printf("%c", c);
            }
            int result = result_random();
            if (result >= 11 && result <= 17)
            {
                printf("\n=>> Ket Qua : Tai");
                if (option == 1)
                {
                    printf("\n=>> Chuc Mung Ban Da Thang ");
                    money += tienCuoc;
                    printf("\n=>> So Tien Hien Tai Cua Ban La : %d", money);
                }
            }
            else if (result >= 4 && result <= 10)
            {
                printf("\n=>> Ket Qua : Xiu");
                printf("\n=>> Ban Da Thua, Chuc Ban May Man Lan Sau ");
                money -= tienCuoc;
                printf("\n=>> So Tien Hien Tai Cua Ban La : %d", money);
                if (money == 0)
                {
                    exit(0);
                }
            }
            else
            {
                printf("\nBi Lua Roi Nha !");
            }
            break;
        }
        case 2:
        {
            printf("\nNhap So Tien Cuoc(Toi Thieu 10000) : ");
            scanf("%d", &tienCuoc);
            if (tienCuoc > money || tienCuoc < 10000)
            {
                printf("\n=>> Ban Khong Du Tien Choi !");
                exit(0);
            }
            else
            {
                printf("\n=>> So Tien Con Lai Sau Khi Cuoc : %d", money - tienCuoc);
                printf("\n");
                for (int i = 0; i < 45; i++)
                {
                    Sleep(50);
                    printf("%c", a);
                }
                printf("\n=>> BAN DA VAO GAME !\n");
            }
            for (int i = 0; i < 45; i++)
            {
                Sleep(50);
                // printf("\n");
                printf("%c", a);
            }
            printf("\nBan Da Cuoc Xiu Vui Long Cho Ket Qua : ");
            // tgian ch? k?t qu?
            for (int i = 0; i < 5; i++)
            {
                Sleep(300);
                printf("%c", c);
            }

            int result = result_random();
            if (result >= 4 && result <= 10)
            {
                printf("\n=>> Ket Qua : Xiu");
                if (option == 2)
                {
                    printf("\n=>> Chuc Mung Ban Da Thang  ");
                    money += tienCuoc;
                    printf("\n=>> So Tien Hien Tai Cua Ban La : %d\n", money);
                }
            }
            else if (result >= 11 && result <= 17)
            {
                printf("\n=>> Ket Qua : Tai");
                printf("\n=>> Ban Da Thua, Chuc Ban May Man Lan Sau ");
                money -= tienCuoc;
                printf("\n=>> So Tien Hien Tai Cua Ban La : %d", money);
                if (money == 0)
                {
                    exit(0);
                }
            }
            else
            {
                printf("\nBi Lua Roi Nha !\n");
            }
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
            printf("\n=>> Ban Chon Khong Dung, Vui Long Chon Lai !");
        }
        printf("\n");
        for (int i = 0; i < 45; i++)
        {
            Sleep(50);
            printf("%c", a);
        }
        printf("\n=>>Nhap so bat ki de tiep tuc. Nhap 0 de thoat : ");
        scanf("%d", &luaChon);
    } while (luaChon != 0);
}

// hàm b?n quy?n
void byCopyright()
{
    int ki_tu = 64;
    printf("%c BY COPYRIGHT : NGUYEN MANH CUONG", ki_tu);
    printf("\n");
    for (int i = 0; i < 45; i++)
    {
        int a = 5;
        Sleep(50);
        printf("%c", a);
    }
    printf("\nChoi Game Qua 180p Moi Ngay Co Anh Huong Cho Suc Khoe !");
}

// hàm chính
int main()
{
    system("color 2"); // thay d?i màu s?c ch? trên màn hình console
    // l?i g?i hàm
    byCopyright();
    checkAgeUser();
    processing();
    return 0;
}
