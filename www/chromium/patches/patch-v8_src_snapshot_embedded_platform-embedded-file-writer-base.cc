$NetBSD: patch-v8_src_snapshot_embedded_platform-embedded-file-writer-base.cc,v 1.9 2025/11/04 14:55:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2025-10-24 16:42:30.000000000 +0000
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
