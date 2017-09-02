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

class test
{
public:
        test(int i) : data(i)
        {}
private:
        int data;
};


class base
{
public:
	void PrintMsg(int a)
	{
		std::cout<<" Printing from PrintMsg of integer parameter. "<<std::endl;
	}
	virtual void PrintMsg(std::string msg = " Base version")
	{
		std::cout<<" Printing from "<<msg<<std::endl;
	}
protected:
	void forTesting()
	{
		std::cout<<" For testing overiding of protected from base: "<<std::endl;
	}
};

class Derived : public base
{
public:
	using base::PrintMsg;  // To make line 316 compile, we need to add this here
	virtual void PrintMsg(std::string msg = " Derived version")
	{
		std::cout<<" Printing from "<<msg<<std::endl;
	}
	void forTesting()
	{
		std::cout<<" For testing overiding of protected from Derived: "<<std::endl;
	}

};

namespace A
{
	struct x {} ;
	void function(x)
	{
		std::cout<<" Inside function with integer argument: "<<std::endl;
	} 	
	void function()
	{
		std::cout<<" Inside function with without argument: "<<std::endl;
	}
}

int global;

int Multiply(int &a)
{
	return a*10;
}

int& Global()
{
	return global;
}


class Array2D
{
public:
       // Proxy class implemenation
	class Array1D
	{
	private:
		int data[10];
	public:
		Array1D()
		{
			//data = new int;
                        for(int i = 0; i<10; i++)
			{
				data[i] = i;
			}
		}
		int& operator[](int index)
		{
			return data[index];
		}

	};


        // Outer class implementation
	Array1D operator[](int index)
	{
		return  arr1[index];
	}
	Array2D()
	{
		arr1 = new Array1D[10];
	}
	Array2D(int index)
	{
		arr1 = new Array1D[index];
	}
	private:
		Array1D *arr1;
};


class BigTable
{
	std::vector<int> v;
	///int accessCounter;
	//mutable int accessCounter;
        int a;
        int *arr;
public:
	int getItem(int index) const
	{
                // two solutions to modify values from const function
                //const_cast<BigTable *>(this)->accessCounter++;
		//accessCounter++;
                arr[index] = index;
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


class Dog
{
public:
	virtual ~Dog()
	{
	}
};

class YellowDog : public Dog
{
	int age;
public:
	void bark()
	{
		std::cout<<"  wooofff .... !  "<<std::endl;
	}
	void bark1()
	{
		std::cout<<"  wooofff .... !  "<<age<<std::endl;
	}
};


class testop
{
	int i;
public:
        testop(int ii) : i(ii)
	{}
	testop& operator++()
	{
		i++;
		return *this ;
	}
	testop operator++(int)
	{
                const testop old(*this);
                //testop old(*this);
                ++(*this);
		return old ;
	}
        int getValue()
	{
		return i;
	}
};


int main()
{
	testop t15(5);;
	++t15;
        std::cout<<" value of i after pre-incremet is : "<<t15.getValue()<<std::endl;
	t15++;
        std::cout<<" value of i after post-incremet is : "<<t15.getValue()<<std::endl;


	Dog *pd = new Dog();
	YellowDog *py = dynamic_cast<YellowDog *>(pd);   // This casting will fail and py will be NULL
	//YellowDog *py = static_cast<YellowDog *>(pd);   // This casting will pass, as it will not check at runtime

	py->bark();  // Even py is NULL, still the bark function will get call, as it is not accepting any members of yellowdog, so compiler will treat it as a statis function

        //py->bark1();  // This line will fail, because it is accessing member of the yellow dog class
	std::cout<<" pd is :  "<<pd<<std::endl;
	std::cout<<" py is :  "<<py<<std::endl;


        //float *fst = static_cast<float *>(tst);    // this will fail as static_cast only cast pointers/references of related type , means in inheritance hierarchy

	py = static_cast<YellowDog *>(pd);  
 
         if(py)
         {
		 std::cout<<" Although the object was null after dynamic_cast, but it's a valid object after static_cast: "<<std::endl;
         }

	long pp = 10009998;
	Dog *dd = reinterpret_cast<Dog *>(pp);


	//test_const t;
        int ij = 10;
	const int x11 = 50;

	BigTable b;
	//const BigTable b1;
	b.fun();
	//b1.fun();

        b.fun_ref(ij);
        b.fun_ref(x11);

	//Array2D a2[10];
	Array2D a2;
	std::cout<<a2[9][9]<<std::endl;
	std::cout<<a2[9][1]<<std::endl;
	std::cout<<a2[9][2]<<std::endl;
	std::cout<<a2[9][3]<<std::endl;
	std::cout<<a2[9][4]<<std::endl;
	std::cout<<a2[9][5]<<std::endl;
	std::cout<<a2[9][6]<<std::endl;
	std::cout<<a2[9][7]<<std::endl;
	std::cout<<a2[9][8]<<std::endl;
	std::cout<<a2[9][9]<<std::endl;
	std::cout<<a2[9][19]<<std::endl;

        for(int i = 0; i<10; i++)
        {
		for(int j = 0; j<10; j++)
		{
			std::cout<<a2[i][j]<<", ";
		}
		std::cout<<std::endl;
	}

        A::x x1;
	function(x1);
	//function();  This line will not compile, However above line will compile
	base *bptr = new Derived();
	bptr->PrintMsg();
	Derived *dptr = new Derived();
        dptr->PrintMsg(10);   // This line will not compile, to make it compile we need using::PrintMsg in public segment of Derived class

        int i = 80;

        //Multiply(10);
        Multiply(i);
        Global() = 89 ;
        std::cout<<" global is : "<<global<<std::endl;
        Derived d;
        d.forTesting();

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


	// Creating array of objects of a class , and class doesn't have default constructor
        typedef test * P;
        P *t = new P[10];

        test **t1 = new test *[10];

        void *rawMemory = operator new[](10*sizeof(test));
        test *t2 = static_cast<test *>(rawMemory);

        for(int i = 0 ; i<10; i++)
         new (&t2[i]) test(i) ;

	return 0;
}
