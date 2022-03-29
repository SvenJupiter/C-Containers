#ifndef SJ_FORWARD_LIST_H
#define SJ_FORWARD_LIST_H

#include <stddef.h> // NULL
#include <stdbool.h> // bool
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, memset



// ----- Define the structs used by the container -----

#define FORWARD_LIST_DEFINE_NODE(element_type, node_struct_name, node_type) \
typedef struct node_struct_name { \
    struct node_struct_name* next; \
    element_type element; \
} node_type

#define FORWARD_LIST_DEFINE_LIST(node_type, list_struct_name, list_type) \
typedef struct list_struct_name { \
    node_type* root; \
} list_type

#define FORWARD_LIST_DEFINE_CONTAINER(element_type, node_struct_name, node_type, list_struct_name, list_type) \
FORWARD_LIST_DEFINE_NODE(element_type, node_struct_name, node_type); \
FORWARD_LIST_DEFINE_LIST(node_type, list_struct_name, list_type)


#define FORWARD_LIST_FOREACH(list_ptr, node_var_name) \
for (__auto_type node_var_name = (list_ptr)->root; node_var_name != NULL; node_var_name = node_var_name->next)

// ----- Declare common functions for the container -----

#define FORWARD_LIST_DECLARE_FUNCTIONS(list_type, element_type, forward_list_construct_func_name, forward_list_emty_func_name, forward_list_front_func_name, forward_list_assign_func_name, forward_list_emplace_front_func_name, forward_list_push_front_func_name, forward_list_pop_front_func_name, forward_list_emplace_after_func_name, forward_list_insert_after_func_name, forward_list_erase_after_func_name, forward_list_swap_func_name, forward_list_resize_func_name, forward_list_clear_func_name, forward_list_destruct_func_name) \
FORWARD_LIST_DECLARE_CONSTRUCT_FUNC(forward_list_construct_func_name, list_type); \
FORWARD_LIST_DECLARE_EMPTY_FUNC(forward_list_emty_func_name, list_type); \
FORWARD_LIST_DECLARE_FRONT_FUNC(forward_list_front_func_name, list_type, element_type); \
FORWARD_LIST_DECLARE_ASSIGN_FUNC(forward_list_assign_func_name, list_type, element_type); \
FORWARD_LIST_DECLARE_EMPLACE_FRONT_FUNC(forward_list_emplace_front_func_name, list_type, element_type); \
FORWARD_LIST_DECLARE_PUSH_FRONT_FUNC(forward_list_push_front_func_name, list_type, element_type); \
FORWARD_LIST_DECLARE_POP_FRONT_FUNC(forward_list_pop_front_func_name, list_type); \
FORWARD_LIST_DECLARE_EMPLACE_AFTER_FUNC(forward_list_emplace_after_func_name, list_type, element_type); \
FORWARD_LIST_DECLARE_INSERT_AFTER_FUNC(forward_list_insert_after_func_name, list_type, element_type); \
FORWARD_LIST_DECLARE_ERASE_AFTER_FUNC(forward_list_erase_after_func_name, list_type); \
FORWARD_LIST_DECLARE_SWAP_FUNC(forward_list_swap_func_name, list_type); \
FORWARD_LIST_DECLARE_RESIZE_FUNC(forward_list_resize_func_name, list_type, element_type); \
FORWARD_LIST_DECLARE_CLEAR_FUNC(forward_list_clear_func_name, list_type); \
FORWARD_LIST_DECLARE_DESTRUCT_FUNC(forward_list_destruct_func_name, list_type) 



// ----- Define common functions for the container -----

