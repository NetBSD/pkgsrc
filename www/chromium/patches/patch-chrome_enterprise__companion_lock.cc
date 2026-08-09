$NetBSD: patch-chrome_enterprise__companion_lock.cc,v 1.24 2026/08/09 06:31:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/enterprise_companion/lock.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/enterprise_companion/lock.cc
@@ -18,7 +18,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLockName[] = "/" PRODUCT_FULLNAME_STRING ".lock";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kLockName[] = MAC_BUNDLE_IDENTIFIER_STRING ".lock";
@@ -42,7 +42,7 @@ base::win::SecurityDescriptor GetAdminDa
 namespace enterprise_companion {
 
 std::unique_ptr<ScopedLock> CreateScopedLock(base::TimeDelta timeout) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return named_system_lock::ScopedLock::Create(kLockName, timeout);
 #elif BUILDFLAG(IS_WIN)
   base::win::SecurityDescriptor sd = GetAdminDaclSecurityDescriptor();
