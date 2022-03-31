#ifndef SJ_DOUBLY_LINKED_LIST_H
#define SJ_DOUBLY_LINKED_LIST_H

#include <stddef.h> // NULL, size_t
#include <stdbool.h> // bool
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, memset



// ----- Define the structs used by the container -----

#define LIST_DEFINE_NODE(element_type, node_struct_name, node_type) \
typedef struct node_struct_name { \
    struct node_struct_name* next; \
    struct node_struct_name* prev; \
    element_type element; \
} node_type

#define LIST_DEFINE_LIST(node_type, list_struct_name, list_type) \
typedef struct list_struct_name { \
    node_type* front; \
    node_type* back; \
    size_t size; \
} list_type


#define LIST_DEFINE_CONTAINER(element_type, node_struct_name, node_type, list_struct_name, list_type) \
LIST_DEFINE_NODE(element_type, node_struct_name, node_type); \
LIST_DEFINE_LIST(node_type, list_struct_name, list_type)


#define LIST_FOREACH(list_ptr, node_var_name) \
for (__auto_type node_var_name = (list_ptr)->front; node_var_name != NULL; node_var_name = node_var_name->next)

#define LIST_REVERSED_FOREACH(list_ptr, node_var_name) \
for (__auto_type node_var_name = (list_ptr)->back; node_var_name != NULL; node_var_name = node_var_name->prev)

// ----- Declare common functions for the container -----

#define LIST_DECLARE_FUNCTIONS(list_type, element_type, list_construct_func_name, list_empty_func_name, list_size_func_name, list_front_func_name, list_back_func_name, list_at_func_name, list_assign_func_name, list_emplace_front_func_name, list_push_front_func_name, list_pop_front_func_name, list_emplace_back_func_name, list_push_back_func_name, list_pop_back_func_name, list_emplace_func_name, list_insert_func_name, list_erase_func_name, list_swap_func_name, list_resize_func_name, list_clear_func_name, list_destruct_func_name) \
LIST_DECLARE_CONSTRUCT_FUNC(list_construct_func_name, list_type); \
LIST_DECLARE_EMPTY_FUNC(list_empty_func_name, list_type); \
LIST_DECLARE_SIZE_FUNC(list_size_func_name, list_type); \
LIST_DECLARE_FRONT_FUNC(list_front_func_name, list_type, element_type); \
LIST_DECLARE_BACK_FUNC(list_back_func_name, list_type, element_type); \
LIST_DECLARE_AT_FUNC(list_at_func_name, list_type, element_type); \
LIST_DECLARE_ASSIGN_FUNC(list_assign_func_name, list_type, element_type); \
LIST_DECLARE_EMPLACE_FRONT_FUNC(list_emplace_front_func_name, list_type, element_type); \
LIST_DECLARE_PUSH_FRONT_FUNC(list_push_front_func_name, list_type, element_type); \
LIST_DECLARE_POP_FRONT_FUNC(list_pop_front_func_name, list_type); \
LIST_DECLARE_EMPLACE_BACK_FUNC(list_emplace_back_func_name, list_type, element_type); \
LIST_DECLARE_PUSH_BACK_FUNC(list_push_back_func_name, list_type, element_type); \
LIST_DECLARE_POP_BACK_FUNC(list_pop_back_func_name, list_type); \
LIST_DECLARE_EMPLACE_FUNC(list_emplace_func_name, list_type, element_type); \
LIST_DECLARE_INSERT_FUNC(list_insert_func_name, list_type, element_type); \
LIST_DECLARE_ERASE_FUNC(list_erase_func_name, list_type); \
LIST_DECLARE_SWAP_FUNC(list_swap_func_name, list_type); \
LIST_DECLARE_RESIZE_FUNC(list_resize_func_name, list_type, element_type); \
LIST_DECLARE_CLEAR_FUNC(list_clear_func_name, list_type); \
LIST_DECLARE_DESTRUCT_FUNC(list_destruct_func_name, list_type)





