#include<iostream>
using namespace std;
class node{
	public:
    node *right;
    node *left; 
    int value = 0;
    node(int v){
       value = v;
       left = NULL;
       right = NULL;
    }
};
class tree{
	public:
    node *n; 
    tree(){
		n=NULL;
	}
    tree(int value){
       n = new node(value);
    }
    bool search(int value){
	    node *i = n;
	    while(true){
	        if(i->value>value&&i->left!=NULL)           { i = i->left;}
	        else if(i->value<value&&i->right!=NULL)     { i = i->right;}
	        else if(i->value==value)                    { return true;}
	        else                                        { return false;}
	    } 
	}
    bool search_counter(int value){
		int counter = 0;
	    node *i = n;
	    while(true){
	        if( i->value > value && i->left != NULL )           { counter++; i = i->left;}
	        else if( i->value < value && i->right != NULL )     { counter++; i = i->right;}
	        else if( i->value == value )                        { counter++; cout<<counter<<'\n'; return true;}
	        else                                                { counter++; cout<<counter<<'\n'; return false;}
	    } 
	}
	void add_node(int key){
		node *i=n;
		while(true){
			if(i==NULL){
				n=new node(key);
				break;
			}
			else if(i->value>key&&i->left!=NULL){
				i=i->left;
			}
			else if(i->value<key&&i->right!=NULL){
				i=i->right;
			}
			else if(i->value<key&&i->right==NULL){
				i->right=new node(key);
				break;
			}
			else if(i->value>key&&i->left==NULL){
				i->left=new node(key);
				break;
			}
			else if(i->value==key&&i->right==NULL){
				i->right=new node(key);
				break;
			}
			else if(i->value==key&&i->right!=NULL){
				i=i->right;
			}
			else break;
		}
		
	}
	void DFS_Pre_order (node *m){
		if( m != NULL )
		{
			cout<<m->value<<",";
			DFS_Pre_order(m->left);
			DFS_Pre_order(m->right);
		}		
	}
	void DFS_In_order (node *m){
		if( m != NULL ){
			DFS_In_order(m->left);
			cout<<m->value<<",";
			DFS_In_order(m->right);
		}		
	}
	void DFS_Post_order (node *m){
		if( m != NULL ){
			DFS_Post_order(m->left);
			DFS_Post_order(m->right);
			cout<<m->value<<",";
		}		
	}	
	int max_height = 0;
	int temp_height = 0;
	void height (node *m){
	    if( m != NULL ){
	        temp_height++;
	        height(m->left); 
	        if(temp_height > max_height ){
	            max_height = temp_height;
	        }
	        height(m->right); 
	        temp_height --;
	    }   
	}
	void BFS_help(node *m, int level){    
	    if(level == 0){ cout<<m->value<<","; }
	    else{
	        if( m->left != NULL ) {  BFS_help(m->left,level-1);   }
	        if( m->right != NULL ){  BFS_help(m->right,level-1);  }     
	    }
	}  
	void BFS(){
		max_height = 0;
		height(n);
		for(int i=0 ; i < max_height ; i++){
	    	BFS_help(n,i);
	    	cout<<"|";
		} 
		cout<<endl;
	}	
	void Depth_node(int value){
		int num_Depth = 0;
	    node *i = n;
	    while(true){
	        if( i->value > value && i->left != NULL ){ 
				num_Depth++;
				i = i->left;      
			}
	        else if( i->value < value && i->right != NULL ){ 
				num_Depth++;
				i = i->right;    	
			}
	        else if( i->value == value ){ 
				cout<<num_Depth<<endl;  	
				return;
			}
	        else{ 
				cout<<"-1"<<'\n'; 
				return;
			}
	    } 	
	}
	int max_temp_height = 0;
	int max_height_node = 0;
	void height2 (node *m){
	    if( m != NULL ){
	        max_temp_height++;
	        height2(m->left); 
	        if(max_temp_height > max_height_node ) {
	            max_height_node = max_temp_height;
	        }
	        height2(m->right); 
	        max_temp_height--;
	    }   
	}
	void height_node(int value){
		max_height_node = -1;
		max_temp_height = -1;
	    node *i = n;
	    while(true){
	        if( i->value > value && i->left != NULL ){ 
				i = i->left;      
			}
	        else if( i->value < value && i->right != NULL ){ 
				i = i->right;    	
			}
	        else if( i->value == value ){ 
				height2(i);
				cout<<max_height_node<<'\n';  	
				return;
			}
	        else{ 
				cout<<"-1"<<'\n'; 
				return;
			}
	    } 
	}
	void delete_node(int v){
	    node *parent = n;
	    node *current = n;   
	    while(true){
	        parent = current;  // update parent
	        //.............................ROOT
			if(n->value == v) //current->value == v
			{
			    if(current->left == NULL && current->right == NULL){
			        return;
			    }
			    else if(current->right != NULL ){
			        SwitchValueR(current);                                     
			    }
			    else if(current->left != NULL){
			       	SwitchValueL(current);
			    }                    
			    return;               
			}
			//Left
			else if(current->value > v){
			    if( current->left != NULL )		{ current = current->left; 		}
			    else							{ return;						}                 
			    if(current->value == v){
			        if(current->left == NULL && current->right == NULL)   //1
			        {                    
			            parent->left = NULL; 
			        }
			        else if(current->left == NULL && current->right != NULL)  //2
			        {
			            parent->left = current->right;
			        }
			        else if(current->left != NULL && current->right == NULL)  //2
			        {
			            parent->left = current->left;
			        }
			        else if(current->left != NULL && current->right != NULL)  //3.1,3.2,3.3
			        {
			            SwitchValueR(current);
			        }          
			        return;
			    }                        
			}
			//right
			else if(current->value < v){
			    if( current->right != NULL )	{current = current->right;}
			    else                        	{return;} 
			    if( current->value == v){
			        if(current->left == NULL && current->right == NULL) //1
			        {
			            parent->right = NULL; 
			        }
			        else if( current->left == NULL && current->right != NULL ) //2
			        {
			            parent->right = current->right;
			        }
			        else if (current->left != NULL && current->right == NULL)  //2
			        {
			            parent->right = current->left;
			        }  
			        else if( current->left != NULL && current->right != NULL )  //3.1,3.2,3.3
			        {
			            SwitchValueR(current);
			        }                     
			        return;
			    }                     
			}
	    }        
	}     
	//Help
	void SwitchValueR(node *current){
	    node *Pmin  = current->right; 
	    node *min   = current->right;
	    if( min->left == NULL )  //3.2
		{
	        current->value = min->value; 
	        current->right = min->right; 
	        return; 
	    }
	    while(true){
	        min = min->left; 
	        if(min->left == NULL && min->right == NULL)      //3.1
	        {
	            current->value = min->value; 
	            Pmin->left = NULL; 
	            return;
	        }
	        if(min->left == NULL && min->right != NULL)   //3.3
	        {
	            current->value = min->value; 
	            Pmin->left = min->right; 
	            return;
	        }
	        Pmin = min;
	    }        
	}
	void SwitchValueL(node *current){
	    node *Pmin  = current->left;
	    node *min   = current->left;
	    if( min->right == NULL ){
	        current->value = min->value; current->left = min->left; return; 
	    }    
	    while(true){
	        min = min->right; 
	        if(min->right == NULL && min->left == NULL) {
	            current->value = min->value; Pmin->right = NULL; return;
	        }
	        if(min->right == NULL && min->left != NULL){
	            current->value = min->value; Pmin->right = min->left; return;
	        }
	        Pmin = min;
	    }           
	}    
};
int main(){
    char s;
    int num=0;
    tree *t=new tree();
    while(1){
        cin>>s;
        if(s=='i'){
			cin>>num;
            t->add_node(num);
        }
        else if(s=='d'){
            cin>>num;
            t->delete_node(num);
        }
        else if(s=='p'){
            t->BFS();
        }
        else if(s=='x'){
            break;
        }
    }
    return 0;
}

