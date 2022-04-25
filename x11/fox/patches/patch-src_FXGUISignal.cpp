$NetBSD: patch-src_FXGUISignal.cpp,v 1.1 2022/04/25 15:17:21 tnn Exp $

Include <sys/filio.h> for FIONREAD on SunOS.

--- src/FXGUISignal.cpp.orig	2018-04-04 03:42:42.000000000 +0000
+++ src/FXGUISignal.cpp
@@ -40,6 +40,9 @@
 #ifdef __CYGWIN__
 #include <asm/socket.h>         /* For FIONREAD */
 #endif
+#ifdef __sun
+#include <sys/filio.h>         /* For FIONREAD */
+#endif
 #else
 #include <process.h>
 #endif
