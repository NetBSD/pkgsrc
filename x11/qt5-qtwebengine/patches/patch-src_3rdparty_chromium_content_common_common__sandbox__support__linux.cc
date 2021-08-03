$NetBSD: patch-src_3rdparty_chromium_content_common_common__sandbox__support__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/common/common_sandbox_support_linux.cc.orig	2020-07-15 18:55:57.000000000 +0000
+++ src/3rdparty/chromium/content/common/common_sandbox_support_linux.cc
@@ -5,6 +5,7 @@
 #include "content/public/common/common_sandbox_support_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <limits>
 #include <memory>
