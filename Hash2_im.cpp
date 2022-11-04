#include<iostream>
using namespace std;
#define MAX 100
#define EMPTY -1
class Linear{
	public:
		int size = MAX;
		int hashkey[MAX];
		string hashtable[MAX];
	
	
	Linear()//contructor
	{
		for(int i=0;i<size;i++)
		{
			hashkey[i] = EMPTY;
			hashtable[i] = "-";
		}
	}
	
	
	void insert(int key,string data)
	{
		for(int i=0;i<size;i++)
		{
			int linear = (key+i) % size; // linear index+1
			
			if(hashkey[linear] == EMPTY)
			{
				hashkey[linear] = key;
				hashtable[linear] = data;
				break;
			}
		}
		
	}
	
	string find(int key)
		{
			for(int i = 0 ; i<size;i++)
			{
				int linear = (key+i) % size;
				
				if(hashkey[linear] == key)
				{
					return hashtable[linear];
				}
				else
				{
					return "-";
				}
			}
		}
	
	
	void print()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"("<<hashkey[i]<<","<<hashtable[i]<<")";
		}
		cout<<endl;
	}
	
	void lazydelete(int key)
	{
		for(int i=0;i<size;i++)
		{
			if(hashkey[i] == key)
			{
				hashkey[i] = -1;
				hashtable[i] = "-";
			}
		}
		
	}
};

int main()
{
	Linear *h = new Linear();
	
	cin>>h->size;
	
	int key; 
	string data; 
	char choice;
	
	while(1)
	{
		cin>>choice;
		if(choice == 'a')
		{
			cin>>key;
			cin>>data;
			h->insert(key,data);
		}
		else if(choice == 'p')
		{
			h->print();
		}
		else if(choice == 's')
		{
			cin>>key;
			cout<<h->find(key);
			
		}
		else if(choice == 'd')
		{
			cin>>key;
			h->lazydelete(key);
		}
		else if(choice == 'e')
		{
			break;
		}
		
	}

	return 0;
}
