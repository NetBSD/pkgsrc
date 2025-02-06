$NetBSD: patch-v8_src_snapshot_embedded_platform-embedded-file-writer-base.h,v 1.1 2025/02/06 09:58:36 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -36,6 +36,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
