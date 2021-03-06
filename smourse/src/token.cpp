#include <iostream>

#include "token.hpp"

Token::Token(std::string token_string, std::string value, int line_num)
	: token_string(token_string), value(value), line_num(line_num) {}

Token::Token(std::string token_string, int line_num)
	: token_string(token_string), value(std::string("")), line_num(line_num) {}

std::string Token::get_token_string() {
	return token_string;
}

std::string Token::get_value() {
	return value;
}

std::ostream& operator<<(std::ostream& stream, Token& token) {
	stream << "Token(" << token.token_string << ", " << token.value << ", " << token.line_num << ")" << std::endl;
	return stream;
}

bool operator==(const Token& token, std::string value) {
	if (token.value == value)
		return true;
	return false;
}

bool operator!=(const Token& token, std::string value) {
	if (token.value != value)
		return true;
	return false;
}