$NetBSD: patch-xpcom_base_nsUUIDGenerator.h,v 1.4 2014/10/05 01:59:08 ryoon Exp $

--- xpcom/base/nsUUIDGenerator.h.orig	2014-09-24 01:05:41.000000000 +0000
+++ xpcom/base/nsUUIDGenerator.h
@@ -29,7 +29,7 @@ private:
 protected:
 
   mozilla::Mutex mLock;
-#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(ANDROID)
+#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(HAVE_ARC4RANDOM)
   char mState[128];
   char* mSavedState;
   uint8_t mRBytes;
