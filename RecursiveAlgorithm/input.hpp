#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

class Input
{
public:
    Input() = delete;
    static std::string
    input(const std::string &message,
          const std::string &errorMessage = "You wrote nothing.");
};

#endif // INPUT_HPP
