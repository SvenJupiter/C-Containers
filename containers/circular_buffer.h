#ifndef SJ_CIRCULAR_BUFFER_H
#define SJ_CIRCULAR_BUFFER_H

#include <threads.h> // mutex


#include <stddef.h> // NULL, size_t
#include <stdint.h> // SIZE_MAX
#include <stdbool.h> // bool
#include <stdlib.h> // malloc, free
#include <string.h> // memset, memcpy




#define CIRCULAR_BUFFER_DEFINE_CONTAINER(element_type, struct_name, buffer_type) \
typedef struct struct_name { \
    element_type* elements; \
    size_t head; \
    size_t tail; \
    size_t size; \
    const size_t capacity; \
    mtx_t mutex; \
} buffer_type


// ----- Declare common functions for the container -----

#define CIRCULAR_BUFFER_DECLARE_FUNCTIONS(buffer_type, element_type, circular_buffer_construct_func_name, circular_buffer_empty_func_name, circular_buffer_full_func_name, circular_buffer_size_func_name, circular_buffer_capacity_func_name, circular_buffer_push_func_name, circular_buffer_pop_func_name, circular_buffer_clear_func_name, circular_buffer_destruct_func_name) \
CIRCULAR_BUFFER_DECLARE_CONSTRUCT_FUNC(circular_buffer_construct_func_name, buffer_type, element_type); \
CIRCULAR_BUFFER_DECLARE_EMPTY_FUNC(circular_buffer_empty_func_name, buffer_type); \
CIRCULAR_BUFFER_DECLARE_FULL_FUNC(circular_buffer_full_func_name, buffer_type); \
CIRCULAR_BUFFER_DECLARE_SIZE_FUNC(circular_buffer_size_func_name, buffer_type); \
CIRCULAR_BUFFER_DECLARE_CAPACITY_FUNC(circular_buffer_capacity_func_name, buffer_type); \
CIRCULAR_BUFFER_DECLARE_PUSH_FUNC(circular_buffer_push_func_name, buffer_type, element_type); \
CIRCULAR_BUFFER_DECLARE_POP_FUNC(circular_buffer_pop_func_name, buffer_type, element_type); \
CIRCULAR_BUFFER_DECLARE_CLEAR_FUNC(circular_buffer_clear_func_name, buffer_type); \
CIRCULAR_BUFFER_DECLARE_DESTRUCT_FUNC(circular_buffer_destruct_func_name, buffer_type) \



// ----- Define common functions for the container -----

#define CIRCULAR_BUFFER_DEFINE_FUNCTIONS(buffer_type, element_type, circular_buffer_construct_func_name, circular_buffer_empty_func_name, circular_buffer_full_func_name, circular_buffer_size_func_name, circular_buffer_capacity_func_name, circular_buffer_push_func_name, circular_buffer_pop_func_name, circular_buffer_clear_func_name, circular_buffer_destruct_func_name) \
CIRCULAR_BUFFER_DEFINE_CONSTRUCT_FUNC(circular_buffer_construct_func_name, buffer_type, element_type); \
CIRCULAR_BUFFER_DEFINE_EMPTY_FUNC(circular_buffer_empty_func_name, buffer_type); \
CIRCULAR_BUFFER_DEFINE_FULL_FUNC(circular_buffer_full_func_name, buffer_type); \
CIRCULAR_BUFFER_DEFINE_SIZE_FUNC(circular_buffer_size_func_name, buffer_type); \
CIRCULAR_BUFFER_DEFINE_CAPACITY_FUNC(circular_buffer_capacity_func_name, buffer_type); \
CIRCULAR_BUFFER_DEFINE_PUSH_FUNC(circular_buffer_push_func_name, buffer_type, element_type); \
CIRCULAR_BUFFER_DEFINE_POP_FUNC(circular_buffer_pop_func_name, buffer_type, element_type); \
CIRCULAR_BUFFER_DEFINE_CLEAR_FUNC(circular_buffer_clear_func_name, buffer_type); \
CIRCULAR_BUFFER_DEFINE_DESTRUCT_FUNC(circular_buffer_destruct_func_name, buffer_type) \




// ----- Macros for declaring functions -----

#define CIRCULAR_BUFFER_DECLARE_CONSTRUCT_FUNC(circular_buffer_construct_func_name, buffer_type, element_type) \
buffer_type circular_buffer_construct_func_name(const size_t buffer_capacity)

#define CIRCULAR_BUFFER_DECLARE_EMPTY_FUNC(circular_buffer_empty_func_name, buffer_type) \
bool circular_buffer_empty_func_name(buffer_type* const cbuff_ptr)

