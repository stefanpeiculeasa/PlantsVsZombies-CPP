#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>

class InvalidClickPosition final : public std::exception {
    std::string message = "Your click was out of bounds or on an invalid entity!";
    public:
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }

};

#endif
