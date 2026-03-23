$NetBSD: patch-xb__config.h,v 1.1 2026/03/23 10:50:44 nia Exp $

EXPLICIT_REGISTER_VARIABLES uses implicit int, which modern GCC no
longer likes. And the register keyword hasn't been useful for a
very long time.

--- xb_config.h.orig	1997-05-15 20:38:25.000000000 +0000
+++ xb_config.h
@@ -11,7 +11,7 @@
 /* #define R4_RESOURCES */
 
 /* on slow machines this might speed things up a bit */
-#define EXPLICIT_REGISTER_VARIABLES
+/* #define EXPLICIT_REGISTER_VARIABLES */
 
 /* if you have no usleep() comment out the following line */
 #define HAS_USLEEP
