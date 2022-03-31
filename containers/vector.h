#ifndef SJ_VECTOR_CONTAINER_H
#define SJ_VECTOR_CONTAINER_H

#include <stddef.h> // NULL, size_t
#include <stdint.h> // SIZE_MAX
#include <stdbool.h> // bool
#include <stdlib.h> // malloc, realloc, free
#include <string.h> // memset, memcpy, memmove

#define VECTOR_MAX_CAPACITY SIZE_MAX

#define VECTOR_DEFINE_CONTAINER(element_type, struct_name, vector_type) \
typedef struct struct_name { \
    element_type* elements; \
    size_t size; \
    size_t capacity; \
} vector_type

#define VECTOR_FOREACH(vec_ptr, element_ptr_name) \
for (__auto_type element_ptr_name = (vec_ptr)->elements; element_ptr_name < &((vec_ptr)->elements[(vec_ptr)->size]);  ++element_ptr_name)

#define VECTOR_FOREACH_REVERSED(vec_ptr, element_ptr_name) \
for (__auto_type element_ptr_name = &((vec_ptr)->elements[(vec_ptr)->size-1]); element_ptr_name >= (vec_ptr)->elements;  --element_ptr_name)

// ----- Declare common functions for the container -----

#define VECTOR_DECLARE_FUNCTIONS(vector_type, element_type, vector_construct_func_name, vector_reserve_func_name, vector_resize_func_name, vector_shrink_to_fit_func_name, vector_at_func_name, vector_front_func_name, vector_back_func_name, vector_data_func_name, vector_size_func_name, vector_capacity_func_name, vector_empty_func_name, vector_assign_func_name, vector_push_back_func_name, vector_pop_back_func_name, vector_insert_func_name, vector_erase_func_name, vector_swap_func_name, vector_clear_func_name, vector_emplace_func_name, vector_emplace_back_func_name, vector_destruct_func_name) \
VECTOR_DECLARE_CONSTRUCT_FUNC(vector_construct_func_name, vector_type); \
VECTOR_DECLARE_RESERVE_FUNC(vector_reserve_func_name, vector_type); \
VECTOR_DECLARE_RESIZE_FUNC(vector_resize_func_name, vector_type, element_type); \
VECTOR_DECLARE_SHRINK_TO_FIT_FUNC(vector_shrink_to_fit_func_name, vector_type); \
VECTOR_DECLARE_AT_FUNC(vector_at_func_name, vector_type, element_type); \
VECTOR_DECLARE_FRONT_FUNC(vector_front_func_name, vector_type, element_type); \
VECTOR_DECLARE_BACK_FUNC(vector_back_func_name, vector_type, element_type); \
VECTOR_DECLARE_DATA_FUNC(vector_data_func_name, vector_type, element_type); \
VECTOR_DECLARE_SIZE_FUNC(vector_size_func_name, vector_type); \
VECTOR_DECLARE_CAPACITY_FUNC(vector_capacity_func_name, vector_type); \
VECTOR_DECLARE_EMPTY_FUNC(vector_empty_func_name, vector_type); \
VECTOR_DECLARE_ASSIGN_FUNC(vector_assign_func_name, vector_type, element_type); \
VECTOR_DECLARE_PUSH_BACK_FUNC(vector_push_back_func_name, vector_type, element_type); \
VECTOR_DECLARE_POP_BACK_FUNC(vector_pop_back_func_name, vector_type); \
VECTOR_DECLARE_INSERT_FUNC(vector_insert_func_name, vector_type, element_type); \
VECTOR_DECLARE_ERASE_FUNC(vector_erase_func_name, vector_type); \
VECTOR_DECLARE_SWAP_FUNC(vector_swap_func_name, vector_type); \
VECTOR_DECLARE_CLEAR_FUNC(vector_clear_func_name, vector_type); \
VECTOR_DECLARE_EMPLACE_FUNC(vector_emplace_func_name, vector_type, element_type); \
VECTOR_DECLARE_EMPLACE_BACK_FUNC(vector_emplace_back_func_name, vector_type, element_type); \
VECTOR_DECLARE_DESTRUCT_FUNC(vector_destruct_func_name, vector_type)



// ----- Define common functions for the container -----

