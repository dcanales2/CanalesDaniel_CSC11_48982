	.global _start @ start file
	_start:		@ start key

		MOV R1, #108 @ load 108 into Register 1
		LDR R2, =0x155556	@ Load R2 with Hex value
		MUL R0, R2,R1	@ multiple R2xR1 and place into R0
		LSR R0, #24 @ LeftShift 24 times /2/2/2/2...../2
		MOV R7, #1 @ end the program
		SWI 0 		@ close the program
