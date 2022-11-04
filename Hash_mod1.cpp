#include<iostream>
using namespace std;
#define MAX 10000
#define EMPTY -1
#define DELETED -2
class Hash{
	public:
		int table[MAX];
		
		Hash()//constructor
		{
			for(int i=0;i<MAX;i++)
			{
				table[i] = -1; //set array empty
			}
		}
		
		int hash(int value)//find key
		{
			return value % MAX;
		}
		
		void insert(int newvalue)
		{
			int index = hash(newvalue);
			table[index] = newvalue;
			cout<<newvalue<<" is insert at "<<index<<endl;
		}
		
		int find(int value)
		{
			int index = hash(value);
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
			if(table[index] != -1)
			{
				table[index] = DELETED;
				cout<<value<<" is Deleted ";
			}
			return index;
		}
};

int main()
{
	Hash *h = new Hash();
	
	h->insert(10);
	h->insert(1);
	h->insert(8);
	
	h->find(1);
	h->find(0);
	return 0;
}

