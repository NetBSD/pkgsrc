$NetBSD: patch-third__party_iamf__tools_src_iamf_cli_codec_opus__decoder.cc,v 1.3 2026/10/02 11:43:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.cc
@@ -30,8 +30,8 @@
 #include "iamf/obu/decoder_config/opus_decoder_config.h"
 #include "iamf/obu/substream_channel_count.h"
 #include "iamf/obu/types.h"
-#include "include/opus.h"
-#include "include/opus_types.h"
+#include "third_party/opus/src/include/opus.h"
+#include "third_party/opus/src/include/opus_types.h"
 
 namespace iamf_tools {
 
