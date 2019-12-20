/*
 * dynamicStack.h
 *
 *  Created on: Dec 17, 2019
 *      Author: eng-m
 */

#ifndef CHECKBALANCE_H_
#define CHECKBALANCE_H_

#include <stdio.h>
#include <stdlib.h>



#define BALANCED 0xff
#define UNBALANCED 0


typedef enum stackState_t{
	EMPTY,
	SAFE_STATE,
	FULL

}stackState_t;
typedef struct ST_stackInfo{
	int *stackPointer;
	int  stackCapacity;
}ST_stackInfo;



/*
 * Description: create new stack of type info the stackPointer is assigned to the first empty
 * 				location at the stack
 * @param: info -> pointer to strucure to assign the stackPointer and capacity in this function.
 * @param: size -> size of stack;
 *
 * */
void createStack(ST_stackInfo *info,int size);
/*
 * Description: function put the passed data at last empty location of stack which assigned to stackPointer.
 *
 * @param: info -> the stack that value would pushed into it
 * @param: data -> data to be pushed.
 * */
void push(ST_stackInfo *info, int data);
/*
 * Description: function get out the last data have been pushed into stack.
 *
 * @param: *info -> the stack that value would pop from it.
 * @param: *data -> after pop data passed to user by this pointer.
 * */
void pop(ST_stackInfo *info, int* data);
/*
 * Description: function specify if stack either full, Empty or in between.
 * @param: *info -> the stack that would be checked.
 * @return: state of the stack if {FULL,EMPTY,NON_OF_THEM}.
 * */
stackState_t stackCheck(ST_stackInfo *info);

/*
 *	Description: the function specify if the brackets, parenthesis or curly brackets are balanced or not
 *	@param: expression -> string that hold the brackets.
 *	@return: 0-> if unbalanced string and 0xff if balanced
 */
unsigned char checkForBalancedParantheses(char* expression);


#endif /* CHECKBALANCE_H_ */
