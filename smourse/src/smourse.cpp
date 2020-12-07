#include <iostream>
#include <vector>

#include "morse_to_en.hpp"
#include "tokenizer.hpp"
#include "token.hpp"
#include "error_log.hpp"
#include "helpers.hpp"
#include "opcodes.hpp"
#include "parser.hpp"
#include "vm.hpp"

int main(int argc, char** argv) {
	std::string filepath = argv[1];

	std::string en_source = morse_to_en(filepath);
	std::vector<Token> tokens;

	Tokenizer tokenizer(en_source);
	try {
		tokenizer.tokenize(tokens);
	}
	catch (ErrorLog& e) {
		std::cerr << e.get_message() << std::endl;
		return -1;
	}

	std::vector<OpCode> opcodes;

	Parser parser(tokens);
	try {
		parser.parse(opcodes);
	}
	catch (ErrorLog& e) {
		std::cerr << e.get_message() << std::endl;
		return -1;
	}

	VM vm(opcodes);
	try {
		vm.execute();
	}
	catch (ErrorLog& e) {
		std::cerr << e.get_message() << std::endl;
		return -1;
	}

	return 0;
}