$NetBSD: patch-third__party_perfetto_src_base_string__utils.cc,v 1.33 2026/11/19 19:46:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/string_utils.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ third_party/perfetto/src/base/string_utils.cc
@@ -40,7 +40,8 @@ namespace base {
 // Locale-independent as possible version of strtod.
 double StrToD(const char* nptr, char** endptr) {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) ||           \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   static auto c_locale = newlocale(LC_ALL, "C", nullptr);
   return strtod_l(nptr, endptr, c_locale);
