				
				AREA asm_functions, CODE, READONLY				
                EXPORT  analisi_accuratezza
analisi_accuratezza		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument OF THE FUNCTIon that doesn't fit in r0-r3
				; r0,r1,r2,r3
				

				; your code
			     MOV r4,#0 ;indice ciclo
				 MOV r8,0
cominciaCiclo1  
				LDRB r5,[r0],#1 ;in r5 ho VETT
				LDRB r6,[r1],#1 ;in r6 ho VETT2

				CMP r5,r6
				SUBCS r7,r5,r6
				SUBCC r7,r6,r5
				
				STRB r7,[r3],#1
				ADD r8,r8,r7

				;CODICE MIO 
				ADD r4,r4,#1
				CMP r2,r4 ;in r2 ho la dimensione del vettore
				BNE cominciaCiclo1


				; setup a value for R0 to return
				UDIV r8,r8,r2
				MOV	  r0, r8
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