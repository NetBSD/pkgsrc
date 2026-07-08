$NetBSD: patch-third__party_pdfium_third__party_lcms_src_cmscgats.c,v 1.1 2026/07/08 13:42:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/pdfium/third_party/lcms/src/cmscgats.c.orig	2026-07-06 22:58:46.000000000 +0000
+++ third_party/pdfium/third_party/lcms/src/cmscgats.c
@@ -752,7 +752,7 @@ cmsFloat64Number ParseFloatNumber(const 
     }
 
     // Exponent, example 34.00E+20
-    if (*Buffer && toupper(*Buffer) == 'E') {
+    if (*Buffer && toupper((unsigned char)*Buffer) == 'E') {
 
         int e;
         int sgn;