#define VECTOR_DEFINE_FUNCTIONS(vector_type, element_type, vector_construct_func_name, vector_reserve_func_name, vector_resize_func_name, vector_shrink_to_fit_func_name, vector_at_func_name, vector_front_func_name, vector_back_func_name, vector_data_func_name, vector_size_func_name, vector_capacity_func_name, vector_empty_func_name, vector_assign_func_name, vector_push_back_func_name, vector_pop_back_func_name, vector_insert_func_name, vector_erase_func_name, vector_swap_func_name, vector_clear_func_name, vector_emplace_func_name, vector_emplace_back_func_name, vector_destruct_func_name) \
VECTOR_DEFINE_CONSTRUCT_FUNC(vector_construct_func_name, vector_type); \
VECTOR_DEFINE_RESERVE_FUNC(vector_reserve_func_name, vector_type, element_type); \
VECTOR_DEFINE_RESIZE_FUNC(vector_resize_func_name, vector_type, element_type); \
VECTOR_DEFINE_SHRINK_TO_FIT_FUNC(vector_shrink_to_fit_func_name, vector_type, element_type); \
VECTOR_DEFINE_AT_FUNC(vector_at_func_name, vector_type, element_type); \
VECTOR_DEFINE_FRONT_FUNC(vector_front_func_name, vector_type, element_type); \
VECTOR_DEFINE_BACK_FUNC(vector_back_func_name, vector_type, element_type); \
VECTOR_DEFINE_DATA_FUNC(vector_data_func_name, vector_type, element_type); \
VECTOR_DEFINE_SIZE_FUNC(vector_size_func_name, vector_type); \
VECTOR_DEFINE_CAPACITY_FUNC(vector_capacity_func_name, vector_type); \
VECTOR_DEFINE_EMPTY_FUNC(vector_empty_func_name, vector_type); \
VECTOR_DEFINE_ASSIGN_FUNC(vector_assign_func_name, vector_type, element_type); \
VECTOR_DEFINE_PUSH_BACK_FUNC(vector_push_back_func_name, vector_type, element_type); \
VECTOR_DEFINE_POP_BACK_FUNC(vector_pop_back_func_name, vector_type); \
VECTOR_DEFINE_INSERT_FUNC(vector_insert_func_name, vector_type, element_type); \
VECTOR_DEFINE_ERASE_FUNC(vector_erase_func_name, vector_type); \
VECTOR_DEFINE_SWAP_FUNC(vector_swap_func_name, vector_type); \
VECTOR_DEFINE_CLEAR_FUNC(vector_clear_func_name, vector_type); \
VECTOR_DEFINE_EMPLACE_FUNC(vector_emplace_func_name, vector_type, element_type); \
VECTOR_DEFINE_EMPLACE_BACK_FUNC(vector_emplace_back_func_name, vector_type, element_type); \
VECTOR_DEFINE_DESTRUCT_FUNC(vector_destruct_func_name, vector_type)





// ----- Macros for declaring functions -----

#define VECTOR_DECLARE_CONSTRUCT_FUNC(vector_construct_func_name, vector_type) \
vector_type vector_construct_func_name(const size_t initial_capacity)

#define VECTOR_DECLARE_RESERVE_FUNC(vector_reserve_func_name, vector_type) \
void vector_reserve_func_name(vector_type* const vec_ptr, const size_t new_capacity)

#define VECTOR_DECLARE_RESIZE_FUNC(vector_resize_func_name, vector_type, element_type) \
void vector_resize_func_name(vector_type* const vec_ptr, const size_t new_size, const element_type* const value_ptr)

#define VECTOR_DECLARE_SHRINK_TO_FIT_FUNC(vector_shrink_to_fit_func_name, vector_type) \
void vector_shrink_to_fit_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_AT_FUNC(vector_at_func_name, vector_type, element_type) \
element_type* vector_at_func_name(vector_type* const vec_ptr, const size_t position)

#define VECTOR_DECLARE_FRONT_FUNC(vector_front_func_name, vector_type, element_type) \
element_type* vector_front_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_BACK_FUNC(vector_back_func_name, vector_type, element_type) \
element_type* vector_back_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_DATA_FUNC(vector_data_func_name, vector_type, element_type) \
element_type* vector_data_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_SIZE_FUNC(vector_size_func_name, vector_type) \
size_t vector_size_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_CAPACITY_FUNC(vector_capacity_func_name, vector_type) \
size_t vector_capacity_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_EMPTY_FUNC(vector_empty_func_name, vector_type) \
bool vector_empty_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_ASSIGN_FUNC(vector_assign_func_name, vector_type, element_type) \
void vector_assign_func_name(vector_type* const vec_ptr, const element_type* const new_elements, const size_t new_size)

