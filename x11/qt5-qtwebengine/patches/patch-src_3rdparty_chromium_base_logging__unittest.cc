$NetBSD: patch-src_3rdparty_chromium_base_logging__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/logging_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/logging_unittest.cc
@@ -552,7 +552,7 @@ void CheckCrashTestSighandler(int, sigin
   // need the arch-specific boilerplate below, which is inspired by breakpad.
   // At the same time, on OSX, ucontext.h is deprecated but si_addr works fine.
   uintptr_t crash_addr = 0;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   crash_addr = reinterpret_cast<uintptr_t>(info->si_addr);
 #else  // OS_POSIX && !OS_MACOSX
   ucontext_t* context = reinterpret_cast<ucontext_t*>(context_ptr);
