$NetBSD: patch-device_vr_openxr_openxr__render__loop.h,v 1.2 2026/10/02 11:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_render_loop.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ device/vr/openxr/openxr_render_loop.h
@@ -38,7 +38,7 @@
 #include "third_party/openxr/src/include/openxr/openxr.h"
 #include "ui/gfx/geometry/rect_f.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/threading/thread.h"
 #endif
 
@@ -65,7 +65,7 @@ class XRThread : public base::android::J
       : base::android::JavaHandlerThread(name) {}
   ~XRThread() override = default;
 };
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class XRThread : public base::Thread {
  public:
   explicit XRThread(const char* name) : base::Thread(name) {}
