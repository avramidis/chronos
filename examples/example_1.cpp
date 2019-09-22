//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include <iostream>
#include "Timer.hpp"

int main() {
    std::cout << "Running example_1" << std::endl;

    Chronos::Timer timer;

    for (int i = 0; i < 100000; i++) {
        std::cout << "Hello from example_1\n";
    }

    timer.stop_timer();

    return 0;
}