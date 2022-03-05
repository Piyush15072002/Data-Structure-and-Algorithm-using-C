# include <stdio.h>
# include <stdlib.h>


struct N{   // N stands for  NODE
    
    int data;
    struct N * ptr;

};

// WE WILL MAKE FRONT AND BACK POINTER GLOBAL VARIABLES   
struct N * front = NULL ;   
struct N * back = NULL ;

// FUNCTION FOR THE TRAVERSAL OF THE LINKED LIST OF QUEUE
int LINKEDLIST( struct N * f){
    while( f != NULL ){
        printf("\t %d\t\t", f->data);
        f = f->ptr;
    }
}

// FUNCTION FOR ENQUEUE IN THE LINKED LIST
int ENQUEUE( int value){
    
    struct N * n = ( struct N *) malloc ( sizeof( struct N ));

    // THE NEW NODE IS CREATED AND ITS MEMORY IS ALLOCATED AS WELL

    if ( n== NULL ){    // condition for stack full
        printf(" THE QUEUE IS FULL !!!\n");
    }
    else{
        n->data = value;
        n->ptr = NULL; // since the enqueue occurs at the end so the pointer of the new node will point at NULL
        
        if( front == NULL ){ // if the queue is empty ie. f==NULL , then our new node will be the both  front and back
            front = back = n;
        }
        else{   // If the  queue is not empty, then make the older back points to our new back n
            back->ptr = n; // making the pointer of old back points to the new back
            back = n;  // since n is the new back now so b - n
        }
    }
    
}



int main(){

    LINKEDLIST( front );

    ENQUEUE( 10);
    ENQUEUE( 20);
    ENQUEUE( 30);
    ENQUEUE( 40);
    ENQUEUE( 50);

    printf("\n\n");
    LINKEDLIST( front );
    printf("\n\n");

    return 0;
}