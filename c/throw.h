// This file is free, and open source
// Its a standard Nebula librarie
#ifndef ___NEBULA_ERROR_THROW___
#define ___NEBULA_ERROR_THROW___
// includes
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
// externs
extern void throw_c(const char *Elem, int Fail);
// body
void throw_c(const char *Elem, int Fail) {
#ifdef _WIN32
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD byteWritten;
    WriteConsole(hCons, Elem, strlen(Elem), &byteWritten, NULL);
#else
    int fd = STDOUT_FILENO;
    write(fd, Elem, strlen(Elem));
#endif // _WIN32
    exit(Fail);
}

#endif // ___NEBULA_ERROR_THROW___

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