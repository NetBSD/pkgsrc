$NetBSD: patch-third__party_nasm_output_outieee.c,v 1.2 2026/08/09 06:31:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/nasm/output/outieee.c.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/nasm/output/outieee.c
@@ -1245,8 +1245,10 @@ static int32_t ieee_putlr(struct ieeeFix
 static void ieee_unqualified_name(char *dest, char *source)
 {
     if (ieee_uppercase) {
-        while (*source)
-            *dest++ = toupper(*source++);
+        while (*source) {
+            unsigned char ch = *source++;
+            *dest++ = toupper(ch);
+        }
         *dest = 0;
     } else
         strcpy(dest, source);
