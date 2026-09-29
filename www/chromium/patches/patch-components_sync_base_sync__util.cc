$NetBSD: patch-components_sync_base_sync__util.cc,v 1.27 2026/09/29 07:42:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/base/sync_util.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/sync/base/sync_util.cc
@@ -58,6 +58,8 @@ std::string GetSystemString() {
   system = "FREEBSD ";
 #elif BUILDFLAG(IS_OPENBSD)
   system = "OPENBSD ";
+#elif BUILDFLAG(IS_NETBSD)
+  system = "NETBSD ";
 #elif BUILDFLAG(IS_MAC)
   system = "MAC ";
 #endif
