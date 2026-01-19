$NetBSD: patch-net_base_sockaddr__util__posix__unittest.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/sockaddr_util_posix_unittest.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/base/sockaddr_util_posix_unittest.cc
@@ -77,7 +77,8 @@ TEST(FillUnixAddressTest, AbstractLinuxA
   SockaddrStorage storage;
   std::string path(kMaxUnixAddressPath, '0');
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX?
   EXPECT_TRUE(FillUnixAddress(path, /*use_abstract_namespace=*/true, &storage));
 
   EXPECT_EQ(path.size() + 1U + offsetof(struct sockaddr_un, sun_path),
