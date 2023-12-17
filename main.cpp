#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "./enums/Side.h"
#include "classes/InputOrder.h"
#include "classes/ExecutionRecord.h"
#include "classes/OrderBook.h"
#include <cstdlib>
#include <ctime>

Instrument convertToInstrument(const string &instrumentString);

Side convertToSide(const string &sideString);

int validatePrice(const string &priceStr);

int validateQuantity(const string &quantityStr);

string generateUniqueID();

vector<InputOrder> readCSV(const string &filename);

using namespace std;

int main() {
    vector<InputOrder> orders = readCSV("order1.csv");
    for(InputOrder order: orders){
        OrderBook& book = OrderBook::getInstance(order.getInstrumentType());

    }

    return 0;
}

vector<InputOrder> readCSV(const string &filename) {
    vector<InputOrder> orders;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        // Skip the header line
        getline(file, line);

        while (getline(file, line)) {
            //unique order id
            string orderId = generateUniqueID();
            stringstream ss(line);
            string clientOrderId, instrumentTypeStr, sideStr, quantityStr, priceStr;

            getline(ss, clientOrderId, ',');
            getline(ss, instrumentTypeStr, ',');
            getline(ss, sideStr, ',');
            getline(ss, quantityStr, ',');
            getline(ss, priceStr, ',');
            Instrument instrumentType;
            Side side;
            int quantity;
            int price;
            try {
                instrumentType = convertToInstrument(instrumentTypeStr);
                side = convertToSide(sideStr);
                quantity = validateQuantity(quantityStr);
                price = validatePrice(priceStr);

                orders.push_back(InputOrder(clientOrderId, instrumentType, side, price, quantity));
            } catch (exception &e) {
                ExecutionRecord record (
                        InputOrder(clientOrderId, instrumentType, side, price, quantity), orderId, Status::REJECTED, e.what(),
                        chrono::system_clock::now());
                cout << "Caught an exception: " << e.what() << '\n';
            }

        }
    }

    return orders;
}


int validatePrice(const string &priceStr) {
    int p = stoi(priceStr);
    if (p > 0) return p;
    throw runtime_error("invalid price!");
}

int validateQuantity(const string &quantityStr) {
    int q = stoi(quantityStr);
    if (q % 10 == 0 && q >= 10 && q <= 1000) return q;
    throw runtime_error("invalid quantity");
}

Side convertToSide(const string &sideString) {
    int side = stoi(sideString);
    switch (side) {
        case 1:
            return Side::BUY;
        case 2:
            return Side::SELL;
        default:
            throw runtime_error("Side not matching!");
    }
}

Instrument convertToInstrument(const string &instrumentString) {
    if (instrumentString == "Rose") {
        return Instrument::ROSE;
    } else if (instrumentString == "Lavender")
        return Instrument::LAVENDER;
    else if (instrumentString == "Lotus")
        return Instrument::LOTUS;
    else if (instrumentString == "Tulip")
        return Instrument::TULIP;
    else if (instrumentString == "Orchid")
        return Instrument::ORCHID;
    else
        throw runtime_error("Instrument type not matching!");
}

string generateUniqueID() {
    srand(time(0)); // use current time as seed for random generator
    std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int len = 10; // Length of the unique ID

    std::string uniqueID;

    for (int i = 0; i < len; i++) {
        uniqueID += str[rand() % str.size()];
    }

    return uniqueID;
}