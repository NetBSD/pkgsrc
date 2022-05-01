$NetBSD: patch-xpcom_reflect_xptcall_xptcstubsdecl.inc,v 1.1 2022/05/01 00:36:11 manu Exp $

Bring NetBSD in line with other BSDs. 
Not sure abut the impact, but there is no reason to single it out

--- xpcom/reflect/xptcall/xptcstubsdecl.inc.orig	2022-04-18 02:30:50.590253192 +0000
+++ xpcom/reflect/xptcall/xptcstubsdecl.inc	2022-04-17 07:00:09.391086988 +0000
@@ -7,9 +7,9 @@
 *  0 is QueryInterface
 *  1 is AddRef
 *  2 is Release
 */
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__))
+#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__) || !defined(__NetBSD__))
 NS_IMETHOD Stub3();
 NS_IMETHOD Stub4();
 NS_IMETHOD Stub5();
 NS_IMETHOD Stub6();
