				
				AREA asm_functions, CODE, READONLY				
                EXPORT  compare 
compare 		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument OF THE FUNCTIon that doesn't fit in r0-r3
				;r0,r1,r2
				

				; your code
				MOV r3,#0 ;indice ciclo
				MOV r6,0
				MOV r7,0
cominciaCiclo1  
				LDRB r4,[r0],#1 ;in r0 e r1 ho l'indirizzo del vettore
				LDRB r5,[r1],#1 
				
				
				CMP r4,r5
				ADDNE r6,r6,1
	
				;CODICE MIO 
				ADD r3,r3,#1
				CMP r2,r3 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo1
				
				; setup a value for R0 to return
				MOV	  r0, r6
				; restore volatile registers
				LDMFD sp!,{r4-r8,r10-r11,pc}
				ENDFUNC

LTORG	
					
				;definizione area dati readONLY
				AREA _data, DATA, READONLY, align=3
					EXPORT my_vector [DATA]
					EXPORT my_variable
my_vector			DCD -5, 0xFFFFFF01
my_variable			DCB 'A'

				;definizione area dati readWRITE
				AREA _data2, DATA, READWRITE, align=3
					EXPORT my_space_4_vector
my_space_4_vector	SPACE    11*22 ;length(11)*n_byte(22)
					
				END  
					
FOR_funct 	  	FUNCTION
				STMFD sp!,{r4-r8,r10-r11,lr}				

				MOV r3,#0 ;indice ciclo
cominciaCiclo  
				LDRB r4,[r0],#1 ;in r0 ho l'indirizzo del vettore
				
				;CODICE MIO 
				ADD r3,r3,#1
				CMP r1,r3 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo
				
				LDMFD sp!,{r4-r8,r10-r11,pc}
				ENDFUNC
				
BubbleSort 		FUNCTION
				Bubble Sort
		bsort:
		// Bubble sort an array of 32bit integers in place
		// Arguments: R0 = Array location, R1 = Array size
		PUSH    {R0-R6,LR}          // Push registers on to the stack
		bsort_next:                     // Check for a sorted array
		MOV     R2,#0               // R2 = Current Element Number
		MOV     R6,#0               // R6 = Number of swaps
		bsort_loop:                     // Start loop
		ADD     R3,R2,#1            // R3 = Next Element Number
		CMP     R3,R1               // Check for the end of the array
		BGE     bsort_check         // When we reach the end, check for changes
		LDR     R4,[R0,R2,LSL #2]   // R4 = Current Element Value
		LDR     R5,[R0,R3,LSL #2]   // R5 = Next Element Value
		CMP     R4,R5               // Compare element values
		STRGT   R5,[R0,R2,LSL #2]   // If R4 > R5, store current value at next
		STRGT   R4,[R0,R3,LSL #2]   // If R4 > R5, Store next value at current
		ADDGT   R6,R6,#1            // If R4 > R5, Increment swap counter
		MOV     R2,R3               // Advance to the next element
		B       bsort_loop          // End loop
		bsort_check:                    // Check for changes
		CMP     R6,#0               // Were there changes this iteration?
		SUBGT   R1,R1,#1            // Optimization: skip last value in next loop
		BGT     bsort_next          // If there were changes, do it again
		bsort_done:                     // Return
		POP     {R0-R6,PC}          // Pop the registers off of the stack
				ENDFUNC
				END
					