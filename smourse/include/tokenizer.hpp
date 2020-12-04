#pragma once

#include "token.hpp"

class Tokenizer {
private:
	std::string en_source;
	int line_num;

	std::vector<std::string> keywords_operators{
		// Keywords
		"print",

		// Operators
		"opt", "qt", "cpt",
	};

	std::string keyword_operator_identifier(std::string& token_string, unsigned int& i);

	void string_val(std::string& token_string, unsigned int& i, char started_with);

	std::string numeric_val(std::string& token_string, unsigned int& i);

public:
	Tokenizer() = delete;

	Tokenizer(std::string& en_source);

	std::vector<Token> tokenize();
};