//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include <iostream>
#include "Timers.hpp"
#include <thread>

int main() {
    std::cout << "Running example_2" << std::endl;

    Chronos::Timers timers;
    timers.add_timer("timer1");
    timers.add_timer("timer2");

    timers.get_timer("timer1").start();
    timers.get_timer("timer2").start();

    for (int i = 0; i < 5; i++) {
        std::cout << "Loop 1 iteration " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    timers.get_timer("timer2").stop_timer(true);

    for (int i = 0; i < 10; i++) {
        std::cout << "Loop 2 iteration " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    timers.get_timer("timer1").stop_timer(true);

    return 0;
}