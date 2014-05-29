$NetBSD: patch-widget_xpwidgets_nsBaseWidget.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- widget/xpwidgets/nsBaseWidget.cpp.orig	2014-05-06 22:56:38.000000000 +0000
+++ widget/xpwidgets/nsBaseWidget.cpp
@@ -58,7 +58,7 @@ static void debug_RegisterPrefCallbacks(
 static int32_t gNumWidgets;
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "nsCocoaFeatures.h"
 #endif
 
@@ -491,7 +491,7 @@ void nsBaseWidget::AddChild(nsIWidget* a
 void nsBaseWidget::RemoveChild(nsIWidget* aChild)
 {
 #ifdef DEBUG
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // nsCocoaWindow doesn't implement GetParent, so in that case parent will be
   // null and we'll just have to do without this assertion.
   nsIWidget* parent = aChild->GetParent();
@@ -837,13 +837,13 @@ bool
 nsBaseWidget::ComputeShouldAccelerate(bool aDefault)
 {
 #if defined(XP_WIN) || defined(ANDROID) || \
-    defined(MOZ_GL_PROVIDER) || defined(XP_MACOSX)
+    defined(MOZ_GL_PROVIDER) || defined(MOZ_WIDGET_COCOA)
   bool accelerateByDefault = true;
 #else
   bool accelerateByDefault = false;
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // 10.6.2 and lower have a bug involving textures and pixel buffer objects
   // that caused bug 629016, so we don't allow OpenGL-accelerated layers on
   // those versions of the OS.
