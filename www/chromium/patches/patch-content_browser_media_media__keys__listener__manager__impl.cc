$NetBSD: patch-content_browser_media_media__keys__listener__manager__impl.cc,v 1.19 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -332,7 +332,7 @@ void MediaKeysListenerManagerImpl::Start
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
