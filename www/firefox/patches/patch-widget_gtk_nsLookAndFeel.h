$NetBSD: patch-widget_gtk_nsLookAndFeel.h,v 1.1 2015/01/16 22:42:09 ryoon Exp $

--- widget/gtk/nsLookAndFeel.h.orig	2015-01-09 04:38:28.000000000 +0000
+++ widget/gtk/nsLookAndFeel.h
@@ -35,7 +35,6 @@ protected:
     struct _GtkStyle *mStyle;
 #else
     struct _GtkStyleContext *mBackgroundStyle;
-    struct _GtkStyleContext *mViewStyle;
     struct _GtkStyleContext *mButtonStyle;
 #endif
 
@@ -64,7 +63,7 @@ protected:
     nscolor sMenuHoverText;
     nscolor sButtonText;
     nscolor sButtonHoverText;
-    nscolor sFrameBackground;
+    nscolor sButtonBackground;
     nscolor sFrameOuterLightBorder;
     nscolor sFrameInnerDarkBorder;
     nscolor sOddCellBackground;
@@ -75,8 +74,8 @@ protected:
     nscolor sMozFieldBackground;
     nscolor sMozWindowText;
     nscolor sMozWindowBackground;
-    nscolor sMozWindowSelectedText;
-    nscolor sMozWindowSelectedBackground;
+    nscolor sTextSelectedText;
+    nscolor sTextSelectedBackground;
     nscolor sMozScrollbar;
     char16_t sInvisibleCharacter;
     float   sCaretRatio;
