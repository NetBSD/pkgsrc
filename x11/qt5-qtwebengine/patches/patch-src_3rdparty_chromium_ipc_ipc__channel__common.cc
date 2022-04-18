$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__channel__common.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ipc/ipc_channel_common.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel_common.cc
@@ -10,7 +10,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
