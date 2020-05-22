#include<iostream>
#include<vector>
using namespace std;

void vector_test_1()
{
	vector<int> first;
	vector<int> second(4, 10);
	vector<int>	third(second.begin(), second.end());
	vector<int>	fourth(third);

	vector<int>::iterator it = third.begin();
	while (it != third.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (int i = 0; i < second.size(); i++)
	{
		cout << second[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < fourth.size(); i++)
	{
		cout << fourth[i] << " ";
	}
	cout << endl;
}
void vector_test_2()
{
	vector<int> first;
	vector<int> second(10, 10);
	vector<int>	third(second.begin(), second.end());
	vector<int>	fourth(third);
	second.push_back(9);
	
	cout << first.size() << endl;
	cout << first.capacity() << endl;
	cout << second.size() << endl;
	cout << second.capacity() << endl;
}
void vector_test_3()
{
	vector<int> v;
	size_t size = v.capacity();

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (size != v.capacity())
		{
			size = v.capacity();
			cout << "capacity changed: " << size << endl;
		}
	}
}
void vector_test_4()
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	vector<int>::iterator it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		v.erase(it);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void vector_test_5()
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int> st;
	st.swap(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < st.size(); i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;

}
void vector_test_6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it=v.erase(it);
		else
		{
			it++;
		}
	}
	while (it != v.end())
	{
		cout << *it<< " ";
	}
	cout << endl;
}

int main()
{
	//vector_test_1();
	//vector_test_2();
	//vector_test_3();
	//vector_test_4();
	//vector_test_5();
	vector_test_6();
	system("pause");
	return 0;
}