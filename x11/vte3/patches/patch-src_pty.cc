$NetBSD: patch-src_pty.cc,v 1.10 2023/05/30 23:04:53 gutteridge Exp $

Use correct includes on SunOS.
Functional fix of posix_openpt() on NetBSD.
https://gitlab.gnome.org/GNOME/vte/-/issues/2575

--- src/pty.cc.orig	2022-03-27 17:52:19.000000000 +0000
+++ src/pty.cc
@@ -62,9 +62,15 @@
 #ifdef HAVE_PTY_H
 #include <pty.h>
 #endif
-#if defined(__sun) && defined(HAVE_STROPTS_H)
+#if defined(__sun)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
 #include <stropts.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
 #include <glib.h>
 #include <gio/gio.h>
 #include "debug.h"
@@ -427,6 +433,27 @@ _vte_pty_open_posix(void)
 #ifndef __linux__
         /* Other kernels may not support CLOEXEC or NONBLOCK above, so try to fall back */
         bool need_cloexec = false, need_nonblocking = false;
+
+#ifdef __NetBSD__
+         // NetBSD is a special case: prior to 9.99.101, posix_openpt() will not return
+         // EINVAL for unknown/unsupported flags but instead silently ignore these flags
+         // and just return a valid PTY but without the NONBLOCK | CLOEXEC flags set.
+         // So we need to manually apply these flags there. See issue #2575.
+        int mib[2], osrev;
+        size_t len;
+
+        mib[0] = CTL_KERN;
+        mib[1] = KERN_OSREV;
+        len = sizeof(osrev);
+        sysctl(mib, 2, &osrev, &len, NULL, 0);
+        if (osrev < 999010100) {
+                need_cloexec = need_nonblocking = true;
+                _vte_debug_print(VTE_DEBUG_PTY,
+                                 "NetBSD < 9.99.101, forcing fallback "
+                                 "for NONBLOCK and CLOEXEC.\n");
+        }
+#else
+
         if (!fd && errno == EINVAL) {
                 /* Try without NONBLOCK and apply the flag afterward */
                 need_nonblocking = true;
@@ -437,6 +464,7 @@ _vte_pty_open_posix(void)
                         fd = posix_openpt(O_RDWR | O_NOCTTY);
                 }
         }
+#endif /* __NetBSD__ */
 #endif /* !linux */
 
         if (!fd) {
