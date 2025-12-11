$NetBSD: patch-chrome_updater_lock.cc,v 1.11 2025/12/11 09:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/lock.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/updater/lock.cc
@@ -26,7 +26,7 @@ namespace updater {
 std::unique_ptr<ScopedLock> CreateScopedLock(const std::string& name,
                                              UpdaterScope scope,
                                              base::TimeDelta timeout) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return named_system_lock::ScopedLock::Create(
       base::StrCat({"/" PRODUCT_FULLNAME_STRING, name,
                     UpdaterScopeToString(scope), ".lock"}),
