$NetBSD: patch-chrome_updater_configurator.cc,v 1.11 2025/12/11 09:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/configurator.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/updater/configurator.cc
@@ -90,7 +90,7 @@ Configurator::Configurator(scoped_refptr
         return std::nullopt;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
       }()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux creating the NetworkFetcherFactory requires performing blocking IO
   // to load an external library. This should be done when the configurator is
   // created.
