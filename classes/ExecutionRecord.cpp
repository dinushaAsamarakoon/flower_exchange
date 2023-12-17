//
// Created by Dinusha Samarakoon on 12/16/2023.
//
#include <chrono>
#include <iostream>
#include "ExecutionRecord.h"
#include "InputOrder.h"

using namespace std;


ExecutionRecord::ExecutionRecord(const InputOrder &inputOrder, const string &orderId, const Status &status,
                                 const string &reason,
                                 const chrono::time_point<chrono::system_clock, chrono::nanoseconds> &timestamp)
        : inputOrder{
        inputOrder}, orderId{orderId}, status{status}, reason{reason}, timestamp{timestamp} {

}
