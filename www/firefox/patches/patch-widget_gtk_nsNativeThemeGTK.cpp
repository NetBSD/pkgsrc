$NetBSD: patch-widget_gtk_nsNativeThemeGTK.cpp,v 1.5 2015/07/03 10:25:40 ryoon Exp $

--- widget/gtk/nsNativeThemeGTK.cpp.orig	2015-06-18 20:55:38.000000000 +0000
+++ widget/gtk/nsNativeThemeGTK.cpp
@@ -761,6 +761,8 @@ nsNativeThemeGTK::GetExtraSizeForWidget(
         return false;
 
       gint gap_height = moz_gtk_get_tab_thickness();
+      if (!gap_height)
+        return false;
 
       int32_t extra = gap_height - GetTabMarginPixels(aFrame);
       if (extra <= 0)
