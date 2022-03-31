#include <stdio.h> // printf
#include "list.h" // list container


// Define a forward list for the double datatype.
LIST_DEFINE_CONTAINER(double, dnode_struct, dnode_t, dlist_struct, dlist_t);


// Define the common funtions for interacting the list.
// We must specify what names these functions should get.
LIST_DEFINE_FUNCTIONS(dlist_t, dnode_t, double, 
    dlist_construct,
    dlist_empty,
    dlist_size,
    dlist_front,
    dlist_back,
    dlist_at,
    dlist_assign,
    dlist_emplace_front,
    dlist_push_front,
    dlist_pop_front,
    dlist_emplace_back,
    dlist_push_back,
    dlist_pop_back,
    dlist_emplace,
    dlist_insert,
    dlist_erase,
    dlist_swap,
    dlist_resize,
    dlist_clear,
    dlist_destruct
);


// Define a function that prints all elements in a list of floats.
void show_dlist(dlist_t* const dlist) {
    printf("{");

    // We can use the FOREACH macro to iterate through the list.
    // for (fnode_t* node = dlist->front; node != NULL; node = node->next) {
    LIST_FOREACH(dlist, node) {
        if (node->next != NULL) { printf("%.2lf, ", node->element); }
        else { printf("%.2lf", node->element); }
    }
    printf("}\r\n");
}




int main() {

    // Create a new list of floats.
    printf("Create a new list of floats.\r\n");
    dlist_t dlist = dlist_construct();

    // Add some elements to the front of the list.
    printf("Add some elements to the front of the list.\r\n");
    for (double d = -1.0; d <= 1.0; d += 0.2) {
        dlist_push_front(&dlist, &d);
    }

    // Show the list
    show_dlist(&dlist);

    // Remove some elements from the front of the list.
    printf("Remove some elements from the front of the list.\r\n");
    for (unsigned int i = 0; i < 3; ++i) {
        dlist_pop_front(&dlist);
    }

    // Show the list again
    show_dlist(&dlist);


    // Add some elements to the back of the list.
    printf("Add some elements to the back of the list..\r\n");
    for (double d = 2.0; d <= 3.0; d += 0.25) {
        // dlist_insert(&dlist, 2, &d);
        dlist_push_back(&dlist, &d);

    }

    // Show the list again
    show_dlist(&dlist);

    // Remove some elements at a specific position to the list.
    printf("Remove some elements at the 4. position of the list.\r\n");
    for (unsigned int i = 0; i < 6; ++i) {
        dlist_erase(&dlist, 4);
    }

    // Show the list again
    show_dlist(&dlist);

    // Call the 'destruct' function to release the memory used by the list.
    // You must call the 'destruct' function before the list goes out of scope,
    // or you will have a memeory leak.
    printf("Call the 'destruct' function to release the memory used by the list.\r\n");
    dlist_destruct(&dlist);

    return 0;
}
