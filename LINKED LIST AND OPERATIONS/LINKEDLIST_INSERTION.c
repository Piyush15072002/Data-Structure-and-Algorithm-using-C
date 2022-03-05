# include<stdio.h>
# include<stdlib.h>

struct Node{
    int data;
    struct Node * ptr;
};

int LinkedList(struct Node * a){    // Function to show Linked list nodes/elements
    while( a != NULL ){
        printf("\t%d", a->data);
        a=a->ptr;
    }
    printf("\n");
}

/*Now we will perfrom Insertion
 There are 4 cases of insertion 
    1. Inserting at the beginning
    2. Inserting in Between
    3. Inserting at the End
    4. Inserting after a Node    */


// CASE 1 : INSERTING THE NODE AT BEGINING OF LINKED LIST

struct Node * Insert_Beginning( struct Node * a, int data ){ // a means the old head, where we have to insert new
    // data is new data for our new node

    // Now we will allocate memory for the New Node
    struct Node * New_Head = ( struct Node * ) malloc ( sizeof(struct Node));

    New_Head->ptr = a; // This will make the Pointer of new Node point to Old Head
    New_Head->data = data; // This will Add data to new Head

    return New_Head;
}
// The reason why we didn't put INT Insert_begining to define our function because
// The Datatype of our Node is " struct Node * "and not "INT"


// CASE 2 : INSERTING IN BETWEEEN 

// This is most important as this is the basic to do any kind of insertion in the Linked list

struct Node * Insert_Between( struct Node * Head, int DATA, int index){

    // Allocating memory for New Node
    struct Node * New_Node = ( struct Node *) malloc ( sizeof(struct Node) );

    // We are using Head cuz we need to start the loop from starting
    // index is the Index where we wanna add our new node
    struct Node * a = Head;
    int i = 0;

    while( i != index-1){
        // This loop will make the pointer a come to node that is before the place where we wanna add our new node
        // We wrote index-1 so that the Pointer can stand on Node before the new node and we can connect our new node to node before it
        a= a->ptr;
        i++;
    }// This will stop the pointer p on node before our New node

    New_Node-> data= DATA;
    New_Node->ptr = a->ptr; // This will store the address of next node to our new node from the node before from our nodes
    a->ptr = New_Node;  // This will make the before Pointer points to our new Node

    return Head;
}

// CASE 3 : INSERTING AT THE END 

struct Node * Insert_End( struct Node * head, int DATA){

    // Allocating memory
    struct Node * End_Node = (struct Node * ) malloc (sizeof(struct Node));

    // Storing data in our new node
    End_Node -> data= DATA;

    //Now we will run a loop to go at the end of the linked list

    struct Node * p = head;
    while( p -> ptr != NULL ){
        p= p->ptr;
    }

    p -> ptr = End_Node; // This is old end node which will now point to our new end node
    End_Node -> ptr = NULL ;

    return head;
}

// CASE 4 : INSERTING AFTER A GIVEN NODE

struct Node * Insert_After_Node( struct Node * head, struct Node * Given_node, int DATA){
    // No use of Head here but we are using it just for professionalism

    // Allocating memory
    struct Node * New_Node_after_givenNode = (struct Node *) malloc ( sizeof( struct Node));

    New_Node_after_givenNode -> data = DATA;

    New_Node_after_givenNode -> ptr = Given_node -> ptr;

    Given_node -> ptr = New_Node_after_givenNode;

    return head;

}


int main(){

    struct Node * Head; // The first node can be called as Head Node 
    struct Node * Second;
    struct Node * Third;

    // Allocating memory to nodes

    Head = (struct Node *) malloc ( sizeof( struct Node));
    Second = (struct Node *) malloc ( sizeof( struct Node));
    Third = (struct Node *) malloc ( sizeof( struct Node));

    // Storing date

    Head-> data = 90;
    Head-> ptr = Second;
    
    Second-> data = 100;
    Second-> ptr = Third;
    
    Third-> data = 150;
    Third-> ptr = NULL ;

    LinkedList(Head);

    Head = Insert_Beginning( Head, 50);
    // We must Assign Head equals to New head

    printf("LINKED LIST AFTER INSERTIING AT BEGINNING\n");
    LinkedList(Head);

    Head = Insert_Between( Head , 98, 1);

    printf("LINKED LIST AFTER INSERTIING BETWEEEN NODES\n");
    LinkedList(Head);

    Head = Insert_End( Head , 500);

    printf("LINKED LIST AFTER INSERTIING AT THE END\n");
    LinkedList(Head);

    Head = Insert_After_Node( Head , Second , 225);

    printf("LINKED LIST AFTER INSERTING AFTER A GIVEN NODE\n");
    LinkedList(Head);

    return 0;
}