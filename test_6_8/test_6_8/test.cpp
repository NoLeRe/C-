#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
using namespace std;

void test_1()
{
	pair<string, int> p("a",10);
	p=make_pair("string", 10);
	cout<<p.first<< "--->" << p.second << endl;
}
void test_2()
{
	map<string, int> mp;
	mp.insert(pair<string, int>("e", 2));
	mp.insert(make_pair("a", 10));
	mp.insert(make_pair("b", 9));
	mp["d"] = 100;
	mp["c"] = 8;
	mp.insert(make_pair("c", 100));
	//.erase(mp.begin(),mp.end());
	
	auto it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "--->" << it->second << endl;
		it++;
	}
	auto it2 = mp.find("a");
	cout << it2->first<< endl;
	cout << mp["a"] << endl;
}
void test_3()
{
	vector<pair<int, int>> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(make_pair(i, i));
	}
	map<int, int> mp(v.begin(), v.end());
	
	map<int, int> mp2(mp);
	auto it = mp2.begin();
	while (it != mp2.end())
	{
		cout << it->first << "-->" << it->second << endl;
		it++;
	}

}
void test_4()
{
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	set<int> st(v.begin(),v.end());
	/*st.erase(2);
	st.erase(st.begin());*/
	/*st.erase(st.begin(), st.end());*/
	auto it = st.begin();
	while (it != st.end())
	{
		cout << *it << endl;
		it++;
	}
	
	cout << *st.find(2) << endl;

	
}
int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	map<string, int> mp;
	cout << mp["a"] << endl;
	system("pause");
	return 0;
}