$NetBSD: patch-src_3rdparty_chromium_third__party_crashpad_crashpad_util_posix_drop__privileges.cc,v 1.1 2025/12/21 09:38:41 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/drop_privileges.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/drop_privileges.cc
@@ -25,7 +25,7 @@ void DropPrivileges() {
   gid_t gid = getgid();
   uid_t uid = getuid();
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // Based on the POSIX.1-2008 2013 edition documentation for setreuid() and
   // setregid(), setreuid() and setregid() alone should be sufficient to drop
   // privileges. The standard specifies that the saved ID should be set to the
