$NetBSD: patch-xpcom_base_nsUUIDGenerator.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- xpcom/base/nsUUIDGenerator.cpp.orig	2014-05-06 22:56:38.000000000 +0000
+++ xpcom/base/nsUUIDGenerator.cpp
@@ -6,7 +6,7 @@
 #if defined(XP_WIN)
 #include <windows.h>
 #include <objbase.h>
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #include <CoreFoundation/CoreFoundation.h>
 #else
 #include <stdlib.h>
@@ -34,7 +34,7 @@ nsUUIDGenerator::Init()
     // We're a service, so we're guaranteed that Init() is not going
     // to be reentered while we're inside Init().
     
-#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(ANDROID)
+#if !defined(XP_WIN) && !defined(MOZ_WIDGET_COCOA) && !defined(ANDROID)
     /* initialize random number generator using NSPR random noise */
     unsigned int seed;
 
@@ -67,7 +67,7 @@ nsUUIDGenerator::Init()
         return NS_ERROR_FAILURE;
 #endif
 
-#endif /* non XP_WIN and non XP_MACOSX */
+#endif /* non XP_WIN and non MOZ_WIDGET_COCOA */
 
     return NS_OK;
 }
@@ -100,7 +100,7 @@ nsUUIDGenerator::GenerateUUIDInPlace(nsI
     HRESULT hr = CoCreateGuid((GUID*)id);
     if (FAILED(hr))
         return NS_ERROR_FAILURE;
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
     CFUUIDRef uuid = CFUUIDCreate(kCFAllocatorDefault);
     if (!uuid)
         return NS_ERROR_FAILURE;
