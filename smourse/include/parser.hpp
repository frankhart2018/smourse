#pragma once

#include "token.hpp"
#include "opcodes.hpp"

class Parser {
private:
	std::vector<Token> tokens;
public:
	Parser() = delete;

	Parser(std::vector<Token>& token);

	std::vector<OpCode> parse();
};