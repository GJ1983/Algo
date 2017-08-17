#include<iostream>
#include<memory>
#include<string>

class test
{
	std::string data;
public:
	test(){}
	test(std::string dat):data(dat)
	{}
};

class test_weak
{
	std::string name;
	//std::shared_ptr<test_weak> m_test;  // cyclic rerfernce, because of this destructor will not get called
        std::weak_ptr<test_weak> m_test; //to overcome cyclic refernce above, we need to use weak pointer instead of shared pointer
public:
	test_weak(std::string data) : name(data)
	{}

	void make_friend(std::shared_ptr<test_weak> sp)
	{
		m_test = sp;
	}

	void show_friend()
	{
		//std::cout<<m_test->name<<std::endl;  // This line will not compile, as we can't use weak_pointer as a normal pointer
		std::cout<<m_test.lock()->name<<std::endl;
	}

        int sharedptr_count()
        {
		return m_test.use_count();
	}

	~test_weak()
	{
		std::cout<<" pointer is destroyed: "<<name <<std::endl;
	}
};

int main()
{
        std::shared_ptr<test> p0(new test) ;

	std::shared_ptr<test> p1 = std::make_shared<test>("Testing");  // This is the better way than p0, in p0 there are 2 calls 1: to creat test object 2. to create shared pointer out of itthere may be chances that creattion of test object is succedded but share_ptr failed

	std::shared_ptr<test> p2 = std::shared_ptr<test>(new test("Smart"), [](test *p) {std::cout<<"custom deleter.. "<<std::endl; delete p;});
	//std::shared_ptr<test> p2 = std::shared_ptr<test>(new test("Smart"), [](auto *p) {std::cout<<"custom deleter.. "<<std::endl; delete p;});   //will compile with c++14

	//std::shared_ptr<test> p3( new test[3]);  // This line can lead to memory leak, here we need customer deleter, otherwise shared pointer will just delete memory for test[0]

	std::shared_ptr<test> p4(new test[3], [](test *p) { delete [] p; } ); // This is the correct way to declare shared pointer, when we need custome deleter.


        test *t = p4.get() ;  //return the raw pointer that shared pointer is pointing

	 //unique pointer is light weight smart pointer

	std::unique_ptr<test> up( new test("Unique up"));

        test *t1 = up.release(); // here up has released it's ownership 

        if(!up)
		std::cout<<" Unique pointer up is now empty! "<<std::endl;

        up.reset(new test("new unique "));
        if(!up)
		std::cout<<" Unique pointer up is now empty! "<<std::endl;
	else
		std::cout<<" Unique pointer up is not empty! "<< std::endl;

	std::unique_ptr<test[]> up1( new test[3]); // we don't need any custom deleter here

	std::shared_ptr<test_weak> spw(new test_weak("Testing shared pointer"));
	std::shared_ptr<test_weak> spw1(new test_weak("Testing shared pointer1 for cycle"));

        spw->make_friend(spw1); 
        spw1->make_friend(spw); 

	std::cout<<" friend of spw1 is : =====> " ;
	spw1->show_friend();
	std::cout<<std::endl;

        std::cout<<" Shared pointer refred by weak pointer spw are =========>: "<<spw->sharedptr_count()<<std::endl;
 
	return 0;
}


// Auto pointer implementation

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

