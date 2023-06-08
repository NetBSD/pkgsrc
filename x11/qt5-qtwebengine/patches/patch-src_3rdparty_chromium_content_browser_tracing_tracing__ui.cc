$NetBSD: patch-src_3rdparty_chromium_content_browser_tracing_tracing__ui.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3 (remove catapult)

--- src/3rdparty/chromium/content/browser/tracing/tracing_ui.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/content/browser/tracing/tracing_ui.cc
@@ -27,7 +27,6 @@
 #include "base/strings/stringprintf.h"
 #include "base/trace_event/trace_event.h"
 #include "base/values.h"
-#include "content/browser/tracing/grit/tracing_resources.h"
 #include "content/browser/tracing/tracing_controller_impl.h"
 #include "content/public/browser/browser_context.h"
 #include "content/public/browser/browser_thread.h"
@@ -242,8 +241,6 @@ TracingUI::TracingUI(WebUI* web_ui)
   WebUIDataSource* source = WebUIDataSource::Create(kChromeUITracingHost);
   source->DisableTrustedTypesCSP();
   source->UseStringsJs();
-  source->SetDefaultResource(IDR_TRACING_HTML);
-  source->AddResourcePath("tracing.js", IDR_TRACING_JS);
   source->SetRequestFilter(base::BindRepeating(OnShouldHandleRequest),
                            base::BindRepeating(OnTracingRequest));
   WebUIDataSource::Add(browser_context, source);
