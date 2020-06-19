#include<iostream>
#include<vector>
using namespace std;

class Bit_map
{
public:
	Bit_map(size_t range)
	{
		bp.resize((range >> 5) + 1);
	}
	void set(int data)
	{
		int index = data >> 5;
		int bitdex = data % 32;

		bp[index] |= (1 << bitdex);
	}
	bool test(int data)
	{
		int index = data >> 5;
		int bitdex = data % 32;
		return bp[index] & (1 << bitdex);
	}
	void reset(int data)
	{
		int index = data >> 5;
		int bitdex = data % 32;
		bp[index] &= ~(1 << bitdex);
	}

private:
	vector<int> bp;
};
struct HF1
{
	size_t operator()(const string& str)
	{
		size_t key = 0;
		for (const auto& ch : str)
		{
			key = key * 131 + ch;
		}
		return key;
	}
};

struct HF2
{
	size_t operator()(const string& str)
	{
		size_t key = 0;
		size_t magic = 63689;
		for (const auto& ch : str)
		{
			key = key * magic + ch;
			magic *= 378551;
		}
		return key;
	}
};

struct HF3
{
	size_t operator()(const string& str)
	{
		size_t key = 0;
		for (const auto& ch : str)
		{
			key = key * 131 + ch;
		}
		return key;
	}
};

template<class K,class HF1,class HF2,class HF3>
class BloomFilter{
public:
	BloomFilter(size_t range)
		:_bp(range * 5)
		, _bitnum(range*5)
	{}
	void set(const K& key)
	{
		size_t index1 = HF1()(key)%_bitnum;
		size_t index2 = HF2()(key)%_bitnum;
		size_t index3 = HF3()(key)%_bitnum;
		_bp.set(index1);
		_bp.set(index2);
		_bp.set(index3);
	}
	bool test(const K& key)
	{
		size_t index1 = HF1()(key)%_bitnum;
		size_t index2 = HF2()(key)%_bitnum;
		size_t index3 = HF3()(key)%_bitnum;
		if (!_bp.test(index1))
			return false;
		if (!_bp.test(index2))
			return false;
		if (!_bp.test(index3))
			return false;
		return true;
	}
private:
	Bit_map _bp;
	size_t _bitnum;
};


void test()
{
	Bit_map mp(100);
	mp.set(42);
	mp.set(21);
	cout << mp.test(42) << endl;
	cout << mp.test(21) << endl;
	cout << mp.test(50) << endl;
	mp.reset(42);
	cout << mp.test(42) << endl;
}
void test_2()
{
	BloomFilter<string, HF1, HF2, HF3> bf(100);
	string s1 = "diajiasj";
	string s2 = "dasdasee";
	string s3 = "diushduw";
	bf.set(s1);
	bf.set(s2);
	bf.set(s3);
	cout << bf.test(s1) << endl;
	cout << bf.test(s2) << endl;
	cout << bf.test("a") << endl;
}
int main()
{
	//test();
	test_2();
	system("pause");
	return 0;
}