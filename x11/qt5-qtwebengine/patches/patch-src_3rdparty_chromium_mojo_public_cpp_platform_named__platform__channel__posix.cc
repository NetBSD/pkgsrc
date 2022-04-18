$NetBSD: patch-src_3rdparty_chromium_mojo_public_cpp_platform_named__platform__channel__posix.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/mojo/public/cpp/platform/named_platform_channel_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/cpp/platform/named_platform_channel_posix.cc
@@ -8,6 +8,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
+#include <string.h>
 
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
