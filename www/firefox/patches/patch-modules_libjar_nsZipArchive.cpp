$NetBSD: patch-modules_libjar_nsZipArchive.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- modules/libjar/nsZipArchive.cpp.orig	2014-01-28 04:04:00.000000000 +0000
+++ modules/libjar/nsZipArchive.cpp
@@ -590,7 +590,9 @@ MOZ_WIN_MEM_TRY_BEGIN
     // Success means optimized jar layout from bug 559961 is in effect
     uint32_t readaheadLength = xtolong(startp);
     if (readaheadLength) {
-#if defined(XP_UNIX)
+#if defined(OS_SOLARIS)
+      posix_madvise(const_cast<uint8_t*>(startp), readaheadLength, POSIX_MADV_WILLNEED);
+#elif defined(XP_UNIX)
       madvise(const_cast<uint8_t*>(startp), readaheadLength, MADV_WILLNEED);
 #elif defined(XP_WIN)
       if (aFd) {
