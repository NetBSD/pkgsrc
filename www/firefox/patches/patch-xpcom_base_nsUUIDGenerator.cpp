$NetBSD: patch-xpcom_base_nsUUIDGenerator.cpp,v 1.5 2014/10/05 01:59:08 ryoon Exp $

--- xpcom/base/nsUUIDGenerator.cpp.orig	2014-09-24 01:05:41.000000000 +0000
+++ xpcom/base/nsUUIDGenerator.cpp
@@ -16,6 +16,10 @@
 
 #include "nsUUIDGenerator.h"
 
+#ifdef ANDROID
+extern "C" NS_EXPORT void arc4random_buf(void *, size_t);
+#endif
+
 using namespace mozilla;
 
 NS_IMPL_ISUPPORTS(nsUUIDGenerator, nsIUUIDGenerator)
@@ -35,7 +39,7 @@ nsUUIDGenerator::Init()
   // We're a service, so we're guaranteed that Init() is not going
   // to be reentered while we're inside Init().
 
-#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(ANDROID)
+#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(HAVE_ARC4RANDOM)
   /* initialize random number generator using NSPR random noise */
   unsigned int seed;
 
@@ -72,7 +76,7 @@ nsUUIDGenerator::Init()
   }
 #endif
 
-#endif /* non XP_WIN and non XP_MACOSX */
+#endif /* non XP_WIN and non XP_MACOSX and non ARC4RANDOM */
 
   return NS_OK;
 }
@@ -122,13 +126,16 @@ nsUUIDGenerator::GenerateUUIDInPlace(nsI
    * back to it; instead, we use the value returned when we called
    * initstate, since older glibc's have broken setstate() return values
    */
-#ifndef ANDROID
+#ifndef HAVE_ARC4RANDOM
   setstate(mState);
 #endif
 
+#ifdef HAVE_ARC4RANDOM_BUF
+  arc4random_buf(aId, sizeof(nsID));
+#else /* HAVE_ARC4RANDOM_BUF */
   size_t bytesLeft = sizeof(nsID);
   while (bytesLeft > 0) {
-#ifdef ANDROID
+#ifdef HAVE_ARC4RANDOM
     long rval = arc4random();
     const size_t mRBytes = 4;
 #else
@@ -150,6 +157,7 @@ nsUUIDGenerator::GenerateUUIDInPlace(nsI
 
     bytesLeft -= toWrite;
   }
+#endif /* HAVE_ARC4RANDOM_BUF */
 
   /* Put in the version */
   aId->m2 &= 0x0fff;
@@ -159,7 +167,7 @@ nsUUIDGenerator::GenerateUUIDInPlace(nsI
   aId->m3[0] &= 0x3f;
   aId->m3[0] |= 0x80;
 
-#ifndef ANDROID
+#ifndef HAVE_ARC4RANDOM
   /* Restore the previous RNG state */
   setstate(mSavedState);
 #endif
