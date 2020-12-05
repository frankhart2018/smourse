#pragma once

#include "token.hpp"
#include "opcodes.hpp"

class Parser {
private:
	std::vector<Token> tokens;

	void parse_print_statement(std::vector<Token>& tokens, std::vector<OpCode>& opcodes, unsigned int& i);
public:
	Parser() = delete;

	Parser(std::vector<Token>& token);

	void parse(std::vector<OpCode>& opcodes);
};