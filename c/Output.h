// This file is free, and open source
// Its a standard Nebula librarie
#ifndef ___NEBULA_O_H___
#include <string.h>
#include "String.h" // stdNebula lib
#include "defines.n"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


void print(const char *str) {

#ifdef _WIN32
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD byteWritten;
    WriteConsole(hCons, str, static_cast<DWORD>(strlen(str)), &byteWritten, NULL);
#else
    int fd = STDOUT_FILENO;
    write(fd, str, strlen(str));
#endif // _WIN32

    return;
}

void endl() { print("\n"); }

void printerr(const char *str) { // Too easy...
    print("\033[031m""error: "); print(str); print(RESET_COLORS);
}

void printwarn(const char *str) { // Too easy...
    print("\033[033m""warn: "); print(str); print(RESET_COLORS);
}

#endif // ___NEBULA_O_H___

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
 * |_| \_|\___|_.__/ \__,_|_|\__,_|  \_____\___/|_| |_| |_|_| |_| |_|\___/|_| |_|  \_____\___/|_| |_| |_| .__/|_|_|\___|_|   
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