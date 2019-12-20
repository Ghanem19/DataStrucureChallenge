/*
 * dynamicStack.c
 *
 *  Created on: Dec 17, 2019
 *      Author: Ghanem.
 */


#include "checkBalance.h"


/*
 * Description: create new stack of type info the stackPointer is assigned to the first empty
 * 				location at the stack
 * @param: info -> pointer to strucure to assign the stackPointer and capacity in this function.
 * @param: size -> size of stack;
 *
 * */
void createStack(ST_stackInfo *info,int size){
	//allocate array of stack size in the memory
	info->stackPointer =  (int*) malloc((size+2)*sizeof(int));
	info->stackCapacity = size;


	*(info->stackPointer) = '#'; //to check this value later if stack is full.
	info->stackPointer += size; //start from the last address.
	*(info->stackPointer + 1) = '$';
}

/*
 * Description: function put the passed data at last empty location of stack which assigned to stackPointer.
 *
 * @param: info -> the stack that value would pushed into it
 * @param: data -> data to be pushed.
 * */
void push(ST_stackInfo *info, int data){
	*(info->stackPointer) = data;
	printf("push = %d\n",*(info->stackPointer));
	info->stackPointer--;
}

/*
 * Description: function get out the last data have been pushed into stack.
 *
 * @param: *info -> the stack that value would pop from it.
 * @param: *data -> after pop data passed to user by this pointer.
 */
void pop(ST_stackInfo *info, int* data){
	info->stackPointer++;
	*data = *(info->stackPointer);
	printf("pop = %d\n",*(data));
	*(info->stackPointer) = 0;
}

/*
 * Description: function specify if stack either full, Empty or in between.
 *
 * */
stackState_t stackCheck(ST_stackInfo *info){
	if(*(info->stackPointer) == '#'){
		return FULL;
	}
	else if(*(info->stackPointer) == '$'){
		return EMPTY;
	}
	return SAFE_STATE;
}

/*
 *	Description: the function specify if the brackets, parenthesis or curly brackets are balanced or not
 *	@param: expression -> string that hold the brackets.
 *	@return: 0-> if unbalanced string and 0xff if balanced
 */
unsigned char checkForBalancedParantheses(char* expression){
	int u32_index = 0;
	int u8_tempChar;
	ST_stackInfo stack = {0};
	while(expression[u32_index] != '\0'){
		u32_index++;
	}
	//use this condition if only brackets on the string.
	/*if(u32_index%2 != 0){
		return UNBALANCED;
	}*/
	createStack(&stack,(u32_index/2)+1);
	u32_index = 0;
	while(u32_index <= (stack.stackCapacity)){
		 switch(expression[u32_index]) {
		            case '(':
		            	push(&stack,')');
		            	if(stackCheck(&stack) ==  FULL) {
		            		return UNBALANCED;
		            	}
		            	break;
		            case '[':
		            	push(&stack,']');
		            	if(stackCheck(&stack) ==  FULL){
		            		return UNBALANCED;
		            	}
		            	break;
		            case '{':
		            	push(&stack,'}');
		            	if(stackCheck(&stack) ==  FULL){
		            		return UNBALANCED;
		            	}
		            	break;
		            default:
		            	// once you have iterated passed the left brackets
		                // compare right bracket with the one expected
		            	pop(&stack,&u8_tempChar); // it matches, so remove it
		            	if(stackCheck(&stack) == EMPTY || expression[u32_index] != u8_tempChar){
		                	return UNBALANCED;
		                }
		        }

		 u32_index++;
	}

		return (stackCheck(&stack) == EMPTY) ? UNBALANCED:BALANCED;
}





