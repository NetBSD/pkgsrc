$NetBSD: patch-v8_src_snapshot_embedded_platform-embedded-file-writer-base.h,v 1.13 2025/12/23 13:22:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -37,6 +37,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
