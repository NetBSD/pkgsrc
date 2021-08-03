$NetBSD: patch-src_3rdparty_chromium_v8_src_api_api.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/v8/src/api/api.cc.orig	2020-07-15 19:01:43.000000000 +0000
+++ src/3rdparty/chromium/v8/src/api/api.cc
@@ -113,7 +113,7 @@
 #include "src/wasm/wasm-result.h"
 #include "src/wasm/wasm-serialization.h"
 
-#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_FREEBSD || V8_OS_NETBSD
 #include <signal.h>
 #include "include/v8-wasm-trap-handler-posix.h"
 #include "src/trap-handler/handler-inside-posix.h"
@@ -5674,7 +5674,7 @@ bool v8::V8::Initialize(const int build_
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_TARGET_ARCH_X64 && !V8_OS_ANDROID
