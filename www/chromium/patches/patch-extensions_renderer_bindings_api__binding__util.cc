$NetBSD: patch-extensions_renderer_bindings_api__binding__util.cc,v 1.31 2026/10/23 15:05:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/renderer/bindings/api_binding_util.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -142,7 +142,7 @@ void InvalidateContext(v8::Local<v8::Con
 std::string_view GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
