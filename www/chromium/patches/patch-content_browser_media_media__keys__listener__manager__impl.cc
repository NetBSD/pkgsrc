$NetBSD: patch-content_browser_media_media__keys__listener__manager__impl.cc,v 1.24 2026/08/09 06:31:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -326,7 +326,7 @@ void MediaKeysListenerManagerImpl::Start
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
