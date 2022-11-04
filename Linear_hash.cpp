#include<iostream>
using namespace std;
#define MAX 10
#define EMPTY -1
#define DELETED -2
class Linearhash{
	public:
		int table[MAX];
		
		int hash(int value)
		{
			return value % MAX;//find key
		}
		
		Linearhash()
		{
			for(int i=0;i<MAX;i++)
			{
				table[i] = -1;
			}
		}
		
		void insert(int newvalue)
		{
			int index = hash(newvalue);
			
			while(table[index] != EMPTY && table[index] != DELETED)
			{
				index = (index+1) % MAX;
			}
			table[index] = newvalue;
			cout<<newvalue<<" is insert at "<<index<<endl;
		}
		
		int find(int value)
		{
			int index = hash(value);
			
			while(table[index] != value && table[index] != EMPTY)
			{
				index = (index*index+1) % MAX;
			}
			
			if(table[index] == value)
			{
				cout<<value<<" is found at "<<index<<endl;
				return index;
			}
			cout<<value<<" is not found "<<endl;
			return -1;
		}
		
		int lazyDeleted(int value)
		{
			int index = find(value);
			if(index != -1)
			{
				table[index] = DELETED;
				cout<<value<<" is Deleted\n ";
			}
			return index;
		}
};
int main()
{
	Linearhash *h = new Linearhash();
	
	h->insert(500);
	h->insert(10);
	h->insert(4);
	h->insert(5);
	
	h->lazyDeleted(4);
	h->find(200);
	h->find(10);
	h->find(4);
	
	
	return 0;
}
