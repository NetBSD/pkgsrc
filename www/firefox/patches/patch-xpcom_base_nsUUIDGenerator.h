$NetBSD: patch-xpcom_base_nsUUIDGenerator.h,v 1.3 2014/06/11 00:41:36 ryoon Exp $

--- xpcom/base/nsUUIDGenerator.h.orig	2014-05-29 23:31:50.000000000 +0000
+++ xpcom/base/nsUUIDGenerator.h
@@ -27,7 +27,7 @@ private:
 protected:
 
     mozilla::Mutex mLock;
-#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(ANDROID)
+#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(HAVE_ARC4RANDOM)
     char mState[128];
     char *mSavedState;
     uint8_t mRBytes;
