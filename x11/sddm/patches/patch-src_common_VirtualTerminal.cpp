$NetBSD: patch-src_common_VirtualTerminal.cpp,v 1.1 2025/12/30 04:00:09 gutteridge Exp $

Fix tty device for NetBSD.

--- src/common/VirtualTerminal.cpp.orig	2024-02-26 10:23:03.000000000 +0000
+++ src/common/VirtualTerminal.cpp
@@ -29,6 +29,8 @@
 #include <signal.h>
 #ifdef __FreeBSD__
 #include <sys/consio.h>
+#elif __NetBSD__
+#include <dev/wscons/wsdisplay_usl_io.h>
 #else
 #include <linux/vt.h>
 #include <linux/kd.h>
@@ -58,6 +60,22 @@ namespace SDDM {
             }
             return vtActive;
         }
+#elif defined(__NetBSD__)
+        static const char *defaultVtPath = "/dev/ttyE0";        
+
+        QString path(int vt) {
+            char c = (vt <= 10 ? '0' : 'a') + (vt - 1);
+            return QStringLiteral("/dev/ttyE%1").arg(c);
+        }
+
+        int getVtActive(int fd) {
+            int vtActive = 0;
+            if (ioctl(fd, VT_GETACTIVE, &vtActive) < 0) {
+                qCritical() << "Failed to get current VT:" << strerror(errno);
+                return -1;
+            }
+            return vtActive;
+        }
 #else
         static const char *defaultVtPath = "/dev/tty0";
 
@@ -119,12 +137,12 @@ namespace SDDM {
 
             if (getmodeReply.mode != VT_AUTO)
                 goto out;
-
+#ifdef KDGETMODE
             if (ioctl(fd, KDGETMODE, &kernelDisplayMode) < 0) {
                 qWarning() << "Failed to query kernel display mode:" << strerror(errno);
                 ok = false;
             }
-
+#endif
             if (kernelDisplayMode == KD_TEXT)
                 goto out;
 
