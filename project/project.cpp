#include <iostream>

using namespace std;

#include "participant_inf.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void print_runners(participant_inf** array_to_print, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "Номер участника: ";
        cout << array_to_print[i]->numb << '\n';
        cout << "Участник: ";
        cout << array_to_print[i]->reader.last_name << ' ';
        cout << array_to_print[i]->reader.first_name[0] << ". ";
        cout << array_to_print[i]->reader.middle_name[0] << ".\n";
        cout << "Время старта: ";
        cout << array_to_print[i]->start.hour << ':';
        cout << array_to_print[i]->start.minutes << ':';
        cout << array_to_print[i]->start.seconds << '\n';
        cout << "Время финиша: ";
        cout << array_to_print[i]->finish.hour << ':';
        cout << array_to_print[i]->finish.minutes << ':';
        cout << array_to_print[i]->finish.seconds << '\n';
        cout << "Название клуба: ";
        cout << array_to_print[i]->club << '\n';
        cout << '\n';
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №1\n";
    cout << "Автор: Петровский Дмитрий\n";
    cout << "Группа: 25пинж1д\n\n";
    participant_inf* partic[MAX_FILE_ROWS_COUNT];
    int size = 0;
    participant_inf** array_to_print = partic;
    participant_inf** filtered_list = nullptr;
    int size_to_print = 0;
    try
    {
        read("data.txt", partic, size);
        size_to_print = size;

        cout << "Выберите фильтр:\n";
        cout << "1. Фильтр на участников клуба \"Спартак\"\n";
        cout << "2. Фильтр на участников,чьё время забега 2:50:00 и меньше\n";
        cout << "3. Вывести всех участников\n";
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;

        switch (choice) {

        case 1:

            filtered_list = filterRunners(partic, size, isFromSpartakClub, size_to_print);
            array_to_print = filtered_list;
            break;

        case 2:
            filtered_list = filterRunners(partic, size, hasResultBetterThan250, size_to_print);
            array_to_print = filtered_list;
            break;

        case 3:
            break;

        default:
            cout << "Неверный выбор. Действие не выполнено.\n";
        }

        cout << "\n***** РЕЗУЛЬТАТЫ МАРАФОНА *****\n\n";

        print_runners(array_to_print, size_to_print);


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