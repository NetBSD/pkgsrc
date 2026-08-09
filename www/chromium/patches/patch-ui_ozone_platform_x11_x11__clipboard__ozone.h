$NetBSD: patch-ui_ozone_platform_x11_x11__clipboard__ozone.h,v 1.6 2026/08/09 06:31:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/x11_clipboard_ozone.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/ozone/platform/x11/x11_clipboard_ozone.h
@@ -14,7 +14,7 @@
 #include "ui/base/x/selection_utils.h"
 #include "ui/ozone/public/platform_clipboard.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/weak_ptr.h"
 #endif
 
@@ -56,7 +56,7 @@ class X11ClipboardOzone : public Platfor
  private:
   void OnSelectionChanged(ClipboardBuffer buffer);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnPortalKeyRead(PlatformClipboard::RequestDataClosure callback,
                        SelectionData selection_data);
   void OnPathsExtracted(PlatformClipboard::RequestDataClosure callback,
@@ -73,7 +73,7 @@ class X11ClipboardOzone : public Platfor
 
   ClipboardDataChangedCallback clipboard_changed_callback_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::WeakPtrFactory<X11ClipboardOzone> weak_factory_{this};
 #endif
 };
