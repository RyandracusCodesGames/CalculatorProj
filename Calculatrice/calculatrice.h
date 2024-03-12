#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <string>
#include <vector>

typedef enum Operator{
	OP_ADD = 0x1,
	OP_SUB = 0x2,
	OP_DIV = 0x3,
	OP_MUL = 0x4,
	OP_PER = 0x5,
	OP_ERR = 0x6,
}Operator;

typedef struct Expr{
	float operand1;
	Operator op;
	float operand2;
	float result;

	public:
	Expr() { 
		operand1 = 0;
		operand2 = 0;
		result = 0;
		op = OP_ERR;
	}
}Expr;

bool string_has_operator(std::string str);
bool second_op_is_neg(std::string func);
void ParseFunc(std::string str, std::string &op1, std::string &op2, std::vector<std::string> &trace);
Operator GetOperatorFromString(std::string func);
Operator CharToOperator(char op);
float StrToOperand(std::string operand);
void CalculateResult(Expr* expr);
void ClearExpr(Expr* expr);
void ClearOps(Expr* expr);

#endif

