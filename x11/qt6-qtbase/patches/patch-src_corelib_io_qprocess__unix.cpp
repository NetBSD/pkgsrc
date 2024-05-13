$NetBSD: patch-src_corelib_io_qprocess__unix.cpp,v 1.1 2024/05/13 10:59:53 jperkin Exp $

SunOS needs sys/termios.h for TIOCNOTTY.

--- src/corelib/io/qprocess_unix.cpp.orig	2024-05-13 09:54:08.532095783 +0000
+++ src/corelib/io/qprocess_unix.cpp
@@ -32,6 +32,10 @@
 #  include <sys/neutrino.h>
 #endif
 
+#ifdef Q_OS_SOLARIS
+#  include <sys/termios.h>
+#endif
+
 #include <errno.h>
 #include <limits.h>
 #include <stdlib.h>
