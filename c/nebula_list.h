// This file is free and open source.
// It was wrote for Nebula Common Compilers
 
#ifndef ___NEBULA_NEBULA_LIST_DEF_EXTERN___
#define ___NEBULA_NEBULA_LIST_DEF_EXTERN___
// --- includes ---
#include "list.h"
// --- externs ---
extern void __init_args__(void);
extern void push_args(void *Elem);
extern void clear_args(void);
extern void *get_args(uint64 index);
extern void del_args(void);
// --- defines ---
__list_t args;
// --- body ---

void __init_args__() {
    args.del = __list_del_fn;
    args.get = __list_get_fn;
    args.insert = __list_insert_fn;
    args.clear = __list_clear_fn;
    args.size = 0;
    args.capacity = 0;
}

void push_args(void *Elem) {
    args.insert(&args, Elem);
}

void clear_args() {
    args.clear(&args);
}

void *get_args(uint64 index) {
    return args.get(&args, index);
}

void del_args(uint64 index) {
    args.del(&args, index);
}

#endif //___NEBULA_NEBULA_LIST_DEF_EXTERN___
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
