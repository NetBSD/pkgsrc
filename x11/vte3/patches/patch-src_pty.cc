$NetBSD: patch-src_pty.cc,v 1.2 2018/05/15 09:50:49 jperkin Exp $

NetBSD fix
Use correct includes on SunOS.

--- src/pty.cc.orig	2018-04-09 21:43:51.000000000 +0000
+++ src/pty.cc
@@ -60,7 +60,9 @@
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
@@ -624,7 +626,12 @@ _vte_pty_open_posix(void)
         fd = posix_openpt(O_RDWR | O_NOCTTY | O_NONBLOCK | O_CLOEXEC);
 #ifndef __linux__
         /* Other kernels may not support CLOEXEC or NONBLOCK above, so try to fall back */
-        bool need_cloexec = false, need_nonblocking = false;
+        bool need_cloexec = false;
+#ifdef __NetBSD__
+	bool need_nonblocking = true;
+#else
+	bool need_nonblocking = false;
+#endif
         if (fd == -1 && errno == EINVAL) {
                 /* Try without NONBLOCK and apply the flag afterward */
                 need_nonblocking = true;
