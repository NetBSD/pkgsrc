$NetBSD: patch-components_dbus_xdg_file__transfer__portal.cc,v 1.8 2026/07/08 13:42:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/dbus/xdg/file_transfer_portal.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ components/dbus/xdg/file_transfer_portal.cc
@@ -31,6 +31,10 @@
 #include "dbus/object_path.h"
 #include "dbus/object_proxy.h"
 
+#if BUILDFLAG(IS_BSD) && !defined(O_PATH)
+#define O_PATH 0
+#endif
+
 namespace dbus_xdg {
 
 BASE_FEATURE(kXdgFileTransferPortal, base::FEATURE_DISABLED_BY_DEFAULT);
