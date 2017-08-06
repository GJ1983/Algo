#include<iostream>
#include<vector>

class BigTable
{
	std::vector<int> v;
	///int accessCounter;
	mutable int accessCounter;
public:
	int getItem(int index) const
	{
                // two solutions to modify values from const function
                const_cast<BigTable *>(this)->accessCounter++;
		accessCounter++;
		return v[index];
	}
};


int main()
{
return 0;
}
