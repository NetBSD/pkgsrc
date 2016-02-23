$NetBSD: patch-hw_xfree86_common_xf86AutoConfig.c,v 1.1 2016/02/23 22:32:45 tnn Exp $

--- hw/xfree86/common/xf86AutoConfig.c.orig	2016-02-08 22:52:26.000000000 +0000
+++ hw/xfree86/common/xf86AutoConfig.c
@@ -269,26 +269,27 @@ listPossibleVideoDrivers(char *matches[]
 
 #if defined(__linux__)
     matches[i++] = xnfstrdup("modesetting");
+    /* matches[i++] = xnfstrdup("fbdev"); */
 #endif
 
-#if !defined(sun)
-    /* Fallback to platform default frame buffer driver */
-    if (i < (nmatches - 1)) {
-#if !defined(__linux__) && defined(__sparc__)
-        matches[i++] = xnfstrdup("wsfb");
-#else
-        matches[i++] = xnfstrdup("fbdev");
+#if defined(__NetBSD__)
+#if defined(__shark)
+    matches[i++] = xnfstrdup("chips");
+    matches[i++] = xnfstrdup("igs");
+#elif defined(__sgimips)
+    matches[i++] = xnfstrdup("crime");
+    matches[i++] = xnfstrdup("newport");
 #endif
+    if (i == 0) {
+#if defined(__i386__) || defined(__amd64__)
+         matches[i++] = xnfstrdup("vesa");
+#endif
+         matches[i++] = xnfstrdup("wsfb");
     }
-#endif                          /* !sun */
-
-    /* Fallback to platform default hardware */
-    if (i < (nmatches - 1)) {
-#if defined(__i386__) || defined(__amd64__) || defined(__hurd__)
-        matches[i++] = xnfstrdup("vesa");
-#elif defined(__sparc__) && !defined(sun)
-        matches[i++] = xnfstrdup("sunffb");
 #endif
+
+    if (i == 0) {
+         matches[i++] = xnfstrdup("wsfb");
     }
 }
 
