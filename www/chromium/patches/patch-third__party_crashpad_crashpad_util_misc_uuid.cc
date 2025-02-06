$NetBSD: patch-third__party_crashpad_crashpad_util_misc_uuid.cc,v 1.1 2025/02/06 09:58:25 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/misc/uuid.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/crashpad/crashpad/util/misc/uuid.cc
@@ -110,7 +110,7 @@ bool UUID::InitializeWithNew() {
   InitializeFromBytes(uuid);
   return true;
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // Linux, Android, and Fuchsia do not provide a UUID generator in a
   // widely-available system library. On Linux and Android, uuid_generate()
   // from libuuid is not available everywhere.
