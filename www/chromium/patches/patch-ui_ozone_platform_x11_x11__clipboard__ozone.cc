$NetBSD: patch-ui_ozone_platform_x11_x11__clipboard__ozone.cc,v 1.3 2026/04/21 15:21:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/x11_clipboard_ozone.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/ozone/platform/x11/x11_clipboard_ozone.cc
@@ -14,7 +14,7 @@
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/base/x/x11_clipboard_helper.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_view_util.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #endif
@@ -39,7 +39,7 @@ void X11ClipboardOzone::OfferClipboardDa
   for (const auto& item : data_map)
     helper_->InsertMapping(item.first, item.second);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto it = data_map.find(kMimeTypeUriList);
   if (it != data_map.end()) {
     std::string unparsed(base::as_string_view(*it->second));
