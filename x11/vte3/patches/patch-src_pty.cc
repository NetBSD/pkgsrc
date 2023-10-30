$NetBSD: patch-src_pty.cc,v 1.12 2023/10/30 23:02:02 gutteridge Exp $

Use correct includes on SunOS.

--- src/pty.cc.orig	2023-04-13 09:57:27.000000000 +0000
+++ src/pty.cc
@@ -57,7 +57,9 @@
 #ifdef HAVE_PTY_H
 #include <pty.h>
 #endif
-#if defined(__sun) && defined(HAVE_STROPTS_H)
+#if defined(__sun)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
 #include <stropts.h>
 #endif
 #ifdef __NetBSD__
