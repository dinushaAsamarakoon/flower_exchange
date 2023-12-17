//
// Created by Dinusha Samarakoon on 12/16/2023.
//

#ifndef FLOWEREXCHANGE_ORDERBOOK_H
#define FLOWEREXCHANGE_ORDERBOOK_H

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include "InputOrder.h"

using namespace std;

class OrderBook {
public:
    static OrderBook& getInstance(Instrument instrument) {
        auto it = instances.find(instrument);
        if (it != instances.end()) {
            return *it->second;
        } else {
            auto* instance = new OrderBook(instrument);
            instances[instrument] = static_cast<const shared_ptr<OrderBook>>(instance);
            return *instance;
        }
    }

    // Delete copy constructor and assignment operator
    OrderBook(const OrderBook&) = delete;
    OrderBook& operator=(const OrderBook&) = delete;
    void addOrder(const InputOrder& order);
    void matchSellOrder(InputOrder& order, InputOrder& sellOrder);
    const vector<InputOrder> &getBuyOrders() const;

    const vector<InputOrder> &getSellOrders() const;

private:
    explicit OrderBook(Instrument instrument);

    static map<Instrument, shared_ptr<OrderBook>> instances;
    Instrument instrument;
    vector<InputOrder> buyOrders;
    vector<InputOrder> sellOrders;
};


#endif //FLOWEREXCHANGE_ORDERBOOK_H
