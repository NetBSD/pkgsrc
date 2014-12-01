$NetBSD: patch-widget_gtk_nsNativeThemeGTK.cpp,v 1.1 2014/12/01 18:11:14 ryoon Exp $

--- widget/gtk/nsNativeThemeGTK.cpp.orig	2014-11-21 03:37:52.000000000 +0000
+++ widget/gtk/nsNativeThemeGTK.cpp
@@ -940,14 +940,18 @@ nsNativeThemeGTK::GetWidgetBorder(nsDevi
     // but don't reserve any space for it.
     break;
   case NS_THEME_TAB:
-    // Top tabs have no bottom border, bottom tabs have no top border
-    moz_gtk_get_widget_border(MOZ_GTK_TAB, &aResult->left, &aResult->top,
-                              &aResult->right, &aResult->bottom, direction,
-                              FALSE);
-    if (IsBottomTab(aFrame))
-        aResult->top = 0;
-    else
-        aResult->bottom = 0;
+    {
+      GtkThemeWidgetType gtkWidgetType;
+      gint flags;
+
+      if (!GetGtkWidgetAndState(aWidgetType, aFrame, gtkWidgetType, nullptr,
+                                &flags))
+        return NS_OK;
+
+      moz_gtk_get_tab_border(&aResult->left, &aResult->top,
+                             &aResult->right, &aResult->bottom, direction,
+                             (GtkTabFlags)flags);
+    }
     break;
   case NS_THEME_MENUITEM:
   case NS_THEME_CHECKMENUITEM:
