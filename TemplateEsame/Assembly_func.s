				
				
				AREA asm_functions, CODE, READONLY				
                EXPORT  ASM_funct
ASM_funct
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument 4 and 5 into R4 and R5
				LDR   r4, [r12]
				LDR   r5, [r12,#4]
				LDR   r6, [r12,#8]
				
				LDR   r7, [r6]
				LDR   r8, [r6,#4]
				
				; your code
				
				; setup a value for R0 to return
				MOV	  r0, r7
				MOV   r1, r8
				; restore volatile registers
				LDMFD sp!,{r4-r8,r10-r11,pc}
				
                END