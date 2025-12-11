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
        cout << "***** Марафон *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Номер участника: ";
            cout << partic[i]->numb << '\n';
            cout << "Участник: ";
            cout << partic[i]->reader.last_name << ' ';
            cout << partic[i]->reader.first_name[0] << ". ";
            cout << partic[i]->reader.middle_name[0] << ".\n";
            cout << "Время старта: ";
            cout << partic[i]->start.hour << ':';
            cout << partic[i]->start.minutes << ':';
            cout << partic[i]->start.seconds << '\n';
            cout << "Время финиша: ";
            cout << partic[i]->finish.hour << ':';
            cout << partic[i]->finish.minutes << ':';
            cout << partic[i]->finish.seconds << '\n';
            cout << "Название клуба: ";
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