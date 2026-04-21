$NetBSD: patch-net_base_sockaddr__util__posix__unittest.cc,v 1.18 2026/04/21 15:21:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/sockaddr_util_posix_unittest.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ net/base/sockaddr_util_posix_unittest.cc
@@ -77,7 +77,8 @@ TEST(FillUnixAddressTest, AbstractLinuxA
   SockaddrStorage storage;
   std::string path(kMaxUnixAddressPath, '0');
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX?
   EXPECT_TRUE(FillUnixAddress(path, /*use_abstract_namespace=*/true, &storage));
 
   EXPECT_EQ(path.size() + 1U + offsetof(struct sockaddr_un, sun_path),
