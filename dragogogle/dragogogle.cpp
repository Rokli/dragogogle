// dragogogle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <random>
using namespace std;
string matrix[][15]{
    {"----------------"},//0
    {},//1
    {},//2
    {"$"," "," "," "," "," "," "," "," "," "," "," "," "," "},//3
    {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"}//4
};
void PathNext() {
    if ((rand() % 100 + 0) < 20) {
        if(matrix[3][14-1] != "|" && matrix[3][14-2] != "|")
                matrix[3][14] = "|";
    }
    for (int i = 1; i < 14; i++) {
        matrix[3][i] = matrix[3][i + 1];
        matrix[3][i + 1] = " ";
        matrix[4][i] = matrix[4][i + 1];
    }
}
void PringMatrix() {
    PathNext();
    for (int i = 0; i < 5; i++) {
        cout << endl;
        for(int j = 0; j < 15;j++)
            cout << matrix[i][j];
    }
}
int main()
{
    bool flag = false;
    srand(time(0));
    PringMatrix();
    while (1) {
        if (GetAsyncKeyState('W') & 0x8000) {
            flag = true;
            matrix[3][0] = " ";
            string tmp = "$";
            for (int i = 3; i > 1; i--) {
                matrix[i][0] = " ";
                matrix[i-1][0] = "$";
                Sleep(1000);
                system("cls");
                PringMatrix();
            }
            for (int i = 1; i < 3; i++) {
                matrix[i][0] = " ";
                matrix[i + 1][0] = "$";
                Sleep(1000);
                system("cls");
                PringMatrix();
            }
        }
        if (!flag) 
        {
            Sleep(1000);
            system("cls");
            PathNext();
            PringMatrix();
        }
        flag = false;
        //Sleep(1000);
        //system("cls");
    }
}
