# include<stdio.h>
# include<stdlib.h>

struct Node{
    int Data;
    struct Node * ptr;
};

// FUNCTION FOR TRAVERSAL

struct Node * Circular_LinkedList(struct Node * head){

    struct Node * Pointer = head;

    do{

        printf("%d\t", Pointer->Data);
        Pointer = Pointer->ptr;

    }while( Pointer != head);

    printf("\n");

    return head;
}

// The Operations on the circular linked list are same as singly linked list
// So i will not re write the codes again but now i will write the program for Insertion at the head or making new head

struct Node * Insert_Head( struct Node * head, int data){

    // Allocating Memory for the new head 
    
    struct Node * Head = (struct Node *) malloc ( sizeof(struct Node) );

    // Now we will make a pointer which will points to the Next node of old head

    struct Node * Pointer = head->ptr;

    Head -> Data = data;  

    // Now we will make the pointer Traverse to the end of the Circular linked list

    while( Pointer-> ptr != head){
        Pointer = Pointer->ptr;
    }
    // Now our Pointer will point to the last node


    Pointer->ptr= Head; // Making last node's Pointer points to our new head

    Head-> ptr = head;  // Making our New Head's Pointer points to Old head

    head = Head;
    // Now the Value of ONE is 0 and not 10

    /* This code is second way to perform this Operation
    Head->ptr = Pointer->ptr;
    Pointer -> ptr = Head; */
    
    return head;
}

int main(){

    struct Node * One;
    struct Node * Two;
    struct Node * Three;
    struct Node * Four;
    struct Node * Five;

    // Allocating Memory

    One = (struct Node *) malloc ( sizeof(struct Node));
    Two = (struct Node *) malloc ( sizeof(struct Node));
    Three= (struct Node *) malloc ( sizeof(struct Node));
    Four= (struct Node *) malloc ( sizeof(struct Node));
    Five = (struct Node *) malloc ( sizeof(struct Node));

    One->Data = 10;
    One->ptr = Two;

    Two->Data = 20;
    Two->ptr = Three;

    Three->Data = 30;
    Three->ptr = Four;

    Four->Data = 40;
    Four->ptr = Five;

    Five->Data = 50;
    Five->ptr = One; 

    printf("\nTHE ORIGINAL LIST IS\n");

    Circular_LinkedList( One ); 

    One = Insert_Head(One, 0);

    Circular_LinkedList( One );

    return 0;
}