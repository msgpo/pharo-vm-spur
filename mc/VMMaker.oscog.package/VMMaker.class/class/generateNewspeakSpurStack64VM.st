configurations
generateNewspeakSpurStack64VM
	"No primitives since we can use those from the Cog VM"
	^VMMaker
		generate: StackInterpreter
		with: #( ObjectMemory Spur64BitMemoryManager
				MULTIPLEBYTECODESETS true
				NewspeakVM true
				FailImbalancedPrimitives false
				EnforceAccessControl true)
		to: (FileDirectory default directoryNamed: self sourceTree, '/nsspurstack64src') fullName
		platformDir: (FileDirectory default directoryNamed: self sourceTree, '/platforms') fullName
		including: #()