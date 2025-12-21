$NetBSD: patch-src_3rdparty_chromium_chrome_test_chromedriver_chrome__launcher.cc,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/test/chromedriver/chrome_launcher.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/chrome/test/chromedriver/chrome_launcher.cc
@@ -73,6 +73,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
