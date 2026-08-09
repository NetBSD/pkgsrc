$NetBSD: patch-third__party_swiftshader_third__party_marl_src_memory.cpp,v 1.24 2026/08/09 06:31:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/third_party/marl/src/memory.cpp.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/swiftshader/third_party/marl/src/memory.cpp
@@ -19,7 +19,8 @@
 
 #include <cstring>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__OpenBSD__) || \
+      defined(__NetBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 namespace {
