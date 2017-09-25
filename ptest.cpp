#include<iostream>

void swap(int *a, int *b)
{
	int *temp = new int;
	*temp = *a;
	*a = *b ;
	*b= *temp;
}

void swap1(int **a, int **b)
{
	int *temp = new int;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int *a  = new int;
	int *b  = new int;

	*a = 10;
	*b = 20;

        //int a = 10;
        //int b = 20;

	std::cout<<" a before swapping is: "<<*a<<std::endl;
	std::cout<<" b before swapping is: "<<*b<<std::endl;

	swap1(&a,&b);

	std::cout<<" a after swapping is: "<<*a<<std::endl;
	std::cout<<" b after swapping is: "<<*b<<std::endl;
	return 0;
}
