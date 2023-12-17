//
// Created by Dinusha Samarakoon on 12/17/2023.
//

#ifndef FLOWEREXCHANGE_EXECUTIONREPORT_H
#define FLOWEREXCHANGE_EXECUTIONREPORT_H


#include "ExecutionRecord.h"

class ExecutionRecord; // Forward declaration


class ExecutionReport {
public:
    ExecutionReport();
    void writeToFile(const string& filename);

private:
    ExecutionRecord* records;
};


#endif //FLOWEREXCHANGE_EXECUTIONREPORT_H
