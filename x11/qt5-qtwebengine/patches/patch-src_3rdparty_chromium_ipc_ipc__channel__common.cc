$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__channel__common.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/ipc/ipc_channel_common.cc.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel_common.cc
@@ -10,7 +10,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