#define FORWARD_LIST_DEFINE_FUNCTIONS(list_type, element_type, forward_list_construct_func_name, forward_list_emty_func_name, forward_list_front_func_name, forward_list_assign_func_name, forward_list_emplace_front_func_name, forward_list_push_front_func_name, forward_list_pop_front_func_name, forward_list_emplace_after_func_name, forward_list_insert_after_func_name, forward_list_erase_after_func_name, forward_list_swap_func_name, forward_list_resize_func_name, forward_list_clear_func_name, forward_list_destruct_func_name) \
FORWARD_LIST_DEFINE_CONSTRUCT_FUNC(forward_list_construct_func_name, list_type); \
FORWARD_LIST_DEFINE_EMPTY_FUNC(forward_list_emty_func_name, list_type); \
FORWARD_LIST_DEFINE_FRONT_FUNC(forward_list_front_func_name, list_type, element_type); \
FORWARD_LIST_DEFINE_ASSIGN_FUNC(forward_list_assign_func_name, list_type, element_type); \
FORWARD_LIST_DEFINE_EMPLACE_FRONT_FUNC(forward_list_emplace_front_func_name, list_type, element_type); \
FORWARD_LIST_DEFINE_PUSH_FRONT_FUNC(forward_list_push_front_func_name, list_type, element_type); \
FORWARD_LIST_DEFINE_POP_FRONT_FUNC(forward_list_pop_front_func_name, list_type); \
FORWARD_LIST_DEFINE_EMPLACE_AFTER_FUNC(forward_list_emplace_after_func_name, list_type, element_type); \
FORWARD_LIST_DEFINE_INSERT_AFTER_FUNC(forward_list_insert_after_func_name, list_type, element_type); \
FORWARD_LIST_DEFINE_ERASE_AFTER_FUNC(forward_list_erase_after_func_name, list_type); \
FORWARD_LIST_DEFINE_SWAP_FUNC(forward_list_swap_func_name, list_type); \
FORWARD_LIST_DEFINE_RESIZE_FUNC(forward_list_resize_func_name, list_type, element_type); \
FORWARD_LIST_DEFINE_CLEAR_FUNC(forward_list_clear_func_name, list_type); \
FORWARD_LIST_DEFINE_DESTRUCT_FUNC(forward_list_destruct_func_name, list_type) 






// ----- Macros for declaring functions -----


#define FORWARD_LIST_DECLARE_CONSTRUCT_FUNC(forward_list_construct_func_name, list_type) \
list_type forward_list_construct_func_name()

#define FORWARD_LIST_DECLARE_EMPTY_FUNC(forward_list_emty_func_name, list_type) \
bool forward_list_emty_func_name(list_type* const list_ptr)

#define FORWARD_LIST_DECLARE_FRONT_FUNC(forward_list_front_func_name, list_type, element_type) \
element_type* forward_list_front_func_name(list_type* const list_ptr)

#define FORWARD_LIST_DECLARE_ASSIGN_FUNC(forward_list_assign_func_name, list_type, element_type) \
void forward_list_assign_func_name(list_type* const list_ptr, const element_type* const new_elements, const unsigned int new_size)

#define FORWARD_LIST_DECLARE_EMPLACE_FRONT_FUNC(forward_list_emplace_front_func_name, list_type, element_type) \
element_type* forward_list_emplace_front_func_name(list_type* const list_ptr, const bool fill_zeros)

#define FORWARD_LIST_DECLARE_PUSH_FRONT_FUNC(forward_list_push_front_func_name, list_type, element_type) \
element_type* forward_list_push_front_func_name(list_type* const list_ptr, const element_type* const new_element)

#define FORWARD_LIST_DECLARE_POP_FRONT_FUNC(forward_list_pop_front_func_name, list_type) \
void forward_list_pop_front_func_name(list_type* const list_ptr)

#define FORWARD_LIST_DECLARE_EMPLACE_AFTER_FUNC(forward_list_emplace_after_func_name, list_type, element_type) \
element_type* forward_list_emplace_after_func_name(list_type* const list_ptr, const unsigned int position, const bool fill_zeros)

#define FORWARD_LIST_DECLARE_INSERT_AFTER_FUNC(forward_list_insert_after_func_name, list_type, element_type) \
element_type* forward_list_insert_after_func_name(list_type* const list_ptr, const unsigned int position, const element_type* const new_element)

#define FORWARD_LIST_DECLARE_ERASE_AFTER_FUNC(forward_list_erase_after_func_name, list_type) \
void forward_list_erase_after_func_name(list_type* const list_ptr, const unsigned int position)

