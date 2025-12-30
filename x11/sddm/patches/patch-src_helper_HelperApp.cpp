$NetBSD: patch-src_helper_HelperApp.cpp,v 1.1 2025/12/30 04:00:09 gutteridge Exp $

Fix adding entry line to the accounting database

--- src/helper/HelperApp.cpp.orig	2024-02-26 10:23:03.000000000 +0000
+++ src/helper/HelperApp.cpp
@@ -375,7 +375,7 @@ namespace SDDM {
 #if defined(Q_OS_LINUX)
         // append to wtmp
         updwtmpx("/var/log/wtmp", &entry);
-#elif defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
         pututxline(&entry);
 #endif
     }
