$NetBSD: patch-gpu_command__buffer_service_gles2__cmd__decoder.cc,v 1.16 2026/03/14 12:40:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/gles2_cmd_decoder.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ gpu/command_buffer/service/gles2_cmd_decoder.cc
@@ -2852,7 +2852,7 @@ std::unique_ptr<GLES2Decoder> GLES2Decod
   }
 
 // Allow linux to run fuzzers.
-#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<GLES2DecoderImpl>(client, command_buffer_service,
                                             outputter, group);
 #else
