//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Timer.hpp"
#include <utility>
#include <stdexcept>

namespace Chronos {

    Timer::Timer(std::string name) : name(std::move(name)), is_measuring(false) {}

    Timer::~Timer() = default;

    void Timer::start() {
        is_measuring = true;
        start_time = std::chrono::steady_clock::now();
    }

    void Timer::stop_timer() {
        end_time = std::chrono::steady_clock::now();
        elapsed_seconds = end_time - start_time;
        is_measuring = false;
        std::cout << "Timer named " << name << " measured " << elapsed_seconds.count() << " s\n";
    }

    std::string Timer::get_name() {
        return name;
    }

    void Timer::pause() {
        if (is_measuring) {
            end_time = std::chrono::steady_clock::now();
            elapsed_seconds += end_time - start_time;
            is_measuring = false;
        } else {
            throw std::runtime_error(
                    std::string("Cannot pause Timer named ") + name + std::string(" because is not measuring!\n"));
        }
    }

    void Timer::resume() {
        if (!is_measuring) {
            is_measuring = true;
            start_time = std::chrono::steady_clock::now();
        } else {
            throw std::runtime_error(
                    std::string("Cannot resume Timer named ") + name + std::string(" because is measuring!\n"));
        }
    }

    void Timer::reset() {

    }
}