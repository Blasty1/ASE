				AREA asm_functions, CODE, READONLY				
                EXPORT  compress

compress        FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				
				; your code
				;r0 contiene vett
				;r1 contiene MAX-1
				;r2 contiene RES
				
				MOV r3,#0
				MOV r7,#0
				SUB r1,r1,1
				
cominciaCiclo   LDRB r4,[r0],#1
			    LDRB r5,[r0]
				
				;r4 e r5 contengono i valori
				
				SUBS r6,r4,r5
				
				ADDMI r7,r7,#1
				STRB r6,[r2],#1
				
				ADD r3,r3,#1
				CMP r1,r3
				BNE cominciaCiclo
				
				; setup a value for R0 to return
				MOV	r0, r7

				; restore volatile registers
				LDMFD sp!,{r4-r8,r10-r11,pc}
				ENDFUNC
                END