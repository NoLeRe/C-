#include<iostream>
using namespace std;

int add(int a, int b){

	//���δ��λ�ĺ�
	//���룺��λ
	while (b)
	{
		int c = (unsigned int)(a&b) << 1;
		a = a^b;
		b = c;
	}
	return a;


}