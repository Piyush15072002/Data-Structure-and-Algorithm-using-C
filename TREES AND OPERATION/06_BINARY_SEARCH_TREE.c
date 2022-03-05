# include<stdio.h>
# include<malloc.h> // for allocating the memory using malloc()

/*
*    A BINARY SEARCH TREE IS A BINARY TREE WITH SOME DIFFERENT PROPERTIES LIKE THIS-
*
*        1. ALL NODES OF THE LEFT SUBTREE ARE LESSER THAN THE ROOT
*
*        2. ALL NODES OF THE RIGHT SUBTREE ARE GREATER THAN THE ROOT
*
*        3. ALL LEFT SUBTREE AND RIGHT SUBTREE ARE BST AS WELL AND FOLLOW ABOVE 2 PROPERTIES
*
*        4. NO DUPLICATE NODE 
*        
*        5. THE IN-ORDER TRAVERSAL OF A BINARY SEARCH TREE WILL ALWAYS GIVE AN ASCENDING SORTED ARRAY AND SO,
*           IF WE WANNA CHECK IF A BINARY TREE IS BST OR NOT THEN WE JUST HAVE TO USE THE IN ORDER TRAVERSAL AND 
*           IF THE ARRAY IS SORTED THEN THE TREE IS BST OTHERWISE NOT
*/

struct Node {   // Structure of each node 

    int data ;

    struct Node * left ;

    struct Node * right ;

};

//*                                     NOW WE WILL MAKE A BINARY SEARCH TREE
//*     
//*                                                 400
//*                                               /     \  
//*                                            200       600
//*                                          /    \     /   \
//*                                         100   300  500  700

//! IN-ORDER TRAVERSAL

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


    return 0;
}