$NetBSD: patch-third__party_swiftshader_src_Reactor_Debug.cpp,v 1.15 2026/02/15 09:04:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/src/Reactor/Debug.cpp.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/swiftshader/src/Reactor/Debug.cpp
@@ -46,7 +46,8 @@ namespace {
 
 bool IsUnderDebugger()
 {
-#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__)
+#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && \
+	!defined(__NetBSD__)
 	static bool checked = false;
 	static bool res = false;
 
