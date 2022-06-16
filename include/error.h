#pragma once

#include <iostream>
#include <string_view>
#include <stdexcept>

#include "token.h"

extern bool hasError;
extern bool hasRuntimeError;

class RuntimeError : public std::runtime_error {
public:
    const Token& token;

    RuntimeError(const Token& token, std::string_view message)
        : std::runtime_error{ message.data() }, token{ token }
    {}
};


static void report(int line, std::string_view where, std::string_view message);

void error(const Token& token, std::string_view message);

void error_prompt(int line, std::string_view message);

void runtimeError(const RuntimeError& error);
