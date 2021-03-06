//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CHRONOS_TIMER_HPP
#define CHRONOS_TIMER_HPP

#include "chronos_export.h"
#include <chrono>
#include <iostream>
#include <string>

namespace Chronos {
    class CHRONOS_EXPORT Timer {
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

        void stop_timer(bool print_elapsed_time);

        void pause();

        void resume();

        void reset();

        std::string get_name();

        void print_elapsed_time();
    };
} // namespace Chronos

#endif // CHRONOS_TIMER_HPP
