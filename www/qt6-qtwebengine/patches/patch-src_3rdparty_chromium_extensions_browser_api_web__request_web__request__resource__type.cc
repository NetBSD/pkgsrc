$NetBSD: patch-src_3rdparty_chromium_extensions_browser_api_web__request_web__request__resource__type.cc,v 1.1 2025/12/21 09:38:29 markd Exp $

Revert to 6.9.3 version until work out why gcc12 doesn't like it

--- src/3rdparty/chromium/extensions/browser/api/web_request/web_request_resource_type.cc.orig	2025-10-02 13:36:39.000000000 +1300
+++ src/3rdparty/chromium/extensions/browser/api/web_request/web_request_resource_type.cc	2025-09-25 23:10:42.000000000 +1200
@@ -2,9 +2,13 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#ifdef UNSAFE_BUFFERS_BUILD
+// TODO(crbug.com/351564777): Remove this and convert code to safer constructs.
+#pragma allow_unsafe_buffers
+#endif
+
 #include "extensions/browser/api/web_request/web_request_resource_type.h"
 
-#include <array>
 #include <string_view>
 
 #include "base/check_op.h"
@@ -16,11 +20,10 @@
 
 namespace {
 
-struct ResourceTypes {
+constexpr struct {
   const char* const name;
   const WebRequestResourceType type;
-};
-constexpr auto kResourceTypes = std::to_array<ResourceTypes>({
+} kResourceTypes[] = {
     {"main_frame", WebRequestResourceType::MAIN_FRAME},
     {"sub_frame", WebRequestResourceType::SUB_FRAME},
     {"stylesheet", WebRequestResourceType::STYLESHEET},
@@ -36,7 +39,7 @@
     {"webtransport", WebRequestResourceType::WEB_TRANSPORT},
     {"webbundle", WebRequestResourceType::WEBBUNDLE},
     {"other", WebRequestResourceType::OTHER},
-});
+};
 
 constexpr size_t kResourceTypesLength = std::size(kResourceTypes);
 
