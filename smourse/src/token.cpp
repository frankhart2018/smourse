#include <iostream>

#include "token.hpp"

Token::Token(std::string token_string, std::string value, int line_num)
	: token_string(token_string), value(value), line_num(line_num) {}

Token::Token(std::string token_string, int line_num)
	: token_string(token_string), value(std::string("")), line_num(line_num) {}

std::ostream& operator<<(std::ostream& stream, Token& token) {
	stream << "Token(" << token.token_string << ", " << token.value << ", " << token.line_num << ")" << std::endl;
	return stream;
}