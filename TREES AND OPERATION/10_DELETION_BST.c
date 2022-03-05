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

// function to create node
struct Node * CreateNode( int data ){

    struct Node * n ;   // creating a node pointer

    n= (struct Node *)malloc(sizeof(struct Node));  // memory allocation for the node

    n->data = data;

    n->left= NULL;
    n->right= NULL;
    
    return n;
}


int IN_ORDER( struct Node * root ){

    if( root != NULL ){

        IN_ORDER( root->left); // left is first

        printf("  %d    ",root->data); // root is second
        
        IN_ORDER( root->right);// right is last

    }

}


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



//* IN-ORDER PREDECESSOR FINDING FUNCTION

struct Node * predecessor( struct Node * root ){
    //* THE PREDECESSOR OF A ROOT IS ALWAYS THE - RIGHT MOST ELEMENT OF THE LEFT SUBTREE
    //* THE POST OF A ROOT IS ALWAYS THE - LEFT MOST ELEMENT OF THE RIGHT SUBTREE

    // In this case, we will find the right most element of the left subtree
    // since we wanna find the predecessor of the node we wanna delete so it will be found in the left subtree
    root = root->left;

    while( root->right != NULL ){// this loop will run until it reaches the right most element
        root = root->right;
    }
    return root;
}

//! DELETION FUNCTION 

struct Node *  DELETE( struct Node * root , int value ){

    struct Node * pre ; // This will store the value of Predecessor of the deleting node

    if( root == NULL ){
        printf(" THE BST IS EMPTY!\n");
        return NULL;
    }
    //* TO DELETE IF THE NODE IS LEAF NODE 
    if( root->left == NULL && root->right == NULL ){// if the node is a leaf node with no child
        free(root);
        return NULL;
    }

    //* SEARCH FOR THE NODE TO BE DELETED 
    if( value < root->data ){
        root->left = DELETE( root->left , value);
        
    }
    else if( value > root->data ){
        root->right = DELETE( root->right , value );
        
    }

    //* DELTETION WHEN THE NODE IS FOUND
    else{ 
        // and replace it with our root which we wanna delete 
        pre = predecessor( root);

        root->data = pre->data; 
        // root is the root we wanna delete and pre is the predecessor which we are replacing root with
        
        // since we have reaplaced the pre with root but still the data of pre is still in two placees now, new position and old position
        // and so now we will delete the old position of the predecessor    
        root->left = DELETE( root->left , pre->data);
        
    }

    return root;

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
    INSERT( Root , 250);
    INSERT( Root , 50);
    INSERT( Root , 950);

    printf("........THE BST AFTER INSERTING ........\n\n");
    IN_ORDER( Root );
    printf("\n\n");
    printf("\n\n");
    //* DELETION

    DELETE( Root , 50 );
    DELETE( Root , 250 );
    DELETE( Root , 950 );

    printf("........THE BST AFTER DELETION ........\n\n");
    IN_ORDER( Root );
    printf("\n\n");

    return 0;
}




