$NetBSD: patch-src_terminal.c,v 1.1 2022/05/09 12:26:42 jperkin Exp $

Provide W_EXITCODE compat.

--- src/terminal.c.orig	2020-03-05 21:43:41.000000000 +0000
+++ src/terminal.c
@@ -44,6 +44,10 @@
 #include "terminal-client-utils.h"
 #include "terminal-libgsystem.h"
 
+#ifndef W_EXITCODE
+#define W_EXITCODE(ret, sig) ((ret) << 8 | (sig))
+#endif
+
 GS_DEFINE_CLEANUP_FUNCTION0(TerminalOptions*, gs_local_options_free, terminal_options_free)
 #define gs_free_options __attribute__ ((cleanup(gs_local_options_free)))
 
