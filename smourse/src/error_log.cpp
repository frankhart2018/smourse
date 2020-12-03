#include <iostream>
#include <string>

#include "error_log.hpp"

ErrorLog::ErrorLog(std::string message, int line_num)
	: message(message), line_num(line_num) {}

std::string ErrorLog::get_message() const {
	return "[Line " + std::to_string(line_num) + "] Error: " + message;
}