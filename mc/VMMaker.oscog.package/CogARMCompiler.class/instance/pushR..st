ARM convenience instructions
pushR: srcReg
"	push word to TOS 
	STR srcReg, [sp, #-4]!"
	^self memMxr: AL reg: srcReg base: SP p: 1 u: 0 b: 0 w: 1l: 0 imm: 4