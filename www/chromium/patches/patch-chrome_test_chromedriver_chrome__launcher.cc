$NetBSD: patch-chrome_test_chromedriver_chrome__launcher.cc,v 1.6 2025/09/08 13:24:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/chromedriver/chrome_launcher.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -75,6 +75,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
