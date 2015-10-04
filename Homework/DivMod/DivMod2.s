.global _start
_start:

	@ Mod number and output remainder
	MOV R1, #60 @ R0 = 60
	MOV R2, #6  @ R0 = 6

_MOD:
	SUB R1, R1, R2 @ R1 = R1-R2
	CMP R1,R2 @ IS  R1 = R2 ?
	BGE  _MOD

_exit:
	MOV R7, #1
	SWI 0