#define FORWARD_LIST_DECLARE_SWAP_FUNC(forward_list_swap_func_name, list_type) \
void forward_list_swap_func_name(list_type* const list_a_ptr, list_type* const list_b_ptr)

#define FORWARD_LIST_DECLARE_RESIZE_FUNC(forward_list_resize_func_name, list_type, element_type) \
void forward_list_resize_func_name(list_type* const list_ptr, const unsigned int new_size, const element_type* const value_ptr)

#define FORWARD_LIST_DECLARE_CLEAR_FUNC(forward_list_clear_func_name, list_type) \
void forward_list_clear_func_name(list_type* const list_ptr)

#define FORWARD_LIST_DECLARE_DESTRUCT_FUNC(forward_list_destruct_func_name, list_type) \
void forward_list_destruct_func_name(list_type* const list_ptr)



// ----- Macros for defining functions -----


#define FORWARD_LIST_DEFINE_CONSTRUCT_FUNC(forward_list_construct_func_name, list_type) \
list_type forward_list_construct_func_name() { \
    list_type list = { \
        .root = NULL \
    }; \
    return list; \
}

#define FORWARD_LIST_DEFINE_EMPTY_FUNC(forward_list_emty_func_name, list_type) \
bool forward_list_emty_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return true; } \
    return (list_ptr->root == NULL); \
}

#define FORWARD_LIST_DEFINE_FRONT_FUNC(forward_list_front_func_name, list_type, element_type) \
element_type* forward_list_front_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return NULL; } \
    return &(list_ptr->root->element); \
}

#define FORWARD_LIST_DEFINE_ASSIGN_FUNC(forward_list_assign_func_name, list_type, element_type) \
void forward_list_assign_func_name(list_type* const list_ptr, const element_type* const new_elements, const unsigned int new_size) { \
    if (list_ptr == NULL ) { return; } \
    typeof(list_ptr->root) next_node; \
    for (__auto_type current_node = list_ptr->root; current_node != NULL; current_node = next_node) { \
        next_node = current_node->next; \
        free(current_node); \
    } \
    list_ptr->root = NULL; \
    if (new_elements == NULL || new_size == 0) {  \
        list_ptr->root = NULL; \
        return;  \
    } \
    else { \
        list_ptr->root = malloc(sizeof(*(list_ptr->root))); \
        if (list_ptr->root == NULL) { return; } \
        list_ptr->root->next = NULL; \
        memcpy(&(list_ptr->root->element), &(new_elements[0]), sizeof(element_type)); \
        __auto_type prev_node = list_ptr->root; \
        typeof(list_ptr->root) new_node; \
        for (unsigned int i = 1; i < new_size; ++i) { \
            new_node = malloc(sizeof(*(list_ptr->root))); \
            if (new_node == NULL) { return; } \
            new_node->next = NULL; \
            memcpy(&(new_node->element), &(new_elements[i]), sizeof(element_type)); \
            prev_node->next = new_node; \
            prev_node = new_node; \
        } \
    } \
}

#define FORWARD_LIST_DEFINE_EMPLACE_FRONT_FUNC(forward_list_emplace_front_func_name, list_type, element_type) \
element_type* forward_list_emplace_front_func_name(list_type* const list_ptr, const bool fill_zeros) { \
    if (list_ptr == NULL) { return NULL; } \
    typeof(list_ptr->root) new_node = malloc(sizeof(*(list_ptr->root))); \
    if (new_node == NULL) { return NULL; } \
    if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
    new_node->next = list_ptr->root; \
    list_ptr->root = new_node; \
    return &(list_ptr->root->element); \
}

#define FORWARD_LIST_DEFINE_PUSH_FRONT_FUNC(forward_list_push_front_func_name, list_type, element_type) \
element_type* forward_list_push_front_func_name(list_type* const list_ptr, const element_type* const new_element) { \
    if (list_ptr == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
    typeof(list_ptr->root) new_node = malloc(sizeof(*(list_ptr->root))); \
    if (new_node == NULL) { return NULL; } \
    memcpy(&(new_node->element), new_element, sizeof(element_type)); \
    new_node->next = list_ptr->root; \
    list_ptr->root = new_node; \
    return &(list_ptr->root->element); \
}

#define FORWARD_LIST_DEFINE_POP_FRONT_FUNC(forward_list_pop_front_func_name, list_type) \
void forward_list_pop_front_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return; } \
    if (list_ptr->root == NULL) { return; } \
    __auto_type old_node = list_ptr->root; \
    list_ptr->root = old_node->next; \
    free(old_node); \
}

