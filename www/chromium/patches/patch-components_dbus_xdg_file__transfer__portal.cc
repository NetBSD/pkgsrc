$NetBSD: patch-components_dbus_xdg_file__transfer__portal.cc,v 1.9 2026/08/09 06:31:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/dbus/xdg/file_transfer_portal.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/dbus/xdg/file_transfer_portal.cc
@@ -32,6 +32,10 @@
 #include "dbus/object_path.h"
 #include "dbus/object_proxy.h"
 
+#if BUILDFLAG(IS_BSD) && !defined(O_PATH)
+#define O_PATH 0
+#endif
+
 namespace dbus_xdg {
 
 BASE_FEATURE(kXdgFileTransferPortal, base::FEATURE_ENABLED_BY_DEFAULT);
