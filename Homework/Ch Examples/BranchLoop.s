.global _start
op
_start:

	MOV R0, #50 @ Make R0=50

loop:
	SUBS R0, R0, #1 @ R0 = R0-1 and set flag
	BNE loop	@ branch if not equal to 0

_exit:
	MOV R7, #1
	SWI 0

