$NetBSD: patch-src_pty.cc,v 1.4 2020/06/20 00:10:24 ryoon Exp $

NetBSD fix
Use correct includes on SunOS.
Don't use packet mode on SunOS.

--- src/pty.cc.orig	2020-05-13 09:51:07.000000000 +0000
+++ src/pty.cc
@@ -64,7 +64,9 @@
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
@@ -638,12 +640,14 @@ fd_setup(int fd)
                 return -1;
         }
 
+#ifndef __sun
         if (fd_set_cpkt(fd) < 0) {
                 vte::util::restore_errno errsv;
                 _vte_debug_print(VTE_DEBUG_PTY,
                                  "%s failed: %s", "ioctl(TIOCPKT)", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -665,7 +669,12 @@ _vte_pty_open_posix(void)
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
@@ -701,12 +710,14 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun
         if (fd_set_cpkt(fd) < 0) {
                 vte::util::restore_errno errsv;
                 _vte_debug_print(VTE_DEBUG_PTY,
                                  "%s failed: %s", "ioctl(TIOCPKT)", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         if (grantpt(fd) != 0) {
                 vte::util::restore_errno errsv;
