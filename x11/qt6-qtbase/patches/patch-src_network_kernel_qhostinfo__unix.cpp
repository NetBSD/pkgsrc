$NetBSD: patch-src_network_kernel_qhostinfo__unix.cpp,v 1.1 2024/05/13 19:39:45 he Exp $

On NetBSD, res_init() is not thread-safe
and NetBSD's resolver code does "auto-refresh".
Ref. PR%58249.

--- src/network/kernel/qhostinfo_unix.cpp.orig	2024-05-13 18:52:13.740627531 +0000
+++ src/network/kernel/qhostinfo_unix.cpp
@@ -47,6 +47,10 @@ static void maybeRefreshResolver()
     // res_init() is not thread-safe; executing it leads to state corruption.
     // Whether it reloads resolv.conf on its own is unknown.
     return;
+#elif defined(Q_OS_NETBSD)
+    // res_init() is not thread-safe, and NetBSD's resolver code
+    // automatically refreshes on resolv.conf modification.
+    return;
 #endif
 
 #if QT_CONFIG(libresolv)
