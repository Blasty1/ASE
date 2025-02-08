				
				AREA asm_functions, CODE, READONLY				
                EXPORT  traduzione_morse
traduzione_morse		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument OF THE FUNCTIon that doesn't fit in r0-r3
				;r0 e r1
				

				; your code
				MOV r2,#0 ;indice ciclo
				MOV r4,=my_space_4_vector
				MOV r5,0
cominciaCiclo1  
				LDRB r3,[r0],#1 ;in r0 ho l'indirizzo del vettore
				
				MOV r5,0
				CMP r3,r5
				STREQ r3,[r4],1
				
				MOV r6,1
				CMP r4,r6
				STREQ r3,[r4],1
				
				MOV r6,2
				CMP r4,r6
				BNE j
			
				
				
j				
				
				
				;CODICE MIO 
				ADD r2,r2,#1
				
				BNE cominciaCiclo1
				
END				
				; setup a value for R0 to return
				MOV	  r0, r7

				; restore volatile registers
				LDMFD sp!,{r4-r8,r10-r11,pc}
				ENDFUNC

LTORG	
					
				;definizione area dati readONLY
				AREA _data, DATA, READONLY, align=3
					EXPORT my_vector [DATA]
my_vector			DCB "A", "11111"

				;definizione area dati readWRITE
				AREA _data2, DATA, READWRITE, align=3
					EXPORT my_space_4_vector
my_space_4_vector	SPACE    5*1 ;length(11)*n_byte(22)
					
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