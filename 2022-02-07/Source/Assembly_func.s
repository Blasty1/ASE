				
				AREA asm_functions, CODE, READONLY				
                EXPORT  stat_satisfaction
stat_satisfaction		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument OF THE FUNCTIon that doesn't fit in r0-r3
				LDR   r4, [r12]
				LDR   r5, [r12,#4]
				
				

				; your code
				MOV r10,100
				ADD r6,r0,r1
				ADD r6,r6,r2 ;in r6 ci sono il numero totale di persone
				
				MUL r0,r0,r10
				UDIV r7,r0,r6 
				
				MUL r1,r1,r10
				UDIV r8,r1,r6
				
				MUL r2,r2,r10
				UDIV r9,r2,r6
				
				STRB r7,[r3]
				STRB r8,[r4]
				STRB r9,[r5]

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
				END