//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#define CATCH_CONFIG_MAIN

#include "Chronos.hpp"
#include "catch.hpp"

TEST_CASE("Test Timer exceptions") {
    Chronos::Timer timer("timer1");

    SECTION("stop timer") {
        timer.start();
        timer.stop_timer(false);
        CHECK_THROWS(timer.stop_timer(false));
    }

    SECTION("pause timer") {
        timer.start();
        timer.stop_timer(false);
        CHECK_THROWS(timer.pause());
    }

    SECTION("start timer") {
        timer.start();
        CHECK_THROWS(timer.start());
    }

    SECTION("resume timer") {
        timer.start();
        CHECK_THROWS(timer.resume());
    }

    SECTION("reset timer") {
        timer.start();
        CHECK_THROWS(timer.reset());
    }

    SECTION("print elapsed time") {
        timer.start();
        CHECK_THROWS(timer.print_elapsed_time());
    }
}