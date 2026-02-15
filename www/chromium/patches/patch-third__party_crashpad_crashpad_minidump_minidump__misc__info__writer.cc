$NetBSD: patch-third__party_crashpad_crashpad_minidump_minidump__misc__info__writer.cc,v 1.15 2026/02/15 09:04:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/minidump/minidump_misc_info_writer.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/crashpad/crashpad/minidump/minidump_misc_info_writer.cc
@@ -159,6 +159,12 @@ std::string MinidumpMiscInfoDebugBuildSt
   static constexpr char kOS[] = "win";
 #elif BUILDFLAG(IS_FUCHSIA)
   static constexpr char kOS[] = "fuchsia";
+#elif defined(OS_OPENBSD)
+  static constexpr char kOS[] = "openbsd";
+#elif defined(OS_FREEBSD)
+  static constexpr char kOS[] = "freebsd";
+#elif defined(OS_NETBSD)
+  static constexpr char kOS[] = "netbsd";
 #else
 #error define kOS for this operating system
 #endif
