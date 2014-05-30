$NetBSD: patch-toolkit_components_jsdownloads_src_DownloadPlatform.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- toolkit/components/jsdownloads/src/DownloadPlatform.cpp.orig	2014-05-06 22:56:29.000000000 +0000
+++ toolkit/components/jsdownloads/src/DownloadPlatform.cpp
@@ -17,7 +17,7 @@
 #include "nsILocalFileWin.h"
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include <CoreFoundation/CoreFoundation.h>
 #endif
 
@@ -67,7 +67,7 @@ static void gio_set_metadata_done(GObjec
 nsresult DownloadPlatform::DownloadDone(nsIURI* aSource, nsIFile* aTarget,
                                         const nsACString& aContentType, bool aIsPrivate)
 {
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(MOZ_WIDGET_ANDROID) || defined(MOZ_WIDGET_GTK)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(MOZ_WIDGET_ANDROID) || defined(MOZ_WIDGET_GTK)
   nsAutoString path;
   if (aTarget && NS_SUCCEEDED(aTarget->GetPath(path))) {
 #if defined(XP_WIN) || defined(MOZ_WIDGET_GTK)
@@ -106,7 +106,7 @@ nsresult DownloadPlatform::DownloadDone(
 #endif
     }
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // On OS X, make the downloads stack bounce.
     CFStringRef observedObject = ::CFStringCreateWithCString(kCFAllocatorDefault,
                                              NS_ConvertUTF16toUTF8(path).get(),
