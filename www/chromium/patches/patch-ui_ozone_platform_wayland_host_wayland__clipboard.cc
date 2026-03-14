$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__clipboard.cc,v 1.1 2026/03/14 12:40:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_clipboard.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_clipboard.cc
@@ -34,7 +34,7 @@
 #include "ui/ozone/platform/wayland/host/zwp_primary_selection_device_manager.h"
 #include "ui/ozone/public/platform_clipboard.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_util.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #include "ui/ozone/platform/wayland/host/wayland_exchange_data_provider.h"
@@ -102,7 +102,7 @@ class ClipboardImpl final : public Clipb
   }
 
   ui::PlatformClipboard::Data ReadFileTransfer() final {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Prefer portal types
     ui::PlatformClipboard::Data data =
         GetDevice()->ReadSelectionData(ui::kMimeTypePortalFileTransfer);
@@ -146,7 +146,7 @@ class ClipboardImpl final : public Clipb
     } else {
       offered_data_ = *data;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Check if we need to register files for transfer
       auto it = offered_data_.find(ui::kMimeTypeUriList);
       if (it != offered_data_.end()) {
