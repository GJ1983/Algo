#include<iostream>
#include<cstring>
#include<cstdlib>

void arrayunion(int arr1[],int arr2[], int size_array1 ,int size_array2);
int longestpalindrome(char *str);
void findDuplicate(int *arr, int size);
int find_max_repetition(int arr[], int n);
void reverse(char *str);
void copy (char *str);

int main()
{
	//Palindrome ..............................
        char str[] = "xsssadasssaerfortesttsetrofuuuuuuuuggdffdfdffdffdfdffdfdfdfdf";
        //char str[] = "forrof";
        std::cout<<" Length of maximum palindrom is : "<<longestpalindrome(str)<<std::endl;

	//array union .........................
	int arr1[] = {1, 2,6,7,8,9};
	int arr2[] = {2,3,4,8};
	int size_array1 = sizeof(arr1)/sizeof(arr1[0]) ;
	int size_array2 = sizeof(arr2)/sizeof(arr2[0]) ;
	arrayunion(arr1,arr2, size_array1 ,size_array2);

	//find duplicate ................
	int arr[] = { 3,2,1,7,5,9,4};
	int size = sizeof(arr)/sizeof(arr[0]) ;
	findDuplicate(arr,size);

	//Max repetition
	int arr3[] = {5,5,1,4,5,5,5,1};
	int size1 = sizeof(arr)/sizeof(arr[0]) ;
	int n = find_max_repetition(arr3, size1);
	std::cout<<" element repeated max number of times is :  "<< arr[n] <<std::endl;

	// String operation
	char *str11 = "my career stack";
	//reverse(str11);
	//copy(str);

	return 0;
}


void reverse(char *str)
{
	std::cout<<str<<std::endl;

	int index = 0;
        int tindex = 0;

	int length = strlen(str);

	char *temp = (char *)malloc(length*sizeof(int));

	while(str[index] != '\0')
	{
		std::cout<<str[index];

		*(temp+tindex) = *(str+index);

		if(std::isspace(*(str+index)))
                {
			std::cout<<"======> "<<std::endl;
                        strcpy(temp, '\0');
			tindex = 0;
		}

                 
		index++;
		tindex++;
		std::cout<<" temp is "<<temp<<std::endl;
	}
}

void copy (char *str)
{
	int index = 0;

	int length = strlen(str);

	char *temp = (char *)malloc(length*sizeof(int));
         
        while(*(str+index))
        {
		*(temp+index) = *(str+index) ;
                index++; 
	}

	std::cout<<" temp is ====>"<<temp<<std::endl;
}


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

int longestpalindrome(char *str)
{
	int maxlength = 1;
	int len = strlen(str);
	int low, high;

	for(int i=0; i<len; i++)
	{
		low = i-1;
		high = i;

		while(i>=0 && high<len && str[low] == str[high])
		{
			if(maxlength < high-low+1)
			{
				maxlength = high-low+1;
			}
			high++ ;
			low--;
		}
	}

	return maxlength;
}

void arrayunion(int arr1[],int arr2[], int size_array1 ,int size_array2)
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

