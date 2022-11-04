#include<iostream>
using namespace std;
#define MAX 100
#define EMPTY -1
#define NONE "-"
//------------------------Double hash----------------------------------------//
class Double{
	public:
		int size1 = MAX;
		int size2 = MAX;
		
		int hashkey[MAX];
		string hashtable[MAX];
		
		Double()//constructor  //set all 0
		{
			for(int i=0;i<size1;i++)
			{
				hashkey[i] = EMPTY;
				hashtable[i] = NONE;
			}
		}
		
		void insert(int key,string data)
		{
			for(int i=0;i<size1;i++)
			{
				if(i == 0)//not collision
				{
					int h1 = key%size1;
					
					if(hashkey[h1] == EMPTY)
					{
						hashkey[h1] = key;
						hashtable[h1] = data;
						break;
					}
				}
				if(i != 0)//collision
				{
					int sizeX = size2-(key%size2);
					int x = (key+(i*sizeX)) %size1;
					
					if(hashkey[x] == EMPTY)
					{
						hashkey[x] = key;
						hashtable[x] = data;
						break;
					}
				}
			}
		}
		
		string find(int key)
		{
			for(int i=0;i<size1;i++)
			{
				if(i == 0)//not collision
				{
					int h1 = key%size1;
					
					if(hashkey[h1] == key)
					{
						return hashtable[h1];
					}
					else
					{
						return NONE;
					}
				}
				if(i != 0)// collision
				{
					int sizeX = size2-(key%size2);
					int x = (key+(i*sizeX)) % size1;
					
					if(hashkey[x] == key)
					{
						return hashtable[x];
					}
					else
					{
						return NONE;
					}
				}
			}
		}
		
		
		void print()
		{
			for(int i=0;i<size1;i++)
			{
				cout<<"("<<hashkey[i]<<","<<hashtable[i]<<")";
			}
			cout<<endl;
		}
		
		
		void lazydelete(int key)
		{
			for(int i=0;i<size1;i++)
			{
				if(hashkey[i] == key)
				{
					hashkey[i] = EMPTY;
					hashtable[i] = NONE;
				}
			}
			
		}
	
};

int main()
{
	Double d;
	
	cin>>d.size1;
	cin>>d.size2;
	
	char b;
	int key;
	string data;
	
	while(1)
	{
		cin>>b;
		if(b == 'a')
		{
			cin>>key;
			cin>>data;
			d.insert(key,data);
		}
		else if(b == 's')
		{
			cin>>key;
			cout<<d.find(key)<<endl;
		}
		else if(b == 'p')
		{
			d.print();
		}
		else if(b == 'e')
		{
			break;
		}
		else if(b == 'd')
		{
			cin>>key;
			d.lazydelete(key);
		}
	}
	
	
	
	return 0;
}
