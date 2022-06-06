$NetBSD: patch-src_bltUnixPipe.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Silence gcc warning in the interests of being able to see the
real build problems.

--- src/bltUnixPipe.c~	2002-06-22 19:21:05.000000000 +0000
+++ src/bltUnixPipe.c
@@ -477,7 +477,7 @@ CreateProcess(interp, argc, argv, inputF
 	 * Reap the child process now if an error occurred during its
 	 * startup.
 	 */
-	Tcl_WaitPid((Tcl_Pid)pid, &status, WNOHANG);
+	Tcl_WaitPid((Tcl_Pid)(intptr_t)pid, &status, WNOHANG);
     }
     if (errPipeIn >= 0) {
 	CloseFile(errPipeIn);
