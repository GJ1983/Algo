#include<iostream>
#include<vector>
#include<algorithm>

void add2(int i)
{
	std::cout<<i+2<<std::endl;
}

template<int val>
void func(int i)
{
	std::cout<<i+val<<std::endl;
}

class AddVal
{
	int val;
public:
	AddVal(int j) : val(j)
	{}
	void operator()(int i)
	{
		std::cout<<i+val<<std::endl;
	}
};

int main()
{
	std::vector<int> vec = {4,8,9,3,5} ;
	std::for_each(vec.begin(),vec.end(),add2);   //  using normal function
	std::for_each(vec.begin(),vec.end(),func<2>);  // using template
        AddVal add(10);
	std::for_each(vec.begin(),vec.end(),add);   // using functor with harcoded parameter

        int x = 34;
	std::for_each(vec.begin(),vec.end(),AddVal(x));  // using functor with customized parameter
        std::cout<<" ========================== "<<std::endl;
        std::cout<<" ========================== "<<std::endl;
        std::cout<<" ========================== "<<std::endl;
        std::cout<<" ========================== "<<std::endl;

        std::cout<<std::count_if(vec.begin(), vec.end(),[](int x){ return x <10;} ) <<std::endl;
	return 0;
}
