$NetBSD: patch-src_3rdparty_chromium_chrome_renderer_pepper_pepper__flash__font__file__host.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/renderer/pepper/pepper_flash_font_file_host.cc
@@ -15,7 +15,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "content/public/common/common_sandbox_support_linux.h"
 #elif defined(OS_WIN)
@@ -29,7 +29,7 @@ PepperFlashFontFileHost::PepperFlashFont
     const ppapi::proxy::SerializedFontDescription& description,
     PP_PrivateFontCharset charset)
     : ResourceHost(host->GetPpapiHost(), instance, resource) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // The global SkFontConfigInterface is configured and initialized with a
   // SkFontconfigInterface compatible font_service::FontLoader in
   // RendererBlinkPlatformImpl (called from RenderThreadImpl::Init) at startup
@@ -74,7 +74,7 @@ bool PepperFlashFontFileHost::GetFontDat
                                           void* buffer,
                                           size_t* length) {
   bool result = false;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (font_file_.IsValid()) {
     result = content::GetFontTable(font_file_.GetPlatformFile(), table,
                                    0 /* offset */,
