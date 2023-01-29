#pragma once
#include <string>
#include <iostream>
#include <exception>

class Except : public std::exception
{
private:
	std::string error_{};

public:
	Except(const std::string error);
	const char* what() const noexcept;
};