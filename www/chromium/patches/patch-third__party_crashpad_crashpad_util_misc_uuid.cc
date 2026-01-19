$NetBSD: patch-third__party_crashpad_crashpad_util_misc_uuid.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/misc/uuid.cc.orig	2026-01-07 00:50:30.000000000 +0000
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
