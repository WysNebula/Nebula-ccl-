// This file is free, and open source
// Its a standard Nebula librarie
#ifndef ___NEBULA_STRINGS_LIB___
#define ___NEBULA_STRINGS_LIB___ 

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h> // Super std C lib !!
#include "defines.n"

extern void reverse_string(char *str, uint64 length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

extern const char *int_to_string(int64 num) {
    if (num == 0) {
        const char *zero = "0";
        return zero;
    }

    int isNegative = 0;
	
	if (num < 0) {
        isNegative = 1;
        num = -num;
    }
	
	char str[1024];
    int64 i = 0;

    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem + '0';
        num = num / 10;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse_string(str, i);

    char* result = (char*)malloc((i + 1) * sizeof(char));

    strcpy(result, str);

    return result;
}

extern const char *uint_to_string(uint64 num) {
	if (num == 0) {
		const char *zero = "0";
		return zero;
	}

	char str[1024*4];
	uint64 i = 0;

	while (num != 0) {
		uint64 rem = num % 10;
		str[i++] = rem + '0';
		num = num / 10;
	}

	str[i] = '\0';

	reverse_string(str, i);

	char *result = (char*)malloc((i + 1) * sizeof(char));

	strcpy(result, str);

	return result;
}
extern const char *bool_to_string(bool _bl) {
	if (_bl) { return "true"; } else { return "false"; }
}

#endif //___NEBULA_STRINGS_LIB___

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