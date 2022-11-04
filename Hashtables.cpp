#include <bits/stdc++.h>
using namespace std;
#define MAX     20  // size of array
#define EMPTY   -1
#define DELETED -2 //make gone

// X = Value
class Hashtable{
	private:
		int table[MAX];
		int hash(int x);

	
	public:
	    Hashtable()//constructor
		{
			for(int i = 0; i<MAX;i++)
			{
				table[i] = -1;
			}
		}
		
	
		void Insert(int X)
		{
			
			int index = hash(X);
			table[index] = X;
			cout<< X << " is inserted at "<<index<<endl;
		}	
		
		//return an index of x,or -1 if x is not inserted
		
		int find(int x)
		{
			int index = hash(x);
			if(table[index] == x)
			{
				cout<<x<<" is found at "<<index<<endl;
				return index;
			}
			cout<<x<<" is NOT found"<<endl;
			return -1;
		}
};

int hash(int x)
{
	return (x % MAX); // find key
}


//******************************************//
class QuadraticProbe{
	private:
		int table[MAX];
		int hash(int x);

	
	public:
	    QuadraticProbe()//constructor
		{
			for(int i = 0; i<MAX;i++)
			{
				table[i] = -1;
			}
		}
		
		void Insert(int X)
		{
			
			int hx = hash(X);
			int index = hx;
			int i = 1; //probe counted
			
			//Quadratic probe
			while(table[index] != EMPTY && table[index]!=DELETED )
			{
			    index = (hx+(i*2)) %MAX;
			    i++;
			}
			table[index] = X;
			cout<< X << " is inserted at "<<index<<endl;
		}	
		
		//return an index of x,or -1 if x is not inserted
		
		int find(int x)
		{
			int hx = hash(x);
			int index = hx;
			int i = 1;
			
			
		    while(table[index] != x && table[index]!= EMPTY )//if not found -> find...until found
			{
			    index = (hx+(i*2)) %MAX;
			    i++;
			}
			
			if(table [index] == x)
			{
				cout<<x<<" is found at "<<index<<endl;
				return index;
			}
			cout<<x<<" is NOT found"<<endl;
			return -1;
		}
        		
		int lazydelete(int x)
		{
	    
			int index = find(x);
			if(index != -1)
			{
			    table[index] = DELETED;//delete value
				cout<< x << " is deleted\n";	
			}
			return index;
		}
};

int QuadraticProbe::hash(int x)
{
	return (x % MAX); 
}

//******************************************//
class Hashtable_LinearProbe{
	private:
		int table[MAX];
		int hash(int x);

	
	public:
	    Hashtable_LinearProbe()//constructor
		{
			for(int i = 0; i<MAX;i++)
			{
				table[i] = -1;
			}
		}
		
		void Insert(int X)
		{
			
			int index = hash(X);
			
			//linearprobe
			while(table[index] != EMPTY && table[index]!=DELETED )// Collision
			{
			    index = (index+1) %MAX;//Linear //key+1
			}
			table[index] = X;
			cout<< X << " is inserted at "<<index<<endl;
		}	
		
		//return an index of x,or -1 if x is not inserted
		
		int find(int x)
		{
			int index = hash(x);//find key
			int hx = x;
			
            //linearprobe
			while(table[index] != x && table[index]!= EMPTY )// != value = mar jer
			{
			    index = (index*index+1) %MAX;
			}
			
			if(table [index] == x)
			{
				cout<<x<<" is found at "<<index<<endl;
				return index; //jer index hnai value found at index
			}
			cout<<x<<" is NOT found"<<endl;
			return -1;
		}
		
		int lazydelete(int x)
		{
			int index = find(x);
			if(index != -1)
			{
			    table[index] = DELETED;
				cout<< x << " is deleted\n";	
			}
			return index;
		}
};

int Hashtable_LinearProbe::hash(int x)
{
	return (x % MAX);
}

//******************************************//

class Hashtable_DoubleHash{
	private:
		int table[MAX];
		int hash(int x);
		int hash2(int x);

	
	public:
	    Hashtable_DoubleHash()//constructor
		{
			for(int i = 0; i<MAX;i++)
			{
				table[i] = -1;
			}
		}
		
		void Insert(int X)
		{
			
			int index = hash(X);
			
			while(table[index] != EMPTY && table[index]!=DELETED )//if is not empty or if is not Deleted
			{
			    index = (index+hash2(X)) % MAX;
			}
			table[index] = X;
			cout<< X << " is inserted at "<<index<<endl;
		}	
		
		//return an index of x,or -1 if x is not inserted
		
		int find(int x)
		{
			int index = hash(x);
			

			while(table[index] != x && table[index]!= EMPTY )
			{
			    index = (index+hash2(x)) % MAX;
			}
			
			if(table [index] == x)
			{
				cout<<x<<" is found at "<<index<<endl;
				return index;
			}
			cout<<x<<" is NOT found"<<endl;
			return -1;
		}
		
		int lazydelete(int x)
		{
			int index = find(x);
			if(index != -1)
			{
			    table[index] = DELETED;
				cout<< x << " is deleted\n";	
			}
			return index;
		}
};

int Hashtable_DoubleHash::hash(int x)
{
	return (x % MAX);
}


int Hashtable_DoubleHash::hash2(int x)
{
    return(x % 13)+1;	
}


int main()
{
	Hashtable_DoubleHash *h = new Hashtable_DoubleHash();
	
	h->Insert(500);
	h->Insert(100);
	h->Insert(400);
	h->Insert(200);
	
	cout<<endl;
	
	h->lazydelete(500);
	
	h->find(500);
	h->find(400);
	h->find(100);
	h->find(200);
	

	return 0 ;
}
