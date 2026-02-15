$NetBSD: patch-chrome_browser_media__galleries_media__file__system__registry.cc,v 1.15 2026/02/15 09:03:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/media_galleries/media_file_system_registry.cc
@@ -572,7 +572,12 @@ class MediaFileSystemRegistry::MediaFile
 // Constructor in 'private' section because depends on private class definition.
 MediaFileSystemRegistry::MediaFileSystemRegistry()
     : file_system_context_(new MediaFileSystemContextImpl) {
-  StorageMonitor::GetInstance()->AddObserver(this);
+  /*
+   * This conditional is needed for shutdown.  Destructors
+   * try to get the media file system registry.
+   */
+  if (StorageMonitor::GetInstance())
+    StorageMonitor::GetInstance()->AddObserver(this);
 }
 
 MediaFileSystemRegistry::~MediaFileSystemRegistry() {
