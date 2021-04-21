$NetBSD: patch-pam__gdm_pam__gdm.c,v 1.2 2021/04/21 12:23:21 cirnatdan Exp $

Include only supported pam headers

--- pam_gdm/pam_gdm.c.orig	2021-03-30 13:25:30.000000000 +0000
+++ pam_gdm/pam_gdm.c
@@ -21,11 +21,13 @@
 
 #include <unistd.h>
 
+#include <security/pam_modules.h>
+#ifndef OPENPAM
 #include <security/_pam_macros.h>
 #include <security/pam_ext.h>
 #include <security/pam_misc.h>
-#include <security/pam_modules.h>
 #include <security/pam_modutil.h>
+#endif
 
 #ifdef HAVE_KEYUTILS
 #include <keyutils.h>
