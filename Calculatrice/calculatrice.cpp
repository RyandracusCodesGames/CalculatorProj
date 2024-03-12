#include "calculatrice.h"
#include <string>
#include <iostream>

bool string_has_operator(std::string str) {
	int i;
	for (i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
			return true;
		}
	}
	return false;
}

void ParseFunc(std::string str, std::string &op1, std::string &op2, std::vector<std::string> &trace) {
	bool change = false;
	if (string_has_operator(str)) {
		op1.push_back(str[0]);

		int i;
		for (i = 1; i < str.length(); i++) {
			trace.push_back("IF STR OF I EQ OP");

			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
				change = true;
			}

			trace.push_back("IF CHANGE EQ TRUE");
			trace.push_back("ELSE CHANGE EQ TRUE");

			if (change == false) {
				op1.push_back(str[i]);
			}
			else {
				trace.push_back("THEN AND IF STR NOT EQ OP");
				if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '%') {
					op2.push_back(str[i]);
				}
			}
		}
	}
}


Operator CharToOperator(char op){

	switch (op) {
		case '+':{
			return OP_ADD;
		}break;
		case '-':{
			return OP_SUB;
		}break;
		case '*':{
			return OP_MUL;
		}break;
		case '/':{
			return OP_DIV;
		}break;
		case '%':{
			return OP_PER;
		}break;
	}

	return OP_ERR;
}

Operator GetOperatorFromString(std::string func) {
	int i;
	for (i = 1; i < func.length(); i++) {
		switch (func[i]){
			case '+': {
				return OP_ADD;
			}break;
			case '-': {
				return OP_SUB;
			}break;
			case '*': {
				return OP_MUL;
			}break;
			case '/': {
				return OP_DIV;
			}break;
			case '%': {
				return OP_PER;
			}break;
		}
	}
}

float StrToOperand(std::string operand){
	std::string op;
	if (operand[1] == '-') {
		op = operand.substr(1, operand.length());
	}
	else {
		op = operand;
	}
	return std::stof(op);
}

void CalculateResult(Expr* expr){
	float result = 0;

	switch (expr->op){
		case OP_ADD:{
			result = expr->operand1 + expr->operand2;
		}break;
		case OP_SUB: {
			result = expr->operand1 - expr->operand2;
		}break;
		case OP_MUL: {
			result = expr->operand1 * expr->operand2;
		}break;
		case OP_DIV: {
			result = expr->operand1 / expr->operand2;
		}break;
		case OP_PER: {
			result = expr->operand1 + expr->operand2 * 0.010;
		}break;
	}

	expr->result = result;
}

void ClearExpr(Expr* expr){
	expr->operand1 = 0;
	expr->operand2 = 0;
	expr->op = OP_ERR;
	expr->result = 0;
}

void ClearOps(Expr* expr){
	expr->operand1 = 0;
	expr->operand2 = 0;
	expr->op = OP_ERR;
}

