.global _start
_start:
			@Create registers
	MOV R4, #6	@Den
	MOV R5, #55	@Num
	MOV R0, R5	@Result
	MOV R1, #0	@Mod
	MOV R2, #1	@Counter
	MOV R3, R4	@Copy

_dowhile_R0_GT_R3:
	CMP R0,R3		@compare both
	BLT _shiftback		@goto if R0<R3
	MOV R3, R3, LSL #1	@R3x2
	MOV R2, R2, LSL #1 	@R2x2
	CMP R0,R3		@Does R0 = R3
	BLT _shiftback		@Goto ShiftB if R0 < R3
	BAL _dowhile_R0_GT_R3	@go back to loop

_shiftback:
	MOV R3, R3, LSR #1	@Shift back to preious1
	MOV R2, R2, LSR #1	@Shift back

	BAL _divide		@Go to Divide

_divide:
	CMP R0,R3		@Comapre R0 & R3
	BLT _exit		@exit if R0 is smaller
	ADD R1, R1, R2		@R1 = R1+R2
	SUB R0, R0, R3		@R0 = R0-R3
	
	CMP R2, #1		@R2 = R1?
	BGT _R2_GT_1		@If R2>R1 goto _R2_GT_R1
	BAL _divide		@Go back to divide

_R2_GT_1:
	CMP R2, #1		@R2 = 1?
	BLT _divide		@If R2 < 1 goto Divide
	BGT _R3_GT_R0		@If R2>1 goto R3_GT_R0

_R3_GT_R0:
	CMP R3, R0		@R3 = R0?
	BLT _divide		@R3<R0 goto Divide
	MOV R2, R2, LSR #1	@R2 shift back 1
	MOV R3, R3, LSR #1	@R3 shift back 1
	BAL _R2_GT_1		@goto R2_GT_1

_exit:
	MOV R0, R1
	MOV R7, #1
	SWI 0
