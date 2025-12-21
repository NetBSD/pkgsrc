$NetBSD: patch-src_3rdparty_chromium_v8_src_snapshot_embedded_platform-embedded-file-writer-base.h,v 1.1 2025/12/21 09:38:51 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -35,6 +35,7 @@ enum class EmbeddedTargetOs {
   kMac,
   kWin,
   kStarboard,
+  kOpenBSD,
   kZOS,
   kGeneric,  // Everything not covered above falls in here.
 };
