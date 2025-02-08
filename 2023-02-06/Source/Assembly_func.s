				
				AREA asm_functions, CODE, READONLY				
                EXPORT  calcola_somma_prodotto
calcola_somma_prodotto		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				;r0,r1,r2
				

				; your code
				
				MOV r3,#0 ;indice ciclo
				MOV r7,0
				MOV r8,1
cominciaCiclo1  
				LDRD r4,r5,[r0],#8 ;in r0 ho l'indirizzo del vettore
				
				MUL r6,r4,r5
				
				ADD r7,r7,r6
				
				
				;CODICE MIO 
				ADD r3,r3,#2
				CMP r1,r3 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo1
				
				MOV R10,255
				
				CMP r10,r7
				MOVCS r8,-1
				
				STRB r8,[r2]
				
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