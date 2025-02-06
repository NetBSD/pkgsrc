$NetBSD: patch-third__party_ipcz_src_reference__drivers_random.cc,v 1.1 2025/02/06 09:58:25 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ipcz/src/reference_drivers/random.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/ipcz/src/reference_drivers/random.cc
@@ -14,7 +14,8 @@
 #include <windows.h>
 #elif BUILDFLAG(IS_FUCHSIA)
 #include <zircon/syscalls.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) && \
+         !BUILDFLAG(IS_NETBSD)
 #include <asm/unistd.h>
 #include <sys/syscall.h>
 #include <unistd.h>
@@ -25,7 +26,7 @@
 #include <nacl/nacl_random.h>
 #endif
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_NETBSD)
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
@@ -55,7 +56,7 @@ decltype(&ProcessPrng) GetProcessPrng() 
 }
 #endif
 
-#if defined(OS_POSIX) && !BUILDFLAG(IS_MAC)
+#if (defined(OS_POSIX) && !BUILDFLAG(IS_MAC)) || BUILDFLAG(IS_NETBSD)
 void RandomBytesFromDevUrandom(absl::Span<uint8_t> destination) {
   static int urandom_fd = [] {
     for (;;) {
@@ -86,7 +87,8 @@ void RandomBytes(absl::Span<uint8_t> des
   process_prng_fn(destination.data(), destination.size());
 #elif BUILDFLAG(IS_FUCHSIA)
   zx_cprng_draw(destination.data(), destination.size());
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) && \
+         !BUILDFLAG(IS_NETBSD)
   while (!destination.empty()) {
     ssize_t result =
         syscall(__NR_getrandom, destination.data(), destination.size(), 0);
@@ -102,7 +104,7 @@ void RandomBytes(absl::Span<uint8_t> des
 #elif BUILDFLAG(IS_MAC)
   const bool ok = getentropy(destination.data(), destination.size()) == 0;
   ABSL_ASSERT(ok);
-#elif BUILDFLAG(IS_IOS)
+#elif BUILDFLAG(IS_IOS) || BUILDFLAG(IS_NETBSD)
   RandomBytesFromDevUrandom(destination);
 #elif BUILDFLAG(IS_NACL)
   while (!destination.empty()) {
