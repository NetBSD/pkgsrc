$NetBSD: patch-remoting_host_evaluate__capability.cc,v 1.14 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/evaluate_capability.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ remoting/host/evaluate_capability.cc
@@ -56,7 +56,7 @@ base::FilePath BuildHostBinaryPath() {
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
