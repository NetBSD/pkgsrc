$NetBSD: patch-gpu_command__buffer_service_gles2__cmd__decoder.cc,v 1.22 2026/07/06 13:06:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/gles2_cmd_decoder.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ gpu/command_buffer/service/gles2_cmd_decoder.cc
@@ -2996,7 +2996,7 @@ std::unique_ptr<GLES2Decoder> GLES2Decod
   }
 
 // Allow linux to run fuzzers.
-#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<GLES2DecoderImpl>(client, command_buffer_service,
                                             outputter, group);
 #else
