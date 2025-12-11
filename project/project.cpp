#include <iostream>
#include "sorting.h"

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
        cout << array_to_print[i]->marathon_runner.last_name << ' ';
        cout << array_to_print[i]->marathon_runner.first_name[0] << ". ";
        cout << array_to_print[i]->marathon_runner.middle_name[0] << ".\n";
        cout << "Время старта: ";
        cout << array_to_print[i]->start.hours << ':';
        cout << array_to_print[i]->start.minutes << ':';
        cout << array_to_print[i]->start.seconds << '\n';
        cout << "Время финиша: ";
        cout << array_to_print[i]->finish.hours << ':';
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
        cout << "3. Bubble Sort - по времени забега\n";
        cout << "4. Bubble Sort - по Клубу и Фамилии\n";
        cout << "5. Quick Sort  - по времени забега\n";
        cout << "6. Quick Sort  - по Клубу и Фамилии\n";
        cout << "7. Вывести всех участников\n";
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
            bubble_sort(partic, size, 1);
            break;
        case 4:
            bubble_sort(partic, size, 2);
            break;
        case 5:
            quick_sort(partic, 0, size - 1, 1);
            break;
        case 6:
            quick_sort(partic, 0, size - 1, 2);
            break;

        case 7:
            break;

        default:
            cout << "Неверный выбор. Действие не выполнено.\n";
        }

        cout << "\n***** РЕЗУЛЬТАТЫ МАРАФОНА *****\n\n";

        print_runners(array_to_print, size_to_print);

        if (filtered_list != nullptr) {
            delete[] filtered_list;
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