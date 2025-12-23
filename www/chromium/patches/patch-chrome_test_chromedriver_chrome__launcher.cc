$NetBSD: patch-chrome_test_chromedriver_chrome__launcher.cc,v 1.13 2025/12/23 13:22:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/chromedriver/chrome_launcher.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -75,6 +75,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
