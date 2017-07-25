#include<iostream>


void findDuplicate(int *arr, int size)
{
	int temp[100];

	for(int i = 0; i< size; i++)
	{
		if( temp[arr[i]] == 1)
                {
			std::cout<<" Duplicates values are present in the array : " <<std::endl;
			return ;
                }
		temp[arr[i]] = 1;
	}

	std::cout<<" No Duplicates are their in the array : " <<std::endl;

}


int main()
{

int arr[] = { 3,2,1,7,5,9,4};
int size = sizeof(arr)/sizeof(arr[0]) ;
findDuplicate(arr,size);
return 0;
}
