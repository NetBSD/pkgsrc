$NetBSD: patch-remoting_host_host__attributes.cc,v 1.6 2025/09/08 13:24:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_attributes.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ remoting/host/host_attributes.cc
@@ -103,7 +103,7 @@ std::string GetHostAttributes() {
   if (media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   result.push_back("HWEncoder");
 #endif
 