#define VECTOR_DECLARE_PUSH_BACK_FUNC(vector_push_back_func_name, vector_type, element_type) \
void vector_push_back_func_name(vector_type* const vec_ptr, const element_type* const new_element)

#define VECTOR_DECLARE_POP_BACK_FUNC(vector_pop_back_func_name, vector_type) \
void vector_pop_back_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_INSERT_FUNC(vector_insert_func_name, vector_type, element_type) \
element_type* vector_insert_func_name(vector_type* const vec_ptr, const size_t position, const element_type* const new_element)

#define VECTOR_DECLARE_ERASE_FUNC(vector_erase_func_name, vector_type) \
void vector_erase_func_name(vector_type* const vec_ptr, const size_t position)

#define VECTOR_DECLARE_SWAP_FUNC(vector_swap_func_name, vector_type) \
void vector_swap_func_name(vector_type* const vec_a_ptr, vector_type* const vec_b_ptr)

#define VECTOR_DECLARE_CLEAR_FUNC(vector_clear_func_name, vector_type) \
void vector_clear_func_name(vector_type* const vec_ptr)

#define VECTOR_DECLARE_EMPLACE_FUNC(vector_emplace_func_name, vector_type, element_type) \
element_type* vector_emplace_func_name(vector_type* const vec_ptr, const size_t position, const bool fill_zeros)

#define VECTOR_DECLARE_EMPLACE_BACK_FUNC(vector_emplace_back_func_name, vector_type, element_type) \
element_type* vector_emplace_back_func_name(vector_type* const vec_ptr, const bool fill_zeros)

#define VECTOR_DECLARE_DESTRUCT_FUNC(vector_destruct_func_name, vector_type) \
void vector_destruct_func_name(vector_type* const vec_ptr)







// ----- Macros for defining functions -----

#define VECTOR_DEFINE_CONSTRUCT_FUNC(vector_construct_func_name, vector_type) vector_type vector_construct_func_name(const size_t initial_capacity) { \
    vector_type vec = { \
        .elements = NULL, \
        .size = 0, \
        .capacity = 0 \
    }; \
    if (initial_capacity > 0) { \
        vec.elements = malloc(initial_capacity * (sizeof(*(vec.elements)))); \
        if (vec.elements != NULL) { \
            vec.capacity = initial_capacity; \
        } \
    } \
    return vec; \
}


#define VECTOR_DEFINE_RESERVE_FUNC(vector_reserve_func_name, vector_type, element_type) \
void vector_reserve_func_name(vector_type* const vec_ptr, const size_t new_capacity) { \
    if (vec_ptr == NULL) { return; } \
    if (new_capacity <= vec_ptr->capacity) { return; } \
    element_type* const reallocated_elements = realloc(vec_ptr->elements, new_capacity * sizeof(*(vec_ptr->elements))); \
    if (reallocated_elements != NULL) { \
        vec_ptr->elements = reallocated_elements; \
        vec_ptr->capacity = new_capacity; \
    } \
}


#define VECTOR_DEFINE_RESIZE_FUNC(vector_resize_func_name, vector_type, element_type) \
void vector_resize_func_name(vector_type* const vec_ptr, const size_t new_size, const element_type* const value_ptr) { \
    if (vec_ptr == NULL) { return; } \
    const size_t old_size = vec_ptr->size; \
    if (new_size == old_size) { return; } \
    else if (new_size < old_size) { \
        vec_ptr->size = new_size; \
        memset(&(vec_ptr->elements[new_size]), 0, (old_size - new_size) * sizeof(element_type)); \
    } \
    else if (new_size <= vec_ptr->capacity) { \
        vec_ptr->size = new_size; \
        if (value_ptr == NULL) { \
            memset(&(vec_ptr->elements[old_size]), 0, (new_size - old_size) * sizeof(element_type)); \
        } \
        else { \
            for (size_t i = old_size; i < new_size; ++i) { \
                memcpy(&(vec_ptr->elements[i]), value_ptr, sizeof(element_type)); \
            } \
        } \
    } \
    else { \
        const size_t new_capacity = new_size; \
        element_type* const reallocated_elements = realloc(vec_ptr->elements, new_capacity * sizeof(element_type)); \
        if (reallocated_elements != NULL) { \
            vec_ptr->elements = reallocated_elements; \
            vec_ptr->capacity = new_capacity; \
            vec_ptr->size = new_size; \
            if (value_ptr == NULL) { \
                memset(&(vec_ptr->elements[old_size]), 0, (new_size - old_size) * sizeof(element_type)); \
            } \
            else { \
                for (size_t i = old_size; i < new_size; ++i) { \
                    memcpy(&(vec_ptr->elements[i]), value_ptr, sizeof(element_type)); \
                } \
            } \
        } \
    } \
}


