#include "filter.h"
#include <iostream>


participant_inf** filterRunners(
    participant_inf* array[],
    int size,
    bool (*check)(participant_inf* element),
    int& result_size
) {

    participant_inf** result = new participant_inf * [size];
    result_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (check(array[i]))
        {
            result[result_size++] = array[i];
        }
    }
    return result;
}


bool isFromSpartakClub(participant_inf* runner) {
    return strcmp(runner->club, "Спартак") == 0;
}


bool hasResultBetterThan250(participant_inf* runner) {

    int start_sec = runner->start.hours * 3600 + runner->start.minutes * 60 + runner->start.seconds;
    int finish_sec = runner->finish.hours * 3600 + runner->finish.minutes * 60 + runner->finish.seconds;


    int totalSeconds = finish_sec - start_sec;
    int limitSeconds = 2 * 3600 + 50 * 60;

    return totalSeconds < limitSeconds;
}