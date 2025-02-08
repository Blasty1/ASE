				
				AREA asm_functions, CODE, READONLY				
                EXPORT  count_negative_and_odd
count_negative_and_odd		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				
				MOV r3,#0 ;indice ciclo
				MOV r6,0
				MOV r8,2
cominciaCiclo  
				MOV r7,0
 				LDR r4,[r0],#4 ;in r0 ho l'indirizzo del vettore
				
				LSRS r5,r4,#1
				
				ADDCS r7,r7,1
				
				SUBS r4,r4,#0
				
				ADDMI r7,r7,1
				
				CMP r7,r8
				ADDEQ r6,r6,#1
				
				
				;CODICE MIO 
				ADD r3,r3,#1
				CMP r1,r3 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo
				
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
cominciaCiclo1  
				LDRB r4,[r0],#1 ;in r0 ho l'indirizzo del vettore
				
				;CODICE MIO 
				ADD r3,r3,#1
				CMP r1,r3 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo1
				
				LDMFD sp!,{r4-r8,r10-r11,pc}
				ENDFUNC
				END