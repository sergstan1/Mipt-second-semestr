#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <assert.h>

using namespace  std;

typedef unsigned long long StackCanary;


//----------------------------------------------------
//! Value of stack protection
//----------------------------------------------------
StackCanary CANARYVALUE = 0xAFBCDEFA9820;


//----------------------------------------------------
//! Start size of the stack
//----------------------------------------------------
const int StackSz = 1000;


class Stack
{
private:
	bool overflow_checker;
	bool underflow_checker;

	StackCanary canary_front;

	int size_;
	int data_[StackSz];

	StackCanary canary_back;

	FILE* logfile_;
	void Logging(void);
	void Print(char* str);

public:
	Stack();
	~Stack();

	//----------------------------------------------------
	//! Puts data into the stack
	//!
	//! @param[in] pointer to stack
	//! @param[in] what we put in the stack
	//----------------------------------------------------
	void Push(int value);


	//----------------------------------------------------
	//! Gets data from the stack
	//! 
	//! @param[in] pointer to stack
	//!
	//----------------------------------------------------
	int Pop(void);
};