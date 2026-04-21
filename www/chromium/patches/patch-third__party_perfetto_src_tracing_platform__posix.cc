$NetBSD: patch-third__party_perfetto_src_tracing_platform__posix.cc,v 1.18 2026/04/21 15:21:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/tracing/platform_posix.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/perfetto/src/tracing/platform_posix.cc
@@ -111,13 +111,15 @@ std::unique_ptr<base::TaskRunner> Platfo
 }
 
 std::string PlatformPosix::GetCurrentProcessName() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string cmdline;
   base::ReadFile("/proc/self/cmdline", &cmdline);
   return cmdline.substr(0, cmdline.find('\0'));
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
   return std::string(getprogname());
 #else
   return "unknown_producer";
