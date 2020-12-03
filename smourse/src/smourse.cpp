#include <iostream>
#include <vector>

#include "morse_to_en.hpp"
#include "tokenizer.hpp"
#include "token.hpp"
#include "error_log.hpp"

int main(int argc, char** argv) {
	std::string filepath = argv[1];

	std::string en_source = morse_to_en(filepath);

	std::cout << en_source << std::endl << std::endl;

	Tokenizer tokenizer(en_source);
	try {
		std::vector<Token> tokens = tokenizer.tokenize();
		for (Token& token : tokens) {
			std::cout << token;
		}
	}
	catch (ErrorLog& e) {
		std::cerr << e.get_message() << std::endl;
	}

	return 0;
}