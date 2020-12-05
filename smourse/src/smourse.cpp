#include <iostream>
#include <vector>

#include "morse_to_en.hpp"
#include "tokenizer.hpp"
#include "token.hpp"
#include "error_log.hpp"
#include "helpers.hpp"
#include "opcodes.hpp"
#include "parser.hpp"

int main(int argc, char** argv) {
	std::string filepath = argv[1];

	std::string en_source = morse_to_en(filepath);
	std::vector<Token> tokens;

	Tokenizer tokenizer(en_source);
	try {
		tokenizer.tokenize(tokens);
		for (Token& token : tokens) {
			print(token);
		}
	}
	catch (ErrorLog& e) {
		std::cerr << e.get_message() << std::endl;
		return -1;
	}

	std::vector<OpCode> opcodes;

	print("\n");

	Parser parser(tokens);
	try {
		parser.parse(opcodes);
		for (OpCode& opcode : opcodes) {
			print(opcode);
		}
	}
	catch (ErrorLog& e) {
		std::cerr << e.get_message() << std::endl;
		return -1;
	}

	return 0;
}