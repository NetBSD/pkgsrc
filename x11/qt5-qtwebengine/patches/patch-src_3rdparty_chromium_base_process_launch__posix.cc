$NetBSD: patch-src_3rdparty_chromium_base_process_launch__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/launch_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/process/launch_posix.cc
@@ -214,6 +214,8 @@ static const char kFDDir[] = "/dev/fd";
 static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_OPENBSD)
 static const char kFDDir[] = "/dev/fd";
+#elif defined(OS_NETBSD)
+static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_ANDROID)
 static const char kFDDir[] = "/proc/self/fd";
 #endif
