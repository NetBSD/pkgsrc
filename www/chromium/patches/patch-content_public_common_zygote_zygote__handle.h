$NetBSD: patch-content_public_common_zygote_zygote__handle.h,v 1.1 2026/10/13 13:16:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/common/zygote/zygote_handle.h.orig	2026-10-06 00:06:58.000000000 +0000
+++ content/public/common/zygote/zygote_handle.h
@@ -11,7 +11,7 @@
 #include "content/common/content_export.h"
 #include "content/public/common/zygote/zygote_buildflags.h"
 
-#if !BUILDFLAG(USE_ZYGOTE)
+#if !BUILDFLAG(USE_ZYGOTE) && !BUILDFLAG(IS_BSD)
 #error "Can not use zygote without USE_ZYGOTE"
 #endif
 
