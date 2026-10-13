$NetBSD: patch-third__party_nasm_output_outobj.c,v 1.7 2026/10/13 13:16:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/nasm/output/outobj.c.orig	2026-10-06 00:06:58.000000000 +0000
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
