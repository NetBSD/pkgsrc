$NetBSD: patch-dom_events_nsEventStateManager.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/events/nsEventStateManager.cpp.orig	2014-05-06 22:55:23.000000000 +0000
+++ dom/events/nsEventStateManager.cpp
@@ -85,7 +85,7 @@
 #include "GeckoProfiler.h"
 #include "Units.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #import <ApplicationServices/ApplicationServices.h>
 #endif
 
@@ -1865,7 +1865,7 @@ nsEventStateManager::FireContextClick()
     return;
   }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // Hack to ensure that we don't show a context menu when the user
   // let go of the mouse after a long cpu-hogging operation prevented
   // us from handling any OS events. See bug 117589.
@@ -3137,7 +3137,7 @@ nsEventStateManager::DecideGestureEvent(
   aEvent->panDirection = panDirection;
 }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 static bool
 NodeAllowsClickThrough(nsINode* aNode)
 {
@@ -3314,7 +3314,7 @@ nsEventStateManager::PostHandleEvent(nsP
             // focused frame
             EnsureDocument(mPresContext);
             if (mDocument) {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
               if (!activeContent || !activeContent->IsXUL())
 #endif
                 fm->ClearFocus(mDocument->GetWindow());
@@ -3689,7 +3689,7 @@ nsEventStateManager::PostHandleEvent(nsP
     }
     break;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   case NS_MOUSE_ACTIVATE:
     if (mCurrentTarget) {
       nsCOMPtr<nsIContent> targetContent;
