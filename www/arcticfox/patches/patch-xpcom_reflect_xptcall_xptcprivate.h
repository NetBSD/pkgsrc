$NetBSD: patch-xpcom_reflect_xptcall_xptcprivate.h,v 1.2 2022/05/05 14:07:39 nia Exp $

Bring NetBSD in line with other BSDs. 
Not sure abut the impact, but there is no reason to single it out

--- xpcom/reflect/xptcall/xptcprivate.h.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/xptcprivate.h
@@ -14,7 +14,7 @@
 
 class xptiInterfaceEntry;
 
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__))
+#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__))
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n() = 0;
 #else
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t) = 0;
@@ -31,7 +31,7 @@ public:
 #undef STUB_ENTRY
 #undef SENTINEL_ENTRY
 
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__))
+#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__))
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n() override;
 #else
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t,uint64_t) override;
