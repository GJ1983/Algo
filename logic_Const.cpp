#include<iostream>
#include<vector>

class BigTable
{
	std::vector<int> v;
	///int accessCounter;
	//mutable int accessCounter;
public:
	int getItem(int index) const
	{
                // two solutions to modify values from const function
                //const_cast<BigTable *>(this)->accessCounter++;
		//accessCounter++;
		return v[index];
	}

// Overloading based on function constness
	void fun() const
	{
		std::cout<<" const function called : "<<std::endl;
	}
	void fun() 
	{
		std::cout<<" Non const function called : "<<std::endl;
	}

// Overloading based on refernce parameter constness

	void fun_ref(const int& t)
	{
		std::cout<<" Printing value from const paramater : "<< t<<std::endl;
	}

	void fun_ref(int& t)
	{
		std::cout<<" Printing value from non-const paramater : "<< t<<std::endl;
	}

//Overloading based on non-reference parameter constness, which is not allowed

//	void fun_nonref(const int t)
//	{
//	}
//	void fun_nonref( int t)
//	{
//	}
};


class test_const
{
	const int x;
	int &y;
};


int main()
{
	//test_const t;
        int i = 10;
	const int x = 50;

	BigTable b;
	const BigTable b1;
	b.fun();
	b1.fun();


        b.fun_ref(i);
        b.fun_ref(x);
	return 0;
}
