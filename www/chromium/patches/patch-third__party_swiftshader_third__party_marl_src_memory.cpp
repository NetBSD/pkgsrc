$NetBSD: patch-third__party_swiftshader_third__party_marl_src_memory.cpp,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/third_party/marl/src/memory.cpp.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/swiftshader/third_party/marl/src/memory.cpp
@@ -19,7 +19,8 @@
 
 #include <cstring>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__OpenBSD__) || \
+      defined(__NetBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 namespace {
