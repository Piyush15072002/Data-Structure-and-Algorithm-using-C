# include <stdio.h>
# include <stdlib.h>

// Now we will create Doubly Linked list
struct Node{

    int Data;
    struct Node * Previous; 
    struct Node * Next; 

    // Both are pointers, Previous Points to Previous Node and Next Points to Next Node
};

int main(){

    struct Node* A ;
    struct Node* B ;
    struct Node* C ;
    struct Node* D ;
    struct Node* E ;

    // Allocating Memory 

    A = (struct Node * ) malloc(sizeof(struct Node));
    B = (struct Node * ) malloc(sizeof(struct Node));
    C = (struct Node * ) malloc(sizeof(struct Node));
    D = (struct Node * ) malloc(sizeof(struct Node));
    E = (struct Node * ) malloc(sizeof(struct Node));

    A-> Data= 10;
    A-> Previous= NULL;
    A-> Next= B;
    
    B-> Data= 20;
    B-> Previous= A;
    B-> Next= C;

    C-> Data= 30;
    C-> Previous= B;
    C-> Next= D;

    D-> Data= 40;
    D-> Previous= C;
    D-> Next= E;

    E-> Data= 50;
    E-> Previous= D;
    E-> Next= NULL ;

    return 0;
}