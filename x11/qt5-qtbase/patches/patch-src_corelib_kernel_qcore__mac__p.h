$NetBSD: patch-src_corelib_kernel_qcore__mac__p.h,v 1.1 2021/09/29 19:28:01 adam Exp $

Fix building for Darwin 21.

--- src/corelib/kernel/qcore_mac_p.h.orig	2021-09-10 11:47:15.000000000 +0000
+++ src/corelib/kernel/qcore_mac_p.h
@@ -66,6 +66,7 @@ struct mach_header;
 #include <ApplicationServices/ApplicationServices.h>
 #else
 #include <CoreFoundation/CoreFoundation.h>
+#include <CoreGraphics/CoreGraphics.h>
 #endif
 
 #ifdef __OBJC__
