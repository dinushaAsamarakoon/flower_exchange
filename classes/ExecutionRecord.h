//
// Created by Dinusha Samarakoon on 12/16/2023.
//
#include <string>
#include <chrono>
#include "../enums/Side.h"
#include "../enums/Instrument.h"
#include "../enums/Status.h"
#include "InputOrder.h"

using namespace std;

#ifndef FLOWEREXCHANGE_EXECUTIONREPORT_H
#define FLOWEREXCHANGE_EXECUTIONREPORT_H


class ExecutionRecord {
public:
    ExecutionRecord(const InputOrder &inputOrder, const string &orderId, const Status &status,
                    const string &reason,
                    const chrono::time_point<chrono::system_clock, chrono::nanoseconds> &timestamp);

private:
    InputOrder inputOrder;
    string orderId;
    Status status;
    string reason;
    chrono::system_clock::time_point timestamp;
};


#endif //FLOWEREXCHANGE_EXECUTIONREPORT_H
