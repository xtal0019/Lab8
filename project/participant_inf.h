#pragma once
#ifndef PARTICIPANT_INF_H
#define PARTICIPANT_INF_H

#include "constants.h"

struct time_
{
    int hour;
    int minutes;
    int seconds;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct participant_inf
{
    int numb;
    person reader;
    time_ start;
    time_ finish;
    char club[MAX_STRING_SIZE];
};

#endif