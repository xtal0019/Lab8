#include "sorting.h"
#include <cstring> 


long to_seconds(time_ t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}


long get_duration(participant_inf* s) {
    long start_sec = to_seconds(s->start);
    long finish_sec = to_seconds(s->finish);
    return finish_sec - start_sec;
}


bool need_swap(participant_inf* a, participant_inf* b, int mode) {
    if (mode == 1) {
        // Критерий 1: По возрастанию времени забега
        return get_duration(a) > get_duration(b);
    }
    else if (mode == 2) {
        // Критерий 2: По названию клуба, затем по фамилии
        int club_cmp = strcmp(a->club, b->club);

        // Если первый клуб "больше" по алфавиту
        if (club_cmp > 0) return true;

        // Если клубы одинаковые, сравниваем фамилии
        if (club_cmp == 0) {
            return strcmp(a->marathon_runner.last_name, b->marathon_runner.last_name) > 0;
        }
    }
    return false;
}



void bubble_sort(participant_inf* array[], int size, int mode) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (need_swap(array[j], array[j + 1], mode)) {
                participant_inf* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void quick_sort(participant_inf* array[], int low, int high, int mode) {
    if (low < high) {
        participant_inf* pivot = array[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {

            if (!need_swap(array[j], pivot, mode)) {
                i++;
                participant_inf* temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        participant_inf* temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;

        quick_sort(array, low, pi - 1, mode);
        quick_sort(array, pi + 1, high, mode);
    }
}