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
    {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},//4
    {"Счётчик:"}//5
};
void setcur(int x, int y)//установка курсора на позицию  x y 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void PathNext() {
    if ((rand() % 100 + 0) < 20) {
        if(matrix[3][14-1] != "|" && matrix[3][14-2] != "|" && matrix[3][14 - 3] != "|")
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
    if (matrix[3][0] == "$" && matrix[3][1] == "|") {
        exit(-1);
    }
    for (int i = 0; i < 6; i++) {
        cout << endl;
        for(int j = 0; j < 15;j++)
            cout << matrix[i][j];
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int counter = 0;
    bool flag = false;
    int timesec = 400;
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
                Sleep(timesec);
                setcur(0, 0);
                PringMatrix();
            }
            for (int i = 1; i < 3; i++) {
                matrix[i][0] = " ";
                matrix[i + 1][0] = "$";
                Sleep(timesec);
                setcur(0, 0);
                PringMatrix();
            }
        }
        if (!flag) 
        {
            Sleep(timesec);
            setcur(0, 0);
            PathNext();
            PringMatrix();
        }
        counter++;
        matrix[5][1] = to_string(counter);
        flag = false;
        //Sleep(1000);
        //system("cls");
    }
}
