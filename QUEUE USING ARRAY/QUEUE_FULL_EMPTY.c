# include <stdio.h>
# include <stdlib.h>

struct QUEUE{

    int size ;
    
    int front ;

    int back ;

    int * ptr ;

};


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

int main(){

    struct QUEUE * q ;

    q->size = 100;
    q->front = q->back = -1;
    q->ptr = ( int * )malloc( q->size * sizeof(int));
    

    printf("\n\n %d\n\n", FULL( q ));
    printf("\n\n %d\n\n", EMPTY( q ));

    return 0;
}

