#include <stdio.h> // printf
#include "forward_list.h" // forward_list container

// Define a complex datatype
struct data_collection {
    unsigned int a;
    float b;
};


// Define a forward list for a complex datatype.
FORWARD_LIST_DEFINE_CONTAINER(struct data_collection, dc_node_struct, dc_node_t, dc_list_struct, dc_list_t);


// Define the common funtions for interacting the list.
// We must specify what names these functions should get.
FORWARD_LIST_DEFINE_FUNCTIONS(dc_list_t, struct data_collection, 
    dc_list_construct,
    dc_list_emty,
    dc_list_front,
    dc_list_assign,
    dc_list_emplace_front,
    dc_list_push_front,
    dc_list_pop_front,
    dc_list_emplace_after,
    dc_list_insert_after,
    dc_list_erase_after,
    dc_list_swap,
    dc_list_resize,
    dc_list_clear,
    dc_list_destruct
);


// Define a function that prints all elements in a list.
void show_dc_list(dc_list_t* const dc_list) {
    printf("{");

    // We can use the FOREACH macro to iterate through the list.
    // for (fnode_t* node = dc_list->root; node != NULL; node = node->next) {
    FORWARD_LIST_FOREACH(dc_list, node) {
        if (node->next != NULL) { printf("(%u:%.2f), ", node->element.a, node->element.b); }
        else { printf("(%u:%.2f)", node->element.a, node->element.b); }
    }
    printf("}\r\n");
}


void dc_list_test1() {

    // Create a new list.
    printf("Create a new list.\r\n");
    dc_list_t dc_list = dc_list_construct();

    // Add some elements to the front of the list.
    printf("Add some elements to the front of the list.\r\n");
    struct data_collection data[] = {{.a = 3, .b = 1.0f}, {.a = 2, .b = 0.5f}, {.a = 1, .b = 0.75f}, {.a = 0, .b = 0.0f}};
    for (unsigned int i = 0; i < (sizeof(data) / sizeof(struct data_collection)); ++i) {
        dc_list_push_front(&dc_list, &(data[i]));
    }

    // Show the list
    show_dc_list(&dc_list);

    // Remove some elements from the front of the list.
    printf("Remove some elements from the front of the list.\r\n");
    for (unsigned int i = 0; i < 2; ++i) {
        dc_list_pop_front(&dc_list);
    }

    // Show the list again
    show_dc_list(&dc_list);


    // Call the 'destruct' function to release the memory used by the list.
    // You must call the 'destruct' function before the list goes out of scope,
    // or you will have a memeory leak.
    printf("Call the 'destruct' function to release the memory used by the list.\r\n");
    dc_list_destruct(&dc_list);
}




// Define the signature for a function, that compares two instances of the 'struct data_collection' datatype.
FORWARD_LIST_DEFINE_COMPARE_FUNCTION_TYPE(cmp_dc_t, struct data_collection);

// We need to define a comparison function for two instances of the 'struct data_collection' datatype.
bool dc_compare(const struct data_collection* const x ,const struct data_collection* const y) {
    if (x == NULL || y == NULL) { return false; }

    // The comparison depends on the kind of data structure you have
    // return (x->a < y->a); // Compare the 'a' component of the struct
    // return (x->b < y->b); // Compare the 'b' component of the struct

    // Use both component for the comparison
    if (x->a == y->a) { return (x->b < y->b); }
    else { return (x->a < y->a); }
}

// Sorting an already existing list is not implemented yet.
// But you can build a sorted sorted list by using the 'sorted_insert' function for your type of list.
// Please note: The 'sorted_insert' function assumes, that the list is already sorted when trying to insert the new element.
FORWARD_LIST_DEFINE_SORTED_INSERT_FUNC(dc_list_sorted_insert, dc_list_t, struct data_collection, cmp_dc_t);

void dc_list_test2_sorted_insert() {

    // Create a new list.
    printf("Create a new list.\r\n");
    dc_list_t dc_list = dc_list_construct();

    // Add some elements to the list.
    printf("Add some elements to the list.\r\n");
    struct data_collection data[] = {{.a = 3, .b = 1.0f}, {.a = 2, .b = 0.5f}, {.a = 1, .b = 0.75f}, {.a = 0, .b = 0.0f}};
    for (unsigned int i = 0; i < (sizeof(data) / sizeof(struct data_collection)); ++i) {
        dc_list_sorted_insert(&dc_list, &(data[i]), dc_compare);
    }

    // Show the list
    show_dc_list(&dc_list);

    // Remove some elements from the front of the list.
    printf("Remove some elements from the front of the list.\r\n");
    for (unsigned int i = 0; i < 2; ++i) {
        dc_list_pop_front(&dc_list);
    }

    // Show the list again
    show_dc_list(&dc_list);


    // Add some elements to the list.
    printf("Add some more elements to the list.\r\n");
    struct data_collection more_data[] = {{.a = 6, .b = 1/3.0f}, {.a = 5, .b = 2/3.0f}, {.a = 0, .b = 0.9f}, {.a = 1, .b = 2.0f}};
    for (unsigned int i = 0; i < (sizeof(more_data) / sizeof(struct data_collection)); ++i) {
        dc_list_sorted_insert(&dc_list, &(more_data[i]), dc_compare);
    }

    // Show the list again
    show_dc_list(&dc_list);


    // Call the 'destruct' function to release the memory used by the list.
    // You must call the 'destruct' function before the list goes out of scope,
    // or you will have a memeory leak.
    printf("Call the 'destruct' function to release the memory used by the list.\r\n");
    dc_list_destruct(&dc_list);
}



int main() {

    dc_list_test1();
    printf("\r\n");
    dc_list_test2_sorted_insert();

    return 0;
}
