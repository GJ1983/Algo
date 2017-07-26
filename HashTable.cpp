#include<iostream>

const int TABLE_SIZE = 128;

class HashEntry
{
private:
	int key;
	int value;
public:
	HashEntry(int key, int value)
	{
		this->key = key;
		this->value = value;
	}
	int getKey()
	{
		return key;
	}

	int getValue()
	{
		return value;
	}
};

class HashMap
{
private:
	HashEntry **table;
public:
	HashMap()
	{
		table = new HashEntry*[TABLE_SIZE];
		for(int i = 0 ; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

int get(int key)
{
	int hash = key%TABLE_SIZE ;
	while(table[hash] != NULL && table[hash]->getKey() != key)
		hash = (hash+1) % TABLE_SIZE ;

	if(table[hash] == NULL)
		return -1;
	else
		return table[hash]->getValue();
}
};


int main()
{
return 0;
}
