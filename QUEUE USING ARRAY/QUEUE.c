# include <stdio.h>
# include <stdlib.h>

struct QUEUE{

    int size ;
    // Allocates size for the queue

    int front ;
    // front is the value of the index of the front of the queue or the the first element entered

    int back ;
    // back is the value of the index of the back of the queue or the last element entered

    int * ptr ;
    // Allocates memory to the queue from the heap

};

int main(){

    struct QUEUE * q ;

    q->size = 100;
    q->front = q->back = -1;
    // Both the front and the back will be -1 as the queue is empty now a
    q->ptr = ( int * )malloc( q->size * sizeof(int));


    /*
    We can also write the code as below

    q.size = 100;
    q.front = q.back = -1;
    q.ptr = ( int * )malloc( q.size * sizeof(int));
    
    */
    return 0;
}