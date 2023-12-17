cmake_minimum_required(VERSION 3.26)
project(FlowerExchange)

set(CMAKE_CXX_STANDARD 20)

add_executable(FlowerExchange main.cpp
        classes/OrderBook.cpp
        classes/OrderBook.h
        enums/Instrument.h
        enums/Side.h
        classes/InputOrder.cpp
        classes/InputOrder.h
        classes/ExecutionRecord.cpp
        classes/ExecutionRecord.h
        enums/Status.h
        classes/ExecutionReport.cpp
        classes/ExecutionReport.h)
