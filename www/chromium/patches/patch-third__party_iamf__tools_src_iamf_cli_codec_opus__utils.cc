$NetBSD: patch-third__party_iamf__tools_src_iamf_cli_codec_opus__utils.cc,v 1.3 2026/10/02 11:43:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/iamf_tools/src/iamf/cli/codec/opus_utils.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ third_party/iamf_tools/src/iamf/cli/codec/opus_utils.cc
@@ -3,7 +3,7 @@
 #include "absl/status/status.h"
 #include "absl/strings/str_cat.h"
 #include "absl/strings/string_view.h"
-#include "include/opus_defines.h"
+#include "third_party/opus/src/include/opus_defines.h"
 
 namespace iamf_tools {
 
