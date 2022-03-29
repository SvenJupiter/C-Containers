#include <stdio.h> // printf
#include "vector.h" // vector container


// Define a complex datatype
struct data_collection {
    unsigned int a;
    float b;
};

// Define a vector for a complex datatype.
VECTOR_DEFINE_CONTAINER(struct data_collection, dc_vector_struct, dc_vector_t);


// Define the common funtions for interacting the vector.
// We must specify what names these functions should get.
VECTOR_DEFINE_FUNCTIONS(dc_vector_t, struct data_collection,
    dc_vector_construct,
    dc_vector_reserve,
    dc_vector_resize,
    dc_vector_shrink_to_fit,
    dc_vector_at,
    dc_vector_front,
    dc_vector_back,
    dc_vector_data,
    dc_vector_size,
    dc_vector_capacity,
    dc_vector_empty,
    dc_vector_assign,
    dc_vector_push_back,
    dc_vector_pop_back,
    dc_vector_insert,
    dc_vector_erase,
    dc_vector_swap,
    dc_vector_clear,
    dc_vector_emplace,
    dc_vector_emplace_back,
    dc_vector_destruct
);


// Define a function that prints all elements of a vector.
void show_dc_vector(dc_vector_t* const dc_vec) {

    printf("Size = %u, Capacity = %u: {", dc_vector_size(dc_vec), dc_vector_capacity(dc_vec));

    // We can use the FOREACH macro to iterate through the vector.
    VECTOR_FOREACH(dc_vec, element) {

        if (element != dc_vector_back(dc_vec)) { printf("(%u:%.2f), ", element->a, element->b); }
        else { printf("(%u:%.2f)", element->a, element->b); }

    }

    printf("}\r\n");
}


// Define the signature for a function, that compares two instances of the 'struct data_collection' datatype.
VECTOR_DEFINE_COMPARE_FUNCTION_TYPE(dc_cmp_func_t, struct data_collection);

// We can sort the elements of a vector if we define a comparison function for two instances of the 'struct data_collection' datatype.
bool dc_compare(const struct data_collection* const x, const struct data_collection* const y) {
    if (x == NULL || y == NULL) { return false; }

    // The comparison depends on the kind of data structure you have
    // return (x->a < y->a); // Compare the 'a' component of the struct
    // return (x->b < y->b); // Compare the 'b' component of the struct

    // Use both component for the comparison
    if (x->a == y->a) { return (x->b < y->b); }
    else { return (x->a < y->a); }
}

// Define the sorting function for the vector.
// The elements will be sorted with the Quick-Sort algorithm.
VECTOR_DEFINE_SORT_FUNC(dc_vector_sort, dc_vector_t, dc_cmp_func_t);



int main() {

    // Create a new vector.
    printf("Create a new vector.\r\n");
    const unsigned int initial_capacity = 10;
    dc_vector_t dc_vec = dc_vector_construct(initial_capacity);

    // Show the vector.
    show_dc_vector(&dc_vec);

    printf("Resizing the vector to size 5.\r\n");
    struct data_collection exampe_var = {.a = 42, .b = 73.0f};
    dc_vector_resize(&dc_vec, 5, &exampe_var);

    // Show the vector
    show_dc_vector(&dc_vec);

    // Clear the vector.
    printf("Clear the vector and reserve space for 20 elements.\r\n");
    dc_vector_clear(&dc_vec);
    dc_vector_reserve(&dc_vec, 20);

    // Show the vector.
    show_dc_vector(&dc_vec);

    // Assign an array to a vector.
    struct data_collection exampe_array[] = {
        {.a = 34, .b = 10.0f }, 
        {.a = 6,  .b = 100.0f}, 
        {.a = 78, .b = 50.0f }, 
        {.a = 14, .b = 66.0f }, 
        {.a = 42, .b = 3.0f  }, 
        {.a = 93, .b = 8.0f  }, 
        {.a = 78, .b = 99.0f }, 
        {.a = 78, .b = 55.0f }, 
        {.a = 33, .b = 75.0f }, 
        {.a = 22, .b = 15.0f }, 
        {.a = 43, .b = 12.0f }, 
        {.a = 42, .b = 73.0f }, 
        {.a = 42, .b = 17.0f }, 
    };
    printf("Assign an array to a vector.\r\n");
    dc_vector_assign(&dc_vec, exampe_array, (sizeof(exampe_array)/sizeof(struct data_collection)));

    // Show the vector.
    show_dc_vector(&dc_vec);

    // Now we sort the vector.
    printf("Now we sort the vector.\r\n");
    dc_vector_sort(&dc_vec, dc_compare, 0, dc_vector_size(&dc_vec)-1);


    // Show the vector.
    show_dc_vector(&dc_vec);

    // Call the 'destruct' function to release the memory used by the vector.
    // You must call the 'destruct' function before the vector goes out of scope,
    // or you will have a memeory leak.
    printf("Call the 'destruct' function to release the memory used by the vector.\r\n");
    dc_vector_destruct(&dc_vec);

    return 0;
}