// ----- Define common functions for the container -----

#define LIST_DEFINE_FUNCTIONS(list_type, node_type, element_type, list_construct_func_name, list_empty_func_name, list_size_func_name, list_front_func_name, list_back_func_name, list_at_func_name, list_assign_func_name, list_emplace_front_func_name, list_push_front_func_name, list_pop_front_func_name, list_emplace_back_func_name, list_push_back_func_name, list_pop_back_func_name, list_emplace_func_name, list_insert_func_name, list_erase_func_name, list_swap_func_name, list_resize_func_name, list_clear_func_name, list_destruct_func_name) \
LIST_DEFINE_CONSTRUCT_FUNC(list_construct_func_name, list_type); \
LIST_DEFINE_EMPTY_FUNC(list_empty_func_name, list_type); \
LIST_DEFINE_SIZE_FUNC(list_size_func_name, list_type); \
LIST_DEFINE_FRONT_FUNC(list_front_func_name, list_type, element_type); \
LIST_DEFINE_BACK_FUNC(list_back_func_name, list_type, element_type); \
LIST_DEFINE_AT_FUNC(list_at_func_name, list_type, node_type, element_type); \
LIST_DEFINE_ASSIGN_FUNC(list_assign_func_name, list_type, node_type, element_type); \
LIST_DEFINE_EMPLACE_FRONT_FUNC(list_emplace_front_func_name, list_type, node_type, element_type); \
LIST_DEFINE_PUSH_FRONT_FUNC(list_push_front_func_name, list_type, node_type, element_type); \
LIST_DEFINE_POP_FRONT_FUNC(list_pop_front_func_name, list_type, node_type); \
LIST_DEFINE_EMPLACE_BACK_FUNC(list_emplace_back_func_name, list_type, node_type, element_type); \
LIST_DEFINE_PUSH_BACK_FUNC(list_push_back_func_name, list_type, node_type, element_type); \
LIST_DEFINE_POP_BACK_FUNC(list_pop_back_func_name, list_type, node_type); \
LIST_DEFINE_EMPLACE_FUNC(list_emplace_func_name, list_type, node_type, element_type); \
LIST_DEFINE_INSERT_FUNC(list_insert_func_name, list_type, node_type, element_type); \
LIST_DEFINE_ERASE_FUNC(list_erase_func_name, list_type, node_type); \
LIST_DEFINE_SWAP_FUNC(list_swap_func_name, list_type); \
LIST_DEFINE_RESIZE_FUNC(list_resize_func_name, list_type, node_type, element_type); \
LIST_DEFINE_CLEAR_FUNC(list_clear_func_name, list_type, node_type); \
LIST_DEFINE_DESTRUCT_FUNC(list_destruct_func_name, list_type, node_type)



// ----- Macros for declaring functions -----

#define LIST_DECLARE_CONSTRUCT_FUNC(list_construct_func_name, list_type) \
list_type list_construct_func_name()

#define LIST_DECLARE_EMPTY_FUNC(list_empty_func_name, list_type) \
bool list_empty_func_name(list_type* const list_ptr)

#define LIST_DECLARE_SIZE_FUNC(list_size_func_name, list_type) \
size_t list_size_func_name(list_type* const list_ptr)

#define LIST_DECLARE_FRONT_FUNC(list_front_func_name, list_type, element_type) \
element_type* list_front_func_name(list_type* const list_ptr)

#define LIST_DECLARE_BACK_FUNC(list_back_func_name, list_type, element_type) \
element_type* list_back_func_name(list_type* const list_ptr)

#define LIST_DECLARE_AT_FUNC(list_at_func_name, list_type, element_type) \
element_type* list_at_func_name(list_type* const list_ptr, const size_t position)

#define LIST_DECLARE_ASSIGN_FUNC(list_assign_func_name, list_type, element_type) \
void list_assign_func_name(list_type* const list_ptr, const element_type* const new_elements, const size_t new_size)

