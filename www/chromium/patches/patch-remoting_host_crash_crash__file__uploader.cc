$NetBSD: patch-remoting_host_crash_crash__file__uploader.cc,v 1.26 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/crash/crash_file_uploader.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/host/crash/crash_file_uploader.cc
@@ -45,7 +45,7 @@ constexpr char kMinidumpFileName[] = "du
 
 #if BUILDFLAG(IS_WIN)
 constexpr char kProductNameValue[] = "Chromoting";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductNameValue[] = "Chromoting_Linux";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kProductNameValue[] = "Chromoting_Mac";
