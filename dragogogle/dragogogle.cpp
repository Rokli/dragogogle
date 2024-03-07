// dragogogle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <windows.h>
#include <iostream>
using namespace std;
string matrix[][15]{
    {"------------------------"},//0
    {},//1
    {},//2
    {"$"},//3
    {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",},//4
};
void PringMatrix() {
    for (int i = 0; i < 5; i++) {
        cout << endl;
        for(int j = 0; j < 15;j++)
            cout << matrix[i][j];
    }
}
int main()
{
    while (1) {
        if (GetKeyState('W')) {
            matrix[3][0] = "";
            string tmp = "$";
            for (int i = 3; i > 1; i--) {
                matrix[i][0] = "";
                matrix[i-1][0] = "";
            }
            for (int i = 1; i < 3; i++) {

            }

        }
        PringMatrix();
        Sleep(1000);
        system("cls");
    }
}
