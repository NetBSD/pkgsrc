$NetBSD: patch-widget_gtk_nsLookAndFeel.cpp,v 1.1 2015/01/16 22:42:09 ryoon Exp $

--- widget/gtk/nsLookAndFeel.cpp.orig	2015-01-09 04:38:28.000000000 +0000
+++ widget/gtk/nsLookAndFeel.cpp
@@ -38,7 +38,6 @@ nsLookAndFeel::nsLookAndFeel()
       mStyle(nullptr),
 #else
       mBackgroundStyle(nullptr),
-      mViewStyle(nullptr),
       mButtonStyle(nullptr),
 #endif
       mDefaultFontCached(false), mButtonFontCached(false),
@@ -53,7 +52,6 @@ nsLookAndFeel::~nsLookAndFeel()
     g_object_unref(mStyle);
 #else
     g_object_unref(mBackgroundStyle);
-    g_object_unref(mViewStyle);
     g_object_unref(mButtonStyle);
 #endif
 }
@@ -114,13 +112,19 @@ nsLookAndFeel::NativeGetColor(ColorID aI
     case eColorID_IMESelectedRawTextBackground:
     case eColorID_IMESelectedConvertedTextBackground:
     case eColorID__moz_dragtargetzone:
-        aColor = sMozWindowSelectedBackground;
+    case eColorID__moz_cellhighlight:
+    case eColorID__moz_html_cellhighlight:
+    case eColorID_highlight: // preference selected item,
+        aColor = sTextSelectedBackground;
         break;
     case eColorID_WidgetSelectForeground:
     case eColorID_TextSelectForeground:
     case eColorID_IMESelectedRawTextForeground:
     case eColorID_IMESelectedConvertedTextForeground:
-        aColor = sMozWindowSelectedText;
+    case eColorID_highlighttext:
+    case eColorID__moz_cellhighlighttext:
+    case eColorID__moz_html_cellhighlighttext:
+        aColor = sTextSelectedText;
         break;
 #endif
     case eColorID_Widget3DHighlight:
@@ -238,19 +242,6 @@ nsLookAndFeel::NativeGetColor(ColorID aI
                                     GTK_STATE_FLAG_INSENSITIVE, &gdk_color);
         aColor = GDK_RGBA_TO_NS_RGBA(gdk_color);
         break;
-    case eColorID_highlight: // preference selected item,
-        // background of selected item
-        gtk_style_context_get_background_color(mViewStyle, 
-                                               GTK_STATE_FLAG_SELECTED, 
-                                               &gdk_color);
-        aColor = GDK_RGBA_TO_NS_RGBA(gdk_color);
-        break;
-    case eColorID_highlighttext:
-        // text of selected item
-        gtk_style_context_get_color(mViewStyle, 
-                                    GTK_STATE_FLAG_SELECTED, &gdk_color);
-        aColor = GDK_RGBA_TO_NS_RGBA(gdk_color);
-        break;
     case eColorID_inactivecaption:
         // inactive window caption
         gtk_style_context_get_background_color(mBackgroundStyle, 
@@ -284,10 +275,17 @@ nsLookAndFeel::NativeGetColor(ColorID aI
 #endif
         break;
 
+    case eColorID_threedlightshadow:
+        // 3-D highlighted inner edge color
+        // always same as background in GTK code
     case eColorID_threedface:
     case eColorID_buttonface:
         // 3-D face color
-        aColor = sFrameBackground;
+#if (MOZ_WIDGET_GTK == 3)
+        aColor = sMozWindowBackground;
+#else
+        aColor = sButtonBackground;
+#endif
         break;
 
     case eColorID_buttontext:
@@ -302,11 +300,6 @@ nsLookAndFeel::NativeGetColor(ColorID aI
         aColor = sFrameOuterLightBorder;
         break;
 
-    case eColorID_threedlightshadow:
-        // 3-D highlighted inner edge color
-        aColor = sFrameBackground; // always same as background in GTK code
-        break;
-
     case eColorID_buttonshadow:
         // 3-D shadow edge color
     case eColorID_threedshadow:
@@ -391,19 +384,6 @@ nsLookAndFeel::NativeGetColor(ColorID aI
     case eColorID__moz_buttonhovertext:
         aColor = sButtonHoverText;
         break;
-    case eColorID__moz_cellhighlight:
-    case eColorID__moz_html_cellhighlight:
-        gtk_style_context_get_background_color(mViewStyle, 
-                                               GTK_STATE_FLAG_SELECTED, 
-                                               &gdk_color);
-        aColor = GDK_RGBA_TO_NS_RGBA(gdk_color);
-        break;
-    case eColorID__moz_cellhighlighttext:
-    case eColorID__moz_html_cellhighlighttext:
-        gtk_style_context_get_color(mViewStyle, 
-                                    GTK_STATE_FLAG_SELECTED, &gdk_color);
-        aColor = GDK_RGBA_TO_NS_RGBA(gdk_color);
-        break;
 #endif
     case eColorID__moz_menuhover:
         aColor = sMenuHover;
@@ -965,7 +945,7 @@ nsLookAndFeel::Init()
     GtkStyleContext *style;
 
     // Gtk manages a screen's CSS in the settings object so we
-    // ask Gtk to create it explicitly. Otherwise we may end up 
+    // ask Gtk to create it explicitly. Otherwise we may end up
     // with wrong color theme, see Bug 972382
     (void)gtk_settings_get_for_screen(gdk_screen_get_default());
 
@@ -975,9 +955,6 @@ nsLookAndFeel::Init()
     mBackgroundStyle = create_context(path);
     gtk_style_context_add_class(mBackgroundStyle, GTK_STYLE_CLASS_BACKGROUND);
 
-    mViewStyle = create_context(path);
-    gtk_style_context_add_class(mViewStyle, GTK_STYLE_CLASS_VIEW);
-
     mButtonStyle = create_context(path);
     gtk_style_context_add_class(mButtonStyle, GTK_STYLE_CLASS_BUTTON); 
 
@@ -990,11 +967,24 @@ nsLookAndFeel::Init()
     g_object_unref(style);
 
     // Text colors
-    gtk_style_context_get_background_color(mViewStyle, GTK_STATE_FLAG_NORMAL, &color);
+    style = create_context(path);
+    gtk_style_context_add_class(style, GTK_STYLE_CLASS_VIEW);
+    gtk_style_context_get_background_color(style, GTK_STATE_FLAG_NORMAL, &color);
     sMozFieldBackground = GDK_RGBA_TO_NS_RGBA(color);
-    gtk_style_context_get_color(mViewStyle, GTK_STATE_FLAG_NORMAL, &color);
+    gtk_style_context_get_color(style, GTK_STATE_FLAG_NORMAL, &color);
     sMozFieldText = GDK_RGBA_TO_NS_RGBA(color);
 
+    // Selected text and background
+    gtk_style_context_get_background_color(style,
+        static_cast<GtkStateFlags>(GTK_STATE_FLAG_FOCUSED|GTK_STATE_FLAG_SELECTED),
+        &color);
+    sTextSelectedBackground = GDK_RGBA_TO_NS_RGBA(color);
+    gtk_style_context_get_color(style,
+        static_cast<GtkStateFlags>(GTK_STATE_FLAG_FOCUSED|GTK_STATE_FLAG_SELECTED),
+        &color);
+    sTextSelectedText = GDK_RGBA_TO_NS_RGBA(color);
+    g_object_unref(style);
+
     // Window colors
     style = create_context(path);
     gtk_style_context_save(style);
@@ -1003,12 +993,6 @@ nsLookAndFeel::Init()
     sMozWindowBackground = GDK_RGBA_TO_NS_RGBA(color);
     gtk_style_context_get_color(style, GTK_STATE_FLAG_NORMAL, &color);
     sMozWindowText = GDK_RGBA_TO_NS_RGBA(color);
-
-    // Selected text and background
-    gtk_style_context_get_background_color(style, GTK_STATE_FLAG_SELECTED, &color);
-    sMozWindowSelectedBackground = GDK_RGBA_TO_NS_RGBA(color);
-    gtk_style_context_get_color(style, GTK_STATE_FLAG_SELECTED, &color);
-    sMozWindowSelectedText = GDK_RGBA_TO_NS_RGBA(color);
     gtk_style_context_restore(style);
 
     // tooltip foreground and background
@@ -1141,7 +1125,7 @@ nsLookAndFeel::Init()
 
     style = gtk_widget_get_style(button);
     if (style) {
-        sFrameBackground = GDK_COLOR_TO_NS_RGB(style->bg[GTK_STATE_NORMAL]);
+        sButtonBackground = GDK_COLOR_TO_NS_RGB(style->bg[GTK_STATE_NORMAL]);
         sFrameOuterLightBorder =
             GDK_COLOR_TO_NS_RGB(style->light[GTK_STATE_NORMAL]);
         sFrameInnerDarkBorder =
@@ -1189,12 +1173,9 @@ nsLookAndFeel::Init()
     GtkWidget *frame = gtk_frame_new(nullptr);
     gtk_container_add(GTK_CONTAINER(parent), frame);
 
-    style = gtk_widget_get_style_context(frame);
-    gtk_style_context_get_background_color(style, GTK_STATE_FLAG_NORMAL, &color);
-    sFrameBackground = GDK_RGBA_TO_NS_RGBA(color);
-
     // TODO GTK3 - update sFrameOuterLightBorder 
     // for GTK_BORDER_STYLE_INSET/OUTSET/GROVE/RIDGE border styles (Bug 978172).
+    style = gtk_widget_get_style_context(frame);
     gtk_style_context_get_border_color(style, GTK_STATE_FLAG_NORMAL, &color);
     sFrameInnerDarkBorder = sFrameOuterLightBorder = GDK_RGBA_TO_NS_RGBA(color);
 #endif
@@ -1257,11 +1238,9 @@ nsLookAndFeel::RefreshImpl()
     mStyle = nullptr;
 #else
     g_object_unref(mBackgroundStyle);
-    g_object_unref(mViewStyle);
     g_object_unref(mButtonStyle);
 
     mBackgroundStyle = nullptr;
-    mViewStyle = nullptr;
     mButtonStyle = nullptr;
 #endif
 