#define LIST_DECLARE_EMPLACE_FRONT_FUNC(list_emplace_front_func_name, list_type, element_type) \
element_type* list_emplace_front_func_name(list_type* const list_ptr, const bool fill_zeros)

#define LIST_DECLARE_PUSH_FRONT_FUNC(list_push_front_func_name, list_type, element_type) \
element_type* list_push_front_func_name(list_type* const list_ptr, const element_type* const new_element)

#define LIST_DECLARE_POP_FRONT_FUNC(list_pop_front_func_name, list_type) \
void list_pop_front_func_name(list_type* const list_ptr)

#define LIST_DECLARE_EMPLACE_BACK_FUNC(list_emplace_back_func_name, list_type, element_type) \
element_type* list_emplace_back_func_name(list_type* const list_ptr, const bool fill_zeros)

#define LIST_DECLARE_PUSH_BACK_FUNC(list_push_back_func_name, list_type, element_type) \
element_type* list_push_back_func_name(list_type* const list_ptr, const element_type* const new_element)

#define LIST_DECLARE_POP_BACK_FUNC(list_pop_back_func_name, list_type) \
void list_pop_back_func_name(list_type* const list_ptr)

#define LIST_DECLARE_EMPLACE_FUNC(list_emplace_func_name, list_type, element_type) \
element_type* list_emplace_func_name(list_type* const list_ptr, const size_t position, const bool fill_zeros)

#define LIST_DECLARE_INSERT_FUNC(list_insert_func_name, list_type, element_type) \
element_type* list_insert_func_name(list_type* const list_ptr, const size_t position, const element_type* const new_element)

#define LIST_DECLARE_ERASE_FUNC(list_erase_func_name, list_type) \
void list_erase_func_name(list_type* const list_ptr, const size_t position)

#define LIST_DECLARE_SWAP_FUNC(list_swap_func_name, list_type) \
void list_swap_func_name(list_type* const list_a_ptr, list_type* const list_b_ptr)

#define LIST_DECLARE_RESIZE_FUNC(list_resize_func_name, list_type, element_type) \
void list_resize_func_name(list_type* const list_ptr, const size_t new_size, const element_type* const value_ptr)

#define LIST_DECLARE_CLEAR_FUNC(list_clear_func_name, list_type) \
void list_clear_func_name(list_type* const list_ptr)

#define LIST_DECLARE_DESTRUCT_FUNC(list_destruct_func_name, list_type) \
void list_destruct_func_name(list_type* const list_ptr)


// ----- Macros for defining functions -----

#define LIST_DEFINE_CONSTRUCT_FUNC(list_construct_func_name, list_type) \
list_type list_construct_func_name() { \
    list_type new_list = { \
        .front = NULL, \
        .back = NULL, \
        .size = 0 \
    }; \
    return new_list; \
}

#define LIST_DEFINE_EMPTY_FUNC(list_empty_func_name, list_type) \
bool list_empty_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return true; } \
    return (list_ptr->size == 0); \
}

#define LIST_DEFINE_SIZE_FUNC(list_size_func_name, list_type) \
size_t list_size_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return 0; } \
    return list_ptr->size; \
}

#define LIST_DEFINE_FRONT_FUNC(list_front_func_name, list_type, element_type) \
element_type* list_front_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return NULL; } \
    return &(list_ptr->front->element); \
}

#define LIST_DEFINE_BACK_FUNC(list_back_func_name, list_type, element_type) \
element_type* list_back_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return NULL; } \
    return &(list_ptr->back->element); \
}

