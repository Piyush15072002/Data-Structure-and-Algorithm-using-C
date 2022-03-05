# include <stdio.h>
# include <stdlib.h>

struct QUEUE{

    int size ;
    
    int front ;

    int back ;

    int * ptr ;

};

// REQUIRED FUNCTION
int EMPTY( struct QUEUE * queue );
int FULL( struct QUEUE * queue );

// FUNCTION FOR ENQUEUE/PUSH

void ENQUEUE( struct QUEUE * queue, int value){

    if( FULL( queue ) ){
        printf("\n!!! THE QUEUE IS OVERFLOWING !!! \n\n");
    }
    else{
        queue->back++ ;
        // We will move the back index one step forward so that our element can be pushed to new index and
        // since the pushing takes place only at the end/back of the queue so we will increment the back end.

        queue->ptr[ queue->back ] = value; 
    }
}

int main(){

    struct QUEUE * q ;

    q->size = 10;
    q->front = q->back = -1;
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

    // THIS WILL GIVE THE QUEUE IS OVERFLOWING AND HENCE CANNOT ENQUEUE THE ELEMENT
    ENQUEUE( q , 10000); 

    return 0;
}


int FULL( struct QUEUE * queue ){

    if( queue->back == queue->size-1){
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
