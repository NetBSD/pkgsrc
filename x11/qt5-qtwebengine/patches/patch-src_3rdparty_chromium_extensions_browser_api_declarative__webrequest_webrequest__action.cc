$NetBSD: patch-src_3rdparty_chromium_extensions_browser_api_declarative__webrequest_webrequest__action.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/extensions/browser/api/declarative_webrequest/webrequest_action.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/declarative_webrequest/webrequest_action.cc
@@ -28,7 +28,7 @@
 #include "extensions/common/extension.h"
 #include "net/base/registry_controlled_domains/registry_controlled_domain.h"
 #include "net/http/http_util.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 using extension_web_request_api_helpers::EventResponseDelta;
 
