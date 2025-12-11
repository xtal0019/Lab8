#ifndef SORTING_H
#define SORTING_H
#include "participant_inf.h"

// Прототипы функций сортировки

// Пузырьковая сортировка
// mode 1 = по времени, mode 2 = по клубу и фамилии
void bubble_sort(participant_inf* array[], int size, int mode);

// Быстрая сортировка
// mode 1 = по времени, mode 2 = по клубу и фамилии
void quick_sort(participant_inf* array[], int low, int high, int mode);

//Время забега
long get_duration(participant_inf* s);
#endif