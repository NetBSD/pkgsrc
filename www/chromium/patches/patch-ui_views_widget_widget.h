$NetBSD: patch-ui_views_widget_widget.h,v 1.18 2026/05/10 15:30:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/widget.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ ui/views/widget/widget.h
@@ -486,7 +486,7 @@ class VIEWS_EXPORT Widget : public inter
     bool dont_show_in_taskbar = false;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only used by X11, for root level windows. Specifies the res_name and
     // res_class fields, respectively, of the WM_CLASS window property. Controls
     // window grouping and desktop file matching in Linux window managers.
