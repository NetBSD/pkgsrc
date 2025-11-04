$NetBSD: patch-v8_src_snapshot_embedded_platform-embedded-file-writer-base.h,v 1.9 2025/11/04 14:55:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -36,6 +36,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
