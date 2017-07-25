#include<iostream>

using namespace std;

template<class T>
class auto_ptr
{
public:
	auto_ptr<T> & operator=(auto_ptr<T> &rhs);
	auto_ptr(const auto_ptr<T> &rhs);
private:
	T *pointee;
};

template<class T>
auto_ptr<T> & auto_ptr<T>::operator=(auto_ptr<T> &rhs)
{
	if(this == &rhs)
		return *this;

	delete pointee;
	pointee = rhs.pointee;
	rhs.pointee = 0;
	return *this;
}

template<class T>
auto_ptr<T>::auto_ptr(const auto_ptr<T> &rhs)
{
	pointee = rhs.pointee;
	rhs.pointee = 0;
}

int main()
{
	return 0;
}
