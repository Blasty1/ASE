				
				AREA asm_functions, CODE, READONLY				
                EXPORT  check_fibonacci
check_fibonacci		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument OF THE FUNCTIon that doesn't fit in r0-r3
				LDR   r4, [r12]
				
				
				MOV r10,1
				; your code
				MOV r5,#0 ;indice ciclo
				LDR r9,=my_space_4_vector
				
				STR r5,[r4]
				
				ADD r5,r5,1
				STR r5,[r9,4]!
				
				;ADD r3,r3,1 ; r3 va a 1 ed è l'indice del ciclo
cominciaCiclo1  
				LDRD r7,r6,[r9,#-8] ;in r4 ho l'indirizzo del vettore
				
				ADD r8,r7,r6
				STR r8,[r9],#4
		
				;CODICE MIO 
				ADD r5,r5,#1
				CMP r2,r5 ;in r2 ho la dimensione del vettore
				BNE cominciaCiclo1
				
				MOV r5,0
				LDR r9,=my_space_4_vector
cominciaCiclo2
				LDRB r6,[r9],#4 ;in r0 ho l'indirizzo del vettore
				
				SUBS r7,r2,r6
				
				MOVEQ r10,0
				
				SUBS r7,r7,r4
				MOVCC r10,0
		
				;CODICE MIO 
				ADD r5,r5,#1
				CMP r1,r5 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo2
				
				
				; setup a value for R0 to return
				MOV	  r0, r10
				
				MOV r11,0
				CMP r10,r11
			
			
				
				; restore volatile registers
salta				LDMFD sp!,{r4-r8,r10-r11,pc}
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
my_space_4_vector	SPACE    14*4 ;length(11)*n_byte(22)
					
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
				END