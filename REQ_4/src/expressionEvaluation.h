/*
 * expressionEvaluation.h
 *
 *  Created on: Dec 20, 2019
 *      Author: eng-m
 */

#ifndef EXPRESSIONEVALUATION_H_
#define EXPRESSIONEVALUATION_H_

#include "dynamicStack.h"
#include "dynamicQueue.h"
/*
 * Description: function specify which operation would be applied on the two arguments.
 * @param: num1 -> the first operand in the operation.
 * @param: num2 -> the second operand in the operation.
 * @param: operation -> one of the four binary operation +,-,* or /
 * @return: result of the operation.
 *
 * */
int operationCalc(int num1,int num2,char operation);


/* Description: the function use stack and queue to calculate the result of given expression.
 * 	but i did not cover the parenthesis cases.
 *
 * @param: expression -> string contain integer and operation to be apply on them.
 *
 * @return: result of the expression.
 * */
long long evaluate(char* expression);

#endif /* EXPRESSIONEVALUATION_H_ */
