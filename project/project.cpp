#include <iostream>

using namespace std;

#include "participant_inf.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №1\n";
    cout << "Автор: Петровский Дмитрий\n\n";
    participant_inf* partic[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", partic, size);
        for (int i = 0; i < size; i++)
        {
            cout << partic[i]->numb << '\n';
            cout << partic[i]->reader.last_name << '\n';
            cout << partic[i]->reader.first_name << '\n';
            cout << partic[i]->reader.middle_name << '\n';
            cout << partic[i]->start.hour << ' ';
            cout << partic[i]->start.minutes << ' ';
            cout << partic[i]->start.seconds << '\n';
            cout << partic[i]->finish.hour << ' ';
            cout << partic[i]->finish.minutes << ' ';
            cout << partic[i]->finish.seconds << '\n';
            cout << partic[i]->club << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete partic[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}