#include<iostream>
#include<vector>

class Person
{
	//std::string *m_name;
	std::string m_name;
public:
	Person(){}
	Person(std::string name)
	{
		//m_name = new std::string(name);
		m_name = name;
	}
	void printName()
	{
		//std::cout<<*m_name<<std::endl;
		std::cout<<m_name<<std::endl;
	}
	~Person()
	{
		//delete m_name;
	}
};

int main()
{
std::vector<Person> persons;
persons.push_back(Person("Geroge"));   //// This will crash
persons.push_back(Person());   //// This will crash

//  1. George has constructed.
//  2. Copy of George is copied to vector
//  3. George is destructed

// The reason for program crash is, default copy construcror provided by compiler used to do shallow copying, because of this both George and the copy of George is pointing to same memory location, and afterward we are caling destructor 

// Possible solutions are as below.
// 1. Define copy constructor and assignment operator for deep copying
// 2. Delete both copy constructor and assignment operator


//persons.back().printName();


return 0;
}
