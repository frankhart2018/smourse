#include <iostream>
#include <vector>

#include "parser.hpp"
#include "opcodes.hpp"
#include "token.hpp"
#include "helpers.hpp"

Parser::Parser(std::vector<Token>& tokens)
	: tokens(tokens) {}

std::vector<OpCode> Parser::parse() {
	std::vector<OpCode> opcodes;
	opcodes.emplace_back(OpCode("hello", "world"));

	for (Token& token : tokens) {
		print(token);
	}

	return opcodes;
}