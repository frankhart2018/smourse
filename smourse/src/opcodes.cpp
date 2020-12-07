#include <iostream>

#include "opcodes.hpp"

OpCode::OpCode(std::string opcode, std::string value)
	: opcode(opcode), value(value) {}

std::string OpCode::get_value() {
	return value;
}

bool operator==(const OpCode& op, std::string value) {
	if (op.opcode == value)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& stream, OpCode& op_code) {
	stream << "OpCode(" << op_code.opcode << ", " << op_code.value << ")" << std::endl;
	return stream;
}