#define CIRCULAR_BUFFER_DECLARE_FULL_FUNC(circular_buffer_full_func_name, buffer_type) \
bool circular_buffer_full_func_name(buffer_type* const cbuff_ptr)

#define CIRCULAR_BUFFER_DECLARE_SIZE_FUNC(circular_buffer_size_func_name, buffer_type) \
bool circular_buffer_size_func_name(buffer_type* const cbuff_ptr, const bool block)

#define CIRCULAR_BUFFER_DECLARE_CAPACITY_FUNC(circular_buffer_capacity_func_name, buffer_type) \
bool circular_buffer_capacity_func_name(buffer_type* const cbuff_ptr)

#define CIRCULAR_BUFFER_DECLARE_PUSH_FUNC(circular_buffer_push_func_name, buffer_type, element_type) \
bool circular_buffer_push_func_name(buffer_type* const cbuff_ptr, const element_type* const new_element, const bool override_if_full)

#define CIRCULAR_BUFFER_DECLARE_POP_FUNC(circular_buffer_pop_func_name, buffer_type, element_type) \
bool circular_buffer_pop_func_name(buffer_type* const cbuff_ptr, element_type* const new_element)

#define CIRCULAR_BUFFER_DECLARE_CLEAR_FUNC(circular_buffer_clear_func_name, buffer_type) \
void circular_buffer_clear_func_name(buffer_type* const cbuff_ptr)

#define CIRCULAR_BUFFER_DECLARE_DESTRUCT_FUNC(circular_buffer_destruct_func_name, buffer_type) \
void circular_buffer_destruct_func_name(buffer_type* const cbuff_ptr)





// ----- Macros for defining functions -----

#define CIRCULAR_BUFFER_DEFINE_CONSTRUCT_FUNC(circular_buffer_construct_func_name, buffer_type, element_type) \
buffer_type circular_buffer_construct_func_name(const size_t buffer_capacity) { \
 \
    buffer_type cbuffer = { \
        .elements = NULL, \
        .head = 0, \
        .tail = 0, \
        .size = 0, \
        .capacity = buffer_capacity, \
    }; \
 \
    if (buffer_capacity > 0) { \
        if (mtx_init(&(cbuffer.mutex), mtx_plain) == thrd_success) { \
            cbuffer.elements = (element_type*) malloc(buffer_capacity * sizeof(element_type)); \
            if (cbuffer.elements == NULL) { mtx_destroy(&(cbuffer.mutex)); } \
        } \
    } \
 \
    return cbuffer; \
}

#define CIRCULAR_BUFFER_DEFINE_EMPTY_FUNC(circular_buffer_empty_func_name, buffer_type) \
bool circular_buffer_empty_func_name(buffer_type* const cbuff_ptr) { \
    if (cbuff_ptr == NULL) { return true; } \
    bool is_empty = false; \
 \
    if (mtx_lock(&(cbuff_ptr->mutex)) == thrd_success) { \
        is_empty = (cbuff_ptr->size == 0); \
        mtx_unlock(&(cbuff_ptr->mutex)); \
    } \
    return is_empty; \
}

#define CIRCULAR_BUFFER_DEFINE_FULL_FUNC(circular_buffer_full_func_name, buffer_type) \
bool circular_buffer_full_func_name(buffer_type* const cbuff_ptr) { \
    if (cbuff_ptr == NULL) { return true; } \
    bool is_full = false; \
 \
    if (mtx_lock(&(cbuff_ptr->mutex)) == thrd_success) { \
        is_full = (cbuff_ptr->size == cbuff_ptr->capacity); \
        mtx_unlock(&(cbuff_ptr->mutex)); \
    } \
    return is_full; \
}

#define CIRCULAR_BUFFER_DEFINE_SIZE_FUNC(circular_buffer_size_func_name, buffer_type) \
bool circular_buffer_size_func_name(buffer_type* const cbuff_ptr, const bool block) { \
    if (cbuff_ptr == NULL) { return true; } \
    size_t num_elements = 0; \
 \
    if (mtx_lock(&(cbuff_ptr->mutex)) == thrd_success) { \
        num_elements = cbuff_ptr->size; \
        mtx_unlock(&(cbuff_ptr->mutex)); \
    } \
    return num_elements; \
}

