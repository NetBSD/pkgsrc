$NetBSD: patch-remoting_base_remoting__export.h,v 1.13 2026/10/23 15:05:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/remoting_export.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ remoting/base/remoting_export.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // On Linux, we need to export this symbol so it can be used by binaries that
 // link against remoting_core.so.
 #if defined(WIN32)
