#pragma once
#include "except.h"

Except::Except(std::string error) : error_(error) {};

const char* Except::what() const noexcept { return error_.std::string::c_str(); }
