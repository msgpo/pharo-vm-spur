/* Automatically generated by
	SmartSyntaxPluginCodeGenerator * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 uuid: ffd1e591-7b0b-41f8-a01f-8ca90622208f
   from
	QuicktimePlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 uuid: ffd1e591-7b0b-41f8-a01f-8ca90622208f
 */
static char __buildInfo[] = "QuicktimePlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 uuid: ffd1e591-7b0b-41f8-a01f-8ca90622208f " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "QuicktimePlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveClearFrameCompletedSemaphore(void);
EXPORT(sqInt) primitiveDestroyHandle(void);
EXPORT(sqInt) primitiveDestroySurface(void);
EXPORT(sqInt) primitiveSetFrameCompletedSemaphore(void);
EXPORT(sqInt) primitiveSetGWorldPtrOntoExistingSurface(void);
EXPORT(sqInt) primitiveSetGWorldPtrOntoSurface(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static sqInt (*integerObjectOf)(sqInt value);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static usqInt (*positive32BitValueOf)(sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern sqInt integerObjectOf(sqInt value);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern usqInt positive32BitValueOf(sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"QuicktimePlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 (i)"
#else
	"QuicktimePlugin * VMMaker.oscog-EstebanLorenzano.781, VMMaker.oscog-eem.810 (e)"
#endif
;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	// InterpreterPlugin>>#getInterpreter
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	// InterpreterPlugin>>#getModuleName
	return moduleName;
}

static sqInt
halt(void)
{
	// InterpreterPlugin>>#halt
	;
	return 0;
}

EXPORT(sqInt)
initialiseModule(void)
{
	// QuicktimePlugin>>#initialiseModule
	return sqQuicktimeInitialize();
}


/*	The module with the given name was just unloaded. 
	Make sure we have no dangling references. */

EXPORT(sqInt)
moduleUnloaded(char *aModuleName)
{
	// QuicktimePlugin>>#moduleUnloaded:
	if ((strcmp(aModuleName, "QuicktimePlugin")) == 0) {
		sqQuicktimeShutdown();
	}
}

static sqInt
msg(char *s)
{
	// InterpreterPlugin>>#msg:
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}

EXPORT(sqInt)
primitiveClearFrameCompletedSemaphore(void)
{
	// QuicktimePlugin>>#primitiveClearFrameCompletedSemaphore
	sqInt data;

	data = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	stQuicktimeClearSemaphore(data);
	return null;
}

EXPORT(sqInt)
primitiveDestroyHandle(void)
{
	// QuicktimePlugin>>#primitiveDestroyHandle
	sqInt data;

	data = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	stQuicktimeDestroy(data);
	return null;
}

EXPORT(sqInt)
primitiveDestroySurface(void)
{
	// QuicktimePlugin>>#primitiveDestroySurface
	sqInt data;

	data = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	stQuicktimeDestroySurface(data);
	return null;
}

EXPORT(sqInt)
primitiveSetFrameCompletedSemaphore(void)
{
	// QuicktimePlugin>>#primitiveSetFrameCompletedSemaphore
	sqInt data;
	sqInt semaIndex;

	semaIndex = stackIntegerValue(1);
	data = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	stQuicktimeSetSemaphorefor(semaIndex, data);
	return null;
}

EXPORT(sqInt)
primitiveSetGWorldPtrOntoExistingSurface(void)
{
	// QuicktimePlugin>>#primitiveSetGWorldPtrOntoExistingSurface
	sqInt bitMapPtr;
	char * buffer;
	sqInt depth;
	sqInt height;
	long movie;
	sqInt moviePtr;
	sqInt rowBytes;
	sqInt surfaceID;
	sqInt width;

	surfaceID = stackIntegerValue(6);
	bitMapPtr = stackValue(5);
	width = stackIntegerValue(4);
	height = stackIntegerValue(3);
	rowBytes = stackIntegerValue(2);
	depth = stackIntegerValue(1);
	moviePtr = stackValue(0);
	if (failed()) {
		return null;
	}
	buffer = ((char *) (positive32BitValueOf(bitMapPtr)));
	movie = ((long) (positive32BitValueOf(moviePtr)));
	stQuicktimeSetToExistingSurfacegworldwidthheightrowBytesdepthmovie(surfaceID, buffer, width, height, rowBytes, depth, movie);
	if (failed()) {
		return null;
	}
	pop(7);
	return null;
}

EXPORT(sqInt)
primitiveSetGWorldPtrOntoSurface(void)
{
	// QuicktimePlugin>>#primitiveSetGWorldPtrOntoSurface
	sqInt bitMapPtr;
	char * buffer;
	sqInt depth;
	sqInt height;
	long movie;
	sqInt moviePtr;
	sqInt results;
	sqInt rowBytes;
	sqInt width;
	sqInt _return_value;

	bitMapPtr = stackValue(5);
	width = stackIntegerValue(4);
	height = stackIntegerValue(3);
	rowBytes = stackIntegerValue(2);
	depth = stackIntegerValue(1);
	moviePtr = stackValue(0);
	if (failed()) {
		return null;
	}
	buffer = ((char *) (positive32BitValueOf(bitMapPtr)));
	movie = ((long) (positive32BitValueOf(moviePtr)));
	results = stQuicktimeSetSurfacewidthheightrowBytesdepthmovie(buffer, width, height, rowBytes, depth, movie);
	_return_value = integerObjectOf(results);
	if (failed()) {
		return null;
	}
	popthenPush(7, _return_value);
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	// InterpreterPlugin>>#setInterpreter:
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {

#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
		integerObjectOf = interpreterProxy->integerObjectOf;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		positive32BitValueOf = interpreterProxy->positive32BitValueOf;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

static sqInt
sqAssert(sqInt aBool)
{
	// SmartSyntaxInterpreterPlugin>>#sqAssert:
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* QuicktimePlugin_exports[][3] = {
	{"QuicktimePlugin", "getModuleName", (void*)getModuleName},
	{"QuicktimePlugin", "initialiseModule", (void*)initialiseModule},
	{"QuicktimePlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"QuicktimePlugin", "primitiveClearFrameCompletedSemaphore\000\000", (void*)primitiveClearFrameCompletedSemaphore},
	{"QuicktimePlugin", "primitiveDestroyHandle\000\000", (void*)primitiveDestroyHandle},
	{"QuicktimePlugin", "primitiveDestroySurface\000\000", (void*)primitiveDestroySurface},
	{"QuicktimePlugin", "primitiveSetFrameCompletedSemaphore\000\000", (void*)primitiveSetFrameCompletedSemaphore},
	{"QuicktimePlugin", "primitiveSetGWorldPtrOntoExistingSurface\000\000", (void*)primitiveSetGWorldPtrOntoExistingSurface},
	{"QuicktimePlugin", "primitiveSetGWorldPtrOntoSurface\000\000", (void*)primitiveSetGWorldPtrOntoSurface},
	{"QuicktimePlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveClearFrameCompletedSemaphoreAccessorDepth = 0;
signed char primitiveDestroyHandleAccessorDepth = 0;
signed char primitiveDestroySurfaceAccessorDepth = 0;
signed char primitiveSetFrameCompletedSemaphoreAccessorDepth = 0;
signed char primitiveSetGWorldPtrOntoExistingSurfaceAccessorDepth = 0;
signed char primitiveSetGWorldPtrOntoSurfaceAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */