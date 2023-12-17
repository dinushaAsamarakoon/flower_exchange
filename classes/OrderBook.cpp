//
// Created by Dinusha Samarakoon on 12/16/2023.
//

#include "OrderBook.h"
#include "../enums/Side.h"
#include "ExecutionRecord.h"

OrderBook::OrderBook(Instrument instrument) : instrument{instrument} {
    this->buyOrders = {};
    this->sellOrders = {};
}

void OrderBook::addOrder(const InputOrder &order) {
    if (order.getSide() == Side::BUY) {
        for (int i = 0; i < sellOrders.size(); i++) {
            InputOrder sellOrder = this->sellOrders[i];
            matchSellOrder(const_cast<InputOrder &>(order), sellOrder);
        }

    } else {
        for (int i = 0; i < buyOrders.size(); i++) {
            InputOrder buyOrder = this->buyOrders[i];
            matchSellOrder(const_cast<InputOrder &>(order), buyOrder);
        }
    }

}


const vector<InputOrder> &OrderBook::getBuyOrders() const {
    return buyOrders;
}

const vector<InputOrder> &OrderBook::getSellOrders() const {
    return sellOrders;
}

void OrderBook::matchSellOrder(InputOrder &order, InputOrder &sellOrder) {
    if (order.getPrice() >= sellOrder.getPrice()) {
        if (order.getQuantity() == sellOrder.getQuantity()){
            ExecutionRecord buyExecution(order, );
        }
    }
}


