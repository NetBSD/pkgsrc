$NetBSD: patch-v8_src_snapshot_embedded_platform-embedded-file-writer-base.cc,v 1.1 2025/02/06 09:58:36 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -148,6 +148,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(cons
     return EmbeddedTargetOs::kStarboard;
   } else if (string == "zos") {
     return EmbeddedTargetOs::kZOS;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }
