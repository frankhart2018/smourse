#pragma once

class Token {
private:
	std::string token_string;
	std::string value;
public:
	int line_num;

	Token() = delete;

	Token(std::string token_string, std::string value, int line_num);

	Token(std::string token_string, int line_num);

	std::string get_token_string();

	std::string get_value();

	friend std::ostream& operator<<(std::ostream& stream, Token& token);

	friend bool operator==(const Token& token, std::string value);

	friend bool operator!=(const Token& token, std::string value);
};