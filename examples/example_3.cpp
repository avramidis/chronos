//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Chronos.hpp"
#include <iostream>
#include <thread>

int main() {
    std::cout << "Running example_3" << std::endl;

    Chronos::Timers timers;
    timers.add_timer("timer1");
    timers.add_timer("timer2");

    timers.get_timer("timer1").start();
    timers.get_timer("timer2").start();

    for (int i = 0; i < 5; i++) {
        std::cout << "Loop 1 iteration " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    timers.get_timer("timer1").pause();

    for (int i = 0; i < 10; i++) {
        std::cout << "Loop 2 iteration " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    timers.get_timer("timer1").resume();

    for (int i = 0; i < 5; i++) {
        std::cout << "Loop 1 iteration " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    timers.stop_timers();
    timers.print_timers_elapsed_time();

    return 0;
}