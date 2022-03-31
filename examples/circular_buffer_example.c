#include <stdio.h> // printf
#include "circular_buffer.h" // circular buffer container



// Define a complex datatype
struct data_collection {
    unsigned int a;
    float b;
};

// Define a circular buffer for a complex datatype.
CIRCULAR_BUFFER_DEFINE_CONTAINER(struct data_collection, dc_buffer_struct, dc_buffer_t);


// Define the common funtions for interacting with the circular buffer.
// We must specify what names these functions should get.
CIRCULAR_BUFFER_DEFINE_FUNCTIONS(dc_buffer_t, struct data_collection, 
    dc_buffer_construct, 
    dc_buffer_empty, 
    dc_buffer_full, 
    dc_buffer_size, 
    dc_buffer_capacity, 
    dc_buffer_push, 
    dc_buffer_pop, 
    dc_buffer_clear, 
    dc_buffer_destruct
);


int main() {

    // Create a new buffer.
    printf("Create a new buffer with a capacity of 10.\r\n");
    dc_buffer_t dc_buffer = dc_buffer_construct(10);


    // Example data
    struct data_collection exampe_array[] = {
        {.a = 1, .b = 10.0f }, 
        {.a = 2,  .b = 100.0f}, 
        {.a = 3, .b = 50.0f }, 
        {.a = 4, .b = 66.0f }, 
        {.a = 5, .b = 3.0f  }, 
        {.a = 6, .b = 8.0f  }, 
        {.a = 7, .b = 99.0f }, 
        {.a = 8, .b = 55.0f }, 
        {.a = 9, .b = 75.0f }, 
        {.a = 10, .b = 15.0f }, 
        {.a = 11, .b = 12.0f }, 
        {.a = 12, .b = 73.0f }, 
        {.a = 13, .b = 17.0f }, 
    };

    // Putting elements into the buffer without overriding.
    printf("Putting elements into the buffer without overriding.\r\n");
    for (size_t i = 0; i < (sizeof(exampe_array)/sizeof(struct data_collection)); ++i) {
        printf("Putting element %lu: (%u:%.2f) into buffer\r\n", i+1, exampe_array[i].a, exampe_array[i].b);
        if (dc_buffer_push(&dc_buffer, &(exampe_array[i]), false)) {
            printf("Successfull put %lu. element into the buffer\r\n", i+1);
        }
        else {
            printf("Couldn't put %lu. element into the buffer\r\n", i+1);
        }
    }

    // Getting elements from the buffer
    printf("Receiving elements from buffer\r\n");
    struct data_collection example_var;
    for (size_t i = 0; !dc_buffer_empty(&dc_buffer); ++i) {
        if (dc_buffer_pop(&dc_buffer, &example_var)) {
            printf("Received element %lu: (%u:%.2f) from buffer\r\n", i+1, example_var.a, example_var.b);
        }
    }



    // Putting elements into the buffer without overriding.
    printf("Putting elements into the buffer with overriding.\r\n");
    for (size_t i = 0; i < (sizeof(exampe_array)/sizeof(struct data_collection)); ++i) {
        printf("Putting element %lu: (%u:%.2f) into buffer\r\n", i+1, exampe_array[i].a, exampe_array[i].b);
        if (dc_buffer_push(&dc_buffer, &(exampe_array[i]), true)) {
            printf("Successfull put %lu. element into the buffer\r\n", i+1);
        }
        else {
            printf("Couldn't put %lu. element into the buffer\r\n", i+1);
        }
    }

    // Getting elements from the buffer
    printf("Receiving elements from buffer\r\n");
    for (size_t i = 0; !dc_buffer_empty(&dc_buffer); ++i) {
        if (dc_buffer_pop(&dc_buffer, &example_var)) {
            printf("Received element %lu: (%u:%.2f) from buffer\r\n", i+1, example_var.a, example_var.b);
        }
    }


    // Call the 'destruct' function to release the memory used by the buffer.
    // You must call the 'destruct' function before the buffer goes out of scope,
    // or you will have a memeory leak.
    printf("Call the 'destruct' function to release the memory used by the buffer.\r\n");
    dc_buffer_destruct(&dc_buffer);

    return 0;
}







