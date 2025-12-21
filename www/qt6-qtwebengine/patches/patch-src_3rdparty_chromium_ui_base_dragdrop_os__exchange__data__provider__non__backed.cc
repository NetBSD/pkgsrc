$NetBSD: patch-src_3rdparty_chromium_ui_base_dragdrop_os__exchange__data__provider__non__backed.cc,v 1.1 2025/12/21 09:38:46 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_non_backed.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_non_backed.cc
@@ -101,7 +101,7 @@ void OSExchangeDataProviderNonBacked::Se
 
 std::optional<std::u16string> OSExchangeDataProviderNonBacked::GetString()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (HasFile()) {
     // Various Linux file managers both pass a list of file:// URIs and set the
     // string representation to the URI. We explicitly don't want to return use
