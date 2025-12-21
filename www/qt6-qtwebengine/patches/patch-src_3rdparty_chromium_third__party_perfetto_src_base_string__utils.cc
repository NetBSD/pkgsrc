$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_src_base_string__utils.cc,v 1.1 2025/12/21 09:38:44 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/perfetto/src/base/string_utils.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/base/string_utils.cc
@@ -38,9 +38,10 @@ namespace base {
 
 // Locale-independant as possible version of strtod.
 double StrToD(const char* nptr, char** endptr) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   static auto c_locale = newlocale(LC_ALL, "C", nullptr);
   return strtod_l(nptr, endptr, c_locale);
 #else
