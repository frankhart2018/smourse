#include <vector>
#include <unordered_map>
#include <cctype>
#include <iostream>

#include "token.hpp"
#include "tokenizer.hpp"
#include "error_log.hpp"
#include "helpers.hpp"

Tokenizer::Tokenizer(std::string& en_source)
	: en_source(en_source), line_num(1) {}

std::string Tokenizer::keyword_operator_identifier(std::string& token_string, unsigned int& i) {
	while (en_source[i] != ' ' && en_source[i] != '\n' && i < en_source.length()) {
		token_string += en_source[i];
		i++;
	}

	std::vector<std::string>::iterator it = std::find(keywords_operators.begin(), keywords_operators.end(), token_string);

	if (it != keywords_operators.end())
		return "word";
	return "id";
}

void Tokenizer::string_val(std::string& token_string, unsigned int& i, char started_with) {
	while (en_source[i] != started_with && en_source[i] != '\n' && i < en_source.length()) {
		token_string += en_source[i];
		i++;
	}

	if (en_source[i] != started_with) {
		throw ErrorLog("unterminated string", line_num);
	}

	i++;
}

std::string Tokenizer::numeric_val(std::string& token_string, unsigned int& i) {
	int decimal_point_count = 0;

	while (en_source[i] != ' ' && en_source[i] != '\n' && i < en_source.length()) {
		if (isdigit(en_source[i]))
			token_string += en_source[i];
		else if (en_source[i] == 'd' && i+1 < en_source.length() && en_source[i+1] == 'c') {
			if (decimal_point_count == 0) {
				token_string += '.';
				decimal_point_count++;
				i++;
			}
			else {
				throw ErrorLog("multiple decimal points in numeric constant", line_num);
			}
		}
		else
			throw ErrorLog("non-numeric characters in numeric constant", line_num);

		i++;
	}

	if (decimal_point_count == 0)
		return "int_numeral";

	return "float_numeral";
}

void Tokenizer::tokenize(std::vector<Token>& tokens) {
	unsigned int i = 0;
	std::string type;
	std::string token_string = "";

	while (i < en_source.length()) {
		if (isdigit(en_source[i])) {
			try {
				type = numeric_val(token_string, i);
				tokens.emplace_back(Token(type, token_string, line_num));
				token_string = "";
			}
			catch (ErrorLog&) {
				throw;
			}
		}
		else if (isalnum(en_source[i])) {
			type = keyword_operator_identifier(token_string, i);
			tokens.emplace_back(Token(type, token_string, line_num));
			token_string = "";
		} 
		else if (en_source[i] == '\'') {
			try {
				i++;
				string_val(token_string, i, en_source[i-1]);
				tokens.emplace_back(Token("string", token_string.substr(1, token_string.length() - 2), line_num));
				token_string = "";
			}
			catch (ErrorLog&) {
				throw;
			}
		}
		else if (en_source[i] == '\n') {
			tokens.emplace_back(Token("newline", line_num));
			i++;
			line_num++;
		}
		else {
			i++;
		}
	}
}