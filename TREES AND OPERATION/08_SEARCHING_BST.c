# include<stdio.h>
# include<malloc.h>

// IT IS FASTER TO  SEARCH IN BINARY SEARCH TREE BECAUSE THE SEARCHING IS SIZE/2 BECAUSE 
// IF THE NUMBER IS BIGGER THAN THE ROOT MEANS IT IS IN THE RIGHT SUB TREEE AND
// IF THE NUMBER IS SMALLER THAN THE ROOT MEANS IT IS IN THE LEFT SUB TREE AND NO SEARCH TIME IS DECREASED

// * WE WILL MAKE 2 FUNCTION FOR SEARCH, RECURSIVE AND ITERATIVE


struct Node {

    int data;

    struct Node * left ;

    struct Node * right ;
};

struct Node * create_node( int data);
int In_order( struct Node * root );

//* RECRUSIVE FUNCTION FOR THE BST SEARCHING

struct Node * Recursive_search( struct Node * root , int search){

    if( root == NULL ){
        return NULL;
    }

    if(  search == root->data ){
        return root ;
    }
    else if (search < root->data){
        return Recursive_search( root->left , search);
    }
    else if (search > root->data){
        return Recursive_search( root->right , search);
    }
}   

//* ITERATIVE FUNCTION FOR THE BST SEARCHING

struct Node * Iterative_search( struct Node * root , int data){

    while( root != NULL ){

        if( data == root->data){
            return root;
        }
        else if( data < root->data ){
            root = root->left;  // since the data is smaller than root so we will go in left sub tree
        }
        else if ( data > root->data ){
            root = root->right;
        }
    }
    return NULL;    // if the root is empty then while loop wont run and return NULL
}


int main( ){

    struct Node * root = create_node( 500 );

    struct Node * node1 = create_node( 100 );
    struct Node * node2 = create_node( 800 );

    struct Node * node1a = create_node( 10 );
    struct Node * node1b = create_node( 200 );

    struct Node * node2a = create_node( 600 );
    struct Node * node2b = create_node( 1000 );

    struct Node * node1a1 = create_node( 0 );
    struct Node * node1a2 = create_node( 50 );

    struct Node * node2b1 = create_node( 900 );
    struct Node * node2b2 = create_node( 1001 );

    root->left=node1;
    root->right=node2;

    node1->left=node1a;
    node1->right=node1b;

    node2->left=node2a;
    node2->right=node2b;

    node1a->left=node1a1;
    node1a->right=node1a2;

    node1b->left=NULL;
    node1b->right=NULL;

    node2a->left=NULL;
    node2a->right=NULL;

    node2b->left=node2b1;
    node2b->right=node2b2;

    
    In_order( root );


    struct Node * R_search = Recursive_search( root , 100);
    
    if( R_search!= NULL){
        printf("\nELEMENT FOUND IN RECURSIVE SEARCH : %d\n\n", R_search->data);
    }
    else{
        printf("\nTHE ELEMENT IS NOT PRESENT IN THE BST\n");
    }

    struct Node * I_search  = Recursive_search( root , 1000);
    
    if( I_search != NULL){
        printf("\nELEMENT FOUND IN ITERATIVE SEARCH : %d\n\n", I_search ->data);
    }
    else{
        printf("\nTHE ELEMENT IS NOT PRESENT IN THE BST\n");
    }



    return 0;
}



int In_order( struct Node * root ){
    if(root != NULL){

        In_order( root->left  );
        printf(" %d   ", root->data);
        In_order( root->right);
    }

}

struct Node * create_node( int data){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}