#define FORWARD_LIST_DEFINE_EMPLACE_AFTER_FUNC(forward_list_emplace_after_func_name, list_type, element_type) \
element_type* forward_list_emplace_after_func_name(list_type* const list_ptr, const unsigned int position, const bool fill_zeros) { \
    if (list_ptr == NULL) { return NULL; } \
    if (list_ptr->root == NULL) { return NULL; } \
    __auto_type prev_node = list_ptr->root; \
    unsigned int count = 0; \
    while (count < position && prev_node != NULL) { ++count; prev_node = prev_node->next; } \
    if (prev_node == NULL) { return NULL; } \
    else { \
        typeof(prev_node) new_node = malloc(sizeof(*prev_node)); \
        if (new_node == NULL) { return NULL; } \
        else { \
            new_node->next = prev_node->next; \
            prev_node->next = new_node; \
            if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
            return &(new_node->element); \
        } \
    } \
}

#define FORWARD_LIST_DEFINE_INSERT_AFTER_FUNC(forward_list_insert_after_func_name, list_type, element_type) \
element_type* forward_list_insert_after_func_name(list_type* const list_ptr, const unsigned int position, const element_type* const new_element) { \
    if (list_ptr == NULL) { return NULL; } \
    if (list_ptr->root == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
    __auto_type prev_node = list_ptr->root; \
    unsigned int count = 0; \
    while (count < position && prev_node != NULL) { ++count; prev_node = prev_node->next; } \
    if (prev_node == NULL) { return NULL; } \
    else { \
        typeof(prev_node) new_node = malloc(sizeof(*prev_node)); \
        if (new_node == NULL) { return NULL; } \
        else { \
            new_node->next = prev_node->next; \
            prev_node->next = new_node; \
            memcpy(&(new_node->element), new_element, sizeof(element_type)); \
            return &(new_node->element); \
        } \
    } \
}

#define FORWARD_LIST_DEFINE_ERASE_AFTER_FUNC(forward_list_erase_after_func_name, list_type) \
void forward_list_erase_after_func_name(list_type* const list_ptr, const unsigned int position) { \
    if (list_ptr == NULL) { return; } \
    if (list_ptr->root == NULL) { return; } \
    __auto_type prev_node = list_ptr->root; \
    unsigned int count = 0; \
    while (count < position && prev_node != NULL) { ++count; prev_node = prev_node->next; } \
    if (prev_node == NULL) { return; } \
    else if (prev_node->next == NULL) { return; } \
    else { \
        __auto_type old_node = prev_node->next; \
        prev_node->next = old_node->next; \
        free(old_node); \
    } \
}

#define FORWARD_LIST_DEFINE_SWAP_FUNC(forward_list_swap_func_name, list_type) \
void forward_list_swap_func_name(list_type* const list_a_ptr, list_type* const list_b_ptr) { \
    if (list_a_ptr == NULL) { return; } \
    if (list_b_ptr == NULL) { return; } \
    const list_type temp = *list_a_ptr; \
    *list_a_ptr = *list_b_ptr; \
    *list_b_ptr = temp; \
}

#define FORWARD_LIST_DEFINE_RESIZE_FUNC(forward_list_resize_func_name, list_type, element_type) \
void forward_list_resize_func_name(list_type* const list_ptr, const unsigned int new_size, const element_type* const value_ptr) { \
    if (list_ptr == NULL) { return; } \
    if (new_size == 0) { \
        typeof(list_ptr->root) next_node; \
        for (__auto_type current_node = list_ptr->root; current_node != NULL; current_node = next_node) { \
            next_node = current_node->next; \
            free(current_node); \
        } \
        list_ptr->root = NULL; \
    } \
    else if (list_ptr->root == NULL) { \
        list_ptr->root = malloc(sizeof(*(list_ptr->root))); \
        if (list_ptr->root == NULL) { return; } \
        list_ptr->root->next = NULL; \
        if(value_ptr == NULL) { \
            memset(&(list_ptr->root->element), 0, sizeof(element_type)); \
        } \
        else { \
            memcpy(&(list_ptr->root->element), value_ptr, sizeof(element_type)); \
        } \
        __auto_type prev_node = list_ptr->root; \
        typeof(list_ptr->root) new_node; \
        for (unsigned int i = 1; i < new_size; ++i) { \
            new_node = malloc(sizeof(*(list_ptr->root))); \
            if (new_node == NULL) { return; } \
            new_node->next = NULL; \
            if(value_ptr == NULL) { \
                memset(&(new_node->element), 0, sizeof(element_type)); \
            } \
            else { \
                memcpy(&(new_node->element), value_ptr, sizeof(element_type)); \
            } \
            prev_node->next = new_node; \
            prev_node = new_node; \
        } \
    } \
    else { \
        __auto_type prev_node = list_ptr->root; \
        unsigned int count = 1; \
        while (count < new_size && prev_node->next != NULL) {  \
            ++count; \
            prev_node = prev_node->next; \
        } \
        if (count < new_size) { \
            typeof(list_ptr->root) new_node; \
            for (unsigned int i = count; i < new_size; ++i) { \
                new_node = malloc(sizeof(*(list_ptr->root))); \
                if (new_node == NULL) { return; } \
                new_node->next = NULL; \
                if(value_ptr == NULL) { \
                    memset(&(new_node->element), 0, sizeof(element_type)); \
                } \
                else { \
                    memcpy(&(new_node->element), value_ptr, sizeof(element_type)); \
                } \
                prev_node->next = new_node; \
                prev_node = new_node; \
            } \
        } \
        else { \
            typeof(list_ptr->root) next_node; \
            for (__auto_type current_node = prev_node->next; current_node != NULL; current_node = next_node) { \
                next_node = current_node->next; \
                free(current_node); \
            } \
            prev_node->next = NULL; \
        } \
    } \
}

#define FORWARD_LIST_DEFINE_CLEAR_FUNC(forward_list_clear_func_name, list_type) \
void forward_list_clear_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return; } \
    typeof(list_ptr->root) next_node; \
    for (__auto_type current_node = list_ptr->root; current_node != NULL; current_node = next_node) { \
        next_node = current_node->next; \
        free(current_node); \
    } \
    list_ptr->root = NULL; \
}

