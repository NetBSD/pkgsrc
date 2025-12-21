$NetBSD: patch-src_3rdparty_chromium_v8_src_snapshot_embedded_platform-embedded-file-writer-base.cc,v 1.1 2025/12/21 09:38:51 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -146,6 +146,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(cons
     return EmbeddedTargetOs::kWin;
   } else if (string == "starboard") {
     return EmbeddedTargetOs::kStarboard;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else if (string == "zos") {
     return EmbeddedTargetOs::kZOS;
   } else {
