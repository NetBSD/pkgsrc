$NetBSD: patch-src_pty.cc,v 1.1 2018/05/14 13:55:23 youri Exp $

NetBSD fix

--- src/pty.cc.orig	2018-04-09 21:43:51.000000000 +0000
+++ src/pty.cc
@@ -624,7 +624,12 @@ _vte_pty_open_posix(void)
         fd = posix_openpt(O_RDWR | O_NOCTTY | O_NONBLOCK | O_CLOEXEC);
 #ifndef __linux__
         /* Other kernels may not support CLOEXEC or NONBLOCK above, so try to fall back */
-        bool need_cloexec = false, need_nonblocking = false;
+        bool need_cloexec = false;
+#if __NetBSD__
+	bool need_nonblocking = true;
+#else
+	bool need_nonblocking = false;
+#endif
         if (fd == -1 && errno == EINVAL) {
                 /* Try without NONBLOCK and apply the flag afterward */
                 need_nonblocking = true;
