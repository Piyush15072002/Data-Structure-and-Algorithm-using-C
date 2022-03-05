# include<stdio.h>
# include<stdlib.h>

struct Node{
    int Data;
    struct Node * ptr;
};

// CREATING A CIRCULAR LINKED LIST IS SAME AS THE SINGLY LINKED LIST
// BUT ONLY CHANGE IS THE POINTER OF THE LAST NODE WHICH POINTS TO THE HEAD NODE INSTEAD OF NULL

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

    Two->Data = 10;
    Two->ptr = Three;

    Three->Data = 10;
    Three->ptr = Four;

    Four->Data = 10;
    Four->ptr = Five;

    Five->Data = 10;
    Five->ptr = One;    // In Circular Linked List, The last Node points to the head rather than NULL


    // *** IMPORTANT *** 
    // THIS PROGRAM WILL NOT PRINT ANYTHING AS THIS WILL JUST CREATE THE CIRCULAR LINKED LIST

    return 0;

}