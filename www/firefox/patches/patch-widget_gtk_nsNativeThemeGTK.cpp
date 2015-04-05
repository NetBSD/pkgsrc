$NetBSD: patch-widget_gtk_nsNativeThemeGTK.cpp,v 1.3 2015/04/05 12:54:12 ryoon Exp $

--- widget/gtk/nsNativeThemeGTK.cpp.orig	2015-03-27 02:20:33.000000000 +0000
+++ widget/gtk/nsNativeThemeGTK.cpp
@@ -1528,9 +1528,15 @@ nsNativeThemeGTK::GetWidgetTransparency(
   case NS_THEME_MENUPOPUP:
   case NS_THEME_WINDOW:
   case NS_THEME_DIALOG:
-  // Tooltips use gtk_paint_flat_box().
+    return eOpaque;
+  // Tooltips use gtk_paint_flat_box() on Gtk2
+  // but are shaped on Gtk3
   case NS_THEME_TOOLTIP:
+#if (MOZ_WIDGET_GTK == 2)
     return eOpaque;
+#else
+    return eTransparent;
+#endif
   }
 
   return eUnknownTransparency;
