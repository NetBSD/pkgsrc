$NetBSD: patch-v8_src_snapshot_embedded_platform-embedded-file-writer-base.cc,v 1.24 2026/08/09 06:31:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -150,6 +150,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(cons
     return EmbeddedTargetOs::kStarboard;
   } else if (string == "zos") {
     return EmbeddedTargetOs::kZOS;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }
