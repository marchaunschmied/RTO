
	PRESERVE8
    THUMB
        
    AREA MyAPOS, CODE, READONLY
		
	EXPORT OSStart
	EXPORT FillTaskA
	EXPORT FillTaskB
	EXPORT FillTaskC
	
  
  
OSStart
    MOVS    R0,#0                                              ; Set the PSP to 0 for initial context switch call
    MSR     PSP,R0



FillTaskA
    MOVS R0,#0xA8
	MOV R8,R0
	MOVS R0,#0xA9
	MOV R9,R0
	MOVS R0,#0xAA
	MOV R10,R0	
	MOVS R0,#0xAB
	MOV R11,R0	
	MOVS R0,#0xAC
	MOV R12,R0
	MOVS R0,#0xA0
	MOVS R1,#0xA1
	MOVS R2,#0xA2
	MOVS R3,#0xA3
	MOVS R4,#0xA4
	MOVS R5,#0xA5
	MOVS R6,#0xA6
	MOVS R7,#0xA7

	
FillTaskB
	MOVS R0,#0xB8
	MOV R8,R0
	MOVS R0,#0xB9
	MOV R9,R0	
	MOVS R0,#0xBA
	MOV R10,R0	
	MOVS R0,#0xBB
	MOV R11,R0	
	MOVS R0,#0xBC
	MOV R12,R0
	MOVS R0, #0xB0
	MOVS R1, #0xB1
	MOVS R2, #0xB2
	MOVS R3, #0xB3
	MOVS R4, #0xB4
	MOVS R5, #0xB5
	MOVS R6, #0xB6
	MOVS R7, #0xB7


FillTaskC
	MOVS R0,#0xC8
	MOV R8,R0
	MOVS R0,#0xC9
	MOV R9,R0
	MOVS R0,#0xCA
	MOV R10,R0
	MOVS R0,#0xCB
	MOV R11,R0
	MOVS R0,#0xCC
	MOV R12,R0
	MOVS R0, #0xC0
	MOVS R1, #0xC1
	MOVS R2, #0xC2
	MOVS R3, #0xC3
	MOVS R4, #0xC4
	MOVS R5, #0xC5
	MOVS R6, #0xC6
	MOVS R7, #0xC7
