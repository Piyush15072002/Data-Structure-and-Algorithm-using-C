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

int DEQUEUE( struct N * f ){

    int del = -1;
    struct N * pop = f;

    if(f == NULL){
        printf("\n\n!!! THE QUEUE IS EMPTY !!!\n\n");
    }
    else{
        front = front->ptr ++;
        int del = pop->data;
        free(pop);
        return del;
    }
}



int main(){

    LINKEDLIST( front );

    ENQUEUE( 10);
    ENQUEUE( 20);
    ENQUEUE( 30);
    ENQUEUE( 40);
    ENQUEUE( 50);

    printf("\nTHE LINKED LIST AFTER ENQUEUEING\n");
    LINKEDLIST( front );
    printf("\n\n");

    printf(" THE DEQUEUED ELEMENT IS %d\n", DEQUEUE( front ));
    printf(" THE DEQUEUED ELEMENT IS %d\n", DEQUEUE( front ));

    printf("\nTHE LINKED LIST AFTER DEQUEUEING\n");
    LINKEDLIST( front );
    printf("\n\n");

    printf(" THE DEQUEUED ELEMENT IS %d\n", DEQUEUE( front ));
    printf(" THE DEQUEUED ELEMENT IS %d\n", DEQUEUE( front ));
    printf(" THE DEQUEUED ELEMENT IS %d\n", DEQUEUE( front ));
    printf(" THE DEQUEUED ELEMENT IS %d\n", DEQUEUE( front ));
    // THE QUEUE HAS BEEN EMPTIED AND NOW IT WILL SAY THAT THE QUEUE IS EMPTY AND CANNOT DEQUEUE


    return 0;
}