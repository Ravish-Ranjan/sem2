#ifndef COMMAND_CPP
#define COMMAND_CPP

#include <string>
#include <cstdio>
#include <array>
#include <memory>
#include <iostream>

std::string runCommand(std::string cmd) {
    std::array<char, 256> buffer;
    std::string result;

    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen failed");

    while (fgets(buffer.data(), buffer.size(), pipe)) {
        result += buffer.data();
    }

    pclose(pipe);

    if (!result.empty() && result.back() == '\n')
        result.pop_back();

    return result;
}

#endif