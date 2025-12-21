$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__channel__common.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ipc/ipc_channel_common.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel_common.cc
@@ -10,7 +10,7 @@
 
 namespace IPC {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 int g_global_pid = 0;
