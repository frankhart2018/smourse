#pragma once

#include "opcodes.hpp"

class VM {
private:
	std::vector<OpCode> opcodes;
public:
	VM() = delete;

	VM(std::vector<OpCode>& opcodes);

	void execute();
};