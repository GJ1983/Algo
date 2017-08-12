#include<iostream>


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

int main()
{
	Dog *pd = new Dog();
	YellowDog *py = dynamic_cast<YellowDog *>(pd);   // This casting will fail and py will be NULL
	//YellowDog *py = static_cast<YellowDog *>(pd);   // This casting will pass, as it will not check at runtime

	py->bark();  // Even py is NULL, still the bark function will get call, as it is not accepting any members of yellowdog, so compiler will treat it as a statis function

        py->bark1();  // This line will fail, because it is accessing member of the yellow dog class
	std::cout<<" pd is :  "<<pd<<std::endl;
	std::cout<<" py is :  "<<py<<std::endl;
	return 0;
}
