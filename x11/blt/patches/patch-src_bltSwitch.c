$NetBSD: patch-src_bltSwitch.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Fix bug spotted by gcc10.

--- src/bltSwitch.c~	2002-06-22 19:21:05.000000000 +0000
+++ src/bltSwitch.c
@@ -285,7 +285,7 @@ Blt_ProcessSwitches(interp, specs, argc,
     for (count = 0; count < argc; count++) {
 	arg = argv[count];
 	if (flags & BLT_SWITCH_OBJV_PARTIAL) {
-	    if ((arg[0] != '-') || ((arg[1] == '-') && (argv[2] == '\0'))) {
+	    if ((arg[0] != '-') || ((arg[1] == '-') && (arg[2] == '\0'))) {
 		/* 
 		 * If the argument doesn't start with a '-' (not a switch)
 		 * or is '--', stop processing and return the number of
