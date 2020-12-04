#include <iostream>
#include <vector>

#include "morse_to_en.hpp"
#include "tokenizer.hpp"
#include "token.hpp"
#include "error_log.hpp"
#include "helpers.hpp"
#include "opcodes.hpp"

int main(int argc, char** argv) {
	std::string filepath = argv[1];

	std::string en_source = morse_to_en(filepath);
	std::vector<Token> tokens;

	Tokenizer tokenizer(en_source);
	try {
		tokens = tokenizer.tokenize();
		for (Token& token : tokens) {
			std::cout << token;
		}
	}
	catch (ErrorLog& e) {
		std::cerr << e.get_message() << std::endl;
	}
	
	OpCode op("hello", "world");
	print(op);

	return 0;
}