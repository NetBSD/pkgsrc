$NetBSD: patch-services_virus__scan_clamav__mod.c,v 1.1 2019/11/01 15:22:31 jperkin Exp $

Avoid symbol clash with newer clamav.

--- services/virus_scan/clamav_mod.c.orig	2019-01-17 10:49:34.000000000 +0000
+++ services/virus_scan/clamav_mod.c
@@ -105,7 +105,7 @@ extern ci_off_t CLAMAV_MAXSCANSIZE;
 extern char *CLAMAV_TMP;
 
 #define CLAMAV_VERSION_SIZE 64
-static char CLAMAV_VERSION[CLAMAV_VERSION_SIZE];
+static char CLAMAV_ENGINE_VERSION[CLAMAV_VERSION_SIZE];
 #define CLAMAV_SIGNATURE_SIZE SERVICE_ISTAG_SIZE + 1
 static char CLAMAV_SIGNATURE[CLAMAV_SIGNATURE_SIZE];
 
@@ -641,13 +641,13 @@ void clamav_set_versions()
     CLAMAV_SIGNATURE[CLAMAV_SIGNATURE_SIZE - 1] = '\0';
 
      /*set the clamav version*/
-     snprintf(CLAMAV_VERSION, CLAMAV_VERSION_SIZE - 1, "%s/%d", str_version, version);
-     CLAMAV_VERSION[CLAMAV_VERSION_SIZE - 1] = '\0';
+     snprintf(CLAMAV_ENGINE_VERSION, CLAMAV_VERSION_SIZE - 1, "%s/%d", str_version, version);
+     CLAMAV_ENGINE_VERSION[CLAMAV_VERSION_SIZE - 1] = '\0';
 }
 
 const char *clamav_version()
 {
-    return CLAMAV_VERSION;
+    return CLAMAV_ENGINE_VERSION;
 }
 
 const char *clamav_signature()
