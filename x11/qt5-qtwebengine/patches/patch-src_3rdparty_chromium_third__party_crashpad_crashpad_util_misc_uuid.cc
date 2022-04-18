$NetBSD: patch-src_3rdparty_chromium_third__party_crashpad_crashpad_util_misc_uuid.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/uuid.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/uuid.cc
@@ -96,7 +96,7 @@ bool UUID::InitializeWithNew() {
   InitializeFromBytes(uuid);
   return true;
 #elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // Linux, Android, and Fuchsia do not provide a UUID generator in a
   // widely-available system library. On Linux and Android, uuid_generate()
   // from libuuid is not available everywhere.
