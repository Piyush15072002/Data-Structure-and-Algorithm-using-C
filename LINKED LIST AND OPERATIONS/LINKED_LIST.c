# include <stdio.h>
# include <stdlib.h>

// A Linked List consists of NODES and each NODE have 2 parts
// 1.Data - Stores the data in the node
// 2.Pointer - Stores the address to the next node and points to it

struct NODE{  // A collection of nodes makes a linked list and so now we will create nodes to make our linked list
    
    int data ;
    struct NODE * pointer;

};

int main(){

    // Now we will create Nodes using our structure
    struct NODE * First; // first is name of the first node 
    struct NODE * Second; 
    struct NODE * Third; 

    // Now we need memory to allocate our NODES 
    // So now we will allocate memory for the nodes of linked list in HEAP
    // Remember that the memory is allocated in the HEAP and not in the stack for Nodes

    First = (struct NODE *) malloc (sizeof (struct NODE));
    Second = (struct NODE *) malloc (sizeof (struct NODE));
    Third = (struct NODE *) malloc ( sizeof ( struct NODE));

    // Now the memory is allocated for our Nodes in the heap

    // Now we will store our date in the node and make the pointer points to the next node

    First -> data = 10;         // Stored Data in Node
    First -> pointer = Second;  // Storing address and Pointing to the next node 

    // Now we will do same with each Node in the Heap

    Second -> data = 20;
    Second -> pointer = Third;

    Third -> data = 20;
    Third -> pointer = NULL ; // NULL shows the end of the linked list as it being last node
    // which will not point to any further node
    // Remember to write NULL in capital


    // *** important ***
    // IF YOU RUN THIS PROGRAM, IT WILL NOT RETURN ANYTHING BECAUSE THIS PROGRAM IS JUST MAKING NODES
    return 0;
}