$NetBSD: patch-remoting_host_crash_crash__file__uploader.cc,v 1.14 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/crash/crash_file_uploader.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ remoting/host/crash/crash_file_uploader.cc
@@ -45,7 +45,7 @@ constexpr char kMinidumpFileName[] = "du
 
 #if BUILDFLAG(IS_WIN)
 constexpr char kProductNameValue[] = "Chromoting";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductNameValue[] = "Chromoting_Linux";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kProductNameValue[] = "Chromoting_Mac";
