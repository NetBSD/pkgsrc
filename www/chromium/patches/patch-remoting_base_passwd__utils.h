$NetBSD: patch-remoting_base_passwd__utils.h,v 1.1 2026/09/22 13:41:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/passwd_utils.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/base/passwd_utils.h
@@ -23,7 +23,7 @@ struct PasswdUserInfo {
   uid_t uid;
   gid_t gid;
   base::FilePath home_dir;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<gid_t> supplementary_gids;
 #endif
 };
