#pragma once
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <fmt/color.h>
#include <fmt/core.h>
#include <list>
#include <string>
#include <string_view>
#include <vector>

namespace athes::utils {
using Clock      = std::chrono::high_resolution_clock;
using TimePoint  = typename Clock::time_point;
using TimePoints = typename std::vector<std::pair<std::string, utils::TimePoint>>;

TimePoint now();
double elapsled(TimePoint start, TimePoint stop);
double elapsled(TimePoint tp);

void read_from_stdin(std::vector<uint8_t>& file);

std::string get_unit(std::list<std::string> const& units, double& value, double factor = 1024);
std::string fmt_unit(std::list<std::string> const& units, double value, double factor = 1024);

enum class LogLevel : int {
    CRITICAL = 50,
    ERROR    = 40,
    WARNING  = 30,
    INFO     = 20,
    DEBUG    = 10,
    NOTSET   = 0,
};
}
