				
				
				AREA funcs, CODE, READONLY				
                EXPORT  check_square
				EXPORT my_division
check_square	FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				PUSH {r4-r8,r10-r11,lr}				
				
				; your code
				MUL R0,R0,R0; 	x^2
				MUL R1,R1,R1 ;	y^2
				ADD R3,R0,R1 ;	x^2 + y^2
				MUL R4,R2,R2 ; 	R^2
				
				CMP R3,R4
				
				MOVLE R0,#1
				MOVGT R0,#0
				
				; restore volatile registers
				POP {r4-r8,r10-r11,pc}
				
                ENDFUNC
				
				IMPORT __aeabi_fdiv
my_division		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				PUSH {r4-r8,r10-r11,lr}				
				
				LDR R0,[R0]
				LDR R1,[R1]
				
			
				BL __aeabi_fdiv
				

				; restore volatile registers
				POP {r4-r8,r10-r11,pc}
				
                ENDFUNC
				END