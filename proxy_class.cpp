#include<iostream>

class Array2D
{
public:
       // Proxy class implemenation
	class Array1D
	{
	private:
		int *data;
	public:
		Array1D()
		{
			data = new int;
                        for(int i = 0; i<=10; i++)
			{
				data[i] = i;
			}
		}
		int operator[](int index)
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


int main()
{
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

        for(int i = 0; i<=10; i++)
        {
		for(int j = 0; j<10; j++)
		{
			std::cout<<a2[i][j]<<", ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
