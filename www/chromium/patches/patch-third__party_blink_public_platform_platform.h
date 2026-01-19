$NetBSD: patch-third__party_blink_public_platform_platform.h,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/public/platform/platform.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/public/platform/platform.h
@@ -377,7 +377,7 @@ class BLINK_PLATFORM_EXPORT Platform {
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // This is called after the thread is created, so the embedder
   // can initiate an IPC to change its thread type (on Linux we can't
   // increase the nice value, so we need to ask the browser process). This
