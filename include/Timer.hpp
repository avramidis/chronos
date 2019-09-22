//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CHRONOS_TIMER_HPP
#define CHRONOS_TIMER_HPP

#include <iostream>
#include <chrono>

namespace Chronos {
    class Timer {
    private:
        std::chrono::time_point<std::chrono::steady_clock> start;
    public:
        Timer();

        ~Timer();

        void stop_timer();
    };
}

#endif //CHRONOS_TIMER_HPP
