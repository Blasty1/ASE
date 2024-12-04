				AREA funcs, CODE, READONLY				
				EXPORT next_state

next_state		FUNCTION
				PUSH {r4-r8,r10-r11,lr}
				; r0 -> CURREN_STATE
				; r1 -> TAPS
				; r2 -> INDIRIZZO OUTPUT BIT
				
				MOV R4,0
				MOV R10,8
				MOV R5,R1 ; in R5 abbiamo il TAPS
				MOV R6,R0 ; in R6 abbiamo Current_state
				MOV R7,-1 ; in R7 abbiamo il valore dell'ultimo XOR
				
calculateValue
				AND R8,R6,0x1
				LSRS R6,R6,1
				
				LSRS R5,R5,1
				
				; se C=1 allora vuoldire che è un TAP altrimenti non mi interessa
				BCC notATap
				
				
				CMP R7,-1
				EORNE R7,R8,R7
				
				MOVEQ R7,R8
				
				
notATap				
				ADD R4,R4,1
				CMP R4,8
				BNE calculateValue


				AND R10,R0,0x1 
				LSRS R0,R0,1
				STR R10,[R2]
				
				LSL R7,R7,7
				
				ORR R0,R0,R7
				
				POP {r4-r8,r10-r11,pc}
				ENDFUNC
				
				END