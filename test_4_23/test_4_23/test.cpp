#include<iostream>
using namespace std;

int add(int a, int b){

	//异或：未进位的和
	//相与：进位
	while (b)
	{
		int c = (unsigned int)(a&b) << 1;
		a = a^b;
		b = c;
	}
	return a;


}