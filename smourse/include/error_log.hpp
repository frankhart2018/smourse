#pragma once

class ErrorLog {
private:
	std::string message;
	int line_num;
public:
	ErrorLog(std::string message, int line_num);

	std::string get_message() const;
};