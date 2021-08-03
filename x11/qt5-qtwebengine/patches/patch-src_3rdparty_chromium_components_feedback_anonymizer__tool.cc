$NetBSD: patch-src_3rdparty_chromium_components_feedback_anonymizer__tool.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/feedback/anonymizer_tool.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/feedback/anonymizer_tool.cc
@@ -15,7 +15,7 @@
 #include "base/threading/thread_restrictions.h"
 #include "content/public/browser/browser_thread.h"
 #include "net/base/ip_address.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 using re2::RE2;
 
