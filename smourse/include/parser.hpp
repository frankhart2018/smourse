#pragma once

#include "token.hpp"

class Parser {
private:
	std::vector<Token> tokens;
	std::vector<OpCode> opcodes;
};