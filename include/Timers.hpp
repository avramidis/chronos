//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CHRONOS_TIMERS_HPP
#define CHRONOS_TIMERS_HPP

#include "Timer.hpp"
#include "chronos_export.h"
#include <string>
#include <unordered_map>

namespace Chronos {
    class CHRONOS_EXPORT Timers {
      private:
        std::unordered_map<std::string, Timer> timers;

      public:
        Timers();

        ~Timers();

        void add_timer(const std::string &name);

        Timer &get_timer(const std::string &name);

        void stop_timers();

        void print_timers_elapsed_time();
    };
} // namespace Chronos

#endif // CHRONOS_TIMERS_HPP
