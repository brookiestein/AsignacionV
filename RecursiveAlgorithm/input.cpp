#include "input.hpp"

#include <iostream>
#include <print>

std::string Input::input(const std::string &message,
                         const std::string &errorMessage)
{
    std::string str {};

    while (true) {
        std::print("{}: ", message);
        std::getline(std::cin, str);

        if (str.empty()) {
            std::println(stderr, "{}", errorMessage);
            continue;
        }

        break;
    }

    return str;
}
