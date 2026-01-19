$NetBSD: patch-v8_src_base_utils_random-number-generator.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/utils/random-number-generator.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ v8/src/base/utils/random-number-generator.cc
@@ -56,7 +56,7 @@ RandomNumberGenerator::RandomNumberGener
   DCHECK_EQ(0, result);
   USE(result);
   SetSeed((static_cast<int64_t>(first_half) << 32) + second_half);
-#elif V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD
+#elif V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
   // Despite its prefix suggests it is not RC4 algorithm anymore.
   // It always succeeds while having decent performance and
   // no file descriptor involved.
