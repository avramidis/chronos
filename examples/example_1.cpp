//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Timer.hpp"
#include <thread>

int main() {
    std::cout << "Running example_1" << std::endl;

    Chronos::Timer timer("timer1");

    timer.start();

    for (int i = 0; i < 5; i++) {
        std::cout << "Loop iteration " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    timer.stop_timer();
    timer.print_elapsed_time();

    return 0;
}