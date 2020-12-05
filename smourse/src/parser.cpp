#include <iostream>
#include <vector>

#include "parser.hpp"
#include "opcodes.hpp"
#include "token.hpp"
#include "helpers.hpp"
#include "error_log.hpp"

Parser::Parser(std::vector<Token>& tokens)
	: tokens(tokens) {}

void Parser::parse_print_statement(std::vector<Token>& tokens, std::vector<OpCode>& opcodes, unsigned int& i) {
	if (tokens[i] != "opt")
		throw ErrorLog("expected ( after print statement", tokens[i].line_num);

	i++;
	std::string token_string = tokens[i].get_token_string();
	if (token_string != "string" && token_string != "int_numeral" && token_string != "float_numeral")
		throw ErrorLog("expected string or numeric value inside print statement", tokens[i].line_num);

	std::string value = tokens[i].get_value();

	i++;
	if (tokens[i] != "cpt")
		throw ErrorLog("expected ) after constant in print statement", tokens[i].line_num);

	opcodes.emplace_back(OpCode("print", value));
}

void Parser::parse(std::vector<OpCode>& opcodes) {
	unsigned int i = 0;
	while (i < tokens.size()) {
		if (tokens[i] == "print") {
			i++;
			try {
				parse_print_statement(tokens, opcodes, i);
			}
			catch (ErrorLog&) {
				throw;
			}
		}

		i++;
	}
}