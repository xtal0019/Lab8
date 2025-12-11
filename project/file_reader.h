#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

#include "participant_inf.h"

void read(const char* file_name, participant_inf* array[], int& size);

#endif