#define VECTOR_DEFINE_SHRINK_TO_FIT_FUNC(vector_shrink_to_fit_func_name, vector_type, element_type) \
void vector_shrink_to_fit_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return; } \
    const size_t new_capacity = vec_ptr->size; \
    if (new_capacity == 0) { \
        free(vec_ptr->elements); \
        vec_ptr->elements = NULL; \
        vec_ptr->capacity = 0; \
    } \
    else { \
        element_type* const reallocated_elements = realloc(vec_ptr->elements, new_capacity * sizeof(*(vec_ptr->elements))); \
        if (reallocated_elements != NULL) { \
            vec_ptr->elements = reallocated_elements; \
            vec_ptr->capacity = new_capacity; \
        } \
    } \
}


#define VECTOR_DEFINE_AT_FUNC(vector_at_func_name, vector_type, element_type) \
element_type* vector_at_func_name(vector_type* const vec_ptr, const size_t position) { \
    if (vec_ptr == NULL) { return NULL; } \
    if (vec_ptr->elements == NULL) { return NULL; } \
    if (position >= vec_ptr->size) { return NULL; } \
    return &(vec_ptr->elements[position]); \
}


#define VECTOR_DEFINE_FRONT_FUNC(vector_front_func_name, vector_type, element_type) \
element_type* vector_front_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return NULL;} \
    if (vec_ptr->size == 0) { return NULL; } \
    return &(vec_ptr->elements[0]); \
}


#define VECTOR_DEFINE_BACK_FUNC(vector_back_func_name, vector_type, element_type) \
element_type* vector_back_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return NULL; } \
    if (vec_ptr->elements == NULL) { return NULL; } \
    if (vec_ptr->size == 0) { return NULL; } \
    return &(vec_ptr->elements[vec_ptr->size - 1]); \
}


#define VECTOR_DEFINE_DATA_FUNC(vector_data_func_name, vector_type, element_type) \
element_type* vector_data_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return NULL; } \
    return vec_ptr->elements; \
}


#define VECTOR_DEFINE_SIZE_FUNC(vector_size_func_name, vector_type) \
size_t vector_size_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return 0; } \
    return vec_ptr->size; \
}


#define VECTOR_DEFINE_CAPACITY_FUNC(vector_capacity_func_name, vector_type) \
size_t vector_capacity_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return 0; } \
    return vec_ptr->capacity; \
}


#define VECTOR_DEFINE_EMPTY_FUNC(vector_empty_func_name, vector_type) \
bool vector_empty_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return true; } \
    return (vec_ptr->elements == NULL || vec_ptr->size == 0); \
}


#define VECTOR_DEFINE_ASSIGN_FUNC(vector_assign_func_name, vector_type, element_type) \
void vector_assign_func_name(vector_type* const vec_ptr, const element_type* const new_elements, const size_t new_size) { \
    if (vec_ptr == NULL) { return; } \
    const size_t old_size = vec_ptr->size; \
    if (new_elements == NULL || new_size == 0) { \
        if (vec_ptr->elements != NULL && old_size > 0) { \
            memset(vec_ptr->elements, 0, old_size * sizeof(element_type)); \
            vec_ptr->size = 0; \
        } \
    } \
    else if (new_size < old_size) { \
        memcpy(vec_ptr->elements, new_elements, new_size * sizeof(element_type)); \
        memset(&(vec_ptr->elements[new_size]), 0, (old_size - new_size) * sizeof(element_type)); \
        vec_ptr->size = new_size; \
    } \
    else if (new_size <= vec_ptr->capacity) { \
        memcpy(vec_ptr->elements, new_elements, new_size * sizeof(element_type)); \
        vec_ptr->size = new_size; \
    } \
    else { \
        element_type* const reallocated_array = malloc(new_size * sizeof(element_type)); \
        if (reallocated_array != NULL) { \
            if (vec_ptr->elements != NULL) { free(vec_ptr->elements); } \
            vec_ptr->elements = reallocated_array; \
            memcpy(vec_ptr->elements, new_elements, new_size * sizeof(element_type)); \
            vec_ptr->size = new_size; \
            vec_ptr->capacity = new_size; \
        } \
    } \
}


