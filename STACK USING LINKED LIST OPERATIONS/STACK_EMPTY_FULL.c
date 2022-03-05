# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node * ptr;
};

int Is_Empty( struct Node * stack_pointer){
    if(stack_pointer == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int Is_Full( struct Node * stack_pointer){
    
    // WE WILL MAKE A POINTER TO SEE IF WE CAN ALLOCATE MEMORY TO OUR STACK OR NOT
    // IF IT IS EQUALS TO NULL MEANS THE STACK IS FULL

    struct Node * p = (struct Node * ) malloc ( sizeof(struct Node));

    if( p == NULL){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    // Now we will make a pointer which will point to the top of the element of the stack

    struct Node * Top;
    
    // Since we don't have any elements in the stack so its NULL

    Top = NULL;

    printf(Is_Full( Top ));
    
    printf(Is_Empty( Top ));
   
    return 0;
}