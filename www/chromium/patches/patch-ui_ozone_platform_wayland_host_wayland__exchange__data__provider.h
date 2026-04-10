$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__exchange__data__provider.h,v 1.2 2026/04/10 17:32:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_exchange_data_provider.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_exchange_data_provider.h
@@ -41,7 +41,7 @@ class WaylandExchangeDataProvider final
   void AddData(PlatformClipboard::Data data, const std::string& mime_type);
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::map<std::string, std::string> additional_data_;
 #endif
 };
