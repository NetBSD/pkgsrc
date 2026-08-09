$NetBSD: patch-third__party_nasm_output_outobj.c,v 1.2 2026/08/09 06:31:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/nasm/output/outobj.c.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/nasm/output/outobj.c
@@ -407,7 +407,7 @@ static ObjRecord *obj_name(ObjRecord * o
     orp->used += len + 1;
     if (obj_uppercase)
         while (--len >= 0) {
-            *ptr++ = toupper(*name);
+            *ptr++ = toupper((unsigned char)*name);
             name++;
     } else
         memcpy(ptr, name, len);
