$NetBSD: patch-content_base_src_nsObjectLoadingContent.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- content/base/src/nsObjectLoadingContent.cpp.orig	2014-05-06 22:55:16.000000000 +0000
+++ content/base/src/nsObjectLoadingContent.cpp
@@ -2786,7 +2786,7 @@ nsObjectLoadingContent::DoStopPlugin(nsP
       return;
     }
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     aInstanceOwner->HidePluginWindow();
 #endif
 
