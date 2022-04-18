$NetBSD: patch-src_3rdparty_chromium_components_feedback_redaction__tool.cc,v 1.1 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/feedback/redaction_tool.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/feedback/redaction_tool.cc
@@ -15,7 +15,7 @@
 #include "base/threading/thread_restrictions.h"
 #include "content/public/browser/browser_thread.h"
 #include "net/base/ip_address.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 using re2::RE2;
 
