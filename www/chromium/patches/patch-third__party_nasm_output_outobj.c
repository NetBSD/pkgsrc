$NetBSD: patch-third__party_nasm_output_outobj.c,v 1.9 2026/10/23 15:05:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/nasm/output/outobj.c.orig	2026-10-19 20:07:21.000000000 +0000
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
