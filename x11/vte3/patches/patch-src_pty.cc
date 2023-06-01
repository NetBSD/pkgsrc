$NetBSD: patch-src_pty.cc,v 1.11 2023/06/01 21:51:27 gutteridge Exp $

Use correct includes on SunOS.
Functional fix of posix_openpt() on NetBSD.
https://gitlab.gnome.org/GNOME/vte/-/issues/2575

--- src/pty.cc.orig	2023-04-13 09:57:27.000000000 +0000
+++ src/pty.cc
@@ -57,9 +57,15 @@
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
@@ -415,11 +421,23 @@ _vte_pty_open_posix(void)
         bool need_cloexec = false, need_nonblocking = false;
 
 #ifdef __NetBSD__
-        // NetBSD is a special case: posix_openpt() will not return EINVAL
-        // for unknown/unsupported flags but instead silently ignore these flags
+        // NetBSD is a special case: prior to 9.99.101, posix_openpt() will not return
+        // EINVAL for unknown/unsupported flags but instead silently ignore these flags
         // and just return a valid PTY but without the NONBLOCK | CLOEXEC flags set.
-        // So we always need to manually apply these flags there. See issue #2575.
-        need_cloexec = need_nonblocking = true;
+        // So we need to manually apply these flags there. See issue #2575.
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
 #else
 
         if (!fd && errno == EINVAL) {
