#pragma once

class OpCode {
private:
	std::string opcode;
	std::string value;
public:
	OpCode() = delete;

	OpCode(std::string opcode, std::string value);

	friend std::ostream& operator<<(std::ostream& stream, OpCode& op_code);
};