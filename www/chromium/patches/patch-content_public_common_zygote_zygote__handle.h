$NetBSD: patch-content_public_common_zygote_zygote__handle.h,v 1.2 2026/10/16 15:30:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/common/zygote/zygote_handle.h.orig	2026-10-14 21:09:54.000000000 +0000
+++ content/public/common/zygote/zygote_handle.h
@@ -11,7 +11,7 @@
 #include "content/common/content_export.h"
 #include "content/public/common/zygote/zygote_buildflags.h"
 
-#if !BUILDFLAG(USE_ZYGOTE)
+#if !BUILDFLAG(USE_ZYGOTE) && !BUILDFLAG(IS_BSD)
 #error "Can not use zygote without USE_ZYGOTE"
 #endif
 
