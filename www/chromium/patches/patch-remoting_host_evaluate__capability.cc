$NetBSD: patch-remoting_host_evaluate__capability.cc,v 1.7 2025/09/12 16:02:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/evaluate_capability.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ remoting/host/evaluate_capability.cc
@@ -56,7 +56,7 @@ base::FilePath BuildHostBinaryPath() {
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
