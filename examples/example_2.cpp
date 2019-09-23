//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include <iostream>
#include "Timers.hpp"

int main() {
    std::cout << "Running example_1" << std::endl;

    Chronos::Timers timers;
    timers.add_timer("timer1");
    timers.add_timer("timer2");


    timers.get_timer("timer1").start_timer();
    timers.get_timer("timer2").start_timer();

    for (int i = 0; i < 100000; i++) {
        std::cout << "Hello from example_1\n";
    }

    timers.get_timer("timer2").stop_timer();

    for (int i = 0; i < 10000; i++) {
        std::cout << "Hello from example_1\n";
    }

    timers.get_timer("timer1").stop_timer();

    return 0;
}