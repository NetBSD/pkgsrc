$NetBSD: patch-ui_views_widget_widget.h,v 1.23 2026/08/09 06:31:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/widget.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/views/widget/widget.h
@@ -489,7 +489,7 @@ class VIEWS_EXPORT Widget : public inter
     bool dont_show_in_taskbar = false;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only used by X11, for root level windows. Specifies the res_name and
     // res_class fields, respectively, of the WM_CLASS window property. Controls
     // window grouping and desktop file matching in Linux window managers.
