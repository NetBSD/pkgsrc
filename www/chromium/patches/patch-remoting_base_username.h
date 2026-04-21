$NetBSD: patch-remoting_base_username.h,v 1.2 2026/04/21 15:21:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/username.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ remoting/base/username.h
@@ -16,7 +16,7 @@ namespace remoting {
 // error or if not implemented.
 std::string GetUsername();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the username that the network process is run as.
 base::cstring_view GetNetworkProcessUsername();
 #endif  // BUILDFLAG(IS_LINUX)
