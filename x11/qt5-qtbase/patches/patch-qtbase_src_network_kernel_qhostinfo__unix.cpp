$NetBSD: patch-qtbase_src_network_kernel_qhostinfo__unix.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtbase/src/network/kernel/qhostinfo_unix.cpp.orig	2013-11-27 01:01:10.000000000 +0000
+++ qtbase/src/network/kernel/qhostinfo_unix.cpp
@@ -126,6 +126,8 @@ static void resolveLibrary()
         if (!local_res_nclose)
             local_res_ninit = 0;
     }
+    if (local_res_ninit)
+        local_res_init = 0;
 #endif
 }
 
