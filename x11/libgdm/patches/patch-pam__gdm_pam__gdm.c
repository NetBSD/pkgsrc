$NetBSD: patch-pam__gdm_pam__gdm.c,v 1.1 2021/04/16 13:57:52 cirnatdan Exp $

Include only supported pam headers

--- pam_gdm/pam_gdm.c.orig	2020-12-15 18:16:43.000000000 +0000
+++ pam_gdm/pam_gdm.c
@@ -21,11 +21,13 @@
 
 #include <unistd.h>
 
+#ifdef __linux__
 #include <security/_pam_macros.h>
 #include <security/pam_ext.h>
 #include <security/pam_misc.h>
-#include <security/pam_modules.h>
 #include <security/pam_modutil.h>
+#endif
+#include <security/pam_modules.h>
 
 #ifdef HAVE_KEYUTILS
 #include <keyutils.h>