#define VECTOR_DEFINE_PUSH_BACK_FUNC(vector_push_back_func_name, vector_type, element_type) \
void vector_push_back_func_name(vector_type* const vec_ptr, const element_type* const new_element) { \
    if (vec_ptr == NULL) { return; } \
    if (new_element == NULL) { return; } \
    if (vec_ptr->size == VECTOR_MAX_CAPACITY) { return; } \
    if (vec_ptr->capacity == 0) { \
        vec_ptr->elements = malloc(sizeof(element_type)); \
        if (vec_ptr->elements != NULL) { \
            memcpy(vec_ptr->elements, new_element, sizeof(element_type)); \
            vec_ptr->size = 1; \
            vec_ptr->capacity = 1; \
        } \
    } \
    else if (vec_ptr->size < vec_ptr->capacity) { \
        memcpy(&(vec_ptr->elements[vec_ptr->size]), new_element, sizeof(element_type)); \
        vec_ptr->size += 1; \
    } \
    else { \
        const size_t new_capacity = (((VECTOR_MAX_CAPACITY / 2) < vec_ptr->capacity) ? VECTOR_MAX_CAPACITY : 2 * vec_ptr->capacity); \
        element_type* const reallocated_elements = realloc(vec_ptr->elements, new_capacity * sizeof(element_type)); \
        if (reallocated_elements != NULL) { \
            vec_ptr->elements = reallocated_elements; \
            vec_ptr->capacity = new_capacity; \
            memcpy(&(vec_ptr->elements[vec_ptr->size]), new_element, sizeof(element_type)); \
            vec_ptr->size += 1; \
        } \
    } \
}


#define VECTOR_DEFINE_POP_BACK_FUNC(vector_pop_back_func_name, vector_type) \
void vector_pop_back_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return; } \
    if (vec_ptr->size > 0) { \
        memset(&(vec_ptr->elements[vec_ptr->size - 1]), 0, sizeof(*(vec_ptr->elements))); \
        vec_ptr->size -= 1; \
    } \
}


