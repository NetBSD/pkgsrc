$NetBSD: patch-v8_src_api_api.cc,v 1.15 2026/02/15 09:04:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/api/api.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ v8/src/api/api.cc
@@ -163,7 +163,7 @@
 
 #include "src/strings/string-hasher-inl.h"
 
-#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 #include <signal.h>
 #include <unistd.h>
 
@@ -6322,7 +6322,7 @@ bool v8::V8::Initialize(const int build_
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD|| V8_OS_NETBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_ENABLE_WEBASSEMBLY && V8_TRAP_HANDLER_SUPPORTED
