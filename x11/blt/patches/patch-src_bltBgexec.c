$NetBSD: patch-src_bltBgexec.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

- For Tcl_File, which is unused in tcl 8.x, use a dummy type that
doesn't cause warnings.

- For Process on non-Windows, use the type that tcl itself expects,
which is a pointer to an incomplete type. It is actually an int value
in that pointer inside tcl, not a pointer, and casting pointers to int
to pointers to pointers causes real problems on LP64 targets.

- Relatedly, when calling Tcl_DetachPids, pass the right thing (a
pointer to the Tcl_Pid) and not the Tcl_Pid's value itself.

- Fix a null dereference calling NotifyOnUpdate, found by gcc10
-Wuninitialized.

- Don't use sprintf.

--- src/bltBgexec.c.orig	2002-09-18 22:30:50.000000000 +0000
+++ src/bltBgexec.c
@@ -44,7 +44,7 @@
 #if (TCL_MAJOR_VERSION == 7)
 #define FILEHANDLER_USES_TCLFILES 1
 #else
-typedef int Tcl_File;
+typedef void *Tcl_File;
 #endif
 
 static Tcl_CmdProc BgexecCmd;
@@ -55,7 +55,7 @@ typedef struct {
     HANDLE hProcess;
 } Process;
 #else
-typedef int Process;
+typedef Tcl_Pid Process;
 #endif
 
 #if (TCL_VERSION_NUMBER <  _VERSION(8,1,0)) 
@@ -1319,7 +1319,9 @@ CollectData(bgPtr, sinkPtr)
  	    }
 	} else {
 	    data = NextBlock(sinkPtr, &length);
-	    NotifyOnUpdate(bgPtr->interp, sinkPtr, data, length);
+	    if (data != NULL) {
+	        NotifyOnUpdate(bgPtr->interp, sinkPtr, data, length);
+	    }
 	}
     }
     if (sinkPtr->status >= 0) {
@@ -1463,7 +1465,7 @@ DestroyBackgroundInfo(bgPtr)
 
 	for (i = 0; i < bgPtr->nProcs; i++) {
 	    if (bgPtr->signalNum > 0) {
-		kill(bgPtr->procArr[i], bgPtr->signalNum);
+		kill((pid_t)(intptr_t)bgPtr->procArr[i], bgPtr->signalNum);
 	    }
 #ifdef WIN32
 	    Tcl_DetachPids(1, (Tcl_Pid *)&bgPtr->procArr[i].pid);
@@ -1471,7 +1473,7 @@ DestroyBackgroundInfo(bgPtr)
 #if (TCL_MAJOR_VERSION == 7)
 	    Tcl_DetachPids(1, &bgPtr->procArr[i]);
 #else
-	    Tcl_DetachPids(1, (Tcl_Pid *)bgPtr->procArr[i]);
+	    Tcl_DetachPids(1, &bgPtr->procArr[i]);
 #endif /* TCL_MAJOR_VERSION == 7 */
 #endif /* WIN32 */
 	}
@@ -1516,7 +1518,7 @@ VariableProc(
 	    register int i;
 
 	    for (i = 0; i < bgPtr->nProcs; i++) {
-		kill(bgPtr->procArr[i], bgPtr->signalNum);
+		kill((pid_t)(intptr_t)bgPtr->procArr[i], bgPtr->signalNum);
 	    }
 	}
     }
@@ -1577,7 +1579,7 @@ TimerProc(clientData)
 #ifdef WIN32
 	pid = WaitProcess(bgPtr->procArr[i], (int *)&waitStatus, WNOHANG);
 #else
-	pid = waitpid(bgPtr->procArr[i], (int *)&waitStatus, WNOHANG);
+	pid = waitpid((pid_t)(intptr_t)bgPtr->procArr[i], (int *)&waitStatus, WNOHANG);
 #endif
 	if (pid == 0) {		/*  Process has not terminated yet */
 	    if (nLeft < i) {
@@ -1928,7 +1930,7 @@ BgexecCmd(clientData, interp, argc, argv
 #ifdef WIN32
 	    sprintf(string, "%u", (unsigned int)bgPtr->procArr[i].pid);
 #else 
-	    sprintf(string, "%d", bgPtr->procArr[i]);
+	    snprintf(string, sizeof(string), "%d", (int)(intptr_t)bgPtr->procArr[i]);
 #endif
 	    Tcl_AppendElement(interp, string);
 	}
