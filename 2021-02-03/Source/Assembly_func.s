				
				AREA asm_functions, CODE, READONLY				
                EXPORT  duty_cycle
duty_cycle		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				

				; your code
				MOV r4,#0 ;indice ciclo
				MOV r7,1
				MOV r6,0
cominciaCiclo1  
				LDRB r5,[r2],#4 ;in r0 ho l'indirizzo del vettore
				
				CMP r5,r7
				ADDEQ r6,r6,r5
				
				;CODICE MIO 
				ADD r4,r4,#1
				CMP r3,r4 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo1
				
				UDIV r8,r6,r3
				
				; setup a value for R0 to return
				MOV	  r0, r8
				
				; restore volatile registers
				LDMFD sp!,{r4-r8,r10-r11,pc}
				ENDFUNC
         	
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
				END