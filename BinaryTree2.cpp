#include <iostream>
using namespace std;

class Node{
	private:
		int key;
		Node *left, *right;
	public:
		Node(int data){
			key = data;
			left = NULL;
			right = NULL;
		}
		void PreorderTraversal(Node *n);
		void PostorderTraversal(Node *n);
		void InorderTraversal(Node *n);	
		Node* insert(int newitem, Node *n);	
		bool find(int item, Node *n);
		
		Node* remove(int item, Node *n);
		
};

Node* Node::remove(int item, Node *n){//left sub tree ->Maximum left subtree
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




bool Node::find(int item, Node *n){
	if (n == NULL) {
		return false;
    }
    
    if (item == n->key){
    	return true;
    } else if (item < n->key){
    	return find(item, n->left);
    } else {
    	return find(item, n->right);
    }
	
}

Node* Node::insert(int newitem, Node *n){
	if (n == NULL) {
		//cout << "create new node " << newitem << endl;
		Node *newnode = new Node(newitem);
		return newnode;
	}
	
	if (newitem < n->key) {
		n->left = insert(newitem, n->left);
	} else {
		n->right = insert(newitem, n->right);
	}
	
}




void Node::PreorderTraversal(Node *n){
	if (n == NULL) return;
	
	//Step 1: Visit root node
	cout << n->key << " - ";
	
	//Step 2: Visit left sub tree in preorder
	PreorderTraversal(n->left);
	
	//Step 3: Visit right sub tree in preorder
	PreorderTraversal(n->right);
}

void Node::PostorderTraversal(Node *n){
	if (n == NULL) return;
	
	//Step 1: Visit left sub tree in postorder
	PostorderTraversal(n->left);
	
	//Step 2: Visit right sub tree in postorder
	PostorderTraversal(n->right);
	
	//Step 3: Visit root node
	cout << n->key << " - ";
}


void Node::InorderTraversal(Node *n){
	if (n == NULL) return;
	
	//Step 1: Visit left sub tree in inorder
	InorderTraversal(n->left);
	
	//Step 2: Visit root node
	cout << n->key << " - ";
	
	//Step 3: Visit right sub tree in inorder
	InorderTraversal(n->right);
}




int main(int argc, char** argv) {
	
	Node *bst = NULL;
	
	int arr[9] = {50, 10, 40, 80, 7, 9 ,14, 13, 22};
	for (int i=0; i<9; i++){
		bst = bst->insert(arr[i], bst);
	}
	bst->InorderTraversal(bst);
	cout<<endl;
	
	/*
	bst->PreorderTraversal(bst);
	cout<<endl;
	
	bst->PostorderTraversal(bst);
	cout<<endl;
	*/
	
	/*
	cout << "\nFind 7 " << bst->find(7,bst);
	cout << "\nFind 14 " << bst->find(14,bst);
	cout << "\nFind 100 " << bst->find(100,bst);
	*/
	
	
	bst = bst->remove(7,bst);
	bst->InorderTraversal(bst);
	cout<<endl;
	
	bst = bst->remove(40,bst);
	bst->InorderTraversal(bst);
	cout<<endl;
	
	
	
	

	return 0;
}

