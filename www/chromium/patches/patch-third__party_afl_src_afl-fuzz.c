$NetBSD: patch-third__party_afl_src_afl-fuzz.c,v 1.1 2025/02/06 09:58:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/afl/src/afl-fuzz.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/afl/src/afl-fuzz.c
@@ -58,7 +58,8 @@
 #include <sys/ioctl.h>
 #include <sys/file.h>
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__) || \
+    defined (__NetBSD__)
 #  include <sys/sysctl.h>
 #endif /* __APPLE__ || __FreeBSD__ || __OpenBSD__ */
 
@@ -3531,7 +3532,8 @@ static double get_runnable_processes(voi
 
   static double res;
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__) || \
+    defined (__NetBSD__)
 
   /* I don't see any portable sysctl or so that would quickly give us the
      number of runnable processes; the 1-minute load average can be a
@@ -7347,7 +7349,8 @@ static void get_core_count(void) {
 
   u32 cur_runnable = 0;
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__) || \
+    defined (__NetBSD__)
 
   size_t s = sizeof(cpu_core_count);
 
@@ -7392,7 +7395,8 @@ static void get_core_count(void) {
 
     cur_runnable = (u32)get_runnable_processes();
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__OpenBSD__) || \
+    defined (__NetBSD__)
 
     /* Add ourselves, since the 1-minute average doesn't include that yet. */
 
