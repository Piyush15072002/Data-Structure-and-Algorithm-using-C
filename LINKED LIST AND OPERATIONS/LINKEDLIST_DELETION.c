# include<stdio.h>
# include<stdlib.h>

struct Node{
    int Data;
    struct Node * ptr;
};

// Function to Print the Linked list
struct Node * Linked_List( struct Node * head){

    struct Node * P = head;

    while( P-> ptr != NULL){
        printf("%d   ", P->Data);
        P= P->ptr;
    }
    printf("\n");

    return head;
}

// Now we will perfrom Deletion on Nodes

/* There are 4 Cases of Deletion
    1. Deletion at Beginning
    2. Deletion Between Nodes
    3. Deletion at the End
    4. Deletion after a Key/Value   */

// WHILE DELETION, WE MUST REMEMBER TO FREE THE MEMORY WE ALLOCATED TO THE NODE AFTER WE DELETE IT


// CASE 1 : DELETION AT BEGINNING

struct Node * Deletion_Beginning(struct Node * head ){

    struct Node * Pointer = head;
    // We made a pointer so that we can delete the node after we shift our head 
    // The logic is - Make a pointer to point to our Head to store its address
    // Shift the head to Pointer of the head (i.e. Next node or second node)
    // Now since Second became Head, Now we will Free the Memory of Our pointer which stores the Old head we wanna delete

    head = head -> ptr;

    free(Pointer);  // This will Free the Dynamic Memory for Old head

    return head;
}

// CASE 2 : DELETION BETWEEN THE NODES

struct Node * Deletion_Between( struct Node * head, int index){

    struct Node * Pointer1 = head;          // This pointer will Point to the first Node
    struct Node * Pointer2 = head->ptr;     // This pointer will Point to the second Node

    // Now we will use a loop to transverse our list until pointer2 reaches the node we wanna delete and pointer 2 reaches one node before that
    for(int i =0 ; i < index- 1; i++){
        Pointer1 = Pointer1->ptr;
        Pointer2 = Pointer2->ptr;
    }

    Pointer1->ptr = Pointer2->ptr;
   
    free(Pointer2);

    return head;
}


// CASE 3 : DELETING THE LAST NODE 

struct Node * Deletion_End( struct Node * head){

    struct Node * Pointer1 = head;        
    struct Node * Pointer2 = head-> ptr;

    while(Pointer2->ptr != NULL){
        Pointer1 = Pointer1->ptr;
        Pointer2 = Pointer2->ptr;
    }

    Pointer1-> ptr=NULL;

    free(Pointer2);

    return head;

}

// CASE 4 : DELETION AT THE GIVEN KEY_VALUE

struct Node * Deletion_Value( struct Node * head , int Value){

    struct Node * Pointer1 = head;
    struct Node * Pointer2 = head->ptr;

    while( Pointer2 -> Data != Value  &&  Pointer2 -> ptr != NULL ){
        // The above condition's logic is
        // Part 1 :(VALUE IS PRESENT IN LIST) The Pointer2 data was equals to Value and if true, the loop will end
        // part 2 :(VALUE IS NOT PRESENT IN LIST) The value wasn't found in the List and we reached end, so if we reach NULL, end the loop !

        Pointer1= Pointer1->ptr;
        Pointer2= Pointer2->ptr;
    }

    /* There are 2 cases after the while loop ends 
        1. The Value was found and so the while loop ended
        2. The list ended and the value wasn't found but still the pointer were at the end and came out

        So in such cases, we will use IF condition to check if the Pointer data equals to our value or not so hence i used IF condition below  
    */

    if( Pointer2-> Data == Value){
        Pointer1->ptr= Pointer2->ptr;
        free(Pointer2);
    }

    return head;
}

int main(){

    struct Node * Head;
    struct Node * Second;
    struct Node * Third;
    struct Node * Fourth;
    struct Node * Fifth;
    struct Node * Sixth;
    struct Node * Seventh;
    struct Node * Eighted;
    struct Node * Nineth;
    struct Node * Tenth;

    // Allocation Memory dynamically in Heap

    Head = (struct Node*) malloc ( sizeof(struct Node));
    Second = (struct Node*) malloc ( sizeof(struct Node));
    Third = (struct Node*) malloc ( sizeof(struct Node));
    Fourth = (struct Node*) malloc ( sizeof(struct Node));
    Fifth= (struct Node*) malloc ( sizeof(struct Node));
    Sixth = (struct Node*) malloc ( sizeof(struct Node));
    Seventh = (struct Node*) malloc ( sizeof(struct Node));
    Eighted = (struct Node*) malloc ( sizeof(struct Node));
    Nineth = (struct Node*) malloc ( sizeof(struct Node));
    Tenth = (struct Node*) malloc ( sizeof(struct Node));

    Head -> Data = 1000;
    Head -> ptr = Second;

    Second -> Data = 1029;
    Second -> ptr = Third;

    Third -> Data = 1500;
    Third -> ptr = Fourth;

    Fourth -> Data = 1600;
    Fourth -> ptr = Fifth;
    
    Fifth -> Data = 1746;
    Fifth -> ptr = Sixth;

    Sixth -> Data = 1902;
    Sixth -> ptr = Seventh;

    Seventh -> Data = 2002;
    Seventh -> ptr = Eighted;

    Eighted -> Data = 2400;
    Eighted -> ptr = Nineth;

    Nineth -> Data = 3000;
    Nineth -> ptr = Tenth;

    Tenth -> Data = 4000;
    Tenth -> ptr = NULL;

    printf("\nTHE ORIGINAL LINKED LIST\n");
    Linked_List( Head);

    Head = Deletion_Beginning( Head );

    printf("LINKED LIST AFTER DELETION AT BEGINNING\n");
    Linked_List( Head );

    Head = Deletion_Between( Head, 3);

    printf("LINKED LIST AFTER DELETION BETWEEN THE NODES\n");
    Linked_List( Head );

    Head = Deletion_End( Head );

    printf("LINKED LIST AFTER DELETION AT THE END\n");
    Linked_List( Head );

    Head = Deletion_Value( Head, 2002);

    printf("LINKED LIST AFTER DELETION AFTER KEY/VALUE\n");
    Linked_List( Head );


    return 0;
}