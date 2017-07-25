#include<iostream>


void printunion(int arr1[],int arr2[], int size_array1 ,int size_array2)
{
	int i = 0;
	int j = 0;

	while(i<size_array1 && j <size_array2)
	{
		if(arr1[i] < arr2[j])
		{
			std::cout<<arr1[i]<<std::endl;
			i++;
		}
		else if (arr1[i] > arr2[j])
		{
			std::cout<<arr2[j]<<std::endl;
			j++;
		}
		else
		{
			std::cout<<arr1[i]<<std::endl;
			i++;
			j++;
		}
	}
        while(i < size_array1)
        {
		std::cout<<arr1[i]<<std::endl;
		i++;
        }
        while(j < size_array2)
        {
		std::cout<<arr2[j]<<std::endl;
		j++;
        }
}

int main()
{
	int arr1[] = {1, 2,6,7,8,9};
	int arr2[] = {2,3,4,8};
	int size_array1 = sizeof(arr1)/sizeof(arr1[0]) ;
	int size_array2 = sizeof(arr2)/sizeof(arr2[0]) ;

	printunion(arr1,arr2, size_array1 ,size_array2);
	return 0;
}
