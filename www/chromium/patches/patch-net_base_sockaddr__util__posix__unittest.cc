$NetBSD: patch-net_base_sockaddr__util__posix__unittest.cc,v 1.1 2025/02/06 09:58:14 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/sockaddr_util_posix_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/base/sockaddr_util_posix_unittest.cc
@@ -88,7 +88,8 @@ TEST(FillUnixAddressTest, AbstractLinuxA
   size_t path_max = MaxPathLength(&storage);
   std::string path(path_max, '0');
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX?
   EXPECT_TRUE(FillUnixAddress(path, /*use_abstract_namespace=*/true, &storage));
 
   EXPECT_EQ(path.size() + 1U + offsetof(struct sockaddr_un, sun_path),
