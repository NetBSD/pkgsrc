$NetBSD: patch-remoting_base_passwd__utils.cc,v 1.8 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/passwd_utils.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/base/passwd_utils.cc
@@ -49,7 +49,7 @@ base::expected<PasswdUserInfo, Loggable>
   user_info.gid = result->pw_gid;
   user_info.home_dir = base::FilePath(result->pw_dir);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   long max_groups = sysconf(_SC_NGROUPS_MAX);
   constexpr int kDefaultNgroups = 64;
   int ngroups =
