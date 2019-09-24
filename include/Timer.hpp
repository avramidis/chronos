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
#include <string>

namespace Chronos {
    class Timer {
    private:
        std::string name;
        std::chrono::time_point<std::chrono::steady_clock> start;
        std::chrono::time_point<std::chrono::steady_clock> end;
        std::chrono::duration<double> elapsed_seconds;

    public:
        explicit Timer(std::string name);

        ~Timer();

        void start_timer();

        void stop_timer();
    };
}

#endif //CHRONOS_TIMER_HPP
