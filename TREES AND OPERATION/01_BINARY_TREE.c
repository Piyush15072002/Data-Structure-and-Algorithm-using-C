# include<stdio.h>
# include<malloc.h> // for allocating the memory using malloc()

//* AS WE KNOW THAT A BINARY TREE IS A TREE IN WHICH ALL THE NODES HAVE ATMOST 2 CHILDREN ie. 0 , 1 AND 2 , AND NOT MORE THAN THIS

//* WE CAN REPRESENT THE BINARY TREE USING ARRAY REPRESENTATION AND LINKED REPRESENTATION BUT
//* WE WILL NOT USE THE ARRAY REPRESENTATION OF THE ARRAY CUZ ARRAY HAVE FIXED SIZE AND WE CANNOT INCREASE IT LATER ON
//* BUT BINARY TREE NEEDS TO GROW AND SO IT IS NOT ADVISABLE TO USE ARRAY REPRESENTATION

//* WE WILL BE USING THE LINKED REPRESENTATION WHICH WORKS ON THE CONCEPT OF THE DOUBLY LINKED LIST 

//! BINARY TREE

struct Node {   // Structure of each node 

    int data ;

    struct Node * left ;

    struct Node * right ;

};


int main(){

    // Since our Node structure has been made so now we will make the root node 

    //! ROOT NODE

    struct Node * ROOT ;

    // now we will allocate memory for it
    ROOT = ( struct Node * ) malloc ( sizeof ( struct Node ) );

    // Now we will enter the data in the node
    
    ROOT-> data = 10;
    
    // Since the binary tree is empty now so we will put its pointer as NULL

    ROOT->left = NULL;
    ROOT->right = NULL;

    //* Now we will add nodes to our ROOT node

    struct Node * node1 ;

    node1= ( struct Node * )malloc ( sizeof( struct Node));

    node1->data = 20;
    node1->left = NULL;
    node1->right = NULL;

    struct Node * node2 ;

    node2= ( struct Node * )malloc ( sizeof( struct Node));

    node2->data = 30;
    node2->left = NULL;
    node2->right = NULL;

    // Now we made children of our root node and we will connect them to the ROOT
    
    ROOT-> left = node1;
    ROOT-> right =node2;

    return 0;
}