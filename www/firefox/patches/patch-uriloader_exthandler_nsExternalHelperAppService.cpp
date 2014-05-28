$NetBSD: patch-uriloader_exthandler_nsExternalHelperAppService.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

nsILocalFileMac.h is only available when the toolkit is cocoa.

--- uriloader/exthandler/nsExternalHelperAppService.cpp.orig	2014-05-06 22:56:37.000000000 +0000
+++ uriloader/exthandler/nsExternalHelperAppService.cpp
@@ -68,7 +68,7 @@
 #include "nsIObserverService.h" // so we can be a profile change observer
 #include "nsIPropertyBag2.h" // for the 64-bit content length
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "nsILocalFileMac.h"
 #elif defined(XP_OS2)
 #include "nsILocalFileOS2.h"
@@ -301,7 +301,7 @@ static bool GetFilenameAndExtensionFromC
 static nsresult GetDownloadDirectory(nsIFile **_directory)
 {
   nsCOMPtr<nsIFile> dir;
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // On OS X, we first try to get the users download location, if it's set.
   switch (Preferences::GetInt(NS_PREF_DOWNLOAD_FOLDERLIST, -1)) {
     case NS_FOLDER_VALUE_DESKTOP:
@@ -467,7 +467,7 @@ struct nsExtraMimeTypeEntry {
   const char* mDescription;
 };
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #define MAC_TYPE(x) x
 #else
 #define MAC_TYPE(x) 0
@@ -484,7 +484,7 @@ static nsExtraMimeTypeEntry extraMimeEnt
 {
 #if defined(VMS)
   { APPLICATION_OCTET_STREAM, "exe,com,bin,sav,bck,pcsi,dcx_axpexe,dcx_vaxexe,sfx_axpexe,sfx_vaxexe", "Binary File" },
-#elif defined(XP_MACOSX) // don't define .bin on the mac...use internet config to look that up...
+#elif defined(MOZ_WIDGET_COCOA) // don't define .bin on the mac...use internet config to look that up...
   { APPLICATION_OCTET_STREAM, "exe,com", "Binary File" },
 #else
   { APPLICATION_OCTET_STREAM, "exe,com,bin", "Binary File" },
