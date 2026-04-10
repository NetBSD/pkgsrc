$NetBSD: patch-ui_base_x_x11__os__exchange__data__provider.cc,v 1.2 2026/04/10 17:32:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/x/x11_os_exchange_data_provider.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ ui/base/x/x11_os_exchange_data_provider.cc
@@ -28,7 +28,7 @@
 #include "ui/gfx/x/atom_cache.h"
 #include "ui/gfx/x/connection.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #endif
 
@@ -217,7 +217,7 @@ void XOSExchangeDataProvider::SetFilenam
           base::JoinString(paths, "\n")));
   format_map_.Insert(x11::GetAtom(kMimeTypeUriList), mem);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Synchronously register files to get the key. This blocks the UI thread
   // briefly but ensures the key is ready for the data offer.
   std::string key = ui::clipboard_util::RegisterFilesWithPortal(filenames);
