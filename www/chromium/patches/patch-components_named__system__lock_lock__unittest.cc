$NetBSD: patch-components_named__system__lock_lock__unittest.cc,v 1.13 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/named_system_lock/lock_unittest.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/named_system_lock/lock_unittest.cc
@@ -18,7 +18,7 @@
 #include "build/build_config.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <fcntl.h>
 #include <sys/mman.h>
 
@@ -45,7 +45,7 @@ class NamedSystemLockTest : public ::tes
   const std::string lock_name_ = base::UnguessableToken::Create().ToString();
 
   std::unique_ptr<ScopedLock> CreateLock() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     return ScopedLock::Create(lock_name_, base::Seconds(0));
 #else
     CSecurityAttributes sa;
@@ -95,7 +95,7 @@ TEST_F(NamedSystemLockTest, TryLockInThr
   EXPECT_TRUE(CreateLock());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST_F(NamedSystemLockTest, SharedMemoryWrongPermissions) {
   // Create a shared memory region with overpermissive perms.
   int shm_fd = shm_open(lock_name_.c_str(), O_RDWR | O_CREAT | O_EXCL,
