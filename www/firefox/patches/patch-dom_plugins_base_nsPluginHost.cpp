$NetBSD: patch-dom_plugins_base_nsPluginHost.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/nsPluginHost.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/nsPluginHost.cpp
@@ -33,7 +33,7 @@
 #include "nsIProtocolProxyService2.h"
 #include "nsIStreamConverterService.h"
 #include "nsIFile.h"
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #include "nsILocalFileMac.h"
 #endif
 #include "nsISeekableStream.h"
@@ -1605,7 +1605,7 @@ int64_t GetPluginLastModifiedTime(const 
 {
   PRTime fileModTime = 0;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   // On OS X the date of a bundle's "contents" (i.e. of its Info.plist file)
   // is a much better guide to when it was last modified than the date of
   // its package directory.  See bug 313700.
@@ -2490,7 +2490,7 @@ nsPluginHost::ReadPluginInfo()
   if (!ReadSectionHeader(reader, "PLUGINS"))
     return rv;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   bool hasFullPathInFileNameField = false;
 #else
   bool hasFullPathInFileNameField = (version < "0.11");
