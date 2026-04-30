$NetBSD: patch-src_3rdparty_chromium_ui_gfx_x_atom__cache.cc,v 1.1 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/x/atom_cache.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/x/atom_cache.cc
@@ -157,6 +157,7 @@ constexpr auto kAtomsToCache = std::to_a
     "application/octet-stream",
     "application/vnd.chromium.test",
     "chromium/filename",
+    "chromium/from-privileged",
     "chromium/x-bookmark-entries",
     "chromium/x-browser-actions",
     "chromium/x-file-system-files",
