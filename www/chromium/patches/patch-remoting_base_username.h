$NetBSD: patch-remoting_base_username.h,v 1.12 2026/10/02 11:43:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/username.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ remoting/base/username.h
@@ -16,7 +16,7 @@ namespace remoting {
 // error or if not implemented.
 std::string GetUsername();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the username that the network process is run as.
 base::cstring_view GetNetworkProcessUsername();
 
