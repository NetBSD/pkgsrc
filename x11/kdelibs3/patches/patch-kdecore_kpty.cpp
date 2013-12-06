$NetBSD: patch-kdecore_kpty.cpp,v 1.1 2013/12/06 19:58:27 asau Exp $

No utmp.h on FreeBSD.

--- kdecore/kpty.cpp.orig	2008-08-19 18:18:18.000000000 +0000
+++ kdecore/kpty.cpp	2013-12-06 19:40:35.460506217 +0000
@@ -77,8 +77,12 @@
 #endif
 
 #ifdef USE_LOGIN
+#if defined(__FreeBSD__)
+# include <utmpx.h>
+#else
 # include <utmp.h>
 #endif
+#endif
 
 #ifdef HAVE_TERMIOS_H
 /* for HP-UX (some versions) the extern C is needed, and for other
