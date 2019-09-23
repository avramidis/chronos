//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Timers.hpp"
#include <stdexcept>

namespace Chronos {

    Timers::Timers() = default;

    Timers::~Timers() = default;

    void Timers::add_timer(const std::string &name) {
        auto search = timers.find(name);

        if (search != timers.end()) {
            throw std::invalid_argument(std::string("Timer named ") + name + std::string(" already exists!\n"));
        } else {
            timers.insert(std::pair<std::string, Timer>(name, Timer(name)));
        }
    }

    Timer Timers::get_timer(const std::string &name) {
        auto search = timers.find(name);

        if (search != timers.end()) {
            return search->second;
        } else {
            throw std::invalid_argument(std::string("Timer named ") + name + std::string(" was not found!\n"));
        }
    }
}

