$NetBSD: patch-src_3rdparty_chromium_services_service__manager_embedder_main.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/service_manager/embedder/main.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/services/service_manager/embedder/main.cc
@@ -277,7 +277,7 @@ int Main(const MainParams& params) {
     base::EnableTerminationOnOutOfMemory();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
