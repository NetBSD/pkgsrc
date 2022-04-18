$NetBSD: patch-src_core_config_linux.pri,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/core/config/linux.pri.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/core/config/linux.pri
@@ -31,7 +31,6 @@ qtConfig(webengine-embedded-build) {
 
     qtConfig(webengine-webrtc): qtConfig(webengine-webrtc-pipewire): gn_args += rtc_use_pipewire=true
 
-    qtConfig(webengine-system-libevent): gn_args += use_system_libevent=true
     qtConfig(webengine-system-libwebp):  gn_args += use_system_libwebp=true
     qtConfig(webengine-system-libxml2):  gn_args += use_system_libxml=true use_system_libxslt=true
     qtConfig(webengine-system-opus):     gn_args += use_system_opus=true
