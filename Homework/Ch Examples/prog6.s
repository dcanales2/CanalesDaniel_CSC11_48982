@ Preform R0 = R1+R2
	.global _start
_start:
	MOV R1, #50 @ Make register 1 value 50
	MOV R2, #60 @ Make R2 value 60
	ADDS R0, R1, R2 @ R1+R2 set value to R0

	MOV R7, #1 @exit through syscall
	SWI 0