#define FORWARD_LIST_DEFINE_DESTRUCT_FUNC(forward_list_destruct_func_name, list_type) \
void forward_list_destruct_func_name(list_type* const list_ptr) { \
    if (list_ptr == NULL) { return; } \
    typeof(list_ptr->root) next_node; \
    for (__auto_type current_node = list_ptr->root; current_node != NULL; current_node = next_node) { \
        next_node = current_node->next; \
        free(current_node); \
    } \
    list_ptr->root = NULL; \
}







// ----- Declare and define Sorting functions -----

#define FORWARD_LIST_DEFINE_COMPARE_FUNCTION_TYPE(element_compare_func_type, element_type) typedef bool (*element_compare_func_type)(const element_type* const, const element_type* const)
#define FORWARD_LIST_DEFINE_COMPARE_CTX_FUNCTION_TYPE(element_ctx_compare_func_type, element_ctx_type, element_type) typedef bool (*element_ctx_compare_func_type)(const element_ctx_type* const, const element_type* const)


#define FORWARD_LIST_DECLARE_SORTED_INSERT_FUNC(forward_list_sorted_insert_func_name, list_type, element_type, element_compare_func_type) \
element_type* forward_list_sorted_insert_func_name(list_type* const list_ptr, const element_type* const new_element, element_compare_func_type cmp_is_smaller)

#define FORWARD_LIST_DECLARE_SORTED_EMPLACE(forward_list_sorted_emplace_func_name, list_type, element_type, element_ctx_type, element_ctx_compare_func_type) \
element_type* forward_list_sorted_emplace_func_name(list_type* const list_ptr, element_ctx_compare_func_type cmp_is_smaller, const element_ctx_type* const ctx, const bool fill_zeros)


