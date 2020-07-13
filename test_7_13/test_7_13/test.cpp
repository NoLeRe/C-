#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int maxcre = 1;
		int maxuse = 1;
		string id, method;
		for (int i = 0; i<n; i++)
		{
			cin >> id >> method;
			if (method == "connect")
			{
				if (maxuse == 0)
				{
					maxcre++;
					maxuse++;
				}
				maxuse--;
			}
			if (method == "disconnect")
			{
				maxuse++;
			}
		}
		cout << maxcre << endl;
	}
	return 0;
}