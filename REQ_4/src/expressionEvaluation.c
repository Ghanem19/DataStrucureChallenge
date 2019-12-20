/*
 * expressionEvaluation.c
 *
 *  Created on: Dec 20, 2019
 *      Author: eng-m
 */

#include "expressionEvaluation.h"

/*
 * Description: function specify which operation would be applied on the two arguments.
 * @param: num1 -> the first operand in the operation.
 * @param: num2 -> the second operand in the operation.
 * @param: operation -> one of the four binary operation +,-,* or /
 * @return: result of the operation.
 *
 * */
int operationCalc(int num1,int num2,char operation){
	switch(operation){
		case '+':
			return num1 + num2;

		case '-':
			return num2-num1;

		case '*':
			return num1*num2;

		case '/':
			return num2/num1;
		default:
			return num1;
			break;
	}


}

/* Description: the function use stack and queue to calculate the result of given expression.
 * 	but i did not cover the parenthesis cases.
 *
 * @param: expression -> string contain integer and operation to be apply on them.
 *
 * @return: result of the expression.
 * */
long long evaluate(char* expression){
		//Initialization
		unsigned int u32_index=0,u32_tempNumber = 0,u32_numberCounter = 0;
		int u32_num1= 0,u32_num2 = 0;
		int tempOperation = 0;
		long long u64_result = 0;
		ST_queueInfo opQueue = {0};
		ST_stackInfo valuesStack = {0};

		//loop to get the string size.
		while(expression[u32_index] != '\0'){
			printf("%c ",expression[u32_index]);
			u32_index++;
		}

		createQueue(&opQueue,u32_index);
		createStack(&valuesStack,u32_index);
		u32_index = 0;

		while(expression[u32_index] != '\0'){


			/*if(expression[u32_index] == '(' ){
				enqueue(&opQueue,expression[u32_index]);
			}
			else if(expression[u32_index] == ')'){
				enqueue(&opQueue,expression[u32_index]);
				while(tempOperation != ')' ){
					dequeue(&opQueue,&tempOperation);
					u32_num1= 0;
					u32_num2 = 0;
					printf("op = %c\n",tempOperation);
					pop(&valuesStack,&u32_num1);
					pop(&valuesStack,&u32_num2);
					if(u32_num2 == 42){
						push(&valuesStack,u32_num1);
						break;
					}
					printf("\n\tnum1 = %d \tnum2 = %d\n",u32_num1,u32_num2);
					push(&valuesStack,operationCalc(u32_num1,u32_num2,tempOperation));



				}


			}

			else*/

			// detect number and push it to the stack of values.
			if(expression[u32_index] <= '9' && expression[u32_index] >= '0'){
				u32_tempNumber = 0;
				while(expression[u32_index] <= '9' && expression[u32_index] >= '0'){
					u32_tempNumber = u32_tempNumber*10 + (expression[u32_index++] - 48);
				}
				u32_index--;
				push(&valuesStack,u32_tempNumber);
				u32_numberCounter++;
			}

			//in case of operation detected
			else{

				enqueue(&opQueue,expression[u32_index]);
				//check if there is more than one value in valuesStack.
				if(u32_numberCounter>1){
					u32_num1= 0;
					u32_num2 = 0;
					tempOperation = 0;
					u32_numberCounter = 1;
					dequeue(&opQueue,&tempOperation);
					pop(&valuesStack,&u32_num1);
					pop(&valuesStack,&u32_num2);

					// $ indicate that the stack is empty.
					if(u32_num2 == '$'){
						u64_result = u32_num1;
						break;
					}
					// if we reach to this point that's mean there is two numbers available
					// also there is valid operation on the queue.
					push(&valuesStack,operationCalc(u32_num1,u32_num2,tempOperation));
				}

			}
			//loop index
			u32_index++;
		}

		//loop to get the rest values on the stack and apply on them the remain operation.
		while(*(valuesStack.stackPointer-1) != 0 && opQueue.queueCapacity != 0){

					u32_num1= 0;
					u32_num2 = 0;
					tempOperation = 0;
					dequeue(&opQueue,&tempOperation);
					pop(&valuesStack,&u32_num1);
					pop(&valuesStack,&u32_num2);

					//check the stack values or operations queue if their empty.
					if(u32_num2 == '$' || tempOperation == EMPTY_QUEUE){
						u64_result = u32_num1;
						break;
					}

					u64_result = operationCalc(u32_num1,u32_num2,tempOperation);
					push(&valuesStack,u64_result);

		}


		return u64_result;
}
