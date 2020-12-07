#include <iostream>
#include <vector>

#include "vm.hpp"
#include "helpers.hpp"

VM::VM(std::vector<OpCode>& opcodes)
	: opcodes(opcodes) {}

void VM::execute() {
	for (OpCode& opcode : opcodes) {
		if (opcode == "print")
			print(opcode.get_value());
	}
}