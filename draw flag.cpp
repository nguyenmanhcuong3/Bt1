#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>
using namespace std;
void loading()
{
	char a =3;
    cout << "\n\t\t\t\t\tLoading...\n\n";
    cout << "\t\t\t\t\t";
    for (int i=0; i<26; i++)
    {
        cout << a;
        Sleep(100);
    }
    cout << "\nDa load xong!!!";
    Sleep(500);
    system("cls");
    system("color F");
}

int main ()
{
	system("color 3");	
    //cout << "Nhan Enter de bat dau...";
    //cin.ignore();
    loading();
    fstream newfile;
    newfile.open("input2.txt", ios::in);
    if(newfile.is_open())
    {
    	system("color 3");
        string tp;
        while(getline(newfile, tp))
        {
            cout << tp << endl;
            Sleep(300);
        }
        newfile.close();
    }
    system("pause");
    return 0;
}
