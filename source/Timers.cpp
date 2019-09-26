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

        std::pair<std::unordered_map<std::string, Timer>::iterator, bool> insert_check = timers.insert(
                std::pair<std::string, Timer>(name, Timer(name)));

        if (!insert_check.second) {
            throw std::invalid_argument(std::string("Timer named ") + name + std::string(" already exists!\n"));
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

    void Timers::stop_timers() {
        for (auto t:timers) {
            t.second.stop_timer(false);
        }
    }
}

