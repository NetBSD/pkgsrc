$NetBSD: patch-daemon_core.cpp,v 1.4 2023/01/07 01:26:14 gutteridge Exp $

Fix SunOS and OpenBSD builds, and work around a bug in NetBSD with the same
macro (PR lib/57172).

--- daemon/core.cpp.orig	2022-11-05 08:17:16.000000000 +0000
+++ daemon/core.cpp
@@ -59,6 +59,15 @@
 
 #include "core.h"

+/* 
+ * SunOS and modern OpenBSD don't define this, and NetBSD's version has an
+ * incorrect shift applied (log facilities are already defined with "<<3", it
+ * shouldn't be done a second time).
+ */
+#if !defined(LOG_MAKEPRI) || defined(__NetBSD__)
+#define LOG_MAKEPRI(fac, pri)    ((fac) | (pri))
+#endif
+
 
 enum
 {
