$NetBSD: patch-remoting_base_username.cc,v 1.10 2026/09/22 13:41:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/username.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/base/username.cc
@@ -86,7 +86,7 @@ std::string GetUsername() {
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID)
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 base::cstring_view GetNetworkProcessUsername() {
   // Should be in sync with CRD_NETWORK_USER in
