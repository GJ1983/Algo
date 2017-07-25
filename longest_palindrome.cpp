#include<iostream>
#include<cstring>

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

int main()
{
        char str[] = "xsssadasssaerfortesttsetrofuuuuuuuuggdffdfdffdffdfdffdfdfdfdf";
        //char str[] = "forrof";
        std::cout<<" Length of maximum palindrom is : "<<longestpalindrome(str)<<std::endl;
	return 0;
}
