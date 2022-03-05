# include <stdio.h>
# include <stdlib.h>

// THIS PROGRAM IS FOR MAKING CIRCULAR QUEUES TO AVOID THE PROBLEM OF SPACE AFTER DEQUEUEING IN THE GENERAL QUEUES
// TO MAKE A NORMAL QUEUE CIRCULAR, WE HAVE TO FIND A LOGIC SO THAT THE LAST INDEX ALWAYS POINTS TO THE FIRST INDEX AGAIN
// THE LOGIC IS THAT ---    ( i + 1 ) % SIZE            , SIZE IS THE SIZE OF QUEUE, i IS THE INDEX
// THIS IS THE LOGIC AND USING THIS WE WILL ALWAYS GET THE FIRST INDEX 0, WHEN WE ARE AT THE LAST ELEMENT
// * ( i + 1 ) % SIZE ---- THIS WILL GIVE US THE NEXT INDEX OF THE GIVEN INDEX AND IN THE CASE OF THE LAST INDEX, IT WILL GIVE US THE FIRST INDEX AGAIN MAKING IT CIRCULAR QUEUE

struct QUEUE{

    int size ;
    
    int front ;

    int back ;

    int * ptr ;

};



int FULL( struct QUEUE *queue ){

    if( ((queue->back + 1) % queue->size) == queue->front){
        return 1;
    }
    else{
        return 0;
    }

}

int EMPTY( struct QUEUE * queue ){

    if( queue->front == queue->back){
        return 1;
    }
    else{
        return 0;
    }
}


int ENQUEUE( struct QUEUE * queue, int value){

    if( FULL( queue ) ){
        printf("\n!!! THE QUEUE IS OVERFLOWING !!! \n\n");
    }
    else{
        // queue->back++ ;
        // this is used for increment the index of back to push in normal queues
        queue->back = ( ( queue->back + 1 ) % queue->size );
    
        queue->ptr[ queue->back ] = value; 
    }
}
int DEQUEUE ( struct QUEUE * queue ){

    if( EMPTY( queue )){
        printf("\n\n!!! THE QUEUE IS EMPTY !!!\n\n\n");
    }    
    else{
        // queue->front++;
        // This is the condition for increment for delete in normal queue

        queue->front = (( queue->front + 1 ) % queue-> size );

        return queue->ptr[queue->front];
    }
}

int main(){

    struct QUEUE * q ;

    q->size = 100;
    q->front = q->back = 0; // In the circular queue, the indexing always start with 0 and not -1
    q->ptr = ( int * )malloc( q->size * sizeof(int));


    ENQUEUE( q , 1000); 
    ENQUEUE( q , 2000); 
    ENQUEUE( q , 3000); 
    ENQUEUE( q , 4000); 
    ENQUEUE( q , 5000); 
    ENQUEUE( q , 6000); 
    ENQUEUE( q , 7000); 
    ENQUEUE( q , 8000); 
    ENQUEUE( q , 9000); 
    ENQUEUE( q , 10000); 

    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));

    // ABOVE ARE SOME BASIC OPERATION FOR ENQUEUEING AND DEQUEUEING

    // PERFORMING SOME OPERATIONS TO SEE IF THE QUEUE IS CIRCULAR
    
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));

    ENQUEUE( q , 1000); 
    ENQUEUE( q , 2000); 
    ENQUEUE( q , 3000); 
    ENQUEUE( q , 4000); 
    ENQUEUE( q , 5000); 
    ENQUEUE( q , 6000); 
    ENQUEUE( q , 7000); 
    ENQUEUE( q , 8000); 
    ENQUEUE( q , 9000); 
    ENQUEUE( q , 10000); 

    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));
    printf("\n\n THE DEQUEUED ELEMENT IS %d\n\n", DEQUEUE( q ));

    return 0;
}