#define LIST_DEFINE_AT_FUNC(list_at_func_name, list_type, node_type, element_type) \
element_type* list_at_func_name(list_type* const list_ptr, const size_t position) { \
    if (list_ptr == NULL) { return NULL; } \
    if (position >= list_ptr->size) { return NULL; } \
 \
    if(position < (list_ptr->size / 2u)) { \
        node_type* node = list_ptr->front; \
        for (size_t count = 0; count < position; ++count) { \
            node = node->next; \
        } \
        return &(node->element); \
    } \
    else { \
        node_type* node = list_ptr->back; \
        for (size_t count = list_ptr->size-1; count > position; --count) { \
            node = node->prev; \
        } \
        return &(node->element); \
    } \
}

#define LIST_DEFINE_ASSIGN_FUNC(list_assign_func_name, list_type, node_type, element_type) \
void list_assign_func_name(list_type* const list_ptr, const element_type* const new_elements, const size_t new_size) { \
    if (list_ptr == NULL) { return; } \
 \
    node_type* next_node; \
    for (node_type* node = list_ptr->front; node != NULL; node = next_node) { next_node = node->next; free(node); } \
    list_ptr->front = NULL; \
    list_ptr->back = NULL; \
    list_ptr->size = 0; \
 \
    if(new_elements != NULL && new_size != 0) { \
 \
        node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
        if (new_node == NULL) { list_ptr->size = 0; return; } \
        new_node->prev = NULL; \
        new_node->next = NULL; \
        memcpy(&(new_node->element), &(new_elements[0]), sizeof(element_type)); \
        list_ptr->front = new_node; \
        list_ptr->back = new_node; \
         \
        for (size_t i = 1; i < new_size; ++i) { \
            new_node = malloc(sizeof(*(list_ptr->front))); \
            if (new_node == NULL) { list_ptr->size = i+1; return; } \
            new_node->prev = list_ptr->back; \
            new_node->next = NULL; \
            memcpy(&(new_node->element), &(new_elements[i]), sizeof(element_type)); \
            list_ptr->back->next = new_node; \
            list_ptr->back = new_node; \
        } \
 \
        list_ptr->size = new_size; \
    } \
}

