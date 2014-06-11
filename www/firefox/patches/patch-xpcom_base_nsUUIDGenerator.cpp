$NetBSD: patch-xpcom_base_nsUUIDGenerator.cpp,v 1.3 2014/06/11 00:41:36 ryoon Exp $

--- xpcom/base/nsUUIDGenerator.cpp.orig	2014-05-29 23:31:50.000000000 +0000
+++ xpcom/base/nsUUIDGenerator.cpp
@@ -15,6 +15,10 @@
 
 #include "nsUUIDGenerator.h"
 
+#ifdef ANDROID
+extern "C" NS_EXPORT void arc4random_buf(void *, size_t);
+#endif
+
 using namespace mozilla;
 
 NS_IMPL_ISUPPORTS1(nsUUIDGenerator, nsIUUIDGenerator)
@@ -34,7 +38,7 @@ nsUUIDGenerator::Init()
     // We're a service, so we're guaranteed that Init() is not going
     // to be reentered while we're inside Init().
     
-#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(ANDROID)
+#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(HAVE_ARC4RANDOM)
     /* initialize random number generator using NSPR random noise */
     unsigned int seed;
 
@@ -67,7 +71,7 @@ nsUUIDGenerator::Init()
         return NS_ERROR_FAILURE;
 #endif
 
-#endif /* non XP_WIN and non XP_MACOSX */
+#endif /* non XP_WIN and non XP_MACOSX and non ARC4RANDOM */
 
     return NS_OK;
 }
@@ -114,13 +118,16 @@ nsUUIDGenerator::GenerateUUIDInPlace(nsI
      * back to it; instead, we use the value returned when we called
      * initstate, since older glibc's have broken setstate() return values
      */
-#ifndef ANDROID
+#ifndef HAVE_ARC4RANDOM
     setstate(mState);
 #endif
 
+#ifdef HAVE_ARC4RANDOM_BUF
+    arc4random_buf(id, sizeof(nsID));
+#else /* HAVE_ARC4RANDOM_BUF */
     size_t bytesLeft = sizeof(nsID);
     while (bytesLeft > 0) {
-#ifdef ANDROID
+#ifdef HAVE_ARC4RANDOM
         long rval = arc4random();
         const size_t mRBytes = 4;
 #else
@@ -141,6 +148,7 @@ nsUUIDGenerator::GenerateUUIDInPlace(nsI
 
         bytesLeft -= toWrite;
     }
+#endif /* HAVE_ARC4RANDOM_BUF */
 
     /* Put in the version */
     id->m2 &= 0x0fff;
@@ -150,7 +158,7 @@ nsUUIDGenerator::GenerateUUIDInPlace(nsI
     id->m3[0] &= 0x3f;
     id->m3[0] |= 0x80;
 
-#ifndef ANDROID
+#ifndef HAVE_ARC4RANDOM
     /* Restore the previous RNG state */
     setstate(mSavedState);
 #endif
