$NetBSD: patch-src_pty.cc,v 1.8 2022/09/01 01:17:27 gutteridge Exp $

Use correct includes on SunOS.
Functional fix of posix_openpt() on NetBSD.

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
@@ -426,7 +428,19 @@ _vte_pty_open_posix(void)
         auto fd = vte::libc::FD{posix_openpt(O_RDWR | O_NOCTTY | O_NONBLOCK | O_CLOEXEC)};
 #ifndef __linux__
         /* Other kernels may not support CLOEXEC or NONBLOCK above, so try to fall back */
-        bool need_cloexec = false, need_nonblocking = false;
+#ifdef __NetBSD__
+        /*
+         * NetBSD's posix_openpt() will pass along flags that don't actually get applied,
+         * so it will return an FD with only O_RDWR actually set, and we need to force the
+         * fallbacks below.
+         */
+        bool need_cloexec = true;
+        bool need_nonblocking = true;
+#else
+        bool need_cloexec = false;
+        bool need_nonblocking = false;
+#endif /* __NetBSD__ */
+
         if (!fd && errno == EINVAL) {
                 /* Try without NONBLOCK and apply the flag afterward */
                 need_nonblocking = true;
