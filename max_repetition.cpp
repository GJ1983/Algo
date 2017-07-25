#include<iostream>



int find_max_repetition(int arr[], int n)
{

	int max = 0, maxIndex = 0;

	for(int i = 0 ; i <n ; i++)
		arr[arr[i]%n] += n;

	for(int i = 0 ; i <n ; i++)
	{
		if(arr[i]/n > max)
		max = arr[i]/n;
		maxIndex = i;
	}

	return maxIndex;

}




int main()
{

	int arr[] = {4,4,4,4,4,5,1,4,3,4,5,4,3,4,5,5,4,4,4,4,4};

	int size = sizeof(arr)/sizeof(arr[0]) ;

	int n = find_max_repetition(arr, size);

	std::cout<<" element repeated max number of times is :  "<< arr[n] <<std::endl;

	return 0;
}
