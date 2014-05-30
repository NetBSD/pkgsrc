$NetBSD: patch-profile_dirserviceprovider_src_nsProfileLock.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- profile/dirserviceprovider/src/nsProfileLock.cpp.orig	2014-05-06 22:56:22.000000000 +0000
+++ profile/dirserviceprovider/src/nsProfileLock.cpp
@@ -7,7 +7,7 @@
 #include "nsProfileLock.h"
 #include "nsCOMPtr.h"
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #include <Carbon/Carbon.h>
 #include <CoreFoundation/CoreFoundation.h>
 #endif
@@ -432,7 +432,7 @@ nsresult nsProfileLock::GetReplacedLockT
 nsresult nsProfileLock::Lock(nsIFile* aProfileDir,
                              nsIProfileUnlocker* *aUnlocker)
 {
-#if defined (XP_MACOSX)
+#if defined (MOZ_WIDGET_COCOA)
     NS_NAMED_LITERAL_STRING(LOCKFILE_NAME, ".parentlock");
     NS_NAMED_LITERAL_STRING(OLD_LOCKFILE_NAME, "parent.lock");
 #elif defined (XP_UNIX)
@@ -464,7 +464,7 @@ nsresult nsProfileLock::Lock(nsIFile* aP
     if (NS_FAILED(rv))
         return rv;
         
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     // First, try locking using fcntl. It is more reliable on
     // a local machine, but may not be supported by an NFS server.
 
