$NetBSD: patch-ui_views_views__delegate.cc,v 1.11 2025/12/11 09:13:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/views_delegate.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ ui/views/views_delegate.cc
@@ -92,7 +92,7 @@ bool ViewsDelegate::IsWindowInMetro(gfx:
   return false;
 }
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
