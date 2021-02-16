#pragma warning(disable : 4996)

#include "Stack.h"
#include "Log.h"

int main(void)
{
	Stack s;

	s.Push(10);
	int a = s.Pop();
			
	return 0;
}


Stack::Stack():
size_(0),
data_(),
overflow_checker(false),
underflow_checker(false),
canary_front(CANARYVALUE),
canary_back(CANARYVALUE),
logfile_(fopen("Log file.txt", "a"))
{}


Stack::~Stack()
{
	size_ = -1;
}


void Stack::Push(int value)
{
	if (++size_ >= StackSz)
	{
		overflow_checker = true;

		return;
	}
	data_[size_] = value;
}


int Stack::Pop(void)
{
	if (size_ == 0)
	{
		underflow_checker = true;
		return NULL;
	}
	else
	{
		size_--;
		int temp1 = data_[size_];

		size_--;

		return temp1;
	}
}


void Stack::Logging(void)
{
	if (logfile_ == NULL)
	{
		cout << "Could not open logfile" << endl;

		return;
	}
	else
	{
							
	}
}


void Stack::Print(char* str)
{
	if (logfile_ == NULL)
	{
		cout << "Could not open logfile" << endl;

		return;
	}
	else
	{

	}
}

