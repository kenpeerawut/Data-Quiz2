#include<iostream>
using namespace std;
#define MAX 10
#define EMPTY -1
#define DELETED -2
class QuadraticHash{
	public:
		int table[MAX];
		
		QuadraticHash()
		{
			for(int i=0;i<MAX;i++)
			{
				table[i] = -1; //set array Empty
			}
		}
		
		int hash(int value)
		{
			return value % MAX;
		}
		
	void insert(int newvalue)
	{
		int hx = hash(newvalue);
		int index = hx;
		int i=1;
		
		while(table[index] != EMPTY && table[index] != DELETED)
		{
			index = (hx+(i*2)) % MAX;
			i++;
		}
		table[index] = newvalue;
		cout<<newvalue<<" is insert at "<<index<<endl;
	}
	
	int find(int value)
	{
		int hx = hash(value);
		int index = hx;
		int i=1;
		
		while(table[index] != value && table[index] != EMPTY)// Beware forgot (EMPTY) 
		{
			index = (hx+(i*2)) % MAX;
			i++;
		}
		
		if(table[index] == value)
		{
			cout<<value<<" is found at "<<index<<endl;
			return index;
		}
		cout<<value<<" is not found "<<endl;
		return -1;
	}
	
	int lazydelete(int value)
	{
		int index = find(value);
		
		if(index != -1)
		{
			table[index] = DELETED;
			cout<<value<<" is Deleted ";
		}
		return index;
	}
};

int main()
{
	QuadraticHash *h = new QuadraticHash();
	
	h->insert(2);
	
	h->find(5);
    
	
	
	return 0;
}
