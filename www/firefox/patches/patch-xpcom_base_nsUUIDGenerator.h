$NetBSD: patch-xpcom_base_nsUUIDGenerator.h,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- xpcom/base/nsUUIDGenerator.h.orig	2014-05-06 22:56:38.000000000 +0000
+++ xpcom/base/nsUUIDGenerator.h
@@ -27,7 +27,7 @@ private:
 protected:
 
     mozilla::Mutex mLock;
-#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(ANDROID)
+#if !defined(XP_WIN) && !defined(MOZ_WIDGET_COCOA) && !defined(ANDROID)
     char mState[128];
     char *mSavedState;
     uint8_t mRBytes;