#define VECTOR_DEFINE_INSERT_FUNC(vector_insert_func_name, vector_type, element_type) \
element_type* vector_insert_func_name(vector_type* const vec_ptr, const size_t position, const element_type* const new_element) { \
    if (vec_ptr == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
    if (vec_ptr->size == VECTOR_MAX_CAPACITY) { return NULL; } \
    if (position > vec_ptr->size) { return NULL; } \
    else if (position == vec_ptr->size) { \
        if (vec_ptr->capacity == 0) { \
            vec_ptr->elements = malloc(sizeof(element_type)); \
            if (vec_ptr->elements != NULL) { \
                memcpy(vec_ptr->elements, new_element, sizeof(element_type)); \
                vec_ptr->size = 1; \
                vec_ptr->capacity = 1; \
                return &(vec_ptr->elements[0]); \
            } \
            else { \
                return NULL; \
            } \
        } \
        else if (vec_ptr->size < vec_ptr->capacity) { \
            memcpy(&(vec_ptr->elements[vec_ptr->size]), new_element, sizeof(element_type)); \
            vec_ptr->size += 1; \
            return &(vec_ptr->elements[vec_ptr->size - 1]); \
        } \
        else { \
            const size_t new_capacity = (((VECTOR_MAX_CAPACITY / 2) < vec_ptr->capacity) ? VECTOR_MAX_CAPACITY : 2 * vec_ptr->capacity); \
            element_type* const reallocated_elements = realloc(vec_ptr->elements, new_capacity * sizeof(element_type)); \
            if (reallocated_elements != NULL) { \
                vec_ptr->elements = reallocated_elements; \
                vec_ptr->capacity = new_capacity; \
                memcpy(&(vec_ptr->elements[vec_ptr->size]), new_element, sizeof(element_type)); \
                vec_ptr->size += 1; \
                return &(vec_ptr->elements[vec_ptr->size - 1]); \
            } \
            else { \
                return NULL; \
            } \
        } \
    } \
    else { \
        if (vec_ptr->size < vec_ptr->capacity) { \
            memmove(&(vec_ptr->elements[position+1]), &(vec_ptr->elements[position]), (vec_ptr->size - position) * sizeof(element_type)); \
            memcpy(&(vec_ptr->elements[position]), new_element, sizeof(element_type)); \
            vec_ptr->size += 1; \
            return &(vec_ptr->elements[position]); \
        } \
        else { \
            const size_t new_capacity = (((VECTOR_MAX_CAPACITY / 2) < vec_ptr->capacity) ? VECTOR_MAX_CAPACITY : 2 * vec_ptr->capacity); \
            element_type* const reallocated_array = malloc(new_capacity * sizeof(element_type)); \
            if (reallocated_array != NULL) { \
                if (position > 0) { \
                    memcpy(reallocated_array, vec_ptr->elements, position * sizeof(element_type)); \
                } \
                memcpy(&(reallocated_array[position]), new_element, sizeof(element_type)); \
                if (position < vec_ptr->size) { \
                    memcpy(&(reallocated_array[position+1]), &(vec_ptr->elements[position]), (vec_ptr->size - position) * sizeof(element_type)); \
                } \
                free(vec_ptr->elements); \
                vec_ptr->elements = reallocated_array; \
                vec_ptr->capacity = new_capacity; \
                vec_ptr->size += 1; \
                return &(vec_ptr->elements[position]); \
            } \
            else { \
                return NULL; \
            } \
        } \
    } \
}


#define VECTOR_DEFINE_ERASE_FUNC(vector_erase_func_name, vector_type) \
void vector_erase_func_name(vector_type* const vec_ptr, const size_t position) { \
    if (vec_ptr == NULL) { return; } \
    if (position >= vec_ptr->size) { return; } \
    else if (position == (vec_ptr->size -1)) { \
        memset(&(vec_ptr->elements[position]), 0, sizeof(*(vec_ptr->elements))); \
        vec_ptr->size -= 1; \
    } \
    else { \
        memmove(&(vec_ptr->elements[position]), &(vec_ptr->elements[position+1]), (vec_ptr->size - (position + 1)) * sizeof(*(vec_ptr->elements))); \
        memset(&(vec_ptr->elements[vec_ptr->size -1]), 0, sizeof(*(vec_ptr->elements))); \
        vec_ptr->size -= 1; \
    } \
}


#define VECTOR_DEFINE_SWAP_FUNC(vector_swap_func_name, vector_type) \
void vector_swap_func_name(vector_type* const vec_a_ptr, vector_type* const vec_b_ptr) { \
    if (vec_a_ptr == NULL) { return; } \
    if (vec_b_ptr == NULL) { return; } \
    const vector_type temp = *vec_a_ptr; \
    *vec_a_ptr = *vec_b_ptr; \
    *vec_b_ptr = temp; \
}


#define VECTOR_DEFINE_CLEAR_FUNC(vector_clear_func_name, vector_type) \
void vector_clear_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return; } \
    if (vec_ptr->size > 0) { \
        memset(vec_ptr->elements, 0, vec_ptr->size * sizeof(*(vec_ptr->elements))); \
        vec_ptr->size = 0; \
    } \
}


