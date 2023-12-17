//
// Created by Dinusha Samarakoon on 12/16/2023.
//

#include <iostream>
#include <string>
#include "../enums/Side.h"
#include "../enums/Instrument.h"

using namespace std;

#ifndef FLOWEREXCHANGE_INPUTORDER_H
#define FLOWEREXCHANGE_INPUTORDER_H


class InputOrder {
public:
    InputOrder() = default;
    InputOrder(const string &clientOrderId, const Instrument &instrumentType, const Side &side,
               const int &price, const int &quantity);
    Instrument& getInstrumentType();

    Side getSide() const;

    int getPrice() const;

    int getQuantity() const;

private:
    string clientOrderId;
    Instrument instrumentType;
    Side side;
    int price{};
    int quantity{};

};


#endif //FLOWEREXCHANGE_INPUTORDER_H
