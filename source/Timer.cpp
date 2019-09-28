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
        if (!is_measuring) {
            is_measuring = true;
            start_time = std::chrono::steady_clock::now();
        } else {
            throw std::runtime_error(
                    std::string("Cannot start Timer named ") + name + std::string(" because is measuring!\n"));
        }
    }

    void Timer::stop_timer(bool print_elapsed_time) {
        if (is_measuring) {
            end_time = std::chrono::steady_clock::now();
            elapsed_seconds += end_time - start_time;
            is_measuring = false;
            if (print_elapsed_time) {
                std::cout << "Timer named " << name << " measured " << elapsed_seconds.count() << " s\n";
            }
        } else {
            throw std::runtime_error(
                    std::string("Cannot stop Timer named ") + name + std::string(" because is not measuring!\n"));
        }
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
        if (!is_measuring) {
            elapsed_seconds = std::chrono::duration<double>::zero();
        } else {
            throw std::runtime_error(
                    std::string("Cannot rest Timer named ") + name + std::string(" because is measuring!\n"));
        }
    }

    void Timer::print_elapsed_time() {
        if (!is_measuring) {
            std::cout << "Timer named " << name << " measured " << elapsed_seconds.count() << " s\n";
        } else {
            throw std::runtime_error(
                    std::string("Cannot print elapsed time of Timer named ") + name +
                    std::string(" because is measuring!\n"));
        }
    }
}