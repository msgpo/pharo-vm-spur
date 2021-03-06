debugging traps
instVar: offset ofContext: aContext

	"offset = InstructionPointerIndex ifTrue:
		[Transcript nextPutAll: '==================='; cr.
		  self printContext: 16r1715630.
		 self printCallStackOf: aContext currentFP: framePointer.
		 Transcript nextPutAll: '==================='; cr.
		 self halt]."

	| result |
	"self shortPrintFrameAndCallers: localFP.
	Transcript print: byteCount; tab; print: thisContext; cr.
	self print: offset; cr.
	self printContext: aContext.
	(self confirm: 'continue?') ifFalse: [self halt]."
	result := super instVar: offset ofContext: aContext.
	"(offset = InstructionPointerIndex
	and: [(self stringOf: (self penultimateLiteralOf: (self fetchPointer: MethodIndex ofObject: aContext))) = #indexOf:startingAt:ifAbsent:]) ifTrue:
		[transcript space; nextPutAll: '^pc '; nextPutAll: result hex.
		 (objectMemory isIntegerObject: result) ifTrue:
			[transcript space; print: (objectMemory integerValueOf: result)].
		 transcript tab.
		 self shortPrintContext: aContext]."
	"offset = StackPointerIndex ifTrue:
		[Transcript nextPutAll: '^stackp ', (self integerValueOf: result) printString; tab.
		 self shortPrintContext: aContext.
		 (#(24205456 24205732) includes: aContext) ifTrue:
		 	[(self checkIsStillMarriedContext: aContext currentFP: localFP)
				ifTrue: [self printFrame: (self frameOfMarriedContext: aContext) WithSP: (self frameOfMarriedContext: aContext) - 48]
				ifFalse: [self printContext: aContext]]]."
	^result