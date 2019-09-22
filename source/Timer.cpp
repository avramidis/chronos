//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Timer.hpp"

namespace Chronos {

    Timer::Timer() : start(std::chrono::steady_clock::now()) {}

    Timer::~Timer() {}

    void Timer::stop_timer() {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds  = end - start;
        std::cout << "Timer " << elapsed_seconds .count() << " s\n";
    }
}