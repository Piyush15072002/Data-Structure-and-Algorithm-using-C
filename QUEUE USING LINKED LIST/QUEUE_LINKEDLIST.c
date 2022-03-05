# include <stdio.h>
# include <stdlib.h>


struct N{   // N stands for  NODE
    
    int data;
    struct N * ptr;

};

// THE QUEUE IS EMPTY NOW BUT HAS BEEN MADE AND CAN BE USED TO  ENQUEUE AND DEQUEUE

int main(){
    
    struct N * front = NULL ;   
    struct N * back = NULL ;
    // Both front and back pointer are NULL because the queue is empty now


    return 0;
}