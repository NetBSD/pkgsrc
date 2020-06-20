$NetBSD: patch-src_pty.cc,v 1.5 2020/06/20 16:00:07 nia Exp $

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
@@ -111,7 +113,7 @@ Pty::child_setup() const noexcept
         sigset_t set;
         sigemptyset(&set);
         if (pthread_sigmask(SIG_SETMASK, &set, nullptr) == -1) {
-                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "pthread_sigmask");
+                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "pthread_sigmask", strerror(errno));
                 _exit(127);
         }
 
@@ -134,7 +136,7 @@ Pty::child_setup() const noexcept
                  */
                 _vte_debug_print (VTE_DEBUG_PTY, "Starting new session\n");
                 if (setsid() == -1) {
-                        _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "setsid");
+                        _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "setsid", strerror(errno));
                         _exit(127);
                 }
         }
@@ -158,7 +160,7 @@ Pty::child_setup() const noexcept
         if (fd == -1 &&
             errno != EINVAL &&
             errno != ENOTTY) {
-		_vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "ioctl(TIOCGPTPEER)");
+		_vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "ioctl(TIOCGPTPEER)", strerror(errno));
 		_exit(127);
         }
 
@@ -168,7 +170,7 @@ Pty::child_setup() const noexcept
         if (fd == -1) {
                 auto const name = ptsname(masterfd);
                 if (name == nullptr) {
-                        _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "ptsname");
+                        _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "ptsname", strerror(errno));
                         _exit(127);
                 }
 
@@ -178,7 +180,7 @@ Pty::child_setup() const noexcept
 
                 fd = ::open(name, fd_flags);
                 if (fd == -1) {
-                        _vte_debug_print (VTE_DEBUG_PTY, "Failed to open PTY: %m\n");
+                        _vte_debug_print (VTE_DEBUG_PTY, "Failed to open PTY: %s\n", strerror(errno));
                         _exit(127);
                 }
         }
@@ -192,7 +194,7 @@ Pty::child_setup() const noexcept
          */
         if (!(m_flags & VTE_PTY_NO_CTTY)) {
                 if (ioctl(fd, TIOCSCTTY, fd) != 0) {
-                        _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "ioctl(TIOCSCTTY)");
+                        _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "ioctl(TIOCSCTTY)", strerror(errno));
                         _exit(127);
                 }
         }
@@ -533,7 +535,7 @@ Pty::set_size(int rows,
         if (ret != 0) {
                 vte::util::restore_errno errsv;
                 _vte_debug_print(VTE_DEBUG_PTY,
-                                 "Failed to set size on %d: %m\n", master);
+                                 "Failed to set size on %d: %s\n", master, strerror(errno));
         }
 
         return ret == 0;
@@ -574,7 +576,7 @@ Pty::get_size(int* rows,
 
         vte::util::restore_errno errsv;
         _vte_debug_print(VTE_DEBUG_PTY,
-                         "Failed to read size from fd %d: %m\n", master);
+                         "Failed to read size from fd %d: %s\n", master, strerror(errno));
 
         return false;
 }
@@ -614,13 +616,13 @@ fd_setup(int fd)
 {
         if (grantpt(fd) != 0) {
                 vte::util::restore_errno errsv;
-                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "grantpt");
+                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "grantpt", strerror(errno));
                 return -1;
         }
 
         if (unlockpt(fd) != 0) {
                 vte::util::restore_errno errsv;
-                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "unlockpt");
+                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "unlockpt", strerror(errno));
                 return -1;
         }
 
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
@@ -701,22 +710,24 @@ _vte_pty_open_posix(void)
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
-                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "grantpt");
+                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "grantpt", strerror(errno));
                 return {};
         }
 
         if (unlockpt(fd) != 0) {
                 vte::util::restore_errno errsv;
-                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "unlockpt");
+                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s\n", "unlockpt", strerror(errno));
                 return {};
         }
 
@@ -757,7 +768,7 @@ Pty::set_utf8(bool utf8) const noexcept
 	struct termios tio;
         if (tcgetattr(fd(), &tio) == -1) {
                 vte::util::restore_errno errsv;
-                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m", "tcgetattr");
+                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s", "tcgetattr", strerror(errno));
                 return false;
         }
 
@@ -772,7 +783,7 @@ Pty::set_utf8(bool utf8) const noexcept
         if (saved_cflag != tio.c_iflag &&
             tcsetattr(fd(), TCSANOW, &tio) == -1) {
                 vte::util::restore_errno errsv;
-                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m", "tcsetattr");
+                _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %s", "tcsetattr", strerror(errno));
                 return false;
 	}
 #endif
