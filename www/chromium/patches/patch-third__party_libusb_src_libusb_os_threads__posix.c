$NetBSD: patch-third__party_libusb_src_libusb_os_threads__posix.c,v 1.1 2025/02/06 09:58:26 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libusb/src/libusb/os/threads_posix.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/libusb/src/libusb/os/threads_posix.c
@@ -19,9 +19,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__)
 # include <unistd.h>
 # include <sys/syscall.h>
+#elif defined(__OpenBSD__)
+# include <unistd.h>
 #elif defined(__APPLE__)
 # include <mach/mach.h>
 #elif defined(__CYGWIN__)
@@ -65,7 +67,7 @@ int usbi_get_tid(void)
 #elif defined(__OpenBSD__)
 	/* The following only works with OpenBSD > 5.1 as it requires
 	   real thread support. For 5.1 and earlier, -1 is returned. */
-	ret = syscall(SYS_getthrid);
+	ret = getthrid();
 #elif defined(__APPLE__)
 	ret = mach_thread_self();
 	mach_port_deallocate(mach_task_self(), ret);
