$NetBSD: patch-content_browser_media_media__keys__listener__manager__impl.cc,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -333,7 +333,7 @@ void MediaKeysListenerManagerImpl::Start
     return;
   }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_WIN)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
