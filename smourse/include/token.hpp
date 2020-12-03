#pragma once

class Token {
private:
	std::string token_string;
	std::string value;
	int line_num;

public:
	Token() = delete;

	Token(std::string token_string, std::string value, int line_num);

	Token(std::string token_string, int line_num);

	friend std::ostream& operator<<(std::ostream& stream, Token& token);
};