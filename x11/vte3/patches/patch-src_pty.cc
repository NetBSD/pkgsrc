$NetBSD: patch-src_pty.cc,v 1.13 2024/01/07 02:14:16 gutteridge Exp $

Use correct includes on SunOS.

--- src/pty.cc.orig	2024-01-06 16:00:59.800608016 +0000
+++ src/pty.cc
@@ -57,7 +57,9 @@
 #if __has_include(<pty.h>)
 #include <pty.h>
 #endif
-#if defined(__sun) && __has_include(<stropts.h>)
+#if defined(__sun)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
 #include <stropts.h>
 #define HAVE_STROPTS_H
 #endif
