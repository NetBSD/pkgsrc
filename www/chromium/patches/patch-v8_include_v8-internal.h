$NetBSD: patch-v8_include_v8-internal.h,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/include/v8-internal.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ v8/include/v8-internal.h
@@ -218,7 +218,7 @@ using SandboxedPointer_t = Address;
 #ifdef V8_ENABLE_SANDBOX
 
 // Size of the sandbox, excluding the guard regions surrounding it.
-#if defined(V8_TARGET_OS_ANDROID)
+#if (defined(V8_TARGET_OS_ANDROID) || defined(V8_TARGET_OS_OPENBSD))
 // On Android, most 64-bit devices seem to be configured with only 39 bits of
 // virtual address space for userspace. As such, limit the sandbox to 128GB (a
 // quarter of the total available address space).
