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
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::time_point<std::chrono::steady_clock> end_time;
        std::chrono::duration<double> elapsed_seconds;
        bool is_measuring;

    public:
        explicit Timer(std::string name);

        ~Timer();

        void start();

        void stop_timer();

        void pause();

        void resume();

        void reset();

        std::string get_name();

        void print_elapsed_time();
    };
}

#endif //CHRONOS_TIMER_HPP
