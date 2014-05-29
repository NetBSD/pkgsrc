$NetBSD: patch-toolkit_profile_nsToolkitProfileService.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

--- toolkit/profile/nsToolkitProfileService.cpp.orig	2014-05-06 22:56:35.000000000 +0000
+++ toolkit/profile/nsToolkitProfileService.cpp
@@ -25,7 +25,7 @@
 #include "nsIFile.h"
 #include "nsISimpleEnumerator.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include <CoreFoundation/CoreFoundation.h>
 #include "nsILocalFileMac.h"
 #endif
@@ -1013,7 +1013,7 @@ NS_NewToolkitProfileService(nsIToolkitPr
 nsresult
 XRE_GetFileFromPath(const char *aPath, nsIFile* *aResult)
 {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     int32_t pathLen = strlen(aPath);
     if (pathLen > MAXPATHLEN)
         return NS_ERROR_INVALID_ARG;
