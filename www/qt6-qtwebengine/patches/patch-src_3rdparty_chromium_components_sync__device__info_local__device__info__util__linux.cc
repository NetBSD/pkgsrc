$NetBSD: patch-src_3rdparty_chromium_components_sync__device__info_local__device__info__util__linux.cc,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/sync_device_info/local_device_info_util_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/sync_device_info/local_device_info_util_linux.cc
@@ -9,6 +9,11 @@
 
 #include "base/linux_util.h"
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
+
 namespace syncer {
 
 std::string GetPersonalizableDeviceNameInternal() {
