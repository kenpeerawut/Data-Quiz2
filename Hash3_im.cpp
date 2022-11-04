#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class hash_linear{
	public:
		int size = MAX ;
		int hashkey[MAX];
		string hashtable[MAX];
		
		hash_linear() // set all data to 0
		{
			for(int i =0 ; i< size;i++)
			{
				hashkey[i] = -1;
				hashtable[i] = "-";
			}
		}
		
		void insert(int key,string data)
		{
			
			for(int i = 0 ;i < size;i++) // loop through every index 
			{
				int linear = (key+(i*i)) % size; // using linnear index+1
				
				if(hashkey[linear] == -1)
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
				int linear = (key+(i*i)) % size;
				
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
			for(int i =0 ; i< size ;i++)
			{
				cout<<"("<<hashkey[i]<<","<<hashtable[i]<<")";
			}
			cout<<endl;
		}
};


int main()
{
	hash_linear l;

	cin>>l.size;
	
	char button;
	int key;
	string data;
	
	while(1)
	{
		cin>>button;
		
		if(button == 'a')
		{
			cin>>key;
			cin>>data;
			l.insert(key,data);
		}
		else if(button == 's')
		{
			cin>>key;
			cout<<l.find(key)<<endl;
		}
		else if(button == 'p')
		{
			l.print();
		}
		else if(button == 'e')
		{
			break;
		}
		
	}
	
}
