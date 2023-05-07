//code chan le

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int age;             // bien tuoi
char c = 175, d = 5; // bien ki tu trong bang ma ascii

// hàm ki?m tra d? tu?i
void checkAge(int age)
{
    for (int i = 0; i <= 49; i++)
    {
        Sleep(50); // ham tgian cho ket qua
        printf("%c", d);
    }
    printf("\nNhap tuoi cua ban : ");
    scanf("%d", &age);
    // kiem tra dieu kien tuoi
    if (age < 18)
    {
        printf(">>> Ban khong du tuoi choi !");
        exit(0);
    }
    else
    {
        printf(">>> BAN DA VAO GAME !\n");
        for (int i = 0; i <= 49; i++)
        {
            Sleep(50);
            printf("%c", d);
        }
    }
}

// ham random xuc sac
int randomDice(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

// ham xu li random va ket qua
void processing()
{
    int dice, option, lua_Chon;
    int money = 5000000, tienCuoc;
    do
    {
    	system("cls");
        // tao menu
        printf("\n================== MOI BAN CHON ==================");
        printf("\n\t\t(1). Nhan 1 De Chon Le ");
        printf("\n\t\t(2). Nhan 2 De Chon Chan ");
        printf("\n\t\t(0). Thoat ");
        printf("\n==================================================");
        printf("\n>>> Moi Ban Nhap Lua Chon : ");
        scanf("%d", &option);

        // xu li ket qua neu nguoi choi chon le
        switch (option)
        {
        case 1:
        {

            if (option == 1)
            {
                for (int i = 0; i <= 49; i++)
                {
                    Sleep(50);
                    printf("%c", d);
                }
                printf("\n>>> So Tien Hien Tai Cua Ban La : %d", money);
                printf("\n>>> Moi Ban Nhap Tien Cuoc : ");
                scanf("%d", &tienCuoc);
                printf(">>> So tien con lai sau khi cuoc la : %d", money - tienCuoc);
                printf("\n>>> Ban Da Cuoc Le, Vui Long Cho Ket Qua : ");
                for (int i = 0; i < 5; i++)
                {
                    Sleep(500); // ham tgian cho ket qua
                    printf("%c", c);
                }
                srand((int)time(0));
                for (int i = 1; i <= 6; i++)
                {

                    dice = randomDice(1, 6);
                    dice %= 10;
                }
                printf("\n>>> Ket Qua Sau Khi Random : %d", dice);
                // kiem tra sau khi chon le va cho nguoi choi biet thang hay thua
                if (dice % 2 != 0)
                {
                    printf("\n>>> Ket Qua : Le");
                    printf("\n>>> Chuc Mung Ban Da Thang ");
                    money += tienCuoc;
                    printf("\n>>> So Tien Hien Tai Cua Ban La : %d", money);
                }
                else
                {
                    printf("\n>>> Ket Qua : Chan");
                    printf("\n>>> Ban Da Thua, Chuc Ban May Man Lan Sau !");
                    money -= tienCuoc;
                    printf("\n>>> So tien hien tai cua ban la : %d", money);
                    if (money == 0)
                        exit(0);
                }
            }
            break;
        }
        case 2: // xu li ket qua neu nguoi choi chon chan
        {
            if (option == 2)
            {
                for (int i = 0; i <= 49; i++)
                {
                    Sleep(50);
                    printf("%c", d);
                }
                printf("\n>>> So Tien Hien Tai Cua Ban La : %d", money);
                printf("\n>>> Moi Ban Nhap Tien Cuoc : ");
                scanf("%d", &tienCuoc);
                printf(">>> So tien con lai sau khi cuoc la : %d", money - tienCuoc);
                printf("\n>>> Ban Da Cuoc Chan, Vui Long Cho Ket Qua : ");
                for (int i = 0; i < 5; i++)
                {
                    Sleep(500); // ham tgian cho ket qua
                    printf("%c", c);
                }
                srand((int)time(0));
                for (int i = 1; i <= 6; i++)
                {

                    dice = randomDice(1, 6);
                    dice %= 10;
                }
                printf("\n>>> Ket Qua Sau Khi Random : %d", dice);
            }

            // xu li ket qua sau khi nguoi choi chon chan va cho nguoi choi biet thang hay thua
            if (dice % 2 == 0)
            {
                printf("\n>>> Ket Qua : Chan");
                printf("\n>>> Chuc mung ban da thang");
                money += tienCuoc;
                printf("\n>>> So tien hien tai cua ban la : %d", money);
            }
            else
            {
                printf("\n>>> Ket Qua : Le");
                printf("\n>>> Ban Da Thua, Chuc Ban May Man Lan Sau !");
                money -= tienCuoc;
                printf("\n>>> So tien hien tai cua ban la : %d", money);
                if (money == 0)
                    exit(0);
            }
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        }
        printf("\n");
        for (int i = 0; i <= 49; i++)
        {
            Sleep(50);
            printf("%c", d);
        }
        printf("\n>>> Nhan so bat ki de tiep tuc choi. Nhan 1 de thoat : ");
        scanf("%d", &lua_Chon);
    } while (lua_Chon != 1);
}
int main()
{
    system("color 2"); // thay doi mau sac
    checkAge(age);
    processing();
    return 0;
}
