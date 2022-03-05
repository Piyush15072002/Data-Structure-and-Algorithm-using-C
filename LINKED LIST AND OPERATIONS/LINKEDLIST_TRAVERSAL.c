# include<stdio.h>
# include<stdlib.h>

struct NODE{
    int data;
    struct NODE * ptr;
};

// Now we will write a function for the Traveral of ṭhe Linked List
// Traversal means visiting the elements of a list one by one sequentially

int Linked_List( struct NODE * a){ // We will put the first node here so that we can access the whole Linked list
    while( a != NULL ){  // This will run until pointer points toNUll 
        printf("\t%d\n", a -> data);
        a = a -> ptr;   // This is important code which will take function to the next node
    }
}

int main(){

    struct NODE * One;
    struct NODE * Two;
    struct NODE * Three;
    struct NODE * Four;
    struct NODE * Five;

    // Allocating memory from Heap to our nodes

    One = (struct NODE *) malloc ( sizeof( struct NODE));
    Two = (struct NODE *) malloc ( sizeof( struct NODE));
    Three = (struct NODE *) malloc ( sizeof( struct NODE));
    Four = (struct NODE *) malloc ( sizeof( struct NODE));
    Five = (struct NODE *) malloc ( sizeof( struct NODE));

    // Now we will store data

    One -> data = 1;
    One -> ptr = Two;
    
    Two -> data = 2;
    Two -> ptr = Three;

    Three -> data = 3;
    Three -> ptr = Four;

    Four -> data = 4;
    Four -> ptr = Five;

    Five-> data = 5;
    Five-> ptr = NULL ;

    // Now we will call the function to traverse our linked list

    Linked_List(One);



    return 0;
}