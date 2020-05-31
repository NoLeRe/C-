// write your code here cpp
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
	int n;

	int v[1000001] = { 0 };
	v[0] = 1;
	v[1] = 2;
	for (int i = 2; i<1000001; i++)
	{
		v[i] = ((v[i - 1] + v[i - 2]) % 1000000);
	}
	while (cin >> n)
	{
		if (n <= 25)
			cout << v[n - 1] << endl;
		else
			cout << setw(6) << setfill('0') << v[n - 1] << endl;
	}
	return 0;
}
