$NetBSD: patch-src_pty.cc,v 1.6 2022/04/05 15:51:58 jperkin Exp $

Use correct includes on SunOS.

--- src/pty.cc.orig	2022-03-27 17:52:19.000000000 +0000
+++ src/pty.cc
@@ -62,7 +62,9 @@
 #ifdef HAVE_PTY_H
 #include <pty.h>
 #endif
-#if defined(__sun) && defined(HAVE_STROPTS_H)
+#if defined(__sun)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
 #include <stropts.h>
 #endif
 #include <glib.h>