#define LIST_DEFINE_EMPLACE_FRONT_FUNC(list_emplace_front_func_name, list_type, node_type, element_type) \
element_type* list_emplace_front_func_name(list_type* const list_ptr, const bool fill_zeros) { \
    if (list_ptr == NULL) { return NULL; } \
 \
    node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
    if (new_node == NULL) { return NULL; } \
    new_node->prev = NULL; \
    new_node->next = list_ptr->front; \
    if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
 \
    if (list_ptr->size == 0) { \
        list_ptr->front = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size = 1; \
        return &(new_node->element); \
    } \
    else { \
        list_ptr->front->prev = new_node; \
        list_ptr->front = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
}

#define LIST_DEFINE_PUSH_FRONT_FUNC(list_push_front_func_name, list_type, node_type, element_type) \
element_type* list_push_front_func_name(list_type* const list_ptr, const element_type* const new_element) { \
    if (list_ptr == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
 \
    node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
    if (new_node == NULL) { return NULL; } \
    new_node->prev = NULL; \
    new_node->next = list_ptr->front; \
    memcpy(&(new_node->element), new_element, sizeof(element_type)); \
 \
    if (list_ptr->size == 0) { \
        list_ptr->front = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size = 1; \
        return &(new_node->element); \
    } \
    else { \
        list_ptr->front->prev = new_node; \
        list_ptr->front = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
}

#define LIST_DEFINE_POP_FRONT_FUNC(list_pop_front_func_name, list_type, node_type) \
void list_pop_front_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return; } \
    if (list_ptr->size == 0) { return; } \
    else if (list_ptr->size == 1) { \
        free(list_ptr->front); \
        list_ptr->front = NULL; \
        list_ptr->back = NULL; \
        list_ptr->size = 0; \
    } \
    else { \
        node_type* old_node = list_ptr->front; \
        list_ptr->front = list_ptr->front->next; \
        list_ptr->front->prev = NULL; \
        list_ptr->size -= 1; \
        free(old_node); \
    } \
}

#define LIST_DEFINE_EMPLACE_BACK_FUNC(list_emplace_back_func_name, list_type, node_type, element_type) \
element_type* list_emplace_back_func_name(list_type* const list_ptr, const bool fill_zeros) { \
    if (list_ptr == NULL) { return NULL; } \
 \
    node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
    if (new_node == NULL) { return NULL; } \
    new_node->next = NULL; \
    new_node->prev = list_ptr->back; \
    if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
 \
    if (list_ptr->size == 0) { \
        list_ptr->front = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size = 1; \
        return &(new_node->element); \
    } \
    else { \
        list_ptr->back->next = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
}

#define LIST_DEFINE_PUSH_BACK_FUNC(list_push_back_func_name, list_type, node_type, element_type) \
element_type* list_push_back_func_name(list_type* const list_ptr, const element_type* const new_element) { \
    if (list_ptr == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
 \
    node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
    if (new_node == NULL) { return NULL; } \
    new_node->next = NULL; \
    new_node->prev = list_ptr->back; \
    memcpy(&(new_node->element), new_element, sizeof(element_type)); \
 \
    if (list_ptr->size == 0) { \
        list_ptr->front = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size = 1; \
        return &(new_node->element); \
    } \
    else { \
        list_ptr->back->next = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
}

#define LIST_DEFINE_POP_BACK_FUNC(list_pop_back_func_name, list_type, node_type) \
void list_pop_back_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return; } \
    if (list_ptr->size == 0) { return; } \
    else if (list_ptr->size == 1) { \
        free(list_ptr->back); \
        list_ptr->front = NULL; \
        list_ptr->back = NULL; \
        list_ptr->size = 0; \
    } \
    else { \
        node_type* old_node = list_ptr->back; \
        list_ptr->back = list_ptr->back->prev; \
        list_ptr->back->next = NULL; \
        list_ptr->size -= 1; \
        free(old_node); \
    } \
}

#define LIST_DEFINE_EMPLACE_FUNC(list_emplace_func_name, list_type, node_type, element_type) \
element_type* list_emplace_func_name(list_type* const list_ptr, const size_t position, const bool fill_zeros) { \
    if (list_ptr == NULL) { return NULL; } \
    if (position > list_ptr->size) { return NULL; } \
 \
    if (position == 0) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
        if (new_node == NULL) { return NULL; } \
        new_node->prev = NULL; \
        new_node->next = list_ptr->front; \
        if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
 \
        if (list_ptr->size == 0) { \
            list_ptr->front = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size = 1; \
            return &(new_node->element); \
        } \
        else { \
            list_ptr->front->prev = new_node; \
            list_ptr->front = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
    } \
    else if (position == list_ptr->size) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
        if (new_node == NULL) { return NULL; } \
        new_node->next = NULL; \
        new_node->prev = list_ptr->back; \
        if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
 \
        if (list_ptr->size == 0) { \
            list_ptr->front = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size = 1; \
            return &(new_node->element); \
        } \
        else { \
            list_ptr->back->next = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
    } \
    else { \
        node_type* current_node;  \
        if(position < (list_ptr->size / 2u)) { \
            current_node = list_ptr->front; \
            for (size_t count = 0; count < position; ++count) { \
                current_node = current_node->next; \
            } \
        } \
        else { \
            current_node = list_ptr->back; \
            for (size_t count = list_ptr->size-1; count > position; --count) { \
                current_node = current_node->prev; \
            } \
        } \
 \
        node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
        if (new_node == NULL) { return NULL; } \
        new_node->next = current_node; \
        new_node->prev = current_node->prev; \
        if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
        current_node->prev->next = new_node; \
        current_node->prev = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
}

#define LIST_DEFINE_INSERT_FUNC(list_insert_func_name, list_type, node_type, element_type) \
element_type* list_insert_func_name(list_type* const list_ptr, const size_t position, const element_type* const new_element) { \
    if (list_ptr == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
    if (position > list_ptr->size) { return NULL; } \
 \
    if (position == 0) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
        if (new_node == NULL) { return NULL; } \
        new_node->prev = NULL; \
        new_node->next = list_ptr->front; \
        memcpy(&(new_node->element), new_element, sizeof(element_type)); \
 \
        if (list_ptr->size == 0) { \
            list_ptr->front = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size = 1; \
            return &(new_node->element); \
        } \
        else { \
            list_ptr->front->prev = new_node; \
            list_ptr->front = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
    } \
    else if (position == list_ptr->size) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
        if (new_node == NULL) { return NULL; } \
        new_node->next = NULL; \
        new_node->prev = list_ptr->back; \
        memcpy(&(new_node->element), new_element, sizeof(element_type)); \
 \
        if (list_ptr->size == 0) { \
            list_ptr->front = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size = 1; \
            return &(new_node->element); \
        } \
        else { \
            list_ptr->back->next = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
    } \
    else { \
        node_type* current_node;  \
        if(position < (list_ptr->size / 2u)) { \
            current_node = list_ptr->front; \
            for (size_t count = 0; count < position; ++count) { \
                current_node = current_node->next; \
            } \
        } \
        else { \
            current_node = list_ptr->back; \
            for (size_t count = list_ptr->size-1; count > position; --count) { \
                current_node = current_node->prev; \
            } \
        } \
 \
        node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
        if (new_node == NULL) { return NULL; } \
        new_node->next = current_node; \
        new_node->prev = current_node->prev; \
        memcpy(&(new_node->element), new_element, sizeof(element_type)); \
        current_node->prev->next = new_node; \
        current_node->prev = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
}

#define LIST_DEFINE_ERASE_FUNC(list_erase_func_name, list_type, node_type) \
void list_erase_func_name(list_type* const list_ptr, const size_t position) { \
    if (list_ptr == NULL) { return; } \
    if (position >= list_ptr->size) { return; } \
 \
    if (position == 0) { \
        if (list_ptr->size == 1) { \
            free(list_ptr->front); \
            list_ptr->front = NULL; \
            list_ptr->back = NULL; \
            list_ptr->size = 0; \
        } \
        else { \
            node_type* old_node = list_ptr->front; \
            list_ptr->front = list_ptr->front->next; \
            list_ptr->front->prev = NULL; \
            list_ptr->size -= 1; \
            free(old_node); \
        } \
    } \
    else if (position == (list_ptr->size - 1)) { \
        if (list_ptr->size == 1) { \
            free(list_ptr->back); \
            list_ptr->front = NULL; \
            list_ptr->back = NULL; \
            list_ptr->size = 0; \
        } \
        else { \
            node_type* old_node = list_ptr->back; \
            list_ptr->back = list_ptr->back->prev; \
            list_ptr->back->next = NULL; \
            list_ptr->size -= 1; \
            free(old_node); \
        } \
    } \
    else { \
 \
        node_type* old_node;  \
        if(position < (list_ptr->size / 2u)) { \
            old_node = list_ptr->front; \
            for (size_t count = 0; count < position; ++count) { \
                old_node = old_node->next; \
            } \
        } \
        else { \
            old_node = list_ptr->back; \
            for (size_t count = list_ptr->size-1; count > position; --count) { \
                old_node = old_node->prev; \
            } \
        } \
 \
        old_node->prev->next = old_node->next; \
        old_node->next->prev = old_node->prev; \
        list_ptr->size -= 1; \
        free(old_node); \
    } \
}

#define LIST_DEFINE_SWAP_FUNC(list_swap_func_name, list_type) \
void list_swap_func_name(list_type* const list_a_ptr, list_type* const list_b_ptr) { \
    if (list_a_ptr == NULL) { return; } \
    if (list_b_ptr == NULL) { return; } \
 \
    list_type temp = *list_a_ptr; \
    *list_a_ptr = *list_b_ptr; \
    *list_b_ptr = temp; \
}

#define LIST_DEFINE_RESIZE_FUNC(list_resize_func_name, list_type, node_type, element_type) \
void list_resize_func_name(list_type* const list_ptr, const size_t new_size, const element_type* const value_ptr) { \
    if (list_ptr == NULL) { return; } \
    const size_t old_size = list_ptr->size; \
 \
    if (new_size == 0) { \
        node_type* next_node; \
        for (node_type* node = list_ptr->front; node != NULL; node = next_node) { next_node = node->next; free(node); } \
        list_ptr->front = NULL; \
        list_ptr->back = NULL; \
        list_ptr->size = 0; \
    } \
    else if (new_size < old_size) { \
        node_type* old_node; \
        for (size_t count = old_size; count > new_size; --count) { \
            old_node = list_ptr->back; \
            list_ptr->back = list_ptr->back->prev; \
            list_ptr->back->next = NULL; \
            free(old_node); \
        } \
        list_ptr->size = new_size; \
    } \
    else if (new_size > old_size) { \
 \
        node_type* new_node; \
        for (size_t count = old_size; count < new_size; ++count) { \
 \
            new_node = malloc(sizeof(*(list_ptr->back))); \
            if (new_node == NULL) { list_ptr->size = count; return; } \
            new_node->next = NULL; \
            new_node->prev = list_ptr->back; \
            if (value_ptr == NULL) { memset(&(new_node->element), 0, sizeof(element_type)); } \
            else { memcpy(&(new_node->element), value_ptr, sizeof(element_type)); } \
 \
            if (count == 0) { \
                list_ptr->front = new_node; \
                list_ptr->back = new_node; \
            } \
            else { \
                list_ptr->back->next = new_node; \
                list_ptr->back = new_node; \
            } \
        } \
        list_ptr->size = new_size; \
    } \
}

#define LIST_DEFINE_CLEAR_FUNC(list_clear_func_name, list_type, node_type) \
void list_clear_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return; } \
    node_type* next_node; \
    for (node_type* node = list_ptr->front; node != NULL; node = next_node) { next_node = node->next; free(node); } \
    list_ptr->front = NULL; \
    list_ptr->back = NULL; \
    list_ptr->size = 0; \
}


#define LIST_DEFINE_DESTRUCT_FUNC(list_destruct_func_name, list_type, node_type) \
void list_destruct_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return; } \
    node_type* next_node; \
    for (node_type* node = list_ptr->front; node != NULL; node = next_node) { next_node = node->next; free(node); } \
    list_ptr->front = NULL; \
    list_ptr->back = NULL; \
    list_ptr->size = 0; \
}







// ----- Declare and define Sorting functions -----

#define LIST_DEFINE_COMPARE_FUNCTION_TYPE(element_compare_func_type, element_type) \
typedef bool (*element_compare_func_type)(const element_type* const, const element_type* const)

#define LIST_COMPARE_CTX_FUNCTION_TYPE(element_ctx_compare_func_type, element_type, element_ctx_type) \
typedef bool (*element_ctx_compare_func_type)(const element_ctx_type* const, const element_type* const)



#define LIST_DECLARE_SORTED_EMPLACE_FUNC(list_sorted_emplace_func_name, list_type, element_type, element_ctx_compare_func_type) \
element_type* list_sorted_emplace_func_name(list_type* const list_ptr, element_ctx_compare_func_type cmp_is_smaller, const element_ctx_type* const ctx, const bool fill_zeros)

#define LIST_DECLARE_SORTED_INSERT_FUNC(list_sorted_insert_func_name, list_type, element_type, element_compare_func_type) \
element_type* list_sorted_insert_func_name(list_type* const list_ptr, element_compare_func_type cmp_is_smaller, const element_type* const new_element)



#define LIST_DEFINE_SORTED_EMPLACE_FUNC(list_sorted_emplace_func_name, list_type, node_type, element_type, element_ctx_compare_func_type) \
element_type* list_sorted_emplace_func_name(list_type* const list_ptr, element_ctx_compare_func_type cmp_is_smaller, const element_ctx_type* const ctx, const bool fill_zeros) { \
    if (list_ptr == NULL) { return NULL; } \
    if (cmp_is_smaller == NULL) { return NULL; } \
 \
    if (list_ptr->size == 0) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
        if (new_node == NULL) { return NULL; } \
        new_node->prev = NULL; \
        new_node->next = NULL; \
        if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
        list_ptr->front = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size = 1; \
        return &(new_node->element); \
    } \
    else if (cmp_is_smaller(ctx, &(list_ptr->front->element))) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
        if (new_node == NULL) { return NULL; } \
        new_node->prev = NULL; \
        new_node->next = list_ptr->front; \
        if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
        list_ptr->front->prev = new_node; \
        list_ptr->front = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
    else { \
        node_type* current_node = list_ptr->front->next; \
        while (current_node != NULL) {  \
            if (cmp_is_smaller(ctx, &(current_node->element))) { break; } \
            else { current_node = current_node->next; } \
        } \
 \
        if (current_node != NULL) { \
            node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
            if (new_node == NULL) { return NULL; } \
            new_node->next = current_node; \
            new_node->prev = current_node->prev; \
            if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
            current_node->prev->next = new_node; \
            current_node->prev = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
        else { \
            node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
            if (new_node == NULL) { return NULL; } \
            new_node->next = NULL; \
            new_node->prev = list_ptr->back; \
            if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
            list_ptr->back->next = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
    } \
}

#define LIST_DEFINE_SORTED_INSERT_FUNC(list_sorted_insert_func_name, list_type, node_type, element_type, element_compare_func_type) \
element_type* list_sorted_insert_func_name(list_type* const list_ptr, element_compare_func_type cmp_is_smaller, const element_type* const new_element) { \
    if (list_ptr == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
    if (cmp_is_smaller == NULL) { return NULL; } \
 \
    if (list_ptr->size == 0) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
        if (new_node == NULL) { return NULL; } \
        new_node->prev = NULL; \
        new_node->next = NULL; \
        memcpy(&(new_node->element), new_element, sizeof(element_type)); \
        list_ptr->front = new_node; \
        list_ptr->back = new_node; \
        list_ptr->size = 1; \
        return &(new_node->element); \
    } \
    else if (cmp_is_smaller(new_element, &(list_ptr->front->element))) { \
        node_type* new_node = malloc(sizeof(*(list_ptr->front))); \
        if (new_node == NULL) { return NULL; } \
        new_node->prev = NULL; \
        new_node->next = list_ptr->front; \
        memcpy(&(new_node->element), new_element, sizeof(element_type)); \
        list_ptr->front->prev = new_node; \
        list_ptr->front = new_node; \
        list_ptr->size += 1; \
        return &(new_node->element); \
    } \
    else { \
        node_type* current_node = list_ptr->front->next; \
        while (current_node != NULL) {  \
            if (cmp_is_smaller(new_element, &(current_node->element))) { break; } \
            else { current_node = current_node->next; } \
        } \
 \
        if (current_node != NULL) { \
            node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
            if (new_node == NULL) { return NULL; } \
            new_node->next = current_node; \
            new_node->prev = current_node->prev; \
            memcpy(&(new_node->element), new_element, sizeof(element_type)); \
            current_node->prev->next = new_node; \
            current_node->prev = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
        else { \
            node_type* new_node = malloc(sizeof(*(list_ptr->back))); \
            if (new_node == NULL) { return NULL; } \
            new_node->next = NULL; \
            new_node->prev = list_ptr->back; \
            memcpy(&(new_node->element), new_element, sizeof(element_type)); \
            list_ptr->back->next = new_node; \
            list_ptr->back = new_node; \
            list_ptr->size += 1; \
            return &(new_node->element); \
        } \
    } \
}








#endif // SJ_DOUBLY_LINKED_LIST_H