#include<iostream>
using namespace std;

class Node{
	
	public:
		int key;
		Node *left,*right;
		
		
	Node(int data)
	{
		key = data;
		left = NULL;
		right = NULL;
	}
	
	void PreorderTraversal(Node *n)
	{
		if(n == NULL) return;
		
		cout<< n->key << ",";
		
		PreorderTraversal(n->left);
		
		PreorderTraversal(n->right);
	}
	
	void InorderTraversal(Node *n)
	{
		if(n == NULL) return;
		
		InorderTraversal(n->left);
		
		cout<< n->key << ",";
		
		InorderTraversal(n->right);
	}
	
	void PostorderTraversal(Node *n)
	{
		if(n == NULL) return;
	
		PostorderTraversal(n->left);
		
		cout<< n->key << ",";
		
		PostorderTraversal(n->right);
	}
	
	Node* insert(int newitem,Node *n)
	{
		if(n == NULL)
		{
			Node *newnode = new Node(newitem);
			return newnode;
		}
		else if(newitem < n->key)
		{
			n->left = insert(newitem,n->left);
		}
		else
		{
			n->right = insert(newitem,n->right);
		}
	}
	
	
	bool find(int item,Node *n)
	{
		if(n == NULL)
		{
			return false;
		}
		else if(item == n->key)
		{
			return true;
		}
		else if(item < n->key)
		{
			return find(item,n->left);
		}
		else
		{
			return find(item,n->right);
		}
	}
	
Node* remove(int item, Node *n){//left sub tree ->Maximum left subtree
	if (n == NULL){
		cout << item << "is not found!\n";
		return NULL;
	}
	if (n->key == item){
		//Found a node to delete .
		
		if(n->left == NULL && n->right == NULL){
			//case 1: NO CHILD---------- (leaf node)
			return NULL;
		}
		else if(n->left != NULL && n->right != NULL){//!=  = have 2 Children
			//case 3: 2 CHILDREN------------
			
		    //step 1: Find maximum in left subtree
		    Node* predecessor = n->left;
		    while(predecessor->right != NULL){
		    	predecessor = predecessor->right;
		    }
		    
		    //step 2: copy predecessor to deleting Node
		    n->key = predecessor->key;
		    
		    //step 3: remove predecessor 
		    n->left = remove(predecessor->key,n->left);
		    return n;
		    
		} else{
			//case 2: 1 CHILD------------
			if(n->left != NULL) return n->left;
			return n->right;
		}
		
	}
	else if(item < n->key){
		n->left = remove(item, n->left);  //n->left = parent
	}
	else{
		n->right = remove(item, n->right);
	}
	
	return n;
}

   
};

int main()
{
	Node *bst = NULL;
	
	int n; //set n to input size of array
	int arr[n];
	char choice;
	int item;
	int newitem;
	
	cin>>n; // input size of array
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];// input element of array 
		bst = bst->insert(arr[i],bst);
	}
	
	while(1)
	{
		cin>>choice;
		
		if(choice == 'I')
		{
			bst->InorderTraversal(bst);
			cout<<endl;
		}
		else if(choice == 'E')
		{
			bst->PreorderTraversal(bst);
			cout<<endl;
		}
		else if(choice == 'O')
		{
			bst->PostorderTraversal(bst);
			cout<<endl;
		}
		else if(choice == 'F')
		{
			cin>>item;
			cout<<bst->find(item,bst);
		}
		else if(choice == 'D')
		{
			cin>>item;
			bst->remove(item,bst);
			bst->PreorderTraversal(bst);
			cout<<endl;
		}
		else if(choice == 'N')
		{

			cin>>newitem;
			bst->insert(newitem,bst);
			bst->PreorderTraversal(bst);
			cout<<endl;
		}
		else if(choice == 'X')
		{
			break;
		}
	}
	
	
	return 0;
}
