# include<stdio.h>
# include<stdlib.h>

struct Node{
    int Data;
    struct Node * ptr;
};

// I will write 2 blocks of codes with different coding style to perform same function that is to Print our circular linked list

struct Node * Circular_Linked_list_Method_1( struct Node * head ){
    
    struct Node * Pointer = head;

    printf("%d\t", Pointer->Data);
    Pointer = Pointer->ptr;

    while( Pointer != head ){

        printf("%d\t", Pointer->Data);
        Pointer = Pointer->ptr;
    }
    // We wrote above code like that because The while loop needed a KICKSTART
    // since the condition was false ( head is already equal to head ) so the loop will not start 
    // and so we printed the head already and made the pointer move to next node to give Kickstart to loop

    printf("\n\n");

    return head;
}

struct Node * Circular_Linked_list_Method_2( struct Node * head ){
    
    struct Node * Pointer = head;

    // since we needed a kick start when we use While loop so we will use DO-WHILE loop here

    do{
        printf("%d\t", Pointer-> Data);
        Pointer = Pointer -> ptr;

    }while( Pointer != head);
    
    printf("\n\n");

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


    Circular_Linked_list_Method_1( One) ;

    Circular_Linked_list_Method_2( One ) ;


    return 0;
}