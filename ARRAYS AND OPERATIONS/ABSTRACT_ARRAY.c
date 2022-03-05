# include<stdio.h>
# include<stdlib.h>

// Ab_array is a an Abstract Datatype where we can add our requirements and perform operations
// This Abstract dataype is like a model for arrays which we can create using it 
struct Ab_array
{
    int total_size;
    int used_size;
    int *ptr;         // Points towards the first element of the array
};

// We will make a function so that we can create arrays from our structure

void Create_Array( struct Ab_array * a , int t_size , int u_size){
    (*a).total_size = t_size;
    (*a).used_size = u_size;
    (*a).ptr = (int *) malloc (t_size * sizeof(int));

}

void set_val( struct Ab_array * name){ // This function will get the value for the array
    int n;
    for( int i=0; i < (*name).used_size; i++)   // it can be written as  name->used_size;
    {   
        printf("ENTER ELEMENT NUMBER %d :  ", i);    
        scanf("%d",&n);
        ((*name).ptr)[i] = n;
    }
}

void show( struct Ab_array * n){ // This function will show the elements of the array
    for (int i=0; i < (*n).used_size; i++)
    {
        printf("THE ELEMENT NUMBER %d IS --> %d\n", i,((*n).ptr)[i]);
    }
}

int main()
{
    struct Ab_array Marks1;

    Create_Array( &Marks1 , 10, 5); // Since our function struct is a pointer so it expects input to be address
    // The above function means it will fill an array created by struct and put total size 100 and used to be 20

    set_val( & Marks1);

    show( & Marks1);

    // Creating new array using our abstract data type structure

    struct Ab_array Marks2;
    Create_Array( &Marks2, 10, 5);
    set_val( & Marks2);
    show( & Marks2);

    return 0;
}
