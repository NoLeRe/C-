#include<iostream>
#include<memory>
#include<mutex>
#include<thread>
using namespace std;

//template<class T>
//class Autoptr{
//public:
//	Autoptr(T* ptr)
//	:_ptr(ptr)
//	{}
//	~Autoptr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	Autoptr( Autoptr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//	Autoptr<T>& operator=(Autoptr<T>& ap)
//	{
//		if (this!= &ap)
//		{
//			if (_ptr)
//				delete _ptr;
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//		return *this;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
////Unique_ptr 不允许拷贝构造和赋值
//template<class T>
//class Uniqueptr{
//public:
//	Uniqueptr(T* ptr) :_ptr(ptr)
//	{}
//	~Uniqueptr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	Uniqueptr(Uniqueptr<T>& ap) = delete;
//	Uniqueptr& operator=(Uniqueptr<T>& ap) = delete;
//	T* _ptr;
//};

template<class T>
class deletor{
public:
	void operator()(T* ptr)
	{
		delete ptr;
	}
};

template<class T, class Deletor = deletor<T>>
class Sharedptr
{
public:
	Sharedptr(T* ptr = nullptr,Deletor deletor=deletor<T>())
		:_ptr(ptr)
		, _pcount(new int(1))
		, _pmtx(new mutex)
		, _delete(deletor)
	{}
	~Sharedptr()
	{
		if (subcount() == 0)
		{
			if (_ptr)
				delete _ptr;
			delete _pcount;
			delete _pmtx;
		}
	}
	Sharedptr(const Sharedptr<T>& sp)
		:_ptr(sp._ptr)
		, _pcount(sp._pcount)
		, _pmtx(sp._pmtx)
	{
		addcount();
	}
	Sharedptr<T>& operator=(Sharedptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			if (subcount() == 0)
			{
				_delete(_ptr);
				delete _pcount;
				delete _pmtx;
			}
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_pmtx = sp._pmtx;
			addcount();
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int addcount()
	{
		_pmtx->lock();
		++(*_pcount);
		_pmtx->unlock();
		return *_pcount;
	}
	int subcount()
	{
		_pmtx->lock();
		--(*_pcount);
		_pmtx->unlock();
		return *_pcount;
	}
	int usecount()
	{
		return *_pcount;
	}
private:
	T* _ptr;
	int* _pcount;
	mutex* _pmtx;
	Deletor _delete;
};


//int main()
//{
//	Autoptr<int> p1(new int(0));
//	cout << *p1 << endl;
//	Autoptr<A> p2(new A());
//	p2->a = 1;
//	cout << p2->a<< endl;
//	system("pause");
//	return 0;
//
//}
//int main()
//{
//	shared_ptr<int> ap(new int(0));
//	cout << ap.use_count() << endl;
//	shared_ptr<int> p = ap;
//	cout << ap.use_count() << endl;
//	cout << p.use_count() << endl;
//	shared_ptr<int> p2(new int(1));
//	p = p2;
//	cout << ap.use_count() << endl;
//	cout << p.use_count() << endl;
//	cout << p2.use_count() << endl;
//	system("pause");
//	return 0;
//}
mutex mtx;
void func1(Sharedptr<int>& ap,int n)
{
	for (int i = 0; i < n; i++)
	{
		mtx.lock();
		++(*ap);
		mtx.unlock();
		Sharedptr<int> cur (ap);
	}
}
void func2(Sharedptr<int>& ap,int n)
{
	for (int i = 0; i < n; i++)
	{
		mtx.lock();
		++(*ap);
		mtx.unlock();
		Sharedptr<int> cur(ap);
	}
}
int main()
{
	Sharedptr<int> ap(new int(0));
	int n = 10000;
	thread t1(func1, ap,n);
	thread t2(func2, ap,n);
	t1.join();
	t2.join();
	cout << *ap << endl;
	cout << ap.usecount() << endl;
	system("pause");
	return 0;
}
//class A{
//public:
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int a;
//};
//
//int main()
//{
//	shared_ptr<A> p((A*)malloc(sizeof(A)*5));
//
//	return 0;
//}