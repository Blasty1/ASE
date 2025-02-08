				
				AREA asm_functions, CODE, READONLY				
                EXPORT  sopra_la_media
sopra_la_media		FUNCTION
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
				; extract argument OF THE FUNCTIon that doesn't fit in r0-r3
				; usiamo R0,R1
				
				MOV r6,r0
				; your code
				MOV r2,#0 ;indice ciclo
				MOV r3,#0
cominciaCiclo1  
				LDRB r4,[r0],#1 ;in r0 ho l'indirizzo del vettore
				
				ADD r3,r3,r4
				
				;CODICE MIO 
				ADD r2,r2,#1
				CMP r1,r2 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo1
				
				UDIV r3,r3,r1 ;media
				
				MOV r0,r6
				; your code
				MOV r2,#0 ;indice ciclo
				MOV r5,0 ;conteggio
cominciaCiclo2  
				LDRB r4,[r0],#1 ;in r0 ho l'indirizzo del vettore
				
				CMP r4,r3
				ADDHI r5,r5,#1
				

				;CODICE MIO 
				ADD r2,r2,#1
				CMP r1,r2 ;in r1 ho la dimensione del vettore
				BNE cominciaCiclo2
				
				
				; setup a value for R0 to return
				MOV	  r0, r5
	
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