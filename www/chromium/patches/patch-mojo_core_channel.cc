$NetBSD: patch-mojo_core_channel.cc,v 1.6 2025/09/08 13:24:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/channel.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ mojo/core/channel.cc
@@ -80,7 +80,11 @@ const size_t kMaxAttachedHandles = 64;
 const size_t kMaxAttachedHandles = 253;
 #endif  // BUILDFLAG(IS_FUCHSIA)
 
+#if defined(__i386__) && defined(OS_FREEBSD)
+const size_t kChannelMessageAlignment = 4;
+#else
 static_assert(alignof(std::max_align_t) >= kChannelMessageAlignment, "");
+#endif
 Channel::AlignedBuffer MakeAlignedBuffer(size_t size) {
   // Generic allocators (such as malloc) return a pointer that is suitably
   // aligned for storing any type of object with a fundamental alignment
@@ -1162,7 +1166,7 @@ void Channel::LogHistogramForIPCMetrics(
 }
 
 // Currently only CrOs, Linux, and Android support upgrades.
-#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID))
+#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 // static
 MOJO_SYSTEM_IMPL_EXPORT bool Channel::SupportsChannelUpgrade() {
   return false;
