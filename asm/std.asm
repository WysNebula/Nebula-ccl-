
; This part of the file was written before building the compiler
; It contains some rules for the process and somes criticals functions.
; *  _   _      _           _       
; * | \ | |    | |         | |      
; * |  \| | ___| |__  _   _| | __ _ 
; * | . ` |/ _ \ '_ \| | | | |/ _` |
; * | |\  |  __/ |_) | |_| | | (_| |
; * |_| \_|\___|_.__/ \__,_|_|\__,_|

section .data

	extern	printf						; Standard printf in C
	extern 	exit						; Standard   exit in C

	__e__ db "Error during process\n", 0
	__a__ db "what():\t",   		   0

section .text

	global _entry:						; void _entry(void)

		mov		rax,	0b1001110		; N
		mov		rax,	0b1100101		; e
		mov		rax,	0b1100010		; b
		mov		rax,	0b1110101		; u
		mov		rax,	0b1110101		; l
		mov		rax,	0b1100001		; a

	ret									; end

	global throw:						; void throw(~)

		mov		rdi,	__e__			; Error during process\n
		call	printf
		
		mov		rdi,	__a__			; what():\t
		call	printf

		mov		rdi,	rcx				; e.what()
		call 	printf

		mov		rdi,	0xA				; \n
		call	printf

		mov		rdi,	0x1
		call	exit

	ret									; end


;/*
; *  _   _      _           _       
; * | \ | |    | |         | |      
; * |  \| | ___| |__  _   _| | __ _ 
; * | . ` |/ _ \ '_ \| | | | |/ _` |
; * | |\  |  __/ |_) | |_| | | (_| |
; * |_| \_|\___|_.__/ \__,_|_|\__,_|
; *                                 
; *  _   _      _           _          _____                                         _____                      _ _           
; * | \ | |    | |         | |        / ____|                                       / ____|                    (_) |          
; * |  \| | ___| |__  _   _| | __ _  | |     ___  _ __ ___  _ __ ___   ___  _ __   | |     ___  _ __ ___  _ __  _| | ___ _ __ 
; * | . ` |/ _ \ '_ \| | | | |/ _` | | |    / _ \| '_ ` _ \| '_ ` _ \ / _ \| '_ \  | |    / _ \| '_ ` _ \| '_ \| | |/ _ \ '__|
; * | |\  |  __/ |_) | |_| | | (_| | | |___| (_) | | | | | | | | | | | (_) | | | | | |___| (_) | | | | | | |_) | | |  __/ |   
; * |_| \_|\___|_.__/ \__,_|_|\__,_|  \_____\___/|_| |_| |_|_| |_| |_|\___/|_| |_|  \_____\___/|_| |_| |_| .__/|_|_|\___|_|   
; *                                                                                                      | |                  
; *                                                                                                      |_|                  
; *  _____            __                          __          __        
; * |  __ \          / _|                         \ \        / /        
; * | |__) | __ ___ | |_ ___  ___ ___  ___  _ __   \ \  /\  / /   _ ___ 
; * |  ___/ '__/ _ \|  _/ _ \/ __/ __|/ _ \| '__|   \ \/  \/ / | | / __|
; * | |   | | | (_) | ||  __/\__ \__ \ (_) | |       \  /\  /| |_| \__ \
; * |_|   |_|  \___/|_| \___||___/___/\___/|_|        \/  \/  \__, |___/
; *                                                            __/ |    
; *                                                           |___/     
; */