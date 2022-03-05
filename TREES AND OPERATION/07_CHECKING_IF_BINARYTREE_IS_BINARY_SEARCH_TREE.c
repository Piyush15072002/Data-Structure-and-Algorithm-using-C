# include<stdio.h>
# include<malloc.h> // for allocating the memory using malloc()

/* 
   IN THIS PROGRAM WE WILL CHECK IS  A BINARY TREE IS A BST OR NOT ?

*  THE IN-ORDER TRAVERSAL OF A BINARY SEARCH TREE WILL ALWAYS GIVE AN ASCENDING SORTED ARRAY AND SO,
*  IF WE WANNA CHECK IF A BINARY TREE IS BST OR NOT THEN WE JUST HAVE TO USE THE IN ORDER TRAVERSAL AND 
*  IF THE ARRAY IS SORTED THEN THE TREE IS BST OTHERWISE NOT
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

// logic of the program is that,
//* WE WILL FOLLOW THE CONCEPT OF IN ORDER TRAVERSAL
// we will create a previous pointer to compare if the element is smaller than previous element or not to check the sorting
// then we will use if condition for all the possibilities of failing to be BST


//! IS BST FUNCTION ?

int Is_BST( struct Node * root ){

    static struct Node * previous = NULL;
    // static is used here cuz we dont want to create pointer everytime the loop runs with NULL value
    // so we use static here which will make sure this doesn't happen

    if( root != NULL ){ // true if the tree is not empty
        
        if( !Is_BST( root->left )){
            // this recurvise function condition will check if the left subtree is BST or not
            // True if - the left subtree is not BST .'. return 0 means failed/is not bst
            return 0;
        }

        if( previous != NULL && root->data <= previous->data ){
            // first this condition will check is previous is NULL or not, true if is not NULL
            // but in the first run for ROOT, this loop will not run cuz nothing is previous to ROOt so
            // at last, we will increment previous
            // second condition compares the element to the previous element
            // if previous is larger than the element means the array is not sorted which means this is not BST
            // so we will return 0/failed/not since the array is not sorted cuz prev element is larger 
            return 0;
        }

        previous = root;    // incrementing ROOT

        return Is_BST( root->right ); // Now this will check is the right subtree is BST or not and if it is
        // it will return 1 for success, and 0 if the right subtree is not BST

    }
    else{   // this is important as it will be returned 
        return 1;
    }

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

    if( Is_BST ( Root )){
        printf("\n\n    !!! THIS IS A BINARY SEARCH TREE !!!\n\n");
    }
    else{
        printf("\n\n    !!! THIS IS NOT A BINARY SEARCH TREE !!!\n\n");
    }

    Is_BST ( Root );
    return 0;
}