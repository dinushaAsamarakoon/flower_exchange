//
// Created by Dinusha Samarakoon on 12/16/2023.
//

#include <iostream>
#include "InputOrder.h"

using namespace std;

InputOrder::InputOrder(const string &clientOrderId, const Instrument &instrumentType, const Side &side,
                       const int &price, const int &quantity)
        : clientOrderId{clientOrderId}, instrumentType{instrumentType}, side{side}, price{price}, quantity{quantity} {

}

Instrument &InputOrder::getInstrumentType() {
    return this->instrumentType;
}

Side InputOrder::getSide() const {
    return side;
}

int InputOrder::getPrice() const {
    return price;
}

int InputOrder::getQuantity() const {
    return quantity;
}