#define VECTOR_DEFINE_EMPLACE_FUNC(vector_emplace_func_name, vector_type, element_type) \
element_type* vector_emplace_func_name(vector_type* const vec_ptr, const size_t position, const bool fill_zeros) { \
    if (vec_ptr == NULL) { return NULL; } \
    if (vec_ptr->size == VECTOR_MAX_CAPACITY) { return NULL; } \
    if (position > vec_ptr->size) { return NULL; } \
    else if (position == vec_ptr->size) { \
        if (vec_ptr->capacity == 0) { \
            vec_ptr->elements = malloc(sizeof(element_type)); \
            if (vec_ptr->elements != NULL) { \
                if (fill_zeros) { memset(vec_ptr->elements, 0, sizeof(element_type)); } \
                vec_ptr->size = 1; \
                vec_ptr->capacity = 1; \
                return &(vec_ptr->elements[0]); \
            } \
            else { \
                return NULL; \
            } \
        } \
        else if (vec_ptr->size < vec_ptr->capacity) { \
            if (fill_zeros) { memset(&(vec_ptr->elements[vec_ptr->size]), 0, sizeof(element_type)); } \
            vec_ptr->size += 1; \
            return &(vec_ptr->elements[vec_ptr->size - 1]); \
        } \
        else { \
            const size_t new_capacity = (((VECTOR_MAX_CAPACITY / 2) < vec_ptr->capacity) ? VECTOR_MAX_CAPACITY : 2 * vec_ptr->capacity); \
            element_type* const reallocated_elements = realloc(vec_ptr->elements, new_capacity * sizeof(element_type)); \
            if (reallocated_elements != NULL) { \
                vec_ptr->elements = reallocated_elements; \
                vec_ptr->capacity = new_capacity; \
                if (fill_zeros) { memset(&(vec_ptr->elements[vec_ptr->size]), 0, sizeof(element_type)); } \
                vec_ptr->size += 1; \
                return &(vec_ptr->elements[vec_ptr->size - 1]); \
            } \
            else { \
                return NULL; \
            } \
        } \
    } \
    else { \
        if (vec_ptr->size < vec_ptr->capacity) { \
            memmove(&(vec_ptr->elements[position+1]), &(vec_ptr->elements[position]), (vec_ptr->size - position) * sizeof(element_type)); \
            if (fill_zeros) { memset(&(vec_ptr->elements[position]), 0, sizeof(element_type)); } \
            vec_ptr->size += 1; \
            return &(vec_ptr->elements[position]); \
        } \
        else { \
            const size_t new_capacity = (((VECTOR_MAX_CAPACITY / 2) < vec_ptr->capacity) ? VECTOR_MAX_CAPACITY : 2 * vec_ptr->capacity); \
            element_type* const reallocated_array = malloc(new_capacity * sizeof(element_type)); \
            if (reallocated_array != NULL) { \
                if (position > 0) { \
                    memcpy(reallocated_array, vec_ptr->elements, position * sizeof(element_type)); \
                } \
                if (fill_zeros) { memset(&(reallocated_array[position]), 0, sizeof(element_type)); } \
                if (position < vec_ptr->size) { \
                    memcpy(&(reallocated_array[position+1]), &(vec_ptr->elements[position]), (vec_ptr->size - position) * sizeof(element_type)); \
                } \
                free(vec_ptr->elements); \
                vec_ptr->elements = reallocated_array; \
                vec_ptr->capacity = new_capacity; \
                vec_ptr->size += 1; \
                return &(vec_ptr->elements[position]); \
            } \
            else { \
                return NULL; \
            } \
        } \
    } \
}


#define VECTOR_DEFINE_EMPLACE_BACK_FUNC(vector_emplace_back_func_name, vector_type, element_type) \
element_type* vector_emplace_back_func_name(vector_type* const vec_ptr, const bool fill_zeros) { \
    if (vec_ptr == NULL) { return NULL; } \
    if (vec_ptr->size == VECTOR_MAX_CAPACITY) { return NULL; } \
    if (vec_ptr->capacity == 0) { \
        vec_ptr->elements = malloc(sizeof(element_type)); \
        if (vec_ptr->elements != NULL) { \
            if (fill_zeros) { memset(vec_ptr->elements, 0, sizeof(element_type)); } \
            vec_ptr->size = 1; \
            vec_ptr->capacity = 1; \
            return vec_ptr->elements; \
        } \
        else { \
            return NULL; \
        } \
    } \
    else if (vec_ptr->size < vec_ptr->capacity) { \
        if (fill_zeros) { memset(&(vec_ptr->elements[vec_ptr->size]), 0, sizeof(element_type)); } \
        vec_ptr->size += 1; \
        return &(vec_ptr->elements[vec_ptr->size-1]); \
    } \
    else { \
        const size_t new_capacity = (((VECTOR_MAX_CAPACITY / 2) < vec_ptr->capacity) ? VECTOR_MAX_CAPACITY : 2 * vec_ptr->capacity); \
        element_type* const reallocated_elements = realloc(vec_ptr->elements, new_capacity * sizeof(element_type)); \
        if (reallocated_elements != NULL) { \
            vec_ptr->elements = reallocated_elements; \
            vec_ptr->capacity = new_capacity; \
            if (fill_zeros) { memset(&(vec_ptr->elements[vec_ptr->size]), 0, sizeof(element_type)); } \
            vec_ptr->size += 1; \
            return &(vec_ptr->elements[vec_ptr->size-1]); \
        } \
        else { \
            return NULL; \
        } \
    } \
}


