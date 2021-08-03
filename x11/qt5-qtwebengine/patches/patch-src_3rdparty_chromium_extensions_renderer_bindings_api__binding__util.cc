$NetBSD: patch-src_3rdparty_chromium_extensions_renderer_bindings_api__binding__util.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc
@@ -130,6 +130,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_NETBSD)
+  return "netbsd";
 #else
   NOTREACHED();
   return std::string();
