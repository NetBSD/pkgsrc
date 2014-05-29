$NetBSD: patch-toolkit_xre_nsXREDirProvider.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- toolkit/xre/nsXREDirProvider.cpp.orig	2014-05-06 22:56:36.000000000 +0000
+++ toolkit/xre/nsXREDirProvider.cpp
@@ -41,7 +41,7 @@
 #include <windows.h>
 #include <shlobj.h>
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "nsILocalFileMac.h"
 // for chflags()
 #include <sys/stat.h>
@@ -55,7 +55,7 @@
 #include <os2.h>
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #define APP_REGISTRY_NAME "Application Registry"
 #elif defined(XP_WIN) || defined(XP_OS2)
 #define APP_REGISTRY_NAME "registry.dat"
@@ -134,7 +134,7 @@ nsXREDirProvider::SetProfile(nsIFile* aD
   if (NS_FAILED(rv))
     return rv;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   bool same;
   if (NS_SUCCEEDED(aDir->Equals(aLocalDir, &same)) && !same) {
     // Ensure that the cache directory is not indexed by Spotlight
@@ -192,7 +192,7 @@ nsXREDirProvider::GetUserProfilesRootDir
                                      aProfileName, aAppName, aVendorName);
 
   if (NS_SUCCEEDED(rv)) {
-#if !defined(XP_UNIX) || defined(XP_MACOSX)
+#if !defined(XP_UNIX) || defined(MOZ_WIDGET_COCOA)
     rv = file->AppendNative(NS_LITERAL_CSTRING("Profiles"));
 #endif
     // We must create the profile directory here if it does not exist.
@@ -217,7 +217,7 @@ nsXREDirProvider::GetUserProfilesLocalDi
                                      aProfileName, aAppName, aVendorName);
 
   if (NS_SUCCEEDED(rv)) {
-#if !defined(XP_UNIX) || defined(XP_MACOSX)
+#if !defined(XP_UNIX) || defined(MOZ_WIDGET_COCOA)
     rv = file->AppendNative(NS_LITERAL_CSTRING("Profiles"));
 #endif
     // We must create the profile directory here if it does not exist.
@@ -341,7 +341,7 @@ nsXREDirProvider::GetFile(const char* aP
       return mAppProvider->GetFile(NS_APP_PROFILE_DIR_STARTUP, aPersistent,
                                    aFile);
   }
-#if defined(XP_UNIX) || defined(XP_MACOSX)
+#if defined(XP_UNIX) || defined(MOZ_WIDGET_COCOA)
   else if (!strcmp(aProperty, XRE_SYS_LOCAL_EXTENSION_PARENT_DIR)) {
 #ifdef ENABLE_SYSTEM_EXTENSION_DIRS
     return GetSystemExtensionsDirectory(aFile);
@@ -350,7 +350,7 @@ nsXREDirProvider::GetFile(const char* aP
 #endif
   }
 #endif
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
   else if (!strcmp(aProperty, XRE_SYS_SHARE_EXTENSION_PARENT_DIR)) {
 #ifdef ENABLE_SYSTEM_EXTENSION_DIRS
 #if defined(__OpenBSD__) || defined(__FreeBSD__)
@@ -1145,7 +1145,7 @@ nsXREDirProvider::GetUserDataDirectoryHo
   nsresult rv;
   nsCOMPtr<nsIFile> localDir;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   FSRef fsRef;
   OSType folderType;
   if (aLocal) {
@@ -1264,13 +1264,13 @@ nsXREDirProvider::GetSysUserExtensionsDi
   return NS_OK;
 }
 
-#if defined(XP_UNIX) || defined(XP_MACOSX)
+#if defined(XP_UNIX) || defined(MOZ_WIDGET_COCOA)
 nsresult
 nsXREDirProvider::GetSystemExtensionsDirectory(nsIFile** aFile)
 {
   nsresult rv;
   nsCOMPtr<nsIFile> localDir;
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   FSRef fsRef;
   OSErr err = ::FSFindFolder(kOnSystemDisk, kApplicationSupportFolderType, kCreateFolder, &fsRef);
   NS_ENSURE_FALSE(err, NS_ERROR_FAILURE);
@@ -1413,7 +1413,7 @@ nsXREDirProvider::AppendSysUserExtension
 
   nsresult rv;
 
-#if defined (XP_MACOSX) || defined(XP_WIN) || defined(XP_OS2)
+#if defined (MOZ_WIDGET_COCOA) || defined(XP_WIN) || defined(XP_OS2)
 
   static const char* const sXR = "Mozilla";
   rv = aFile->AppendNative(nsDependentCString(sXR));
@@ -1472,7 +1472,7 @@ nsXREDirProvider::AppendProfilePath(nsIF
 
   nsresult rv;
 
-#if defined (XP_MACOSX)
+#if defined (MOZ_WIDGET_COCOA)
   if (!profile.IsEmpty()) {
     rv = AppendProfileString(aFile, profile.get());
   }
