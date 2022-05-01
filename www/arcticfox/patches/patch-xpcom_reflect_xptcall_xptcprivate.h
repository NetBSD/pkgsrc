$NetBSD: patch-xpcom_reflect_xptcall_xptcprivate.h,v 1.1 2022/05/01 00:36:11 manu Exp $

Bring NetBSD in line with other BSDs. 
Not sure abut the impact, but there is no reason to single it out

--- xpcom/reflect/xptcall/xptcprivate.h.orig	2022-04-18 02:30:50.579699047 +0000
+++ xpcom/reflect/xptcall/xptcprivate.h	2022-04-17 05:04:46.979926191 +0000
@@ -13,9 +13,9 @@
 #include "mozilla/Attributes.h"
 
 class xptiInterfaceEntry;
 
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__))
+#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__))
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n() = 0;
 #else
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t) = 0;
 #endif
@@ -30,9 +30,9 @@
 
 #undef STUB_ENTRY
 #undef SENTINEL_ENTRY
 
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__))
+#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__))
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n() override;
 #else
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t) override;
 #endif
