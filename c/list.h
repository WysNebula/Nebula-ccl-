// This file is free and open source.
// It was wrote for Nebula Common Compilers
 
#ifndef ___NEBULA_COMPILER_TEMPLATE_LIST___
#define ___NEBULA_COMPILER_TEMPLATE_LIST___
// --- includes ---
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include "throw.h"
#include "defines.n"
// --- defines ---
#define LIST_MAX_SIZE 4611686018427387904
// --- body ---

struct __list_t {
    uint64 capacity;
    uint64 size;
    void *data;
    void (*insert)(struct __list_t*, void*); // void insert(__list_t& list, void *Elem)
    void (*del)(struct __list_t*, uint64); // void del(__list_t& list, uint64 Who)
    void *(*get)(struct __list_t*, uint64); // void get(__list_t& list, uint64 Elmplacement)
    void (*clear)(struct __list_t*); // void clear(__list_t& list)
};

void __list_insert_fn(struct __list_t *list, void *Elem) {
    if (list->capacity == 0 || list->capacity <= list->size++) {
        list->capacity = sizeof(Elem) * 4;
        list->size++;
        
        list->data = malloc(list->capacity);
        if (list->data == NULL) {
            throw_c("Unable to re-size memory to nebula->list\n<Nebula>, <NebulaC>, <list.h>, <__list_insert_fn>", 1);
        }
        memcpy((char*)list->data + (list->size - 1) * sizeof(Elem), Elem, sizeof(Elem));
    } else {
        list->size++;
        memcpy((char*)list->data + (list->size - 1) * sizeof(Elem), Elem, sizeof(Elem));
    }
}

void *__list_get_fn(struct __list_t *list, uint64 index) {
    if (index >= list->size) {
        throw_c("Index out of bounds\n<Nebula>, <NebulaC>, <list.h>, <__list_get_fn>", 1);
    }

    void *Elem_addr = (char*)list->data + index * list->capacity / list->size;
    return Elem_addr;
}

void __list_del_fn(struct __list_t *list, uint64 index) {
    if (index >= list->size) {
        throw_c("Index out of bounds\n<Nebula>, <NebulaC>, <list.h>, <__list_del_fn>", 1);
    }

    void *element_address = (char *)list->data + index * list->capacity / list->size;

    for (uint64 i = index; i < list->size - 1; ++i) {
        void *next_element_address = (char *)list->data + (i + 1) * list->capacity / list->size;
        memcpy(element_address, next_element_address, list->capacity / list->size);
        element_address = next_element_address;
    }

    list->size--;
    // free list if is empty
    if (list->size == 0) {
        free(list->data);
        list->data;
        list->capacity = 0;
    }
}

void __list_clear_fn(struct __list_t *list) {
    free(list->data);
    list->data;
    list->capacity = 0;
    list->size = 0;
}

#endif //___NEBULA_COMPILER_TEMPLATE_LIST___
/*
 *  _   _      _           _       
 * | \ | |    | |         | |      
 * |  \| | ___| |__  _   _| | __ _ 
 * | . ` |/ _ \ '_ \| | | | |/ _` |
 * | |\  |  __/ |_) | |_| | | (_| |
 * |_| \_|\___|_.__/ \__,_|_|\__,_|
 *                                 
 *  _   _      _           _          _____                                         _____                      _ _           
 * | \ | |    | |         | |        / ____|                                       / ____|                    (_) |          
 * |  \| | ___| |__  _   _| | __ _  | |     ___  _ __ ___  _ __ ___   ___  _ __   | |     ___  _ __ ___  _ __  _| | ___ _ __ 
 * | . ` |/ _ \ '_ \| | | | |/ _` | | |    / _ \| '_ ` _ \| '_ ` _ \ / _ \| '_ \  | |    / _ \| '_ ` _ \| '_ \| | |/ _ \ '__|
 * | |\  |  __/ |_) | |_| | | (_| | | |___| (_) | | | | | | | | | | | (_) | | | | | |___| (_) | | | | | | |_) | | |  __/ |   
 * |_| \_|\___|_.__/ \__,_|_|\__,_|  \_____\___/|_| |_| |_|_| |_| |_|\___/|_| |_|  \_____|\___/|_| |_| |_| .__/|_|_|\___|_|   
 *                                                                                                      | |                  
 *                                                                                                      |_|                  
 *  _____            __                          __          __        
 * |  __ \          / _|                         \ \        / /        
 * | |__) | __ ___ | |_ ___  ___ ___  ___  _ __   \ \  /\  / /   _ ___ 
 * |  ___/ '__/ _ \|  _/ _ \/ __/ __|/ _ \| '__|   \ \/  \/ / | | / __|
 * | |   | | | (_) | ||  __/\__ \__ \ (_) | |       \  /\  /| |_| \__ \
 * |_|   |_|  \___/|_| \___||___/___/\___/|_|        \/  \/  \__, |___/
 *                                                            __/ |    
 *                                                           |___/     
 */
