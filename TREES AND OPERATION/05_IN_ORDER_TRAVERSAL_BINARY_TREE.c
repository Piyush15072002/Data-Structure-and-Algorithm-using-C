# include<stdio.h>
# include<malloc.h> // for allocating the memory using malloc()

/* THERE ARE 3 WAYS TO TRAVRESE A NON LINAR STRUCTURE
        1. PRE-ORDER TRAVERSAL
        2. POST-ORDER TRAVERSAL
        3. IN-ORDER TRAVERSAL

    IN THIS SECTION, WE WILL SEE THE IN ORDER TRAVERSAL OF OUR BINARY TREE

    IN THE IN ORDER TRAVERSAL, THE PRIORITY OF TRAVERSING IS :
*        LEFT SUBTREE  ----> ROOT ----> RIGHT SUBTREE
*/

struct Node {   // Structure of each node 

    int data ;

    struct Node * left ;

    struct Node * right ;

};

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

    struct Node * Root = CreateNode ( 100 );

    // Our Root node is created and so now we will create other nodes

    struct Node *  node1 = CreateNode ( 200 );
    struct Node *  node2 = CreateNode ( 300 );

    // Now we will connect the ROOT node with its children

    Root->left = node1;
    Root->right = node2;

    struct Node *  node1_1 = CreateNode ( 400 );
    struct Node *  node1_2 = CreateNode ( 500 );
    node1->left = node1_1;
    node1->right = node1_2;

    struct Node *  node2_1 = CreateNode ( 600 );
    struct Node *  node2_2 = CreateNode ( 700 );
    node2->left = node2_1;
    node2->right = node2_2;

    IN_ORDER( Root );

    return 0;
}