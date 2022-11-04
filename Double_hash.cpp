#include<iostream>
using namespace std;
#define MAX 10
#define EMPTY -1
#define DELETED -2
class DoubleHash{
	public:
		int table[MAX];
		
		DoubleHash()
		{
			for(int i=0;i<MAX;i++)
			{
				table[i] = -1;//set array empty
			}
		}
		
		int hash(int value)
		{
			return value % MAX;//find key
		}
		
		int hash2(int value)
		{
			return (value % 13)+1;//find key
		}
		
		
		
		void insert(int newvalue)
		{
			int index = hash(newvalue);
			
			while(table[index] != EMPTY && table[index] != DELETED)
			{
				index = (index+hash2(newvalue)) % MAX;
			}
			table[index] = newvalue;
			cout<<newvalue<<" is insert at "<<index<<endl;
		}
		
		int find(int value)
		{
			int index = hash(value);
			
			while(table[index] != value && table[index] != EMPTY)
			{
				index = (index+hash2(value)) % MAX;
			}
			
			if(table[index] == value)
			{
				cout<<value<<" is found at "<<index<<endl;
				return index;
			}
			cout<<" is not found "<<endl;
			return -1;
		}
};

int main()
{
	DoubleHash *h = new DoubleHash();
	
	h->insert(5);
	h->insert(2);
	h->insert(7);
	h->insert(47);
	
	
	
	return 0;
}
