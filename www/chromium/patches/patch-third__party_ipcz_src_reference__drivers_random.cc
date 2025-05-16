$NetBSD: patch-third__party_ipcz_src_reference__drivers_random.cc,v 1.2 2025/05/16 16:08:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ipcz/src/reference_drivers/random.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ third_party/ipcz/src/reference_drivers/random.cc
@@ -55,7 +55,7 @@ decltype(&ProcessPrng) GetProcessPrng() 
 }
 #endif
 
-#if defined(OS_POSIX) && !BUILDFLAG(IS_MAC)
+#if defined(OS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void RandomBytesFromDevUrandom(absl::Span<uint8_t> destination) {
   static int urandom_fd = [] {
     for (;;) {
@@ -99,7 +99,7 @@ void RandomBytes(absl::Span<uint8_t> des
       return;
     }
   }
-#elif BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   const bool ok = getentropy(destination.data(), destination.size()) == 0;
   ABSL_ASSERT(ok);
 #elif BUILDFLAG(IS_IOS)
