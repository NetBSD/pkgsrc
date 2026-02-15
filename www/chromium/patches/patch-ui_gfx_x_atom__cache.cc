$NetBSD: patch-ui_gfx_x_atom__cache.cc,v 1.14 2026/02/15 09:04:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/x/atom_cache.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/gfx/x/atom_cache.cc
@@ -157,6 +157,7 @@ constexpr auto kAtomsToCache = std::to_a
     "application/octet-stream",
     "application/vnd.chromium.test",
     "chromium/filename",
+    "chromium/from-privileged",
     "chromium/x-bookmark-entries",
     "chromium/x-browser-actions",
     "chromium/x-file-system-files",
