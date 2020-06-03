#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Base1{
public:
	virtual void func1()
	{
		cout << "Base1::func1" << endl;
	}
	virtual void func2()
	{
		cout << "Base1::func2" << endl;
	}
private:
	int b1;
};

class Base2{
public:
	virtual void func1()
	{
		cout << "Base2::func1" << endl;
	}
	virtual void func2()
	{
		cout << "Base2::func2" << endl;
	}
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1()
	{
		cout << "Derive::func1" << endl;
	}
	virtual void func3()
	{
		cout << "Derive::func3" << endl;
	}
private:
	int d1;
};

typedef void(*vfptr) ();

void PrintVfuntable(vfptr* vf)
{
	cout << "虚表的地址：" << vf << endl;
	for (int i = 0; vf[i] != nullptr;i++)
	{
		cout << "函数地址：" << vf[i] << endl;
		vfptr f = vf[i];
		f();
	}
}
int main()
{
	Derive d;
	Base2 b2;
	Base1 b1;
	cout << "d的第一个虚表：" << endl;
	PrintVfuntable((vfptr*)(*(int*)&d));
	cout << "d的第二个虚表：" << endl;
	Base2* b = &d;
	PrintVfuntable((vfptr*)(*(int*)b));
	cout << "b1的虚表：" << endl;
	PrintVfuntable((vfptr*)(*(int*)&b1));
	cout << "b2的虚表：" << endl;
	PrintVfuntable((vfptr*)(*(int*)&b2));
	system("pause");
	return 0;
}