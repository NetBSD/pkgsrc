$NetBSD: patch-components_dbus_xdg_file__transfer__portal.cc,v 1.3 2026/04/21 15:21:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/dbus/xdg/file_transfer_portal.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/dbus/xdg/file_transfer_portal.cc
@@ -28,6 +28,10 @@
 #include "dbus/object_path.h"
 #include "dbus/object_proxy.h"
 
+#if BUILDFLAG(IS_BSD) && !defined(O_PATH)
+#define O_PATH 0
+#endif
+
 namespace dbus_xdg {
 
 BASE_FEATURE(kXdgFileTransferPortal, base::FEATURE_DISABLED_BY_DEFAULT);
