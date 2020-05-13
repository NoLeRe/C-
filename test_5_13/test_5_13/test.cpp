#include<iostream>
using namespace std;

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	if (pushed == NULL || popped == NULL)
		return false;
	if (pushedSize != poppedSize)
		return false;
	if (pushedSize == 0)
		return true;

	int stack[pushedSize];
	int top = 0;
	int i = 0, j = 0;
	while (j<poppedSize)
	{
		if (i >= pushedSize)
			break;
		stack[top++] = pushed[i++];
		while (top>0 && stack[top - 1] == popped[j] && j<poppedSize)
		{
			top--;
			j++;
		}
	}
	if (top == 0)
		return true;
	else
		return false;
}