#define FORWARD_LIST_DEFINE_SORTED_INSERT_FUNC(forward_list_sorted_insert_func_name, list_type, element_type, element_compare_func_type) \
element_type* forward_list_sorted_insert_func_name(list_type* const list_ptr, const element_type* const new_element, element_compare_func_type cmp_is_smaller) { \
    if (list_ptr == NULL) { return NULL; } \
    if (new_element == NULL) { return NULL; } \
    if (cmp_is_smaller == NULL) { return NULL; } \
    if (list_ptr->root == NULL) { \
        typeof(list_ptr->root) new_node = malloc(sizeof(*(list_ptr->root))); \
        if (new_node == NULL) { return NULL; } \
        memcpy(&(new_node->element), new_element, sizeof(element_type)); \
        new_node->next = list_ptr->root; \
        list_ptr->root = new_node; \
        return &(list_ptr->root->element); \
    } \
    else if (cmp_is_smaller(new_element, &(list_ptr->root->element))) { \
        typeof(list_ptr->root) new_node = malloc(sizeof(*(list_ptr->root))); \
        if (new_node == NULL) { return NULL; } \
        memcpy(&(new_node->element), new_element, sizeof(element_type)); \
        new_node->next = list_ptr->root; \
        list_ptr->root = new_node; \
        return &(list_ptr->root->element); \
    } \
    else { \
        __auto_type prev_node = list_ptr->root; \
        while (prev_node->next != NULL) { \
            if (cmp_is_smaller(new_element, &(prev_node->next->element))) { \
                break; \
            } \
            else { \
                prev_node = prev_node->next;  \
            } \
        } \
        typeof(prev_node) new_node = malloc(sizeof(*prev_node)); \
        if (new_node == NULL) { return NULL; } \
        else { \
            new_node->next = prev_node->next; \
            prev_node->next = new_node; \
            memcpy(&(new_node->element), new_element, sizeof(element_type)); \
            return &(new_node->element); \
        } \
    } \
}

#define FORWARD_LIST_DEFINE_SORTED_EMPLACE(forward_list_sorted_emplace_func_name, list_type, element_type, element_ctx_type, element_ctx_compare_func_type) \
element_type* forward_list_sorted_emplace_func_name(list_type* const list_ptr, element_ctx_compare_func_type cmp_is_smaller, const element_ctx_type* const ctx, const bool fill_zeros) { \
    if (list_ptr == NULL) { return NULL; } \
    if (cmp_is_smaller == NULL) { return NULL; } \
    if (list_ptr->root == NULL) { \
        typeof(list_ptr->root) new_node = malloc(sizeof(*(list_ptr->root))); \
        if (new_node == NULL) { return NULL; } \
        if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
        new_node->next = list_ptr->root; \
        list_ptr->root = new_node; \
        return &(list_ptr->root->element); \
    } \
    else if (cmp_is_smaller(ctx, &(list_ptr->root->element))) { \
        typeof(list_ptr->root) new_node = malloc(sizeof(*(list_ptr->root))); \
        if (new_node == NULL) { return NULL; } \
        if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
        new_node->next = list_ptr->root; \
        list_ptr->root = new_node; \
        return &(list_ptr->root->element); \
    } \
    else { \
        __auto_type prev_node = list_ptr->root; \
        while (prev_node->next != NULL) { \
            if (cmp_is_smaller(ctx, &(prev_node->next->element))) { \
                break; \
            } \
            else { \
                prev_node = prev_node->next;  \
            } \
        } \
        typeof(prev_node) new_node = malloc(sizeof(*prev_node)); \
        if (new_node == NULL) { return NULL; } \
        else { \
            new_node->next = prev_node->next; \
            prev_node->next = new_node; \
            if (fill_zeros) { memset(&(new_node->element), 0, sizeof(element_type)); } \
            return &(new_node->element); \
        } \
    } \
}




#endif // SJ_FORWARD_LIST_H
