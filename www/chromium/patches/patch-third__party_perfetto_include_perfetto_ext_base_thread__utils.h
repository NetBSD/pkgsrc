$NetBSD: patch-third__party_perfetto_include_perfetto_ext_base_thread__utils.h,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/ext/base/thread_utils.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/perfetto/include/perfetto/ext/base/thread_utils.h
@@ -41,9 +41,10 @@
 namespace perfetto {
 namespace base {
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 // Sets the "comm" of the calling thread to the first 15 chars of the given
 // string.
 inline bool MaybeSetThreadName(const std::string& name) {
