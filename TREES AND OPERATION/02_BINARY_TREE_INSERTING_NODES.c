# include<stdio.h>
# include<malloc.h> // for allocating the memory using malloc()


struct Node {   // Structure of each node 

    int data ;

    struct Node * left ;

    struct Node * right ;

};

// we can add nodes to our binary representation by repititon method shown in the previous code 
// now we wil write a function to insert nodes in the binary tree

struct Node * CreateNode( int data ){

    struct Node * n ;   // creating a node pointer

    n= (struct Node *)malloc(sizeof(struct Node));  // memory allocation for the node

    n->data = data;

    n->left= NULL;
    n->right= NULL;
    
    return n;
}

int main(){

    // NOW we will make the Root node of the binary tree

    struct Node * Root = CreateNode ( 100 );

    // Our Root node is created and so now we will create other nodes

    struct Node *  node1 = CreateNode ( 200 );
    struct Node *  node2 = CreateNode ( 300 );

    // Now we will connect the ROOT node with its children

    Root->left = node1;
    Root->right = node2;

    
    return 0;
}