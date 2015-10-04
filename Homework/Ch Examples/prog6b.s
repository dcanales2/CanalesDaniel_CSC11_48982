@ Add 2 64-bit numbers
	.global _start
_start:
	MOV R2, #0xFFFFFFFF @ low half num1
	MOV R3, #0x1	    @ hi half num1
	MOV R4, #0xFFFFFFFF @ low half num2
	MOV R5, #0xFF 	    @ hi half num2
	ADDS R0, R2, R4	    @ add low and set flags (s)
	ADCS R1, R3, R5	    @ Add hi with carry

	MOV R7, #1 	    @ exit through syscall
	SWI 0
