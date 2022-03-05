# include<stdio.h>
# include<malloc.h> // for allocating the memory using malloc()

struct Node {   // Structure of each node 

    int data ;

    struct Node * left ;

    struct Node * right ;

};

//*                                         BINARY SEARCH TREE
//*     
//*                                                 400
//*                                               /     \  
//*                                            200       600
//*                                          /    \     /   \
//*                                         100   300  500  700

struct Node * CreateNode( int data );
int IN_ORDER( struct Node * root );


//! INSERTION FUNCTION 

struct Node * INSERT( struct Node * root , int value ){

    struct Node * previous= NULL;   // pointer to traverse and find a spot for the insertion

    while( root != NULL ){  // this loop will run until it reaches the leaf node or the null place to insert
        previous = root;
        if( value == root->data){
            printf(" THE INSERTION CANNOT BE PERFORMED BECAUSE THE %d IS ALREADLY PRESENT IN BST\n", value);
            return 0 ;    // since the value is already present in BST and BST cannot have duplicate value so we cannot insert
        }
        else if ( value < root->data ){
            root = root->left;
        }
        else if ( value > root->data ){
            root = root->right;
        }
    }
    struct Node * new = CreateNode( value );    // new node

    // since previous is our pointer which stays one step back ( that's why named previous ) so 
    // now we will see where we have to insert, on left or right
    if( value < previous->data){
        previous->left = new;
    }
    else if( value > previous->data){
        previous->right = new;
    }
}



int main(){

    // NOW we will make the Root node of the binary tree

    struct Node * Root = CreateNode ( 400 );

    // Our Root node is created and so now we will create other nodes

    struct Node *  node1 = CreateNode ( 200 );
    struct Node *  node2 = CreateNode ( 600 );

    // Now we will connect the ROOT node with its children

    Root->left = node1;
    Root->right = node2;

    struct Node *  node1_1 = CreateNode ( 100 );
    struct Node *  node1_2 = CreateNode ( 300 );
    node1->left = node1_1;
    node1->right = node1_2;

    struct Node *  node2_1 = CreateNode ( 500 );
    struct Node *  node2_2 = CreateNode ( 700 );
    node2->left = node2_1;
    node2->right = node2_2;

    IN_ORDER( Root );
    printf("\n\n");

    INSERT( Root , 1000);
    INSERT( Root , 200);
    INSERT( Root , 50);
    INSERT( Root , 950);

    IN_ORDER( Root );
    printf("\n\n");



    return 0;
}





int IN_ORDER( struct Node * root ){

    if( root != NULL ){

        IN_ORDER( root->left); // left is first

        printf("  %d    ",root->data); // root is second
        
        IN_ORDER( root->right);// right is last

    }

}

// function to create node
struct Node * CreateNode( int data ){

    struct Node * n ;   // creating a node pointer

    n= (struct Node *)malloc(sizeof(struct Node));  // memory allocation for the node

    n->data = data;

    n->left= NULL;
    n->right= NULL;
    
    return n;
}
