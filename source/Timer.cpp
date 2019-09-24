//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Timer.hpp"
#include <utility>

namespace Chronos {

    Timer::Timer(std::string name) : name(std::move(name)) {}

    Timer::~Timer() = default;

    void Timer::start_timer() {
        start = std::chrono::steady_clock::now();
    }

    void Timer::stop_timer() {
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Timer named " << name << " measured " << elapsed_seconds.count() << " s\n";
    }
}