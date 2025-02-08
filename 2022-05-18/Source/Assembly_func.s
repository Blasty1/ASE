				
				AREA asm_functions, CODE, READONLY				
                EXPORT  totale_pressioni_con_filtro
totale_pressioni_con_filtro		FUNCTION
	
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument OF THE FUNCTIon that doesn't fit in r0-r3
				;r0,r1,r2,r3
				
				MOV r4,#0 ;indice ciclo
				MOV r7,#0

cominciaCiclo1  
				MOV r6,#0
				LDRB r5,[r0],#1 ;in r0 ho l'indirizzo del vettore
				
				CMP r2,r5
				ADDCS r6,r6,#1
				
				CMP r3,r5
				ADDLS r6,r6,#1
				
				SUBS r6,r6,#2
				ADDEQ r7,r7,r5
				
				;CODICE MIO 
				ADD r4,r4,#1
				CMP r1,r4 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo1
				

				; your code
				
				; setup a value for R0 to return
				MOV	  r0, r7
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