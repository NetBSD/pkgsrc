$NetBSD: patch-ui_gfx_x_atom__cache.cc,v 1.6 2025/09/12 16:02:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/x/atom_cache.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/gfx/x/atom_cache.cc
@@ -157,6 +157,7 @@ constexpr auto kAtomsToCache = std::to_a
     "application/octet-stream",
     "application/vnd.chromium.test",
     "chromium/filename",
+    "chromium/from-privileged",
     "chromium/x-bookmark-entries",
     "chromium/x-browser-actions",
     "chromium/x-file-system-files",
