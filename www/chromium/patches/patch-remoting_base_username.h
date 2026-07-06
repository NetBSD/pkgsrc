$NetBSD: patch-remoting_base_username.h,v 1.6 2026/07/06 13:06:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/username.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ remoting/base/username.h
@@ -16,7 +16,7 @@ namespace remoting {
 // error or if not implemented.
 std::string GetUsername();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the username that the network process is run as.
 base::cstring_view GetNetworkProcessUsername();
 #endif  // BUILDFLAG(IS_LINUX)