#define CIRCULAR_BUFFER_DEFINE_CAPACITY_FUNC(circular_buffer_capacity_func_name, buffer_type) \
bool circular_buffer_capacity_func_name(buffer_type* const cbuff_ptr) { \
    if (cbuff_ptr == NULL) { return true; } \
    size_t max_num_elements = 0; \
 \
    if (mtx_lock(&(cbuff_ptr->mutex)) == thrd_success) { \
        max_num_elements = cbuff_ptr->capacity; \
        mtx_unlock(&(cbuff_ptr->mutex)); \
    } \
    return max_num_elements; \
}

#define CIRCULAR_BUFFER_DEFINE_PUSH_FUNC(circular_buffer_push_func_name, buffer_type, element_type) \
bool circular_buffer_push_func_name(buffer_type* const cbuff_ptr, const element_type* const new_element, const bool override_if_full) { \
    if (cbuff_ptr == NULL) { return false; } \
    if (new_element == NULL) { return false; } \
 \
    if (mtx_lock(&(cbuff_ptr->mutex)) == thrd_success) { \
        if (cbuff_ptr->size < cbuff_ptr->capacity) { \
 \
            cbuff_ptr->size += 1; \
            memcpy(&(cbuff_ptr->elements[cbuff_ptr->head]), new_element, sizeof(element_type)); \
            cbuff_ptr->head += 1;  \
            if (cbuff_ptr->head >= cbuff_ptr->capacity) { cbuff_ptr->head = 0; } \
 \
            mtx_unlock(&(cbuff_ptr->mutex)); \
            return true; \
        } \
        else { \
            if (override_if_full) { \
 \
                memcpy(&(cbuff_ptr->elements[cbuff_ptr->head]), new_element, sizeof(element_type)); \
                cbuff_ptr->head += 1;  \
                if (cbuff_ptr->head >= cbuff_ptr->capacity) { cbuff_ptr->head = 0; } \
                cbuff_ptr->tail += 1;  \
                if (cbuff_ptr->tail >= cbuff_ptr->capacity) { cbuff_ptr->tail = 0; } \
 \
                mtx_unlock(&(cbuff_ptr->mutex));  \
                return true; \
            } \
            else { \
                mtx_unlock(&(cbuff_ptr->mutex));  \
                return false;  \
            } \
        } \
    } \
    return false; \
}

#define CIRCULAR_BUFFER_DEFINE_POP_FUNC(circular_buffer_pop_func_name, buffer_type, element_type) \
bool circular_buffer_pop_func_name(buffer_type* const cbuff_ptr, element_type* const new_element) { \
    if (cbuff_ptr == NULL) { return false; } \
    if (new_element == NULL) { return false; } \
 \
    if (mtx_lock(&(cbuff_ptr->mutex)) == thrd_success) { \
        if (cbuff_ptr->size == 0) { \
            mtx_unlock(&(cbuff_ptr->mutex));  \
            return false;  \
        } \
        else { \
 \
            cbuff_ptr->size -= 1; \
            memcpy(new_element, &(cbuff_ptr->elements[cbuff_ptr->tail]), sizeof(element_type)); \
            cbuff_ptr->tail += 1;  \
            if (cbuff_ptr->tail >= cbuff_ptr->capacity) { cbuff_ptr->tail = 0; } \
 \
            mtx_unlock(&(cbuff_ptr->mutex));  \
            return true;  \
        } \
    } \
    return false; \
}

#define CIRCULAR_BUFFER_DEFINE_CLEAR_FUNC(circular_buffer_clear_func_name, buffer_type) \
void circular_buffer_clear_func_name(buffer_type* const cbuff_ptr) { \
    if (cbuff_ptr == NULL) { return; } \
 \
    if (mtx_lock(&(cbuff_ptr->mutex)) == thrd_success) { \
        cbuff_ptr->head = 0; \
        cbuff_ptr->tail = 0; \
        cbuff_ptr->size = 0; \
        mtx_unlock(&(cbuff_ptr->mutex)); \
    } \
}

#define CIRCULAR_BUFFER_DEFINE_DESTRUCT_FUNC(circular_buffer_destruct_func_name, buffer_type) \
void circular_buffer_destruct_func_name(buffer_type* const cbuff_ptr) { \
    if (cbuff_ptr == NULL) { return; } \
    if (cbuff_ptr->elements != NULL) { \
        free(cbuff_ptr->elements);  \
        cbuff_ptr->elements = NULL; \
        cbuff_ptr->head = 0; \
        cbuff_ptr->tail = 0; \
        cbuff_ptr->size = 0; \
        mtx_destroy(&(cbuff_ptr->mutex)); \
    } \
}





#endif