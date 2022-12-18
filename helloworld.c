#include <stdio.h>
#include <locale.h>
#include <windows.h>

int main(void) {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    //                |    |                   |
    printf("Привет мир");
}