$NetBSD: patch-extensions_renderer_bindings_api__binding__util.cc,v 1.4 2025/07/25 16:17:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/renderer/bindings/api_binding_util.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -129,7 +129,7 @@ void InvalidateContext(v8::Local<v8::Con
 std::string GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