#define VECTOR_DEFINE_DESTRUCT_FUNC(vector_destruct_func_name, vector_type) \
void vector_destruct_func_name(vector_type* const vec_ptr) { \
    if (vec_ptr == NULL) { return; } \
    if (vec_ptr->elements != NULL) { \
        free(vec_ptr->elements); \
        vec_ptr->elements = NULL; \
    } \
    vec_ptr->capacity = 0; \
    vec_ptr->size = 0; \
}





// ----- Declare and define Sorting functions -----

#define VECTOR_DEFINE_COMPARE_FUNCTION_TYPE(element_compare_func_type, element_type) \
typedef bool (*element_compare_func_type)(const element_type* const, const element_type* const)


#define VECTOR_DECLARE_SORT_FUNC(vector_quick_sort_func_name, vector_type, element_compare_func_type) \
void vector_quick_sort_func_name(vector_type* const vec_ptr, element_compare_func_type cmp_is_smaller, const size_t start, const size_t end)


#define VECTOR_DEFINE_SORT_FUNC(vector_quick_sort_func_name, vector_type, element_type, element_compare_func_type) \
void vector_quick_sort_func_name(vector_type* const vec_ptr, element_compare_func_type cmp_is_smaller, const size_t start, const size_t end) { \
    if (vec_ptr == NULL) { return; } \
    if (vec_ptr->elements == NULL) { return; } \
    if (cmp_is_smaller == NULL) { return; } \
    if (end >= vec_ptr->size) { return; } \
    if (start >= end) { return; } \
    else if ((end - start + 1) == 2) { \
        if (cmp_is_smaller(&(vec_ptr->elements[end]), &(vec_ptr->elements[start]))) { \
            element_type* const temp = malloc(sizeof(*(vec_ptr->elements))); \
            if (temp == NULL) { return; } \
            memcpy(temp, &(vec_ptr->elements[end]), sizeof(*(vec_ptr->elements))); \
            memcpy(&(vec_ptr->elements[end]), &(vec_ptr->elements[start]), sizeof(*(vec_ptr->elements))); \
            memcpy(&(vec_ptr->elements[start]), temp, sizeof(*(vec_ptr->elements))); \
            free(temp); \
        } \
    } \
    else { \
        size_t pivot = end; \
        size_t right = end; \
        size_t left = start-1; \
        element_type* const pivot_element = malloc(sizeof(*(vec_ptr->elements))); \
        if (pivot_element == NULL) { return; } \
        else { memcpy(pivot_element, &(vec_ptr->elements[pivot]), sizeof(*(vec_ptr->elements))); } \
        while (left+1 < right) { \
            while (left+1 < right) { \
                ++left; \
                if (cmp_is_smaller(pivot_element, &(vec_ptr->elements[left]))) { \
                    memcpy(&(vec_ptr->elements[pivot]), &(vec_ptr->elements[left]), sizeof(*(vec_ptr->elements))); \
                    pivot = left; \
                    break; \
                } \
            } \
            while (right > left+1) { \
                --right; \
                if (cmp_is_smaller(&(vec_ptr->elements[right]), pivot_element)) { \
                    memcpy(&(vec_ptr->elements[pivot]), &(vec_ptr->elements[right]), sizeof(*(vec_ptr->elements))); \
                    pivot = right; \
                    break; \
                } \
            } \
        } \
        memcpy(&(vec_ptr->elements[pivot]), pivot_element, sizeof(*(vec_ptr->elements))); \
        free(pivot_element); \
        vector_quick_sort_func_name(vec_ptr, cmp_is_smaller, start, pivot - 1); \
        vector_quick_sort_func_name(vec_ptr, cmp_is_smaller, pivot + 1, end); \
    } \
}




#endif // SJ_VECTOR_CONTAINER_H
