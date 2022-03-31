#include <stdio.h> // printf
#include "forward_list.h" // forward_list container


// Define a forward list for the float datatype.
FORWARD_LIST_DEFINE_CONTAINER(float, fnode_struct, fnode_t, flist_struct, flist_t);


// Define the common funtions for interacting the list.
// We must specify what names these functions should get.
FORWARD_LIST_DEFINE_FUNCTIONS(flist_t, fnode_t, float, 
    flist_construct,
    flist_emty,
    flist_front,
    flist_assign,
    flist_emplace_front,
    flist_push_front,
    flist_pop_front,
    flist_emplace_after,
    flist_insert_after,
    flist_erase_after,
    flist_swap,
    flist_resize,
    flist_clear,
    flist_destruct
);


// Define a function that prints all elements in a list of floats.
void show_flist(flist_t* const flist) {
    printf("{");

    // We can use the FOREACH macro to iterate through the list.
    // for (fnode_t* node = flist->root; node != NULL; node = node->next) {
    FORWARD_LIST_FOREACH(flist, node) {
        if (node->next != NULL) { printf("%.2f, ", node->element); }
        else { printf("%.2f", node->element); }
    }
    printf("}\r\n");
}




int main() {

    // Create a new list of floats.
    printf("Create a new list of floats.\r\n");
    flist_t flist = flist_construct();

    // Add some elements to the front of the list.
    printf("Add some elements to the front of the list.\r\n");
    for (float f = -1.0f; f <= 1.0f; f += 0.2f) {
        flist_push_front(&flist, &f);
    }

    // Show the list
    show_flist(&flist);

    // Remove some elements from the front of the list.
    printf("Remove some elements from the front of the list.\r\n");
    for (unsigned int i = 0; i < 3; ++i) {
        flist_pop_front(&flist);
    }

    // Show the list again
    show_flist(&flist);


    // Add some elements after a specific position to the list.
    printf("Add some elements after the 2. position to the list.\r\n");
    for (float f = 2.0f; f <= 3.0f; f += 0.25f) {
        flist_insert_after(&flist, 2, &f);
    }

    // Show the list again
    show_flist(&flist);

    // Remove some elements after a specific position to the list.
    printf("Remove some elements after the 4. position of the list.\r\n");
    for (unsigned int i = 0; i < 6; ++i) {
        flist_erase_after(&flist, 4);
    }

    // Show the list again
    show_flist(&flist);

    // Call the 'destruct' function to release the memory used by the list.
    // You must call the 'destruct' function before the list goes out of scope,
    // or you will have a memeory leak.
    printf("Call the 'destruct' function to release the memory used by the list.\r\n");
    flist_destruct(&flist);

    return 0;
}
