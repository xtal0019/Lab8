#pragma once
#ifndef MARATHON_FILTERS_H
#define MARATHON_FILTERS_H

#include "participant_inf.h"


participant_inf** filterRunners(
    participant_inf* array[],
    int size,
    bool (*check)(participant_inf* element),
    int& result_size
);

bool isFromSpartakClub(participant_inf* marathon_runner);
bool hasResultBetterThan250(participant_inf* marathon_runner);

#endif

